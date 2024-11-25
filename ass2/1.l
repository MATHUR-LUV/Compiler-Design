%{
#include <stdio.h>
%}

%%


[a]+    { printf("Matched a+: %s\n", yytext); }


[b]+    { printf("Matched b+: %s\n", yytext); }


.       { /* Ignore other characters */ }

%%

// Main function
int main(int argc, char **argv) {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}