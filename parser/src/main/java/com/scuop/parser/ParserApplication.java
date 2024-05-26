package com.scuop.parser;

import java.io.IOException;

import com.scuop.lexer.lexerService.LexerService;
import com.scuop.parser.parserImpl.Parser;
import com.scuop.parser.parserTree.TreeNode;

public class ParserApplication {

	public static void main(String[] args) throws IOException {
		TreeNode res = null;
		LexerService lexer = new LexerService();
		// lexer.setPath("/home/ubuntu/workspace/C-Lex-Par/test/input1.c", null);
		Parser parser = new Parser(lexer);
		switch (args.length) {
			case 0:
				System.out.println("请输入文件路径参数");
				break;
			case 1:
				try {
					lexer.setPath(args[0], "");
					res = parser.parse();
					if (res != null) {
						res.show();
					}
					break;
				} catch (IOException e) {
					System.out.println("文件路径有误");
					e.printStackTrace();
					break;
				}
			case 2:
				try {
					lexer.setPath(args[0], args[1]);
					res = parser.parse();
					if (res != null) {
						res.show();
					}
					break;
				} catch (IOException e) {
					System.out.println("文件路径有误");
					e.printStackTrace();
					break;
				}
		}
	}

}
