package com.scuop.lexer.tokenType.tokenEnum;

import java.util.Map;

// 关键字类型
public enum KeywordType {
    NULL, IF, ELSE, INT, RETURN, VOID, WHILE;

    public final static Map<String, KeywordType> keywordMap = Map.of(
            "if", KeywordType.IF,
            "else", KeywordType.ELSE,
            "int", KeywordType.INT,
            "return", KeywordType.RETURN,
            "void", KeywordType.VOID,
            "while", KeywordType.WHILE);

    public final static KeywordType String2KeywordType(String str) {
        if (keywordMap.containsKey(str)) {
            return keywordMap.get(str);
        }
        return KeywordType.NULL;
    }

    public final static String KeywordType2String(KeywordType keywordType) {
        switch (keywordType) {
            case IF:
                return "if";
            case ELSE:
                return "else";
            case INT:
                return "int";
            case RETURN:
                return "return";
            case VOID:
                return "void";
            case WHILE:
                return "while";
            default:
                return "<invalid token>";
        }
    }
}
