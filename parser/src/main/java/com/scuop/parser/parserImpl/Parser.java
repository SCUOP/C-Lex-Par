package com.scuop.parser.parserImpl;

import java.io.IOException;

import com.scuop.lexer.lexerService.LexerService;
import com.scuop.lexer.tokenType.TokenBase;
import com.scuop.lexer.tokenType.TokenSub.TokenIdentifier;
import com.scuop.lexer.tokenType.TokenSub.TokenKeyWord;
import com.scuop.lexer.tokenType.TokenSub.TokenNum;
import com.scuop.lexer.tokenType.TokenSub.TokenOperator;
import com.scuop.lexer.tokenType.tokenEnum.KeywordType;
import com.scuop.lexer.tokenType.tokenEnum.OperatorType;
import com.scuop.lexer.tokenType.tokenEnum.TokenType;
import com.scuop.parser.parserTree.TreeNode;
import com.scuop.parser.parserTree.kindEnum.ExpKind;
import com.scuop.parser.parserTree.kindEnum.StmtKind;

public class Parser {
    private LexerService lexer; // 获取lexer指针，以操作lexer进行语法分析
    private TokenBase currentToken;
    private int idxToken;
    private boolean errorState = false;
    // 抽象语法树的根节点
    private TreeNode AST;

    public Parser() {
    }

    // 需要传入lexer作为初始化起点
    public Parser(LexerService lexer) {
        this.lexer = lexer;
    }

    public void resetStatus() {
        idxToken = 0;
    }

    // 获取下一个token 指针
    public TokenBase getNextToken() throws IOException {
        currentToken = lexer.getNextToken();
        if (currentToken != null) {
            System.out.println(currentToken.toString());
        }
        return currentToken; // 或者抛出一个异常表示没有更多的Token
    }

    // 获取当前token 指针
    public TokenBase getCurrentToken() {
        return currentToken;
    }

    // 获取当前token 类型
    public TokenType getCurrentTokenType() {
        return currentToken.getTokenType();
    }

    // 在确认token类型后，以keyword 获取
    public TokenKeyWord getCurrentKeyword() {
        if (currentToken == null)
            return null;
        if (currentToken.getTokenType() == TokenType.KEYWORD) {
            return (TokenKeyWord) currentToken;
        } else {
            return null;
        }

    }

    // 在确认token类型后， 以 number获取
    public TokenNum getCurrentNumber() {
        if (currentToken == null)
            return null;
        if (currentToken.getTokenType() == TokenType.NUM) {
            return (TokenNum) currentToken;
        } else {
            return null;
        }

    }

    // 在确认token类型后， 以运算符获取
    public TokenOperator getCurrentOperator() {
        if (currentToken == null)
            return null;
        if (currentToken.getTokenType() == TokenType.OPERATOR) {
            return (TokenOperator) currentToken;
        } else {
            return null;
        }
    }

    // 在确认Token类型后， 以标识符获取
    public TokenIdentifier getCurrentId() {
        if (currentToken == null)
            return null;
        if (currentToken.getTokenType() == TokenType.ID) {
            return (TokenIdentifier) currentToken;
        } else {
            return null;
        }
    }

    // 发生语法错误的报错，传入的字符串作为报错信息
    public void syntaxError(String errorString) {
        // 输出错误信息
        System.out.print(">>> ");
        System.out.println("SyntaxError:" + errorString + " at line: "
                + currentToken.getLine() + " pos: " + currentToken.getPos());

        // 设置错误状态
        errorState = true;

        throw new RuntimeException("Syntax error occurred.");
    }

    // Match下一个关键字，如果不匹配则抛异常
    public boolean matchKeyword(KeywordType t) throws IOException {

        if (getCurrentToken().getTokenType() == TokenType.KEYWORD
                && ((TokenKeyWord) currentToken).getKeywordType() == t) {
            getNextToken();
            return true;
        } else {
            syntaxError(" Unexpected token type -->  " + getCurrentToken().toString() + "\n    Should be ->"
                    + KeywordType.KeywordType2String(t) + "    \n");
            errorState = true;
            return false;
        }
    }

