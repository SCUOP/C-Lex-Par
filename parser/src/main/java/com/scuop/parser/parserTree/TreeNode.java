package com.scuop.parser.parserTree;

import java.util.Arrays;

import com.scuop.lexer.tokenType.tokenEnum.KeywordType;
import com.scuop.lexer.tokenType.tokenEnum.OperatorType;
import com.scuop.parser.parserTree.kindEnum.ExpKind;
import com.scuop.parser.parserTree.kindEnum.NodeType;
import com.scuop.parser.parserTree.kindEnum.StmtKind;

// 语法树节点
public class TreeNode {
    public static final int MAXCHILDREN = 4;

    // 确定是什么类型，表达式还是语句
    public NodeType type;
    // 子节点
    public TreeNode[] child = new TreeNode[MAXCHILDREN];
    // 兄弟节点
    public TreeNode sibling;

    // 具体到节点内的类型、什么表达式或什么语句
    public ExpKind expKind;
    public StmtKind stmtKind;

    // 如果是表达式
    public OperatorType operator;
    public KeywordType keyword;
    public int num;
    public String id;

    // 用于保存当前节点的行号
    public int lineno = 0;

    // 生成一个表达式节点并返回
    public static TreeNode newExpNode(ExpKind kind, int line) {
        TreeNode node = new TreeNode();
        node.type = NodeType.EXPR_KIND;
        Arrays.fill(node.child, null);
        node.sibling = null;
        node.expKind = kind;
        node.lineno = line;
        return node;
    }

    // 生成一个语句节点并返回
    public static TreeNode newStmtNode(StmtKind kind, int line) {
        TreeNode node = new TreeNode();
        node.type = NodeType.STMT_KIND;
        Arrays.fill(node.child, null);
        node.sibling = null;
        node.stmtKind = kind;
        node.lineno = line;
        return node;
    }

    // 设置运算符表达式中的运算符类型
    public void setOperator(OperatorType oper) {
        if (type != NodeType.EXPR_KIND) {
            throw new IllegalArgumentException("Error, 尝试对于非表达式节点赋值！");
        }
        expKind = ExpKind.OPK;
        operator = oper;
    }

    // 设置当前树节点 数值 并设置节点类型
    public void setNumber(String numString) {
        if (type != NodeType.EXPR_KIND) {
            throw new IllegalArgumentException("Error, 尝试对于非表达式节点赋值！");
        }
        expKind = ExpKind.NUM;
        num = Integer.parseInt(numString);
    }

    // 设置当前节点的 字符值,并设置节点类型
    public void setId(String idString) {
        if (type != NodeType.EXPR_KIND) {
            throw new IllegalArgumentException("Error, 尝试对于非表达式节点赋值！");
        }
        expKind = ExpKind.ID;
        id = idString;
    }

    public void toStringNode() {
        StringBuilder sb = new StringBuilder();
        switch (type) {
            case STMT_KIND:
                sb.append("<");
                break;
            case EXPR_KIND:
                sb.append("<");
                break;
        }

        switch (type) {
            case STMT_KIND:
                switch (stmtKind) {
                    case PROGRAM:
                        sb.append("Program");
                        break;
                    case DECLARATION_LIST:
                        sb.append("Declaration_list");
                        break;
                    case DECLARATION:
                        sb.append("Declaration");
                        break;
                    case VAR_DECLARATION:
                        sb.append("Var_declaration");
                        break;
                    case FUN_DECLARATION:
                        sb.append("Fun_declaration");
                        break;
                    case PARAM:
                        sb.append("Param");
                        break;
                    case PARAM_ARRAY:
                        sb.append("Param_array");
                        break;
                    case COMPOUND_STMT:
                        sb.append("Compound_stmt");
                        break;
                    case EXPRESSION_STMT:
                        sb.append("Expression_stmt");
                        break;
                    case SELECTION_STMT:
                        sb.append("Selection_stmt");
                        break;
                    case ITERATION_STMT:
                        sb.append("Iteration_stmt");
                        break;
                    case RETURN_STMT:
                        sb.append("Return_stmt");
                        break;
                    default:
                        break;
                }
                break;

            case EXPR_KIND:
                switch (expKind) {
                    case VOID:
                        sb.append("Type_identifier : VOID");
                        break;
                    case INT:
                        sb.append("Type_identifier : INT");
                        break;
                    case ASSIGN:
                        sb.append("Assign: = ");
                        break;
                    case VAR:
                        sb.append("Var");
                        break;
                    case ARRAY_VAR:
                        sb.append("Array_var");
                        break;
                    case CALL:
                        sb.append("Call");
                        break;
                    case ARGS:
                        if (operator == OperatorType.COM) {
                            sb.append("Args : ").append(OperatorType.Operator2String(operator));
                        } else {
                            sb.append("Args");
                        }
                        break;
                    case NUM:
                        sb.append("NUM : ").append(num);
                        break;
                    case ID:
                        sb.append("Identifier : ").append(id);
                        break;
                    case OPK:
                        sb.append("Operator : ").append(OperatorType.Operator2String(operator));
                        break;
                    case EMPTY:
                        sb.append("Empty");
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        sb.append("> (").append(lineno).append(")");
        System.out.println(sb.toString());
    }

    public void debugDfs(int layer) {
        for (int i = 0; i < MAXCHILDREN; i++) {
            if (expKind != ExpKind.ARGS) {
                if (i == 1) {
                    System.out.print("└");
                    for (int j = 0; j < layer; j++) {
                        System.out.print("-");
                    }
                    toStringNode();
                    System.out.println();
                }
            }
            if (child[i] != null) {
                child[i].dfs(layer + 1);
            }
        }
        if (sibling != null) {
            System.out.println("--sibling start--");
            sibling.dfs(layer);
            System.out.println("--sibling   end--");
        }
    }

    public void dfs(int layer) {
        for (int i = 0; i < layer; i++) {
            System.out.print(" ");
        }
        toStringNode();
        for (int i = 0; i < MAXCHILDREN; i++) {
            if (child[i] != null) {
                child[i].dfs(layer + 1);
            }
        }
        if (sibling != null) {
            sibling.dfs(layer);
        }
    }

    public void show() {
        dfs(0);
    }
}
