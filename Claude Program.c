#include <stdio.h>

int main(void) {
    int secret = 7;
    int guess;
    int attempts = 3;
    int won = 0;

    printf("Guess a number between 1 and 10.\n");

    for (int i = 1; i <= attempts; i++) {
        printf("Attempt %d/%d. Enter your guess: ", i, attempts);
        scanf("%d", &guess);

        if (guess < secret) {
            printf("Too low! Try again.\n");
        } else if (guess > secret) {
            printf("Too high! Try again.\n");
        } else {
            printf("Correct! You win!\n");
            won = 1;
            break;
        }
    }

    if (!won) {
        printf("Out of attempts! The number was %d. You lose.\n", secret);
    }

    return 0;
}
