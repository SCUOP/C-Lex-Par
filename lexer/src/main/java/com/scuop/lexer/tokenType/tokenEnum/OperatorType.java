package com.scuop.lexer.tokenType.tokenEnum;

import java.util.HashMap;
import java.util.Map;

public enum OperatorType {
    NULL,
    COMMENT, // 注解/* */
    ADD, // +
    SUB, // -
    MUL, // *
    DIV, // /
    LES, // <
    LEQ, // <=
    GRE, // >
    GEQ, // >=
    EQU, // ==
    NEQ, // !=
    ASI, // =
    SEM, // ;
    COM, // ,
    SLB, // (
    SRB, // )
    MLB, // [
    MRB, // ]
    LLB, // {
    LRB; // }

    public final static Map<String, OperatorType> operatorMap = new HashMap<>() {
        {
            put("/*", OperatorType.COMMENT);
            put("+", OperatorType.ADD);
            put("-", OperatorType.SUB);
            put("*", OperatorType.MUL);
            put("/", OperatorType.DIV);
            put("<", OperatorType.LES);
            put("<=", OperatorType.LEQ);
            put(">", OperatorType.GRE);
            put(">=", OperatorType.GEQ);
            put("==", OperatorType.EQU);
            put("!=", OperatorType.NEQ);
            put("=", OperatorType.ASI);
            put(";", OperatorType.SEM);
            put(",", OperatorType.COM);
            put("(", OperatorType.SLB);
            put(")", OperatorType.SRB);
            put("[", OperatorType.MLB);
            put("]", OperatorType.MRB);
            put("{", OperatorType.LLB);
            put("}", OperatorType.LRB);
        }
    };

    public final static OperatorType String2Operator(String str) {
        if (operatorMap.containsKey(str)) {
            return operatorMap.get(str);
        }
        return OperatorType.NULL;
    }

    public final static String Operator2String(OperatorType op) {
        switch (op) {
            case ADD:
                return "+";
            case SUB:
                return "-";
            case MUL:
                return "*";
            case DIV:
                return "/";
            case LES:
                return "<";
            case LEQ:
                return "<=";
            case GRE:
                return ">";
            case GEQ:
                return ">=";
            case EQU:
                return "==";
            case NEQ:
                return "!=";
            case ASI:
                return "=";
            case SEM:
                return ";";
            case COM:
                return ",";
            case SLB:
                return "(";
            case SRB:
                return ")";
            case MLB:
                return "[";
            case MRB:
                return "]";
            case LLB:
                return "{";
            case LRB:
                return "}";
            default:
                return "<invalid token>";
        }
    }
}
