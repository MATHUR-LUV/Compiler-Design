%{
#include <stdio.h>

%}

%%
"int"           { printf("**%s**", yytext); }
"return"        { printf("**%s**", yytext); }
"if"            { printf("**%s**", yytext); }
"else"          { printf("**%s**", yytext); }
"for"           { printf("**%s**", yytext); }
"while"         { printf("**%s**", yytext); }
"do"            { printf("**%s**", yytext); }
"switch"        { printf("**%s**", yytext); }
"case"          { printf("**%s**", yytext); }
"break"         { printf("**%s**", yytext); }
"continue"      { printf("**%s**", yytext); }
"typedef"       { printf("**%s**", yytext); }
"struct"        { printf("**%s**", yytext); }
"default"       { printf("**%s**", yytext); }
"const"         { printf("**%s**", yytext); }
"static"        { printf("**%s**", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* { printf("%s", yytext); }

[ \t\n]       { printf("%s", yytext); }
.             { printf("%s", yytext); }

%%

int main() {
    printf("Enter the C program code (press Ctrl+D to end input):\n");
    yylex();
    return 0;
}

