package com.scuop.lexer.lexerService;

import java.util.Map;
import java.util.Set;

public enum LexerState {
    START, // 普通状态0
    OUTPUT, // 可以输出一个词法单元状态1
    IN_OPERATOR, // 运算符状态2
    IN_COMMENT, // 注释状态3
    IN_NUMBER, // 数字状态4
    IN_IDENTIFIER, // 标识符状态5
    EX_COMMENT, // 退出注释状态6
    UNEXPECTED_CHAR, // 未知字符7
    UNDEFINED_OPERATOR, // 未知运算符8
    UNEXPECTED_STATE; // 异常状态转换

    public final static Set<Character> operatorSet = Set.of(
            '+', '-', '*', '/', '<', '>', '=', '!', ';', ',', '(', ')', '[', ']', '{', '}');

    public final static Map<LexerState, String> errMap = Map.of(
            UNEXPECTED_CHAR, "未知字符",
            UNDEFINED_OPERATOR, "未知运算符",
            UNEXPECTED_STATE, "状态机异常");

    public final static boolean isOperator(char c) {
        return operatorSet.contains(c);
    }

    public final static String getErrString(LexerState s) {
        if (errMap.containsKey(s)){
            return errMap.get(s);
        }
        return "<invalid error>";
    }

}