    // Match 下一个运算符，如果和参数列表中的不匹配则抛异常
    public boolean matchOperator(OperatorType t) throws IOException {
        if (getCurrentToken().getTokenType() == TokenType.OPERATOR
                && ((TokenOperator) currentToken).getOperatorType() == t) {
            getNextToken();
            return true;
        } else {
            syntaxError(" Unexpected token type -->  " + getCurrentToken().toString() + "\n    Should be -> '"
                    + OperatorType.Operator2String(t) + "'\n    ");
            errorState = true;
            return false;
        }
    }

    // 运行parser
    public TreeNode parse() throws IOException {
        getNextToken();
        TreeNode res = program();
        if (currentToken != null) {
            syntaxError("Unexpected Exit!");
            return null;
        } else {
            return res;
        }
    }

    // program -> declaration_list
    private TreeNode program() throws IOException {
        System.out.println("program");
        TreeNode treeNode = TreeNode.newStmtNode(StmtKind.PROGRAM, currentToken.getLine());
        treeNode.child[0] = declarationList();
        System.out.println("----FINISH PARSING----");
        return treeNode;
    }

    // declaration_list -> declaration {declaration}
    private TreeNode declarationList() throws IOException {
        TreeNode f = TreeNode.newStmtNode(StmtKind.DECLARATION_LIST, currentToken.getLine());
        f.child[0] = declaration();
        TreeNode p = f.child[0];
        while (currentToken != null
                && (getCurrentTokenType() == TokenType.ID
                        || (getCurrentTokenType() == TokenType.KEYWORD
                                && (getCurrentKeyword().getKeywordType() == KeywordType.INT
                                        || getCurrentKeyword().getKeywordType() == KeywordType.VOID)))) {
            p.sibling = declaration();
            p = p.sibling;
        }
        return f;
    }

    // declaration -> var_declaration | fun_declaration
    private TreeNode declaration() throws IOException {
        System.out.println("declaration");
        TreeNode t = TreeNode.newStmtNode(StmtKind.DECLARATION, currentToken.getLine());
        TreeNode local_type_specifier = new TreeNode();
        TreeNode local_ID = new TreeNode();
        if (getCurrentKeyword() != null) {
            switch (getCurrentKeyword().getKeywordType()) {
                case VOID:
                    local_type_specifier = TreeNode.newExpNode(ExpKind.VOID, currentToken.getLine());
                    matchKeyword(KeywordType.VOID);
                    break;
                case INT:
                    local_type_specifier = TreeNode.newExpNode(ExpKind.INT, currentToken.getLine());
                    matchKeyword(KeywordType.INT);
                    break;
                default:
                    syntaxError("不合法的声明");
                    getNextToken();
                    break;
            }
            if (getCurrentId() != null) {
                local_ID = TreeNode.newExpNode(ExpKind.ID, currentToken.getLine());
                local_ID.setId(getCurrentId().getIdentifier());
                getNextToken();
            } else {
                syntaxError("不合法的声明");
                getNextToken();
            }
        }
        if (getCurrentOperator() != null) {
            switch (getCurrentOperator().getOperatorType()) {
                case MLB:
                    t.child[0] = varDeclaration(local_type_specifier, local_ID);
                    break;
                case SLB:
                    t.child[0] = funDeclaration(local_type_specifier, local_ID);
                    break;
                default:
                    t.child[0] = varDeclaration(local_type_specifier, local_ID);
                    break;
            }
        } else {
            t.child[0] = varDeclaration(local_type_specifier, local_ID);
        }
        return t;
    }

