package com.scuop.parser;

import java.io.IOException;

import com.scuop.lexer.lexerService.LexerService;
import com.scuop.parser.parserImpl.Parser;
import com.scuop.parser.parserTree.TreeNode;

public class ParserApplication {

	public static void main(String[] args) throws IOException {
		TreeNode res = null;
		LexerService lexer = new LexerService();
		lexer.setPath("/home/ubuntu/workspace/C-LexPar/test/input1.c", null);
		Parser parser = new Parser(lexer);
		res = parser.parse();
		if (res != null) {
			res.show();
		}
	}

}
