#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void signUp (char username [SIZE], char password [SIZE], char name [SIZE])
{
    char leftover;
    printf("\n                                                                                      SIGN UP \n\n");
    scanf("%c", &leftover);
    printf("                                                                   !! The Username and Password are case sensitive !!\n");
    printf("Please enter a username: ");                // puts usernames and password into character/string arrays
    gets(username);
    printf("Please enter a password: ");
    gets(password);
    printf("Enter your full name: ");
    gets(name);

    FILE * fUser;
    fUser = fopen("Username.txt", "w");                 // writes username into the text document
    fprintf(fUser, "%s", username);
    fclose(fUser);

    FILE * fPass;
    fPass = fopen("Password.txt", "w");                 // writes password into the text document
    fprintf(fPass, "%s", password);
    fclose(fPass);
}
                                                        // goes back to login process

int logIn (char username [SIZE], char password [SIZE]) //login process
{
    char user [SIZE];
    char pass [SIZE];

    printf("\n                                                                                      LOG IN \n");
    FILE * fUser;
    fUser = fopen("Username.txt", "r");                 // reads the username from the text file
    while(!feof(fUser))                                 // goes through all the characters in the file until it hits a null
    {
        fgets(username, SIZE, fUser);                   // takes the chaarcters in from the file and stores it in username
    }
    fclose(fUser);

    FILE * fPass;
    fPass = fopen("Password.txt", "r");
    while(!feof(fPass))
    {
        fgets(password, SIZE, fPass);
    }
    fclose(fPass);

    printf("\nEnter your username: ");
    gets(user);
    printf("Enter your password: ");
    gets(pass);

    int compareUser = strcmp(username, user);           // compares username to user to check if usernames match
    int comparePass = strcmp(password, pass);           // compares the strings to authorize

    if (compareUser == 0 && comparePass == 0)           // if both strings are the same, the strcmp function will yield 0
                                                        // if not it will be greater or less than 0 and will go to else statement
    {
        printf("\n                                                                               YOU HAVE GAINED ACCESS! \n\n");
        return 0;
    }
    else
    {
        printf("\nThat is not the right username and password\n");
        return 1;
    }
}


                                                        // the start of entering

void Monday()
{
                                                        // Program accepts string to an array which
                                                        // uses file IO to send to its specified text file
                                                        // confirms by printing confirmation line
                                                        // this process is looped with the entINFO function
                                                        // the steps for this functions are repeated for every day of the week

    char sentence [SIZE];
    printf("\nWhat are you planning on doing on this day!\n");
    gets(sentence);

    FILE * Mon;
    Mon = fopen("Monday.txt", "a+");                    // appends new information entered with the old information by every new line
    fprintf(Mon, "%s\n", sentence);
    fclose(Mon);

    printf("\nYour calendar has been updated...\n");
}

void Tuesday()
{
    char sentence [1000];
    printf("\nWhat are you planning on doing on this day!\n");
    gets(sentence);

    FILE * Tue;
    Tue = fopen("Tuesday.txt", "a+");
    fprintf(Tue, "%s\n", sentence);
    fclose(Tue);

    printf("\nYour calendar has been updated...\n");
}

void Wednesday()
{
    char sentence [1000];
    printf("\nWhat are you planning on doing on this day!\n");
    gets(sentence);

    FILE * Wed;
    Wed = fopen("Wednesday.txt", "a+");
    fprintf(Wed, "%s\n", sentence);
    fclose(Wed);

    printf("\nYour calendar has been updated...\n");
}

void Thursday()
{
    char sentence [1000];
    printf("\nWhat are you planning on doing on this day!\n");
    gets(sentence);

    FILE * Thurs;
    Thurs = fopen("Thursday.txt", "a+");
    fprintf(Thurs, "%s\n", sentence);
    fclose(Thurs);

    printf("\nYour calendar has been updated...\n");
}

void Friday()
{
    char sentence [1000];
    printf("\nWhat are you planning on doing on this day!\n");
    gets(sentence);

    FILE * Fri;
    Fri = fopen("Friday.txt", "a+");
    fprintf(Fri, "%s\n", sentence);
    fclose(Fri);

    printf("\nYour calendar has been updated...\n");
}

void Saturday()
{
    char sentence [1000];
    printf("\nWhat are you planning on doing on this day!\n");
    gets(sentence);

    FILE * Sat;
    Sat = fopen("Saturday.txt", "a+");
    fprintf(Sat, "%s\n", sentence);
    fclose(Sat);

    printf("\nYour calendar has been updated...\n");
}

void Sunday()
{
    char sentence [1000];
    printf("\nWhat are you planning on doing on this day!\n");
    gets(sentence);

    FILE * Sun;
    Sun = fopen("Sunday.txt", "a+");
    fprintf(Sun, "%s\n", sentence);
    fclose(Sun);

    printf("\nYour calendar has been updated...\n");
}

                                                            // the control for the days of the week the user can enter their plans
void enterInfo()
{
                                                            // start off with a function that does not return a value
    printf("\nChoose the day of the week | only numbers allowed\n\n");
    int choice;

    printf("1. Monday\n");
    printf("2. Tuesday\n");
    printf("3. Wednesday\n");
    printf("4. Thursday\n");
    printf("5. Friday\n");
    printf("6. Saturday\n");
    printf("7. Sunday\n");
    printf("8. Main Menu\n\n");
    scanf("%d",&choice);

    char leftover;                                          // takes in any left over values from the functions that might disturb the system
    scanf("%c", &leftover);

    switch(choice)                                          // control gate for each of the days of the week the user has suggested
    {
        case (1) :
            Monday();
            break;
        case (2) :
            Tuesday();
            break;
        case (3) :
            Wednesday();
            break;
        case (4) :
            Thursday();
            break;
        case (5) :
            Friday();
            break;
        case 6 :
            Saturday();
            break;
        case (7) :
            Sunday();
            break;
        case (8) :
            control();
            break;
        default :
            printf("Please choose one of the days through number next time.\n\n" );
    }
    control();
}

