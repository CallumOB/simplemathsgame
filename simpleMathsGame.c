/* 
This program is a maths quiz game. It lets the user choose the number of questions and see the number answered correctly or not.
It has full error checking for both scenarios where the user has to enter values between x and y, and for if the user enters a character.

Author: Callum O'Brien
Date: 10/11/21
*/


#include <stdio.h>
#include <stdbool.h> // used for my boolean variables
#include <stdlib.h> // used for random number generation
#include <time.h> // used for random number generation


#define clear() printf("\e[1;1H\e[2J") // this clears the console for a cleaner UI - i put this as a symbolic name as "clear()" is much cleaner than the other option, as well as being easier to repeat
#define clrbuffer() while(getchar() != '\n') // this clears the input buffer
#define size 4 // defines how many maths operations there are (+, -, /, *)


int main()
{

    int i;
    int menuSelect;
    int numberOfQuestions = 5; // by default the game will have 5 questions
    int amountCorrect;
    int amountWrong;
    int opSelect;
    int randInt1;
    int randInt2;
    int ans;
    int userAns;

    bool endProgram = false;
    bool gamePlayed = false;
    bool awaitInput;
    bool divide;


    //clears the standard output
    clear();
    printf("\nWelcome to the game!\nPlease select a mode from the menu below:\n\n");


    // the initial do while loop ensures the program executes at least once, and the main menu is shown again once the program finishes; unless the user chooses to end the game.
    do
    {


        // displays the main menu 
        printf("\n1. Enter the number of questions in the quiz, with a default number of 5\n2. Start and play the quiz\n3. See the results of your quiz\n4. Exit the game\n\n");


        // the do while loop ensures the user is asked for their input at least once
        do
        {
            // the program is awaiting input
            awaitInput = true;
            menuSelect = 0;

            // takes the users menu choice
            scanf("%d", &menuSelect);
            clrbuffer(); // this clears the input buffer so that the program does not infinitely loop when a character is entered 

            // the program ensures the user enters a valid option
            if (menuSelect < 1 || menuSelect > 4)
            {
                printf("You entered an invalid option.\n\n");
            } // end if
            else
            {
                awaitInput = false;
            } // end else

        } // end do while 
        while (awaitInput == true); // the boolean variable awaitInput is used to run the loop while the program is expecting user input, and breaks it when the input is received 


        // the switch evaluates what the user has chosen from the main menu
        switch (menuSelect)
        {

            // lets the user choose a number of questions, max 5
            case 1: 
            {

                // clears the standard output
                clear();


                do 
                {
                    // the program is awaiting input
                    awaitInput = true;
                    numberOfQuestions = 0; // the program has 5 questions by default. this clears that so the loop condition isn't immediately true

                    // asks the user how many questions they would like
                    printf("\nHow many questions would you like the game to have? The maximum amount is 5.\n");
                    scanf("%d", &numberOfQuestions);
                    clrbuffer(); // this clears the input buffer so that the program does not infinitely loop when a character is entered 

                    
                    // if the user enters a number outside the range or a character they will be given an error message
                    if (numberOfQuestions < 1 || numberOfQuestions > 5)
                    {
                        printf("\nYou entered an invalid option.\n");
                    } // end if
                    else
                    {
                        // this indicates the program is no longer looking for input and breaks the loop
                        awaitInput = false; 
                        // suggests an appropriate option for the user to choose
                        printf("\nYou can select option 2 to start playing the game.\n");
                    } // end else

                } // end do while 
                while (awaitInput == true); // the boolean variable awaitInput is used to run the loop while the program is expecting user input, and breaks it when the input is received 

                break;

            } // end case 1


            // runs the game 
            case 2:
            {

                // clears the standard output
                clear();

                // generates random numbers
                srand(time(NULL));

                // resets the variables for the amount of questions right/wrong, and the user's answer 
                amountCorrect = 0;
                amountWrong = 0;
                userAns = 0;


                // a for loop is ran using the number of questions the user specifies, or the default of 5
                for (i = 0; i < numberOfQuestions; i++)
                {

                    // randInt1 and randInt2 are assigned random numbers between 1 and 10 - this is done in the loop so each question uses different numbers
                    randInt1 = rand() % 10 + 1;
                    randInt2 = rand() % 10 + 1;


                    //var opSelect1 will menuSelect a random maths operation - there are 4 possible operations in this quiz
                    opSelect = rand() % size;


                    switch(opSelect)
                    {

                        // this case generates a random question using addition
                        case 0:
                        {
                            ans = randInt1 + randInt2;
                            printf("%d + %d = \t", randInt1, randInt2);
                            
                            break;
                        } // end case 0

                        // this case generates a random question using subtraction
                        case 1:
                        {
                            ans = randInt1 - randInt2;
                            printf("%d - %d = \t", randInt1, randInt2);

                            break;
                        } // end case 1

                        // this case generates a random question using multiplication
                        case 2:
                        {
                            ans = randInt1 * randInt2;
                            printf("%d x %d = \t", randInt1, randInt2);

                            break;
                        } // end case 2

                        // this case generates a random question using division, but only if the two numbers evenly divide
                        case 3:
                        {
                            // divide needs to be false intially or the loop will immediately infinitely loop
                            divide = false;

                            
                            // a while loop is used to ensure the numbers the user is asked to divide divide into each other evenly
                            while (divide == false) 
                            {

                                // the user should not have to enter decimals, so the program checks randInt1 and randInt2 are evenly divisible
                                if ((randInt1 % randInt2) == 0)
                                {
                                    ans = randInt1 / randInt2;
                                    printf("%d / %d = \t", randInt1, randInt2);

                                    // if the conditions are true, divide becomes true and the loop is broken
                                    divide = true;
                                } // end if

                                // if those conditions are false, randInt1 and randInt2 are assigned different random values and the program loops
                                else
                                {
                                    // randInt1 and randInt2 are assigned random numbers between 1 and 10
                                    randInt1 = rand() % 10 + 1;
                                    randInt2 = rand() % 10 + 1;
                                } // end else

                            } // end while


                            break;
                        } // end case 3

                    } // end switch


                    // this do while loop ensures the user doesn't enter a character
                    do
                    {

                        // the program is awaiting input 
                        awaitInput = true;

                        // simply having the scanf() inside the if statement still prompts the user for their input
                        if ((scanf("%d", &userAns) != 1)) 
                        {
                            printf("You didn't enter a number.\n\n");
                            clrbuffer();
                        } // end if
                        else
                        {
                            awaitInput = false;
                        } // end else

                    } // end do while 
                    while (awaitInput == true); // the boolean variable awaitInput is used to run the loop while the program is expecting user input, and breaks it when the input is received 


                    // if the user gets the answer wrong, the program displays the correct answer, if they do get it right they are told so
                    if (userAns != ans)
                    {
                        printf("Incorrect. The answer was %d.\n\n", ans);
                        amountWrong++; // the count of how many questions the user has gotten right is incremented
                    } // end if
                    else
                    {
                        printf("Correct!\n\n");
                        amountCorrect++; // the count of how many questions the user has gotten wrong is incremented
                    } // end else

                } // end for
                
                // this tells the program the game has been played and allows the user to see their score
                gamePlayed = true; 


                // suggests an appropriate option for the user to choose
                printf("\nYou can select option 3 to see your results.\n");


                break;

            } // end case 2


            case 3:
            {

                // clears the standard output
                clear();


                // the user cannot see their score if they have not yet played the game
                if (gamePlayed == false)
                {
                    // clears the standard output
                    clear();

                    printf("You cannot view your results as you have not yet played the game.\n\n");
                } // end if
                else
                {
                    printf("The number of questions you got right in the last round was %d.\nThe number of questions you got wrong in the last round was %d.\n\n", amountCorrect, amountWrong);
                } // end else

                // suggests an appropriate option for the user to choose
                printf("\nYou can enter option 2 to play again, or option 4 to exit the game.\n");

                break;

            } // end case 3

            case 4:
            {

                // clears the standard output
                clear();


                printf("\nThanks for playing!\nTerminating program...\n\n");
                endProgram = true; // this breaks the do ... while loop surrounding the program and terminates it

                break;

            } // end case 4

        } // end switch


    } // end do while 
    while (endProgram == false);
    

    return 0;

} // end main