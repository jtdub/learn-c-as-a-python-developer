/*
 * Exercise 3.3: Number Guessing Game
 *
 * Create a simple guessing game:
 * 1. Set a secret number (hardcode for now, or use rand())
 * 2. Ask user to guess
 * 3. Say "Too high", "Too low", or "Correct!"
 * 4. Count and display number of guesses
 *
 * Compile: cc -Wall -o ex03_guessing_game ex03_guessing_game.c
 * Run: ./ex03_guessing_game
 */

#include <stdio.h>
#include <stdlib.h>  // For rand(), srand()
#include <time.h>    // For time() to seed random

int main(void) {
    // Seed random number generator
    srand(time(NULL));

    // Generate secret number between 1 and 100
    int secret = (rand() % 100) + 1;
    int guess = 0;
    int attempts = 0;

    printf("=== Number Guessing Game ===\n");
    printf("I'm thinking of a number between 1 and 100.\n\n");

    // TODO: Implement the game loop
    // - Use scanf("%d", &guess) to read input
    // - Compare guess to secret
    // - Print appropriate message
    // - Keep track of attempts
    // - Break when correct

    // Hint: while (guess != secret) { ... }

    return 0;
}
