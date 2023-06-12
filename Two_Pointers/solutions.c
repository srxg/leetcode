#include <stdio.h>
#include <stdbool.h>
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

}


int main(void) {

}