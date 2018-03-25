#include "odev.h"
#include <math.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

double alan(double arr[][2], int size){
    double area = 0;
    for(int i=0; i < size-1; i++){
        area += (arr[i+1][0]+arr[i][0])*(arr[i+1][1]-arr[i][1]);
    }
    return fabs(area)/2;
}

int getInput(void){
    int input;
    char buffer[20];          // fgets buffer
    char *endptr;             // For strtol
    printf("Enter a number : ");
    while(fgets(buffer, sizeof buffer, stdin)) {
        input = (int) strtol(buffer, &endptr, 10);
        if (*endptr != '\n' || endptr == buffer) {
            printf("Please try again : ");
        }else
            break;
    }
    return input;
}

int* getArr(int size){
    int* arr = malloc(size*sizeof(int));
    for(int i=0; i<size; i++){
        arr[i] = getInput();
    }
    return arr;
}

double ortalama(int arr[], int size){
    double sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    return sum/size;
}

double standartSapma(int arr[], int size){
    double stdDeviation = 0;
    double mean = ortalama(arr,size);
    printf("ortalama (mean) = %f\n",mean);
    for(int i=0; i<size; i++){
        stdDeviation += pow(arr[i]-mean,2);
    }
    return sqrt(stdDeviation/(size-1));
}

void fillMatrix(int(*matrix)[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            (*matrix)[i][j] = getInput();
        }
    }
}

void matrisCarpim(int (*mDizi)[3][3]){
    int m1[3][3] = {0};
    int m2[3][3] = {0};
    fillMatrix(&m1);
    fillMatrix(&m2);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){

        }
    }


}


