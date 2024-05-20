package com.scuop.lexer;

import java.io.IOException;

import com.scuop.lexer.lexerService.LexerService;

public class LexerApplication {
	public static void main(String[] args) {
		LexerService lexerService = new LexerService();
		switch (args.length) {
			case 0:
				System.out.println("请输入文件路径参数");
				break;
			case 1:
				try {
					lexerService.setPath(args[0], "");
					lexerService.lexingFile();
					break;
				} catch (IOException e) {
					System.out.println("文件路径有误");
					e.printStackTrace();
					break;
				}
			case 2:
				try {
					lexerService.setPath(args[0], args[1]);
					lexerService.lexingFile();
					break;
				} catch (IOException e) {
					System.out.println("文件路径有误");
					e.printStackTrace();
					break;
				}
		}
	}

}
