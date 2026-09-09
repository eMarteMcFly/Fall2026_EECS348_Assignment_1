#include <stdio.h>
 
int main() {
    int secret = 7;     //initializing variables
    int guess;
    int max_attempts = 3;
    int won = 0;
    int input_ended = 0;
 
    printf("Guess a number between 1 and 10.\n");
 
    for (int attempt = 1; attempt <= max_attempts; attempt++) { //iterates through each attempt
        printf("Attempt %d/%d. Enter your guess: ", attempt, max_attempts); //prompts user
        int result = scanf("%d", &guess);
 
        if (result == EOF) {
            // No more input is coming at all; stop instead of looping forever.
            printf("\nNo more input received. Ending game.\n");
            input_ended = 1;
            break;
        }
 
        if (result != 1) {
            printf("Invalid input! Please enter a number.\n");
 
            // Discard the rest of the bad line, one character at a time,
            // until we hit a newline or run out of input.
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                // discard
            }
            if (c == EOF) {
                printf("No more input received. Ending game.\n");
                input_ended = 1;
                break;
            }
 
            attempt--; // Makes sure not to waste an attempt on invalid input
            continue;
        }
 
        if (guess == secret) {  //guess is correct; game is won
            printf("Correct! You win!\n");
            won = 1;
            break; // Stop the loop immediately on correct guess
        } else if (guess < secret) {    //guess is too low; tell user to try again if attempts remain
            if (attempt < max_attempts) {
                printf("Too low! Try again.\n");
            } else {
                printf("Too low!\n");
            }
        } else {
            if (attempt < max_attempts) {   //guess is too high; tell user to try again if attempts remain
                printf("Too high! Try again.\n");
            } else {
                printf("Too high!\n");
            }
        }
    }
 
    if (!won && !input_ended) { //losing outcome; tells user and reveals secret number
        printf("Sorry, you ran out of attempts! The secret number was %d.\n", secret);
    }
 
    return 0;
}
 


