#include <stdio.h>
#ifndef ALGORITHMHOMEWORK_GUESSINGGAME_H
#define ALGORITHMHOMEWORK_GUESSINGGAME_H

// Data structure for Top 10 file.
typedef struct list {
    int place;
    char* name;
    int score;
    struct list* next;
    struct list* previous;
}topTenList;

int power(int, int);             //Calculates the power of a number
int* generateRandom(int);        //Generates a random number of certain digits.
int* getUserGuess(int);          //Gets user guess into an array.
int checkMinus(int*, int*, int); //Checks the user guess for matching not-in-place numbers.
int checkPlus(int*, int*, int);  //Checks the user guess for matching in-place numbers.
int fileExists(void);            //Checks if the topTen.txt file exists which keeps track of Top 10 list.
int countLines(FILE*);           //Counts the lines in the Top 10 list.
topTenList* readToStruct(void);  //Reads the data in Top 10 file into the data struct.
void saveToFile(topTenList*,char*, int);    //Writes the new Top 10 list to the file.
void createFile(char*, int);                //If the Top 10 file doesn't exist, creates one.
topTenList* sortStruct(topTenList*, char*, int);    //Sorts the list after successful user guess.
int inTopTen(int);               //Checks if the user score in Top 10.
int score(int, int, int);        //Calculates the score.
int calculateNumber(int*,int);   //Returns the int type of user guess array.
int clearStdin(void);            //Clears buffer overflows for next possible input prompts
char* getInput(int);             //Gets user input
char getCharInput(void);         //Gets only a 'char'
void startGame(void);            //Starts the game

#endif //ALGORITHMHOMEWORK_GUESSINGGAME_H
