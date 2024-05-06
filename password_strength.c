#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define FALSE 0
#define TRUE 1

int password_validator(char *password);

int main() {
    char password[25];
    int result;
    // Instructions
    printf("**************************************************************\n");
    printf("A strong password should have at least 8 characters, including\n");
    printf("a mix of letters, numbers, and other characters (+,$,#,!).\n");
    printf("**************************************************************\n\n\n");


    // Get Input
    printf("Please enter the password to be tested: ");
    fgets(password, 25, stdin);
    password[strcspn(password, "\n")] = 0; // remove trailing newline from input

    // Send password for analysis
    result = password_validator(password);

    // Output
    if (result == FALSE){
        printf("'%s' is a weak password.\n", password);
    }
    else if (result == TRUE){
        printf("'%s' is a strong password.\n", password);
    }

    return (0);
}

/* This function checks various parameters to determine password strength */
int password_validator(char *password){
    int length = strlen(password);
    int alpha = 0;
    int numeric = 0;
    int other = 0;
    
    // Check length of password. If < 8, return FALSE
    if (length < 8){
        return FALSE;
    }
    // Count alphabetic and numeric characters
    for (int i = 0; i < length; ++i){
        if (isalpha(password[i]) != 0 ){
            ++alpha;
        }
        else if(isdigit(password[i]) != 0){
            ++numeric;
        }
        else{
            ++other;
        }

    }
    printf("LETTERS: \t\t%d\n", alpha);
    printf("NUMBERS: \t\t%d\n", numeric);
    printf("OTHER CHARACTERS: \t%d\n", other);
    // If the password contains only letters or only numbers, and no punctuation return FALSE
    if (alpha == 0 || numeric == 0){
        return FALSE;
    }
    else if (other == 0){
        return FALSE;
    }
    // Otherwise, return TRUE
    else {
        return TRUE;
    }
}