void readInfo ()
{
    char c;                                                                

    printf("\n\nMonday: \n");
    FILE * Mon;
    Mon = fopen("Monday.txt", "r");
    while((c = fgetc(Mon))!= EOF)
    {
        printf("%c",c);
    }
    fclose(Mon);

    printf("\n\nTuesday: \n");
    FILE * Tue;
    Tue = fopen("Tuesday.txt", "r");
    while((c = fgetc(Tue))!= EOF)
    {
        printf("%c",c);
    }
    fclose(Tue);

    printf("\n\nWednesday: \n");
    FILE * Wed;
    Wed = fopen("Wednesday.txt", "r");
    while((c = fgetc(Wed))!= EOF)
    {
        printf("%c",c);
    }
    fclose(Wed);

    printf("\n\nThursday: \n");
    FILE * Thurs;
    Thurs = fopen("Thursday.txt", "r");
    while((c = fgetc(Thurs))!= EOF)
    {
        printf("%c",c);
    }
    fclose(Thurs);

    printf("\n\nFriday: \n");
    FILE * Fri;
    Fri = fopen("Friday.txt", "r");
    while((c = fgetc(Fri))!= EOF)
    {
        printf("%c",c);
    }
    fclose(Fri);

    printf("\n\nSaturday: \n");
    FILE * Sat;
    Sat = fopen("Saturday.txt", "r");
    while((c = fgetc(Sat))!= EOF)
    {
        printf("%c",c);
    }
    fclose(Sat);

    printf("\n\nSunday: \n");
    FILE * Sun;
    Sun = fopen("Sunday.txt", "r");
    while((c = fgetc(Sun))!= EOF)
    {
        printf("%c",c);
    }
    fclose(Sun);

    char leftover;
    scanf("%c",&leftover);

    control();
}

void reset()                                                // overwrites all the files to make it blank
{
    FILE * Mon;
    Mon = fopen("Monday.txt", "w");
    fclose(Mon);

    FILE * Tue;
    Tue = fopen("Tuesday.txt", "w");
    fclose(Tue);

    FILE * Wed;
    Wed = fopen("Wednesday.txt", "w");
    fclose(Wed);

    FILE * Thurs;
    Thurs = fopen("Thursday.txt", "w");
    fclose(Thurs);

    FILE * Fri;
    Fri = fopen("Friday.txt", "w");
    fclose(Fri);

    FILE * Sat;
    Sat = fopen("Saturday.txt", "w");
    fclose(Sat);

    FILE * Sun;
    Sun = fopen("Sunday.txt", "w");
    fclose(Sun);

    printf("\nYour planner has been resetted\n");

    control();
}

void verify ()
{
    char password [SIZE];
    char pass [SIZE];
    char choice;

    FILE * fPass;
    fPass = fopen("Password.txt", "r");
    while(!feof(fPass))
    {
        fgets(password, SIZE, fPass);                       // reads all characters until the null and places it back into password variable
    }
    fclose(fPass);
    char leftover;

    printf("\n                                                                                   !! WARNING !!");
    printf("\nAre you sure you want to reset all entries");
    printf("\nAll entries once resetted cannot be restored");
    leftover = getchar();

    printf("\n\nEnter R to reset or B to go back: ");
    choice = getchar();
    leftover = getchar();                                   // placed to take in any new lines from the choice so it does not interfere with the program

    if (choice == 'R' || choice == 'r')
    {
        printf("\nEnter your password for verification purposes: ");
        gets(pass);
        int compare = strcmp(password, pass);               // compares if password matches
        switch (compare)
        {
            case (0):                                       // if strings match the function gives out a 0
                reset();                                    // goes to function reset
                break;
            default:
                printf("\nThe password is incorrect, you will be redirected to the menu\n");
                control();
                break;
        }
    }
    else if (choice == 'B' || choice == 'b')
    {
        control();
    }
    else
    {
        printf("\nYou have entered an invalid value...");
        printf("\nYou will be taken back main menu\n");
        control();
    }
}
void control()                                              // the gateway from the login to 3 choices
{
    char decide;
    int keepGoing = 0;
    int choice = 0;
    char leftover;                                          // used to collects the the new line being read

    printf("\n                                                                                       Menu\n");

    while (keepGoing == 0)
    {
        printf("\nPress 'C' to continue or Press 'R' to return back to the main menu: ");
        decide = getchar();                                 // using getchar is more easier than scanf
        if((decide == 'C') ||(decide == 'c'))
        {
            while (choice == 0)
            {
                printf("\n\nPlease enter a number from one of the following");
                printf("\n1. View the planner \n2. Write to the planner \n3. Reset the planner");
                printf("\nChoice: ");
                scanf("%d", &choice);
                switch (choice)
                {
                    case (1):
                        readInfo();                         // reads all the files
                        break;
                    case (2):
                        enterInfo();                        // takes you to interface/function of writing in information
                        break;
                    case (3):
                        verify();                           // to reset, it takes to verify then to reset()
                        break;
                    default:
                        printf("\nPlease enter an option given above");
                        choice  = 0;                        // sets choice to 0 so while loop does not break
                }
            }
        }
        else if((decide == 'R') ||(decide == 'r'))
        {
            printf("You have been successfully logged out.\n");
            main();
        }
        else
        {
            printf("\nPlease choose to enter or return back to the main menu\n\n");
            leftover = getchar();
            keepGoing = 0;
        }
    }

}
