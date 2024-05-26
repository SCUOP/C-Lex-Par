package com.scuop.lexer.tokenType.TokenSub;

import com.scuop.lexer.tokenType.TokenBase;
import com.scuop.lexer.tokenType.tokenEnum.OperatorType;
import com.scuop.lexer.tokenType.tokenEnum.TokenType;

// 运算符
public class TokenOperator extends TokenBase {

    private OperatorType operatorType;

    public TokenOperator(OperatorType t, int l, int p) {
        super(l, p);
        operatorType = t;
    }

    public OperatorType getOperatorType() {
        return operatorType;
    }

    @Override
    public TokenType getTokenType() {
        return TokenType.OPERATOR;
    }

    @Override
    public String toString() {
        return "Operator:    \t" + OperatorType.Operator2String(operatorType);
    }

}
