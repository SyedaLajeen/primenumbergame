#include <stdio.h>

void intro();
int isPrime(int num);
void playLevel(int level, int start, int end);
void exitMessage();

int main() {
    intro();

    playLevel(1, 1, 10);
    playLevel(2, 10, 100);
    playLevel(3, 100, 999);

    exitMessage();

    return 0;
}

void intro() {
    printf("***********************************************\n");
    printf("**** Welcome to the Prime Number Game!Enhance your learning experience with our game. ****\n");
    printf("***********************************************\n");
    printf("You will play three levels:\n");
    printf("1. Guess a prime number between 1 and 10\n");
    printf("2. Guess a prime number between 10 and 100\n");
    printf("3. Guess a prime number between 100 and 999\n");
    printf("You have three tries for each level. Let's get started!\n\n");
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void playLevel(int level, int start, int end) {
    int guess;
    int correct = 0;

    printf("\nLevel %d: Enter a prime number between %d and %d. You have 3 tries.\n", level, start, end);

    for (int tries = 1; tries <= 3; ++tries) {
        printf("Try %d: ", tries);
        scanf("%d", &guess);

        if (guess >= start && guess <= end && isPrime(guess)) {
            printf("Congratulations! %d is a prime number within the range %d to %d.\n", guess, start, end);
            correct = 1;
            break;
        } else {
            printf("Sorry, %d is not a prime number within the range %d to %d.\n", guess, start, end);
        }
    }

    if (!correct) {
        printf("You've used all your tries for Level %d. Better luck next time!\n", level);
    }
}

void exitMessage() {
    printf("\nThank you for playing the Prime Number Game!\n");
    printf("We hope you enjoyed the game and learned your prime numbers effectively. Have a great day!\n");
}
