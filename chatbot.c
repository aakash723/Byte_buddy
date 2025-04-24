#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "chatbot.h"

// Function to trim leading and trailing whitespaces
void trimWhitespace(char *str) {
    int i, start = 0, end = strlen(str) - 1;
    
    // Trim leading spaces
    while (isspace((unsigned char)str[start])) {
        start++;
    }
    
    // Trim trailing spaces
    while (end >= start && isspace((unsigned char)str[end])) {
        end--;
    }
    
    // Shift the characters in the string to remove the spaces
    for (i = start; i <= end; i++) {
        str[i - start] = str[i];
    }
    str[i - start] = '\0';  // Null-terminate the string
}

// Function to convert string to lowercase
void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to match the user's input to the dataset and return a response
int matchKeywordResponse(const char *userInput, Dataset *dataset, int datasetSize) {
    char trimmedUserInput[MAX_INPUT_LENGTH];
    strncpy(trimmedUserInput, userInput, sizeof(trimmedUserInput));
    trimWhitespace(trimmedUserInput);
    toLowercase(trimmedUserInput);

    for (int i = 0; i < datasetSize; i++) {
        char trimmedKeyword[MAX_INPUT_LENGTH];
        strncpy(trimmedKeyword, dataset[i].keyword, sizeof(trimmedKeyword));
        trimWhitespace(trimmedKeyword);
        toLowercase(trimmedKeyword);

        if (strstr(trimmedUserInput, trimmedKeyword) != NULL) {
            // If a keyword is found, return a random response
            int index = rand() % dataset[i].numResponses;
            printf("🤖 Chatbot: %s\n", dataset[i].responses[index]);
            return 1;
        }
    }
    return 0;  // No match found
}
