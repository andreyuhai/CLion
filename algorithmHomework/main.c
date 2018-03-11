#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

typedef struct list {
    int place;
    char* name;
    int score;
    struct list* next;
    struct list* previous;
}topTenList;

int power(int base, int exponent){
    int pow = base;
    if(exponent != 0){
        for(int i = 1; i<exponent; i++){
            pow *= base;
        }
    }else{
        return 1;
    }

    return pow;
}

int* generateRandom(int digits){
    time_t t;
    time(&t);                 // Time past since epoch, in seconds.
    srand(t);                 // Pseudo-random seed
    int randPool[10] = { 0 }; // Uniqueness flags.
    int *randNumArr = malloc(digits*sizeof(int));
    int isFirstElem = 1;        // Flag for the Thousands unit of the randNumArr.
    int temp;

    for(int i = 0; i<digits; i++){
        do{
            temp = rand() % 10;
            if(isFirstElem && !temp) {
                temp = (rand() % 9) + 1;
            }
        }
        while(randPool[temp]);
        isFirstElem = 0;
        randNumArr[i] = temp;
        randPool[temp] = 1;
    }

    return randNumArr;
}

int* getUserGuess(int digits){
    int guess;
    int* guessArr = malloc(digits*sizeof(int));
    char buffer[20];          // fgets buffer
    char *endptr;             // For strtol
    int pow = power(10, digits-1);
    printf("Your guess : ");
    while(fgets(buffer, sizeof buffer, stdin)){
        if(!(guess = (int) strtol(buffer,&endptr,10)) || *endptr != '\n' || endptr == buffer || guess < pow || guess >= pow*10){
            printf("Please try again : ");
        }else
            break;
    }

    for(int i = digits-1; i >= 0; i--){
        guessArr[i] = guess % 10;
        guess /= 10;
    }

    return guessArr;
}

int checkMinus(int* randNumArr, int* guessArr, int digits){

    int minus = 0;

    for(int i = 0; i<digits; i++){
        for(int j = 0; j<digits; j++){
            if(guessArr[j] == randNumArr[i] && i != j)
                minus += 1;
        }
    }

    return minus;
}

int checkPlus(int* randNumArr, int* guessArr, int digits){

    int plus = 0;

    for(int i = 0; i<digits; i++){
        if(randNumArr[i] == guessArr[i])
            plus += 1;
    }

    return plus;
}

int fileExists(void){
    FILE* test;
    if(test = fopen("topTen.txt","r")){
        fclose(test);
        return 1;
    }

    return 0;
}

int countLines(FILE* file){
    int lineCount = 0;
    int ch;
    do{
        ch = fgetc(file);
        if(ch == '\n')
            lineCount++;
    }while( ch != EOF);

    return lineCount;
}

topTenList* readToStruct(){

    topTenList* list;
    topTenList* temp;
    int place;
    char name[20];
    char buffer[200];
    int userScore;
    int numberOfLines = 0;

    FILE* topTen = fopen("topTen.txt","r");
    numberOfLines = countLines(fopen("topTen.txt","r"));
    int i_thLine = 1;
    list = malloc(sizeof(topTenList));
    list->next = NULL;
    list->previous = NULL;
    temp = list;
    while(fgets(buffer,200,topTen)){
        sscanf(buffer,"%d %s %d",&place,name,&userScore);
        //printf("name = %s score = %d place = %d\n",name,userScore,place);
        temp->name = strdup(name);
        temp->place = place;
        temp->score = userScore;
        if(i_thLine == numberOfLines){
            temp->next = NULL;
        }else{
            temp->next = malloc(sizeof(topTenList));
            topTenList* previous = temp;
            temp = temp->next;
            temp->previous = previous;
        }
        i_thLine++;
    }
    fclose(topTen);

    topTenList* temp1 = list;
    while(temp1 != NULL){
        //printf("ŞAHANE name %s -- place %d -- score %d\n",temp1->name,temp1->place,temp1->score);
        temp1 = temp1->next;
    }

    return list;

}


void saveToFile(topTenList* list,char* name, int score) {
    FILE *topTen = fopen("topTen.txt","w");
    while(list != NULL){
        fprintf(topTen,"%d %s %d\n",list->place,list->name,list->score);
        list = list->next;
    }
    fclose(topTen);
}

void createFile(char* userName, int score){
    FILE* topTen = fopen("topTen.txt","a+");
    fprintf(topTen,"%d %s %d\n",1,userName,score);
    puts("Creating the \"Top 10\" file for the first time...");
    fclose(topTen);
}

