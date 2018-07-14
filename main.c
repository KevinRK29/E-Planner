#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    system("color 70");
    printf("\n------------------------------------------------------------------------- WELCOME TO YOUR PERSONAL PLANNER! ----------------------------------------------------------------\n");
    printf("\n                                                                                     MAIN MENU\n");
    printf("Enter one of the following\n\n");
    printf("1. Log In\n");                                          // Enter 1 for logging in
    printf("2. Sign Up\n");                                         // Enter 2 for signing up
    //printf("3. Quit\n\n");
    int choice;

    char username [SIZE];                                           // SIZE is a constant we made of value 1000 in the header
    char password [SIZE];
    char name [SIZE];
    int check;
    char leftover;
    int keepGoing = 0;

    while (keepGoing == 0)
    {
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice)                                             // control for cases
        {
            case (1):
                scanf("%c", &leftover);
                check = logIn (username, password);                 // takes you to login process
                if (check == 0)                                     // checks if the return value is 1 or 0
                {
                    control();                                      // takes you to control (main body of the program)
                }
                keepGoing = 1;
                break;
            case (2):
                signUp (username, password, name);                  // takes you to signup process(goes to function.c file)
                check = logIn(username, password);                  // takes you to login process(goes to function.c file)
                if (check == 0)
                {
                    control();
                }
                break;
                /*
            case (3):
                keepGoing = 1;
                //goto SKIP;
                break;
                */
            default:
                printf("\nPlease enter a choice from the given options\n\n");
                keepGoing = 0;
                break;
        }
    }
    //SKIP:
    return 0;
}

