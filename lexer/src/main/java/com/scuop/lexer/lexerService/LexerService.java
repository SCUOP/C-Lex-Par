package com.scuop.lexer.lexerService;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

import com.scuop.lexer.tokenType.TokenBase;
import com.scuop.lexer.tokenType.TokenSub.TokenIdentifier;
import com.scuop.lexer.tokenType.TokenSub.TokenKeyWord;
import com.scuop.lexer.tokenType.TokenSub.TokenNum;
import com.scuop.lexer.tokenType.TokenSub.TokenOperator;
import com.scuop.lexer.tokenType.tokenEnum.KeywordType;
import com.scuop.lexer.tokenType.tokenEnum.OperatorType;

public class LexerService {

    private int buffLen = 0;
    private int lineNo = 1; // 当前行号
    private int linePos = 0; // 当前行所在字符号
    private StringBuffer buffer = new StringBuffer(); // 当前token缓冲区
    private String lineBuffer; // 当前行缓冲区
    private int lineIndex = 0; // 当前行索引
    private boolean isEof = false; // 是否扫描结束
    private boolean next = true; // 在output状态之后，需要通过这个状态量来确保能重新读入上一个仅仅用来判断“状态”但没读入缓冲区的变量
    private LexerState state = LexerState.START; // 当前状态
    private String inputPath; // 输入路径
    private String outputPath; // 输出路径

    public List<TokenBase> results = new ArrayList<>(); // 保存结果数组
    public FileInputStream ifs;
    public FileOutputStream ofs;
    public boolean ifStdOutput = true; // 是否为标准输出
    public boolean outputRedirect = false; // 是否重定向输出至文件

    // 设置存取路径
    public void setPath(String i, String o) throws FileNotFoundException {
        ifs = new FileInputStream(i);
        if (o != null && !o.isEmpty()) {
            outputRedirect = true;
            ofs = new FileOutputStream(o);
            PrintStream ps = new PrintStream(ofs);
            // System.out输出至文件
            System.setOut(ps);
        }
    }

    public LexerState readNext(char ch, boolean next) {
        if (next) {
            linePos++;
        }
        // 状态机
        switch (state) {
            case START: {
                if (ch == '\0')
                    return state;
                else if (ch == '\n') {
                    linePos = 0;
                    lineNo++;
                    return state;
                } else if (Character.isWhitespace(ch)) {
                    return state;
                } else if (Character.isDigit(ch)) {
                    buffer.append(ch);
                    state = LexerState.IN_NUMBER;
                    return state;
                } else if (LexerState.isOperator(ch)) {
                    buffer.append(ch);
                    state = LexerState.IN_OPERATOR;
                    return state;
                } else if (Character.isAlphabetic(ch)) {
                    buffer.append(ch);
                    state = LexerState.IN_IDENTIFIER;
                    return state;
                } else if (ch == -1) {
                    state = LexerState.OUTPUT;
                    return state;
                } else {
                    state = LexerState.UNEXPECTED_CHAR;
                    return state;
                }
            }
            case IN_OPERATOR: {
                // 非运算符
                if (!LexerState.isOperator(ch)) {
                    // 处理完成
                    OperatorType op = OperatorType.String2Operator(buffer.toString());
                    // 清空缓冲区
                    buffer.setLength(0);
                    if (op == OperatorType.NULL) {
                        // 不存在
                        state = LexerState.UNDEFINED_OPERATOR;
                        return state;
                    } else if (op == OperatorType.COMMENT) {
                        // 注释
                        state = LexerState.IN_COMMENT;
                        return state;
                    } else {
                        // 增加token结果
                        results.add(new TokenOperator(op, lineNo, linePos - 1));
                        state = LexerState.OUTPUT;
                        return state;
                    }
                } else {
                    // 新读进来的也是运算符
                    OperatorType op = OperatorType.String2Operator(buffer.toString());
                    // 未识别的运算符
                    if (op != OperatorType.NULL
                            && OperatorType.String2Operator(buffer.toString() + ch) == OperatorType.NULL) {
                        // 清空缓冲区
                        buffer.setLength(0);
                        results.add(new TokenOperator(op, lineNo, linePos - 1));
                        state = LexerState.OUTPUT;
                        return state;
                    } else if (op != OperatorType.NULL
                            && OperatorType.String2Operator(buffer.toString() + ch) != OperatorType.NULL) {
                        if (OperatorType.COMMENT == (OperatorType.String2Operator(buffer.toString() + ch))) {
                            // 清空缓冲区
                            buffer.setLength(0);
                            state = LexerState.IN_COMMENT;
                            return state;
                        }
                    }
                    buffer.append(ch);
                    return state;
                }
            }
            case IN_COMMENT: {
                if (ch == '\n') {
                    linePos = 0;
                    lineNo++;
                    return state;
                } else if (ch == '*') {
                    state = LexerState.EX_COMMENT;
                    return state;
                } else {
                    state = LexerState.IN_COMMENT;
                    return state;
                }
            }
            case EX_COMMENT: {
                if (ch == '/') {
                    state = LexerState.START;
                    return state;
                } else if (ch == '\n') {
                    linePos = 0;
                    lineNo++;
                }
                state = LexerState.IN_COMMENT;
                return state;
            }
            case IN_IDENTIFIER: {
                if (Character.isAlphabetic(ch)) {
                    buffer.append(ch);
                    return state;
                } else {
                    // 是否是关键字
                    KeywordType keywordType = KeywordType.String2KeywordType(buffer.toString());
                    // 非关键字
                    if (keywordType == KeywordType.NULL) {
                        results.add(new TokenIdentifier(buffer.toString(), lineNo, linePos - 1));
                    } else {
                        results.add(new TokenKeyWord(keywordType, lineNo, linePos - 1));
                    }
                    buffer.setLength(0);
                    state = LexerState.OUTPUT;
                    return state;
                }
            }
            case IN_NUMBER: {
                if (Character.isDigit(ch)) {
                    buffer.append(ch);
                    return state;
                } else {
                    results.add(new TokenNum(buffer.toString(), lineNo, linePos));
                    buffer.setLength(0);
                    state = LexerState.OUTPUT;
                    return state;
                }
            }
            default: {
                state = LexerState.UNEXPECTED_STATE;
                return state;
            }
        }
    }