    // fun_declaration -> type_specifier ID ( params ) compound_stmt
    private TreeNode funDeclaration(TreeNode typeSpecifier, TreeNode id) throws IOException {
        System.out.println("fun_declaration");
        TreeNode t = TreeNode.newStmtNode(StmtKind.FUN_DECLARATION, currentToken.getLine());
        ;
        if (typeSpecifier == null) {
            if (getCurrentKeyword() != null) {
                TreeNode temp;
                switch (getCurrentKeyword().getKeywordType()) {
                    case VOID:
                        temp = TreeNode.newExpNode(ExpKind.VOID, currentToken.getLine());
                        t.child[0] = temp;
                        matchKeyword(KeywordType.VOID);
                        break;
                    case INT:
                        temp = TreeNode.newExpNode(ExpKind.INT, currentToken.getLine());
                        t.child[0] = temp;
                        matchKeyword(KeywordType.INT);
                        break;
                    default:
                        syntaxError("不合法的函数声明");
                        getNextToken();
                        break;
                }
                if (currentToken != null && getCurrentTokenType() != TokenType.ID) {
                    temp = TreeNode.newExpNode(ExpKind.ID, currentToken.getLine());
                    temp.setId(getCurrentId().getIdentifier());
                    t.child[1] = temp;
                    getNextToken();
                } else {
                    syntaxError("不合法的函数声明");
                    getNextToken();
                }
            }
        } else {
            t.child[0] = typeSpecifier;
            t.child[1] = id;
        }
        matchOperator(OperatorType.SLB);
        TreeNode tempNode = params();
        t.child[2] = tempNode;
        matchOperator(OperatorType.SRB);
        tempNode = compoundStmt();
        t.child[3] = tempNode;
        return t;
    }

    // params -> param_list | VOID
    private TreeNode params() throws IOException {
        System.out.println("params");
        if (getCurrentKeyword() != null
                && getCurrentKeyword().getKeywordType() == KeywordType.VOID) {
            TreeNode tempNode = TreeNode.newExpNode(ExpKind.VOID, currentToken.getLine());
            matchKeyword(KeywordType.VOID);
            if (currentToken != null && getCurrentTokenType() != TokenType.ID) {
                tempNode.stmtKind = StmtKind.PARAM;
                return tempNode;
            } else {
                return paramList(tempNode);
            }
        } else {
            return paramList(null);
        }
    }

    // param_list -> param {, param}
    private TreeNode paramList(TreeNode passNode) throws IOException {
        System.out.println("param_list");
        TreeNode t = param(passNode);
        TreeNode p = t;
        while (currentToken != null && getCurrentTokenType() == TokenType.OPERATOR
                && getCurrentOperator().getOperatorType() == OperatorType.COM) {
            matchOperator(OperatorType.COM);
            TreeNode tempNode = param(null);
            p.sibling = tempNode;
            p = tempNode;
        }
        return t;
    }

    // param -> type_specifier ID [
    private TreeNode param(TreeNode passNode) throws IOException {
        System.out.println("param");
        TreeNode t = TreeNode.newStmtNode(StmtKind.PARAM, currentToken.getLine());
        // 匹配开头的 type_specifier
        if (getCurrentKeyword() != null) {
            if (passNode == null) {
                if (getCurrentKeyword().getKeywordType() == KeywordType.VOID) {
                    TreeNode tempNode = TreeNode.newExpNode(ExpKind.VOID, currentToken.getLine());
                    tempNode.child[0] = tempNode;
                    matchKeyword(KeywordType.VOID);
                } else if (getCurrentKeyword().getKeywordType() == KeywordType.INT) {
                    TreeNode tempNode = TreeNode.newExpNode(ExpKind.INT, currentToken.getLine());
                    t.child[0] = tempNode;
                    matchKeyword(KeywordType.INT);
                }
            } else {
                t.child[0] = passNode;
            }
            // 匹配ID
            if (getCurrentId() != null) {
                TreeNode tempNode = TreeNode.newExpNode(ExpKind.ID, currentToken.getLine());
                tempNode.setId(getCurrentId().getIdentifier());
                t.child[1] = tempNode;
                getNextToken();
            }
            if (getCurrentOperator() != null
                    && getCurrentOperator().getOperatorType() == OperatorType.MLB) {
                t.stmtKind = StmtKind.PARAM_ARRAY;
                matchOperator(OperatorType.MLB);
                matchOperator(OperatorType.MRB);
            }
            return t;
        } else {
            syntaxError("不符合形参列表的规范");
            return null;
        }
    }

