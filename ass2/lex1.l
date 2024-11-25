%{
#include <iostream>
using namespace std;
%}

%{
int count = 0;
%}

%%

a+  { cout << "Matched sequence of a's: " << yytext << endl; }
b+  { cout << "Matched sequence of b's: " << yytext << endl; }

%%

int main() {
    yylex();
    return 0;
}
