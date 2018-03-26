#include <stdio.h>
#include "odev.h"
#include <math.h>

int main() {

    double triangle[][2] = {
            {5.09,5.80},
            {1.03,2.54},
            {5.88,0.66},
            {5.09,5.80}

    }; // Alanı 11.721 olmalı

    double pentagon[][2] = {
            {5.09,5.80},
            {1.68,4.90},
            {1.48,1.38},
            {4.76,0.10},
            {7,2.83},
            {5.09,5.80}

    }; //Alanı 21.40435 olmalı

    printf("The area = %f\n",alan(triangle, 4)); //Alan hesabında ilk ve son koordinatlar aynı olmalı

    //int* arr = getArr(7);
    /* Örnek ;
     *
     * 35, 22, 43, 36, 72, 68, 29
     * Mean = 43.571429
     * Standard deviation = 19.208133
     */
    //printf("standard deviation = %f\n",standartSapma(arr,7));


    int m1[3][3] = {0};
    matrisCarpim(m1);
    for(int i = 0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ",m1[i][j]);
        }
        printf("\n");
    }
    return 0;
}