    // compound_stmt -> {local-declarations statement-list}
    // 此处是First集合为{开头，不是0个或多个
    private TreeNode compoundStmt() throws IOException {
        System.out.println("compound-stmt");
        TreeNode t = TreeNode.newStmtNode(StmtKind.COMPOUND_STMT, currentToken.getLine());
        matchOperator(OperatorType.LLB);
        t.child[0] = localDeclarations();
        t.child[1] = statementList();
        matchOperator(OperatorType.LRB);
        return t;
    }

    // local_declarations -> {var-declaration}
    private TreeNode localDeclarations() throws IOException {
        System.out.println("local_declarations");
        TreeNode t = null;
        TreeNode p = null;
        while (currentToken != null && (getCurrentTokenType() == TokenType.KEYWORD &&
                (getCurrentKeyword().getKeywordType() == KeywordType.INT ||
                        getCurrentKeyword().getKeywordType() == KeywordType.VOID))) {
            TreeNode q = varDeclaration(null, null);
            if (q != null) {
                if (t == null) {
                    t = p = q;
                } else {
                    p.sibling = q;
                    p = q;
                }
            }
        }
        return t;
    }

    // var_declaration -> type_specifier ID; | type_specifier ID [ NUM ] ;
    private TreeNode varDeclaration(TreeNode typeSpecifier, TreeNode id) throws IOException {
        System.out.println("var_declaration");
        TreeNode t = null;
        if (typeSpecifier == null) {
            if (currentToken != null && getCurrentTokenType() == TokenType.KEYWORD) {
                t = TreeNode.newStmtNode(StmtKind.VAR_DECLARATION, currentToken.getLine());
                // 匹配 void int
                if (getCurrentKeyword().getKeywordType() == KeywordType.VOID) {
                    TreeNode tempNode = TreeNode.newExpNode(ExpKind.VOID, currentToken.getLine());
                    t.child[0] = tempNode;
                    matchKeyword(KeywordType.VOID);
                } else if (getCurrentKeyword().getKeywordType() == KeywordType.INT) {
                    TreeNode tempNode = TreeNode.newExpNode(ExpKind.INT, currentToken.getLine());
                    t.child[0] = tempNode;
                    matchKeyword(KeywordType.INT);
                } else {
                    syntaxError("语句中出现了非法的数据类型");
                    return null;
                }
                // 匹配ID
                if (currentToken != null && getCurrentTokenType() == TokenType.ID) {
                    TreeNode tempNode = TreeNode.newExpNode(ExpKind.ID, currentToken.getLine());
                    tempNode.setId(getCurrentId().getIdentifier());
                    tempNode.child[1] = tempNode;
                    getNextToken();
                } else {
                    syntaxError("语句中出现了非法的标识符");
                    return null;
                }
            } else {
                return null;
            }
        }
        // 如果从上面传下来了已经读好的type_specifier和ID
        else {
            t = TreeNode.newStmtNode(StmtKind.VAR_DECLARATION, currentToken.getLine());
            t.child[0] = typeSpecifier;
            t.child[1] = id;
        }
        // 如果有方括号
        if (getCurrentOperator() != null
                && getCurrentOperator().getOperatorType() == OperatorType.MLB) {
            matchOperator(OperatorType.MLB);
            TreeNode tempNode = TreeNode.newExpNode(ExpKind.NUM, currentToken.getLine());
            tempNode.setNumber(getCurrentNumber().getNumber());
            t.child[2] = tempNode;
            getNextToken();
            matchOperator(OperatorType.MRB);
        }
        matchOperator(OperatorType.SEM);
        return t;
    }

