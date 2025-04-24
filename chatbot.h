#ifndef CHATBOT_H
#define CHATBOT_H

#define MAX_RESPONSES 100
#define MAX_DATASET 100
#define MAX_INPUT_LENGTH 256

// Define the structure for storing a dataset entry
typedef struct {
    char keyword[MAX_INPUT_LENGTH];
    char responses[MAX_RESPONSES][MAX_INPUT_LENGTH];
    int numResponses;
} Dataset;

// Function prototypes

// Function to trim leading and trailing whitespaces
void trimWhitespace(char *str);

// Function to convert string to lowercase
void toLowercase(char *str);

// Function to match the user's input to the dataset and return a response
int matchKeywordResponse(const char *userInput, Dataset *dataset, int datasetSize);

#endif // CHATBOT_H
