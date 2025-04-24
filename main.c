// main.c
#include <stdio.h>
#include <string.h>
#include "databank.h"

int main() {
    char input[100];
    setupDataBank();

    printf("Type 'exit' to quit the chat.\n");

    while (1) {
        printf("You: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline

        if (strcmp(input, "exit") == 0) {
            printf("Bot: Goodbye!\n");
            break;
        }

        char* response = findReplyMatch(input);
        printf("Bot: %s\n", response);
    }

    return 0;
}
