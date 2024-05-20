package com.scuop.lexer;

import org.junit.jupiter.api.Test;

import com.scuop.lexer.tokenType.TokenSub.TokenIdentifier;
import com.scuop.lexer.tokenType.TokenSub.TokenKeyWord;
import com.scuop.lexer.tokenType.TokenSub.TokenNum;
import com.scuop.lexer.tokenType.TokenSub.TokenOperator;
import com.scuop.lexer.tokenType.tokenEnum.KeywordType;
import com.scuop.lexer.tokenType.tokenEnum.OperatorType;

public class TokenTest {

    @Test
    public void testTokens() {
        TokenKeyWord tokenKeyWord = new TokenKeyWord(KeywordType.IF, 1, 2);
        TokenOperator tokenOperator = new TokenOperator(OperatorType.ADD, 2, 3);
        TokenIdentifier tokenIdentifier = new TokenIdentifier("testId", 4, 5);
        TokenNum tokenNum = new TokenNum("123", 5, 2);
        System.out.println("=============================================");
        System.out.println(tokenKeyWord.toString());
        System.out.println(tokenOperator.toString());
        System.out.println(tokenIdentifier.toString());
        System.out.println(tokenNum.toString());
        System.out.println("=============================================");
    }
}
