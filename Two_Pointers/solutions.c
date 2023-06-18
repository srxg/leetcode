#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    if(s == NULL) return true;
    bool palin = false;
    int left = 0;
    int right = strlen(s)-1;
    
    while(left <= right) {
        while(left <= right && !isalnum(s[left])) {
            left++;
        }
        while(left <= right && !isalnum(s[right])) {
            right--;
        }
        char lowerLeft = tolower(s[left]);
        char lowerRight = tolower(s[right]);
        if(left <= right) {
            if(lowerLeft != lowerRight) return false;
            left++;
            right--;
        }
    }
    return true;

}

#include <string.h>

int main(int argc, char* argv[]) {
    // Calculate the total length of the arguments
    int total_length = 0;
    for (int i = 1; i < argc; i++) {
        total_length += strlen(argv[i]);
    }

    // Add space for the spaces between arguments and the null terminator
    total_length += argc - 1;

    char* s = (char*) malloc(total_length * sizeof(char));
    if (s == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return EXIT_FAILURE;
    }

    // Copy the first argument into s
    strcpy(s, argv[1]);

    // Concatenate the rest of the arguments with a space in between
    for(int i = 2; i < argc; i++) {
        strcat(s, " ");
        strcat(s, argv[i]);
    }

    printf("Palindrome: %s, %d\n", s, isPalindrome(s));

    free(s);
    return EXIT_SUCCESS;
}