topTenList* sortStruct(topTenList* list, char* userName, int score){

    topTenList* sortedStruct = list;
    topTenList* newUserPlace = malloc(sizeof(topTenList));
    newUserPlace->name = userName;
    newUserPlace->score = score;
    newUserPlace->next = NULL;
    newUserPlace->previous = NULL;
    while(list != NULL) {
        if(list->score < score) { // For the first place
            newUserPlace->place = list->place;
            if(list->place == 1){
                list->previous = newUserPlace;
                newUserPlace->next = list;
                sortedStruct = newUserPlace;
            }else if(list->place > 1 && list->place < 10 ){
                newUserPlace->previous = list->previous;
                newUserPlace->previous->next = newUserPlace;
                list->previous = newUserPlace;
                newUserPlace->next = list;

            }else{ // If 10th element.
                newUserPlace->previous = list->previous;
                newUserPlace->previous->next = newUserPlace;
                free(list);
            }

            break;
        }else if(list->next == NULL && list->place != 10){
            newUserPlace->previous = list;
            list->next = newUserPlace;
            newUserPlace->place = (list->place)+1;
            break;
        }
        list = list->next;
    }

    topTenList* temp = newUserPlace;
    while(temp->next != NULL && temp->next->place != 10){
        temp->next->place = (temp->next->place)+1;
        if(temp->next->next != NULL && temp->next->next->place == 10){
            free(temp->next->next);
            temp->next->next = NULL;
            break;
        }
        temp = temp->next;
    }

    return sortedStruct;

}

int inTopTen(int score){ // Check if the score is in top ten.
    topTenList* list = readToStruct();
    while(list != NULL){
        if(score > list->score){
            return 1;
        }else if(list->next == NULL && list->place != 10){
            return 1;
        }
        list = list->next;
    }
    return 0;
}

int score(int plus, int minus, int lives){
    return (10*plus)+(5*minus)+(1000/lives)-((plus*minus)/(plus+minus));
}

int calculateNumber(int* randNumArr,int digits){
    int number = 0;
    for(int i = 0; i<digits; i++){
        number += power(10,digits-(i+1))*randNumArr[i];
    }
    return number;
}

int clearStdin(){
    int c;
    while(c = getchar() != '\n' && c != EOF);
}

char* getInput(int size){
    char* input;
    input = malloc(size*sizeof(char));
    fgets(input,size,stdin);
    if(input[strlen(input)-1] != '\n'){
        clearStdin();
    }else
        input[strlen(input)-1] = 0;

    return input;
}

char getCharInput(void){
    char* input;
    input = malloc(sizeof(char));
    fgets(input,2,stdin);
    if(input[strlen(input)-1] != '\n'){
        clearStdin();
    }else
        input[strlen(input)-1] = 0;

    return *input;
}

void startGame(void){
    while(1){
        int digits = 4;
        int lives = 0;
        int* randNumArr = generateRandom(digits);
        int randNum = calculateNumber(randNumArr,digits);
        topTenList* list;
        int plusScore = 0;
        int minusScore = 0;
        int totalScore;
        char userName[25];
        char answer;
        int won = 0;

        for(int i =0; i<4;i++){
            printf("Array = %d\n",randNumArr[i]);
        }

        while(lives < 10){
            int* guessArr = getUserGuess(4);
            int minus = checkMinus(randNumArr, guessArr, 4);
            int plus = checkPlus(randNumArr, guessArr, 4);
            plusScore += plus;
            minusScore += minus;
            printf("The result : +%d -%d\n",plus,minus);

            if(plus == 4) {
                printf("You won!\n");
                lives++;
                won = 1;
                printf("lives = %d\n",lives);
                printf("Plus score : %d\nMinus score : %d\n",plusScore,minusScore);
                totalScore = score(plusScore,minusScore,lives);
                printf("Your score : %d\n",totalScore);
                break;
            }
            lives += 1;
        }

        if(won){
            printf("You are in top 10!\nPlease enter your name : ");
            strcpy(userName,getInput(25));
            sscanf(userName,"%s",userName);
            if(fileExists()){
                if(inTopTen(totalScore)){
                    list = sortStruct(readToStruct(),userName,totalScore);
                    topTenList* temp = list;
                    puts("!---- TOP 10 ----!");
                    while(temp != NULL){
                        printf("%d) %s %d\n",temp->place,temp->name,temp->score);
                        temp = temp->next;
                    }
                    saveToFile(list,userName,totalScore);
                }
            }else{
                createFile(userName,totalScore);
            }
        }else
            printf("You lost. :(\nThe number was : %d\n",randNum);


        printf("Do you want to play again ? [y/N] : ");
        answer = getCharInput();
        if(answer != 'y'){
            break;
        }
    }
}

int freeAll(){

}

int main() {
    startGame();
    return 0;
}
