%{
#include <stdio.h>
%}

%option noyywrap

%%
ab+ {printf("Matched");}
ba+ {printf("Matched");}
.+ {printf("Invalid\n");} 

%%

int main() {
	yylex();
	return 0;
}
