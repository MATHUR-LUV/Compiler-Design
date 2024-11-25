%{
#include <stdio.h>
%}

%%
[ \t\n]    ;  // Skip spaces, tabs, and newlines
.          { printf("%c", yytext[0]); }  // Print any other character without a newline
%%

int main() {
    yylex();  // Call the lexer
    printf("\n");  // Print a newline at the end for better output formatting
    return 0;
}

int yywrap() {
    return 1;  // Indicate end of input
}

