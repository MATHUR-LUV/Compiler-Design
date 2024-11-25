%{
#include <stdio.h>
%}



%%
[0-9] {printf("digit %s\n", yytext);}
[^0-9] {}
%%

int main() {
	yylex();
	return 0;
}