    // statement_list -> {statement}
    private TreeNode statementList() throws IOException {
        System.out.println("statement_list");
        TreeNode t = null;
        TreeNode p = null;
        while (currentToken != null && ((getCurrentTokenType() == TokenType.KEYWORD
                && (getCurrentKeyword().getKeywordType() == KeywordType.IF
                        || getCurrentKeyword().getKeywordType() == KeywordType.WHILE
                        || getCurrentKeyword().getKeywordType() == KeywordType.RETURN))
                || (getCurrentTokenType() == TokenType.OPERATOR
                        && (getCurrentOperator().getOperatorType() == OperatorType.LLB
                                || getCurrentOperator().getOperatorType() == OperatorType.SEM
                                || getCurrentOperator().getOperatorType() == OperatorType.SLB))
                || (getCurrentTokenType() == TokenType.ID)
                || (getCurrentTokenType() == TokenType.NUM))) {
            TreeNode q = statement();
            if (q != null) {
                if (t == null) {
                    t = p = q;
                } else {
                    p.sibling = q;
                    p = q;
                }
            }
        }
        return t;
    }

    // statement -> expression_stmt | compound_stmt | selection_stmt |
    // iteration_stmt | return_stmt
    private TreeNode statement() throws IOException {
        System.out.println("statement");
        TreeNode t = null;
        if (currentToken != null) {
            switch (getCurrentTokenType()) {
                case KEYWORD:
                    switch (getCurrentKeyword().getKeywordType()) {
                        case IF:
                            t = selectionStmt();
                            break;
                        case WHILE:
                            t = iterationStmt();
                            break;
                        case RETURN:
                            t = returnStmt();
                            break;
                        default:
                            syntaxError("语句中出现了非法的关键字");
                            getNextToken();
                            break;
                    }
                    break;
                case ID:
                case NUM:
                    t = expressionStmt();
                    break;
                case OPERATOR:
                    switch (getCurrentOperator().getOperatorType()) {
                        // {
                        case LLB:
                            t = compoundStmt();
                            break;
                        // ;
                        case SEM:
                            // (
                        case SLB:
                            t = expressionStmt();
                            break;
                        default:
                            syntaxError("语句中出现了非法的运算符");
                            getNextToken();
                            break;
                    }
                    break;
                default:
                    syntaxError("语句中出现了非法的token");
                    getNextToken();
                    break;
            }
        }
        return t;
    }

    // expression_stmt -> expression ; | ;
    private TreeNode expressionStmt() throws IOException {
        System.out.println("expression_stmt");
        TreeNode t = null;
        // ;
        if (currentToken != null && getCurrentTokenType() == TokenType.OPERATOR
                && getCurrentOperator().getOperatorType() == OperatorType.SEM) {
            matchOperator(OperatorType.SEM);
        } else {
            t = expression();
            matchOperator(OperatorType.SEM);
        }
        return t;
    }

    // selection_stmt -> IF ( expression ) statement | IF ( expression ) statement
    // ELSE statement
    private TreeNode selectionStmt() throws IOException {
        System.out.println("selection_stmt");
        TreeNode t = TreeNode.newStmtNode(StmtKind.SELECTION_STMT, currentToken.getLine());
        // if
        matchKeyword(KeywordType.IF);
        // (
        matchOperator(OperatorType.SLB);
        // expression
        t.child[0] = expression();
        // )
        matchOperator(OperatorType.SRB);
        // statement
        t.child[1] = statement();
        // else
        if (currentToken != null && getCurrentTokenType() == TokenType.KEYWORD
                && getCurrentKeyword().getKeywordType() == KeywordType.ELSE) {
            matchKeyword(KeywordType.ELSE);
            // statement
            t.child[2] = statement();
        }
        return t;
    }

    // iteration_stmt -> WHILE ( expression ) statement
    private TreeNode iterationStmt() throws IOException {
        System.out.println("iteration_stmt");
        TreeNode t = TreeNode.newStmtNode(StmtKind.ITERATION_STMT, currentToken.getLine());
        // while
        matchKeyword(KeywordType.WHILE);
        // (
        matchOperator(OperatorType.SLB);
        // expression
        t.child[0] = expression();
        // )
        matchOperator(OperatorType.SRB);
        // statement
        t.child[1] = statement();
        return t;
    }

