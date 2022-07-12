#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

char words[50][12] = { "foundation", "queen","restaurant","atmosphere","volume","suggestion","fact",
	"artisan","marketing","mood","elevator","connection","republic","childhood","outcome","application","soup",
	"perspective","emotion","sample","professor","piano","youth","comparison","college","pie","orange","person",
	"instance","measurement","anxiety","marriage","lake","procedure","bread","nature","relation","uncle","moment",
	"guest","maintenance","inflation","guidance","definition","hotel","news","way","error","mom","loss" }, WORD[12], guessChar, newWord[12];
int k, i, contains_char(char x[], char y), lives = 6;
int* getchar_pos(char x[], char y, size_t* size);
size_t pos = 0, size, index = 0;


int main() {
	srand(GetTickCount());
	strcpy(WORD, words[rand()%49+1]);
	newWord[0] = WORD[0];
	newWord[strlen(WORD) - 1] = WORD[strlen(WORD) - 1];
	for (i = 1; i < strlen(WORD)-1; i++) {
		newWord[i] = '_';
	}
	for (i = 0; i < strlen(WORD); i++) {
		if (i == 0) {
			printf("Welcomeee to hangman:(), try and guess this word now: %c", WORD[0]);
		}
		else if (i == strlen(WORD) - 1) {
			printf("%c\n", WORD[i]);
		}
		else {
			printf("_");
		}
	}
	while (1) {
		printf("Enter your guess: ");
		if (scanf(" %c", &guessChar) == 1) {
			if (contains_char(WORD, guessChar) == 1) {
				printf("Great! The word now is: %c", newWord[0]);
				int* charPos = getchar_pos(WORD, guessChar, &size);
				for (i = 1; i < strlen(WORD) - 1; i++) {
					if (i == charPos[index]) {
						newWord[i] = WORD[i];
						index++;
					}
					printf("%c", newWord[i]);
				}
				printf("%c", newWord[strlen(WORD)-1]);
				printf("\n");
				index = 0;
				free(charPos);
				if (!(contains_char(newWord, '_'))) {
					printf("Great, you won");
					break;
				}
			}
			else {
				if (lives == 0) {
					printf("You lose:(, the word was %s", WORD);
					break;
				}
				printf("Wrong muahahahah, you have %d lives left\n", lives); lives -= 1;
			}
			guessChar = '\0';
		}
		else {
			exit(0);
		}
	}
	return 0;
}

int contains_char(char x[], char y) {
	for (size_t i = 0; i < strlen(x); i++) {
		if (x[i] == y) {
			return 1;
		}
	}
	return 0;
}

int* getchar_pos(char x[], char y, size_t* size) {
	int* arr = (int*)malloc(sizeof(int) + 1);
	size_t pos = 0, index = 2;
	if (arr) {
		for (int i = 1; i < strlen(x)-1; i++) {
			if (x[i] == y) {
				arr[pos++] = i;
				arr = realloc(arr, index*sizeof(int));
				index++;
				if (arr == NULL) {
					printf("NULL\n");
				}
			}
		}
		*size = pos;
	}
	return arr;
}
