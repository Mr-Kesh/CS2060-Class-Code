/*
* The program randomly generates numbers   
* between 1 and 1000 for the user to guess.
*/


// A library to import the many functions that visual code provies for C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// This line is a preprocessor directive, specifically a macro definition for the constant MIN_NUMBER with a value of 1.
#define MIN_NUMBER 1

// This line defines a constant variable with the name MAX_NUMBER and a value of 100.
const int MAX_NUMBER = 100;

// This line declares a function named "guessGame" that takes no parameters and returns no value. This line declares a function named "isCorrect" that takes two integers as parameters and returns a boolean value.
void guessGame(void); 
bool isCorrect(int, int); 


int main(void)
{
    // This line seeds the random number generator with the current time to ensure that the generated number will be truly random.
   srand(time(0));

   // This line calls the "guessGame" function.
   guessGame(); 

   // This line returns a value of 0 to indicate that the program has finished executing successfully.
   return 0;
}

// This function handles the main logic of the guessing game. It generates a random number, prompts the user to guess the number, and checks if the user's guess is correct.
void guessGame(void)
{
    // This line declares a variable named "answer" to store the randomly generated number.
   int answer = 0; 
   int guess = 0; 
   int response = 0; 

   do {

       // This line generates a random number between MIN_NUMBER and MAX_NUMBER and assigns it to the "answer" variable.
      answer = MIN_NUMBER + rand() % MAX_NUMBER;


      // This line prompts the user to guess the number and displays the range of the number.
      printf("Hello, I have a number between %d and %d .\n" 
          "Can you guess my number?\n"
           "Please type your first guess.", MIN_NUMBER, MAX_NUMBER);

      // This loop prompts the user to guess the number until their guess is correct.
      do
      {
          // This line prompts the user to input their guess and assigns it to the "guess" variable.
          scanf("%d", &guess);
      } while (!isCorrect(guess, answer));
         
      // This line displays a message to the user to inform them that they have guessed the number correctly.
      puts("\nExcellent! You guessed the number!\n"
         "Would you like to play again?");

      printf("%s", "Please type ( 1=yes, 2=no ) ");
      scanf("%d", &response);

      puts("");
   } while (response == 1);
} 

// This function compares the user's guess to the answer and returns a boolean value indicating whether the guess is correct or not.
bool isCorrect(int g, int a)
{
    // This line declares a variable named "found" to store the boolean value indicating whether the guess is correct or not.
    bool found = false;

    // This line checks if the user's guess is equal to the answer.
    if (g == a){
        found = true;
    }else  if (g < a)
      printf( "%s", "Too low. Try again.\n? " );
   else
      printf( "%s", "Too high. Try again.\n? " );

    // This line returns the "found" variable, which indicates whether the user's guess is correct or not.
   return found;
} 

