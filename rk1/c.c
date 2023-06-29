#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAX_TEXT_LENGTH 1000

// Функция для чтения текста из файла
void readTextFromFile(char *filename, char *text) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fgets(text, MAX_TEXT_LENGTH, file);

    fclose(file);
}

// Функция для очистки экрана
void clearScreen() {
    system("cls");
}

// Функция для получения текущего времени
double getCurrentTime() {
    return (double)clock() / CLOCKS_PER_SEC;
}

// Функция для проверки вводимого символа
bool isCorrectChar(char inputChar, char targetChar) {
    if (inputChar == targetChar)
        return true;
    else
        return false;
}

// Функция для вычисления скорости печати в символах в минуту
int calculateCPM(int correctChars, double elapsedTime) {
    if (elapsedTime == 0)
        return 0;
    else
        return (int)((correctChars / elapsedTime) * 60);
}

// Функция для вычисления скорости печати в словах в минуту
int calculateWPM(int correctWords, double elapsedTime) {
    if (elapsedTime == 0)
        return 0;
    else
        return (int)((correctWords / elapsedTime) * 60);
}

// Функция для отображения статистики игры
void displayStatistics(int correctChars, int incorrectChars, int totalChars, int correctWords, double elapsedTime) {
    int cpm = calculateCPM(correctChars, elapsedTime);
    int wpm = calculateWPM(correctWords, elapsedTime);

    printf("\nGame statistics:\n");
    printf("Correct characters entered: %d\n", correctChars);
    printf("Incorrect characters entered: %d\n", incorrectChars);
    printf("Total characters entered: %d\n", totalChars);
    printf("Average typing speed (CPM): %d\n", cpm);
    printf("Average typing speed (WPM): %d\n", wpm);
}

// Функция для игры в тест скорости печати
void playTypingTest(char *text, int timeLimit, int errorLimit) {
    int textLength = strlen(text);
    int correctChars = 0;
    int incorrectChars = 0;
    int totalChars = 0;
    int correctWords = 0;
    int currentCharIndex = 0;
    double startTime = getCurrentTime();

    clearScreen();
    printf("%s\n", text);
    fflush(stdout);

    while (currentCharIndex < textLength) {
        char inputChar = getch();

        if (isCorrectChar(inputChar, text[currentCharIndex])) {
            correctChars++;
            printf("\033[1;32m%c\033[0m", text[currentCharIndex]);
            fflush(stdout);
            currentCharIndex++;
        } else {
            incorrectChars++;
            printf("\033[1;31m%c\033[0m", text[currentCharIndex]);
            fflush(stdout);
        }

        totalChars++;

        if (isspace(inputChar))
            correctWords++;

        if (incorrectChars > errorLimit || getCurrentTime() - startTime > timeLimit)
            break;
    }

    double elapsedTime = getCurrentTime() - startTime;
    clearScreen();
    displayStatistics(correctChars, incorrectChars, totalChars, correctWords, elapsedTime);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <text_file> <time_limit_sec> <error_limit>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int timeLimit = atoi(argv[2]);
    int errorLimit = atoi(argv[3]);

    char text[MAX_TEXT_LENGTH];
    readTextFromFile(filename, text);

    playTypingTest(text, timeLimit, errorLimit);

    return 0;
}
