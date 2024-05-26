package com.scuop.parser.parserTree.kindEnum;

// 语句类型的多种节点
public enum StmtKind {
    // 注释中为“语法规则有，但是没有实现”的非终结符，不影响结果
    PROGRAM,          // 程序入口
    DECLARATION_LIST, // 声明列表
    DECLARATION,      // 一次声明
    VAR_DECLARATION,  // 变量声明
                      // type_specifier       - 只有int和void
    FUN_DECLARATION,  // 函数声明
                      // params               - 只有param_list和void，直接用param代替
                      // param_list           - 用多个param的body代替
    PARAM,            // 由param组成params
    PARAM_ARRAY,      // 数组形参 - 是原来的表达式中没有的
    COMPOUND_STMT,    // {local_declarations statement_list}
                      // local_declarations   - 用多个var_declaration或者nullptr代替
                      // statement_list       - 用多个不同种类的statement直接代替
    EXPRESSION_STMT,  // 表达式语句
    SELECTION_STMT,   // 分支语句
    ITERATION_STMT,   // 循环语句
    RETURN_STMT,      // 返回语句
}

