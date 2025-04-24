// databank.c
#include <string.h>
#include "databank.h"

char* keys[] = {"hi", "hello","how are you", "bye"};
char* replies[] = {"Hey there!", "Hello!", "fine", "Goodbye!"};
int totalItems = 3;

void setupDataBank() {
    // Reserved for future setup; no logic needed here for now.
}

char* findReplyMatch(const char* input) {
    for (int i = 0; i < totalItems; ++i) {
        if (strcmp(input, keys[i]) == 0) {
            return replies[i];
        }
    }
    return "Sorry, I don't understand.";
}
