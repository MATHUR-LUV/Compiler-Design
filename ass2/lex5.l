%{
#include <stdio.h>
int word_count = 0;
%}

%%

[a-zA-Z]+      { word_count++; }  
[ \t]+         ;  
\n             { return 0; } 

%%

int main() {
    char input[1000];

    printf("Enter a paragraph (press Enter when done):\n");
    while(fgets(input, sizeof(input), stdin)) {
        yy_scan_string(input);  
        yylex();  
        printf("\nTotal number of words: %d\n", word_count);
        word_count = 0;  
    }
    return 0;
}

