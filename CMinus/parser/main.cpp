#include <iostream>
#include <fstream>
#include "TokenType.h"
#include "Lexer.h"
#include "Parser.h"
#include "abstract_tree.h"
// ==========全局参数定义============
std::string input = "";
// outpur路径为空，则输出到标准输出，如果不为空，则输出到文件
// std::string output = "./test_cases/output.txt";
std::string output = "";
cmlexer lex; // 初始化语法解析器类
cmparser myparser(&lex);
// ====================================

// 初始化输入输出文件路径
void initPath()
{
    lex.setPath(input, output);
}

int main(int argc, char *argv[])
{
    TreeNode* res = nullptr;

    switch (argc)
    {
    case 1: // 解析
        std::cout << "ERROR:缺少参数，请输入需要解析的文件路径！" << std::endl;
        break;
    case 2: // 如果有一个参数，则从文件路径读入，并从标准输出输出结果
        input.assign(argv[1]);
        initPath();
        res = myparser.parse();
        if (res != nullptr)
            res->show();
        break;
    default:
        std::cout << "ERROR:参数过多，请确认是否只有'输入路径'一个参数。" << std::endl;
        break;
    }
    return 0;
}