    // 获取下一个token
    public TokenBase getNextToken() throws IOException {
        return getNextToken(ifs);
    }

    public TokenBase getNextToken(FileInputStream localIfs) throws IOException {
        BufferedReader ifs = new BufferedReader(new InputStreamReader(localIfs));
        do {
            if (isEof)
                return null;
            else {
                if (lineIndex >= lineBuffer.length()) {
                    lineBuffer = ifs.readLine();
                    if (lineBuffer == null) {
                        isEof = true;
                    }
                    lineIndex = 0;
                    lineBuffer += '\n'; // 下一行
                }
                readNext(lineBuffer.charAt(lineIndex), next);
                if (!next) {
                    next = true;
                }
                if (errState()) {
                    System.out.println("ERROR :" + LexerState.getErrString(state));
                    lineBuffer = lineBuffer.replace('\t', ' ');
                    // TODO: 可能会有问题
                    System.out.println(" " + lineBuffer);
                    System.out.println(" " + " ".repeat(getLinePos() - 1) + "^");
                    System.out.println("In the line " + getLineNo() + ", position " + getLinePos());
                    System.out.println();
                    resetState();
                    return null;
                }
                if (state == LexerState.OUTPUT) {
                    next = false;
                    return this.getResult();
                }
                lineIndex++;
            }
        } while (true);
    }

    // 从输入流解析整个文件的函数
    public void lexingFile(FileInputStream ifstream) throws IOException {
        TokenBase res;
        while ((res = getNextToken()) != null) {
            if (ifStdOutput) {
                System.out.println("#" + res.getLine() + "\t" + res.getPos() + "\t" + res.toString());
            }
        }
    }

    public void lexingFile() throws IOException {
        lexingFile(ifs);
    }

    public TokenBase getResult() {
        state = LexerState.START;
        return results.get(results.size() - 1);
    }

    public List<TokenBase> getResults() {
        return results;
    }

    public String getBuffer() {
        return buffer.toString();
    }

    public int getLineNo() {
        return lineNo;
    }

    public int getLinePos() {
        return linePos;
    }

    public void resetState() {
        state = LexerState.START;
        buffer.setLength(0);
        isEof = false;
    }

    public boolean errState() {
        return (state == LexerState.UNDEFINED_OPERATOR
                || state == LexerState.UNEXPECTED_CHAR
                || state == LexerState.UNEXPECTED_STATE);
    }
}