    // return_stmt -> RETURN; | RETURN expression;
    private TreeNode returnStmt() throws IOException {
        System.out.println("return_stmt");
        TreeNode t = TreeNode.newStmtNode(StmtKind.RETURN_STMT, currentToken.getLine());
        // return
        matchKeyword(KeywordType.RETURN);
        // ;
        if (currentToken != null && getCurrentTokenType() == TokenType.OPERATOR
                && getCurrentOperator().getOperatorType() == OperatorType.SEM) {
            matchOperator(OperatorType.SEM);
        }
        // expression
        else {
            t.child[0] = expression();
            matchOperator(OperatorType.SEM);
        }
        return t;
    }

    // expression -> var = expression | simple_expression
    private TreeNode expression() throws IOException {
        System.out.println("expression");
        TreeNode t = var();
        // simple_expression
        if (t == null) {
            t = simpleExpression(null);
        }
        // var
        else {
            // =
            if (getCurrentOperator() != null
                    && getCurrentOperator().getOperatorType() == OperatorType.ASI) {
                TreeNode tempNode = TreeNode.newExpNode(ExpKind.ASSIGN, currentToken.getLine());
                tempNode.operator = OperatorType.ASI;
                matchOperator(OperatorType.ASI);
                tempNode.child[0] = t;
                // expression
                tempNode.child[1] = expression();
                return tempNode;
            } else {
                t = simpleExpression(t);
            }
        }
        return t;
    }

    // simple_expression -> additive_expression relop additive_expression |
    // additive_expression
    private TreeNode simpleExpression(TreeNode passNode) throws IOException {
        System.out.println("simple_expression");
        // additive_expression
        TreeNode t = additiveExpression(passNode);
        if (currentToken != null && getCurrentTokenType() == TokenType.OPERATOR) {
            OperatorType currenOperatorType = getCurrentOperator().getOperatorType();
            if (currenOperatorType == OperatorType.LES
                    || currenOperatorType == OperatorType.LEQ
                    || currenOperatorType == OperatorType.GRE
                    || currenOperatorType == OperatorType.GEQ
                    || currenOperatorType == OperatorType.EQU
                    || currenOperatorType == OperatorType.NEQ) {
                TreeNode tempNode = TreeNode.newExpNode(ExpKind.OPK, currentToken.getLine());
                tempNode.operator = currenOperatorType;
                // relop
                matchOperator(currenOperatorType);
                tempNode.child[0] = t;
                t = tempNode;
                // additive_expression
                t.child[1] = additiveExpression(null);
            }
        }
        return t;
    }

    // additive_expression -> term {addop term}
    private TreeNode additiveExpression(TreeNode passNode) throws IOException {
        System.out.println("additive_expression");
        // term
        TreeNode t = term(passNode);
        // addop
        while (getCurrentOperator() != null && (getCurrentOperator().getOperatorType() == OperatorType.ADD
                || getCurrentOperator().getOperatorType() == OperatorType.SUB)) {
            TreeNode tempNode = TreeNode.newExpNode(ExpKind.OPK, currentToken.getLine());
            tempNode.child[0] = t;
            tempNode.setOperator(getCurrentOperator().getOperatorType());
            // + or -
            matchOperator(getCurrentOperator().getOperatorType());
            t = tempNode;
            t.child[1] = term(null);
        }
        return t;
    }

    // term -> factor {mulop factor }
    private TreeNode term(TreeNode passNode) throws IOException {
        System.out.println("term");
        // factor
        TreeNode t = factor(passNode);
        // mulop
        while (getCurrentOperator() != null && (getCurrentOperator().getOperatorType() == OperatorType.DIV
                || getCurrentOperator().getOperatorType() == OperatorType.MUL)) {
            TreeNode tempNode = TreeNode.newExpNode(ExpKind.OPK, currentToken.getLine());
            tempNode.child[0] = t;
            tempNode.setOperator(getCurrentOperator().getOperatorType());
            matchOperator(getCurrentOperator().getOperatorType());
            t = tempNode;
            t.child[1] = factor(null);
        }
        return t;
    }

