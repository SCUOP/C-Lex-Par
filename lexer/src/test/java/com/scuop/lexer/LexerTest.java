package com.scuop.lexer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;

import org.junit.jupiter.api.Test;

import com.scuop.lexer.lexerService.LexerService;
import com.scuop.lexer.lexerService.LexerState;
import com.scuop.lexer.tokenType.TokenBase;

public class LexerTest {

    @Test
    public void testLexer() throws IOException {
        boolean next = true;
        LexerService lexerService = new LexerService();
        String a;
        BufferedReader ifs = new BufferedReader(new StringReader("""
                /* A program to perform Euclid's
                Algorithm to compute gcd. */
                int gcd (int u, int v)
                {
                    if (v == 0)
                        return u ;
                    else
                        return gcd(v,u-u/v*v);
                    /* u-u/v*v ==
                    u mod v */
                }

                void main(void)
                {
                    int x; int y;
                    x = input();
                    y = input();
                    output(gcd(x,y));
                }
                """));
        System.out.println("line" + "\t" + "pos" + "\t" + "tokenType" + "\t" + "word");
        while ((a = ifs.readLine()) != null) {
            a += "\n";
            for (int i = 0; i < a.length();) {
                LexerState state = lexerService.readNext(a.charAt(i), next);
                if (!next) {
                    next = true;
                }
                if (state == LexerState.OUTPUT) {
                    TokenBase res = lexerService.getResult();
                    System.out.println("#" + res.getLine() + "\t" + res.getPos() + "\t" + res.toString());
                    next = false;
                    continue;
                }
                i++;
            }
        }
    }
}
