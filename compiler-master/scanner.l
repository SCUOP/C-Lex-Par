%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Node.h"
using namespace std;
#define YYSTYPE Node*
#include "parser.hpp"

#define LOG

int log(int type, int id) {
#ifdef LOG
    const char names[7][10] = {
        "K_WORD  ",
        "SYMBOL  ",
        "ID      ",
        "NUMBER  ",
        "COMMENT ",
        "ERROR   ",
        "SPACES  "
    };
    fprintf(stdout, "%s %s\n", names[type-1], yytext);
#endif
    return id;
}
%}

%option yylineno

letter  [a-zA-Z]
digit   [0-9]
ID      (else|if|int|return|void|while)({letter}|{digit})+|{letter}+({letter}|{digit})*
NUM     {digit}+
NO_ID   [^a-zA-Z0-9]
U_LEGAL ([^(a-zA-Z0-9|=|<|>|!|\(|\)|\[|\]|\{|\}|/\*|\*/|,|\.|\+|\-|\*|\/|;|\t|\0|\n|\r|\ )])+

SPACES  (\t|\0|\r|\n|\ )+
COMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/

%%

{SPACES}    { /* ignore */ }
{COMMENT}   { /* ignore */ }

{U_LEGAL} { return log(6, U_LEGAL); }

else    { yylval = new Terminal(K_ELSE, "else");      return log(1, K_ELSE); }
if      { yylval = new Terminal(K_IF, "if");          return log(1, K_IF); }
int     { yylval = new Terminal(K_INT, "int");        return log(1, K_INT); }
return  { yylval = new Terminal(K_RETURN, "return");  return log(1, K_RETURN); }
void    { yylval = new Terminal(K_VOID, "void");      return log(1, K_VOID); }
while   { yylval = new Terminal(K_WHILE, "while");    return log(1, K_WHILE); }
printf  { yylval = new Terminal(K_PRINTF, "printf");  return log(1, K_PRINTF); }
read    { yylval = new Terminal(K_READ, "read");      return log(1, K_READ); }

{ID}    { yylval = new Terminal(ID, string(yytext));  return log(3, ID); }
{NUM}   { yylval = new Terminal(NUM, string(yytext)); return log(4, NUM); }

=       { yylval = new Terminal(O_ASSIGN, "=");       return log(2, O_ASSIGN); }
,       { yylval = new Terminal(O_COMMA, ",");        return log(2, O_COMMA); }
;       { yylval = new Terminal(O_SEMI, ";");         return log(2, O_SEMI); }

\(      { yylval = new Terminal(O_LSBRACKER, "(");    return log(2, O_LSBRACKER); }
\)      { yylval = new Terminal(O_RSBRACKER, ")");    return log(2, O_RSBRACKER); }
\[      { yylval = new Terminal(O_LMBRACKER, "[");    return log(2, O_LMBRACKER); }
\]      { yylval = new Terminal(O_RMBRACKER, "]");    return log(2, O_RMBRACKER); }
\{      { yylval = new Terminal(O_LLBRACKER, "{");    return log(2, O_LLBRACKER); }
\}      { yylval = new Terminal(O_RLBRACKER, "}");    return log(2, O_RLBRACKER); }

\+      { yylval = new Terminal(O_ADD, "+");          return log(2, O_ADD); }
\-      { yylval = new Terminal(O_SUB, "-");          return log(2, O_SUB); }
\*      { yylval = new Terminal(O_MUL, "*");          return log(2, O_MUL); }
\/      { yylval = new Terminal(O_DIV, "/");          return log(2, O_DIV); }

\<      { yylval = new Terminal(O_LESS, "<");         return log(2, O_LESS); }
\<=     { yylval = new Terminal(O_L_EQUAL, "<=");     return log(2, O_L_EQUAL); }
>       { yylval = new Terminal(O_GREATER, ">");      return log(2, O_GREATER); }
>=      { yylval = new Terminal(O_G_EQUAL, ">=");     return log(2, O_G_EQUAL); }
==      { yylval = new Terminal(O_EQUAL, "==");       return log(2, O_EQUAL); }
!=      { yylval = new Terminal(O_U_EQUAL, "!=");     return log(2, O_U_EQUAL); }

%%

int yywrap() { return 1; }

void yyerror(const char* msg) {
    printf("%s,%s,Line %d\n", yytext, msg, yylineno);
}