    // factor -> 1.(expression) 2.ID (args) 3.ID [expression] 4.ID 5.NUM
    private TreeNode factor(TreeNode passNode) throws IOException {
        System.out.println("factor");
        TreeNode t = null;
        if (passNode != null) {
            if (getCurrentOperator() != null && getCurrentOperator().getOperatorType() == OperatorType.SLB) {
                t = call(passNode);
            } else {
                t = passNode;
            }
        } else {
            if (currentToken != null) {
                switch (getCurrentTokenType()) {
                    case OPERATOR:
                        // (expression)
                        if (getCurrentOperator().getOperatorType() == OperatorType.SLB) {
                            matchOperator(OperatorType.SLB);
                        } else {
                            syntaxError("非法的字符");
                            getNextToken();
                        }
                        t = expression();
                        matchOperator(OperatorType.SRB);
                        break;
                    case NUM:
                        t = TreeNode.newExpNode(ExpKind.NUM, currentToken.getLine());
                        t.setNumber(getCurrentNumber().getNumber());
                        getNextToken();
                        break;
                    case ID:
                        t = var();
                        if (getCurrentOperator() != null
                                && getCurrentOperator().getOperatorType() == OperatorType.SLB) {
                            t = call(t);
                        }
                        break;
                    default:
                        syntaxError("非法的字符");
                        getNextToken();
                        break;
                }
            }
        }
        return t;
    }

    // var -> ID | ID [ expression ]
    private TreeNode var() throws IOException {
        System.out.println("var");
        TreeNode t = TreeNode.newExpNode(ExpKind.VAR, currentToken.getLine());
        if (getCurrentId() != null) {
            TreeNode tempNode = TreeNode.newExpNode(ExpKind.ID, currentToken.getLine());
            tempNode.setId(getCurrentId().getIdentifier());
            t.child[0] = tempNode;
            getNextToken();
            // [expression]
            if (getCurrentOperator() != null && getCurrentOperator().getOperatorType() == OperatorType.MLB) {
                t.expKind = ExpKind.ARRAY_VAR;
                matchOperator(OperatorType.MLB);
                t.child[1] = expression();
                matchOperator(OperatorType.MRB);
            }
            return t;
        } else {
            return null;
        }
    }

    // call -> ID ( args )
    private TreeNode call(TreeNode k) throws IOException {
        System.out.println("call");
        TreeNode t = TreeNode.newExpNode(ExpKind.CALL, currentToken.getLine());
        if (k != null) {
            t.child[0] = k;
        }
        matchOperator(OperatorType.SLB);
        if (getCurrentOperator() != null && getCurrentOperator().getOperatorType() == OperatorType.SRB) {
            matchOperator(OperatorType.SRB);
            t.child[1] = TreeNode.newExpNode(ExpKind.EMPTY, currentToken.getLine());
        } else if (k != null) {
            t.child[1] = argList();
            matchOperator(OperatorType.SRB);
        }
        return t;
    }

    // args -> empty | expression {, expression}
    private TreeNode argList() throws IOException {
        System.out.println("arg_list");
        TreeNode t = TreeNode.newExpNode(ExpKind.ARGS, currentToken.getLine());
        TreeNode p = expression();
        t.child[0] = p;
        TreeNode q = t;
        while (getCurrentOperator() != null && getCurrentOperator().getOperatorType() == OperatorType.COM) {
            matchOperator(OperatorType.COM);
            TreeNode tempNode = TreeNode.newExpNode(ExpKind.ARGS, currentToken.getLine());
            tempNode.child[0] = expression();
            tempNode.operator = OperatorType.COM;
            q.sibling = tempNode;
            q = q.sibling;
        }
        return t;
    }
}
