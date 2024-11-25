%{
#include <stdio.h>
%}

%option noyywrap

%%
bb[ab]+ {printf("Matched");}
.+ {printf("Invalid\n");} 

%%

int main() {
	yylex();
	return 0;
}
