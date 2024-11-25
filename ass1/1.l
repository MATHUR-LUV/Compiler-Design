%{
#include <stdio.h>
%}

%%
[a-zA-Z][a-zA-Z0-9]*  { printf("Matched: %s\n", yytext); }
.                      { /* Ignore other characters */ }
%%

int main() {
    yylex();
    return 0;
}

