package com.scuop.parser.parserTree.kindEnum;

// 表达式类型节点
public enum ExpKind {
    VOID,       // Void节点
    INT,        // int节点
    ASSIGN,     // 赋值语句
    TERM,       // 乘法项
    FACTOR,     // 因子
    VAR,        // 变量
    ARRAY_VAR,  // 数组变量
    CALL,       // 函数调用
    ARGS,       // 函数形参列表
    NUM,        // 只含有数值的节点
    ID,         // 只含有ID的节点
    OPK,        // 二元运算符节点
    EMPTY;      // 空节点
}

