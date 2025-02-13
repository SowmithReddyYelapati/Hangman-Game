#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20
char *wordList[MAX_WORDS] = {
"programming",
"hangman",
"computer",
"language",
"keyboard",
"algorithm",
"developer",
"software",
"variable",
"function"
};
void displayWord(char *word, char *guessedLetters) {
for (int i = 0; i < strlen(word); i++) {
if (strchr(guessedLetters, word[i]) != NULL) {
printf("%c ", word[i]);
} else {
printf("_ ");
}
}
printf("\n");
}
int isGameWon(char *word, char *guessedLetters) {
for (int i = 0; i < strlen(word); i++) {
if (strchr(guessedLetters, word[i]) == NULL) {
return 0; // Not all letters are guessed
}
}
return 1; // All letters are guessed
}
int main() {
srand(time(NULL));
char *wordToGuess = wordList[rand() % MAX_WORDS];
char guessedLetters[MAX_WORD_LENGTH] = "";
int attempts = 7;
printf("Welcome to Hangman!\n");
do {
printf("Attempts left: %d\n", attempts);
displayWord(wordToGuess, guessedLetters);
char guess;
printf("Enter your guess: ");
scanf(" %c", &guess);
if (strchr(guessedLetters, guess) != NULL) {
printf("You already guessed that letter. Try again.\n");
continue;
}
strncat(guessedLetters, &guess, 1);
if (strchr(wordToGuess, guess) == NULL) {
printf("Incorrect guess!\n");
attempts--;
} else {
printf("Correct guess!\n");
}
if (isGameWon(wordToGuess, guessedLetters)) {
printf("Congratulations! You won. The word was: %s\n", wordToGuess);
break;
}
if (attempts == 0) {
printf("Game over! You ran out of attempts. The word was: %s\n", wordToGuess);
break;
}
} while (1);
return 0;
}
