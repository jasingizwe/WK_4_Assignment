#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESSES 6
#define WORD_COUNT 5

char *word_list[WORD_COUNT] = {"apple", "banana", "cherry", "date", "elderberry"};

void displayWord(char word[], char guessed[]);
int checkWin(char word[], char guessed[]);

int main() {
    srand(time(0));
    char *word = word_list[rand() % WORD_COUNT]; // Randomly select a word
    int word_len = strlen(word);
    char guessed[word_len + 1];
    int incorrect_guesses = 0;
    int i;

    for (i = 0; i < word_len; i++) {
        guessed[i] = '_'; // Initialize with underscores
    }
    guessed[word_len] = '\0';

    printf("Welcome to the Word Guessing Game!\n");
    
    while (incorrect_guesses < MAX_GUESSES) {
        displayWord(word, guessed);
        
        char guess;
        printf("\nEnter a letter: ");
        scanf(" %c", &guess);
        
        int found = 0;
        for (i = 0; i < word_len; i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                found = 1;
            }
        }
        
        if (!found) {
            incorrect_guesses++;
            printf("Wrong guess! You have %d attempts left.\n", MAX_GUESSES - incorrect_guesses);
        }
        
        if (checkWin(word, guessed)) {
            printf("\nCongratulations! You guessed the word: %s\n", word);
            return 0;
        }
    }
    
    printf("\nGame Over! The word was: %s\n", word);
    return 0;
}

void displayWord(char word[], char guessed[]) {
    printf("\nWord: ");
    for (int i = 0; i < strlen(word); i++) {
        printf("%c ", guessed[i]);
    }
    printf("\n");
}

int checkWin(char word[], char guessed[]) {
    return strcmp(word, guessed) == 0;
}
