%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG

int log(int type, const char* text) {
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
    fprintf(stdout, "%s %s\n", names[type-1], text);
#endif
    return type;
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

{U_LEGAL} { log(6, yytext); }

else    { log(1, "else"); }
if      { log(1, "if"); }
int     { log(1, "int"); }
return  { log(1, "return"); }
void    { log(1, "void"); }
while   { log(1, "while"); }
printf  { log(1, "printf"); }
read    { log(1, "read"); }

{ID}    { log(3, yytext); }
{NUM}   { log(4, yytext); }

=       { log(2, "="); }
,       { log(2, ","); }
;       { log(2, ";"); }

\(      { log(2, "("); }
\)      { log(2, ")"); }
\[      { log(2, "["); }
\]      { log(2, "]"); }
\{      { log(2, "{"); }
\}      { log(2, "}"); }

\+      { log(2, "+"); }
\-      { log(2, "-"); }
\*      { log(2, "*"); }
\/      { log(2, "/"); }

\<      { log(2, "<"); }
\<=     { log(2, "<="); }
>       { log(2, ">"); }
>=      { log(2, ">="); }
==      { log(2, "=="); }
!=      { log(2, "!="); }

%%

int yywrap() { return 1; }

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }

    yylex();
    
    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}

void yyerror(const char* msg) {
    fprintf(stderr, "Error: %s at line %d\n", msg, yylineno);
}
