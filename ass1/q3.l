%{
#include <stdio.h>
#include <string.h>

char search_word[100];  // Variable to hold the word to search for
%}

%%
[ \t\n]+       ;  // Skip whitespace
[a-zA-Z]+      { /* Match words and can use for further processing if needed */ }

%%

// Function to find the word and print its position
void find_word(char *sentence) {
    char *pos = strstr(sentence, search_word);
    while (pos != NULL) {
        printf("Found '%s' at position: %ld\n", search_word, pos - sentence + 1);
        pos = strstr(pos + 1, search_word); // Search for the next occurrence
    }
}

int main() {
    printf("Enter the word to search for: ");
    scanf("%s", search_word);  // Read the word to search for

    printf("Enter the sentence: ");
    char sentence[1000];
    getchar();  // Clear the newline character from the buffer
    fgets(sentence, sizeof(sentence), stdin);  // Read the input sentence

    find_word(sentence);  // Call the function to find the word
    return 0;
}

int yywrap() {
    return 1;  // Indicate end of input
}

