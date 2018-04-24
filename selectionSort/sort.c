/*
 * Burak KAYMAKCI
 * 17060605
 *
 */

#include <stdlib.h>
#include <memory.h>
#include "sort.h"
#include <stdio.h>

int* selectionSort(int size, int* to_beSorted){

    int* sortedArr = malloc(size*sizeof(int));
    memcpy(sortedArr,to_beSorted,size*(sizeof(int)));
    int smallest;
    int larger;

    for(int i = 0; i < size-1; i++){
        smallest = sortedArr[i]; // Temporary smallest element
        larger = i;
        for(int j = i+1; j < size; j++){
            if(smallest > sortedArr[j]) {
                smallest = sortedArr[j];
                larger = j;
            }
        }

        int temp = sortedArr[i];

        sortedArr[i] = smallest;
        sortedArr[larger] = temp;

        printf("%d. step = ",i+1);
        printArray(i+1,size,sortedArr,i,larger);
    }

    return sortedArr;
}

int printArray(int step, int size, int* array, int smallIndex, int largeIndex){ //Prints out the array in selection sort
    int gapCount = 0; // gap count between two arrows
    int startIndex = 0; // start index of the first arrow.
    int stepSize = digitCount(step) + 8; // number of digits of step count and plus 8 characters = " step = "


    for(int i = 0; i < size; i++){ // Printing out the array.
        if(i == size-1){
            printf("%d\n",array[i]);
        }else{
            if(smallIndex >= i && i <= largeIndex){
                startIndex += digitCount(array[i])+1;

            }
            if(smallIndex < i && i < largeIndex)
                gapCount += digitCount(array[i])+1;
            printf("%d ",array[i]);
        }
    }
    if(smallIndex == largeIndex){
        gapCount = -1;
    }
    startIndex += stepSize;
    insertArrows(startIndex,gapCount);
    return gapCount;
}

void insertArrows(int startIndex, int size){
    for(int i = 0; i < startIndex-1; i++){
        printf(" ");
    }
    if(size == -1){ // If no change has occurred.
        printf("⟳\n");
    }else{
        printf("⬑"); // Start
        for(int i = 0; i < size; i++){
            printf("-"); //―
        }
        printf("⬏\n"); // End
    }
}

int digitCount(int number){ // Counts the number of digits in a number
    int digits = 0;
    if(number == 0){
        return 1;
    }
    while(number != 0){
        number /= 10;
        digits++;
    }
    return digits;
}

int* heapSort(int size, int* to_beSorted){

    int* sortedArr = malloc(size*sizeof(int));
    memcpy(sortedArr,to_beSorted,size*(sizeof(int)));
    int sizeCp = size;
    int gapCount = 0;
    int temp;
    int numOf_Steps = 0;

    for(;size > 1; size--){
        maxHeapify((size/2)-1,size,sortedArr);

        temp = sortedArr[size-1];
        sortedArr[size-1] = sortedArr[0];
        sortedArr[0] = temp;
        numOf_Steps++;
        for(int i = 0; i < sizeCp; i++){
            if(i == 0) //To count gap size for dashes between arrows.
                gapCount += digitCount(sortedArr[i]);
            else if(i < size-1 && i != sizeCp-1)
                gapCount += digitCount(sortedArr[i])+1;

            if(i == sizeCp-1){
                printf("%d\n",sortedArr[i]);
                insertArrows(0,gapCount-1);
                gapCount = 0;
            }else
                printf("%d ",sortedArr[i]);
        }
    }
    printf("Done in %d steps.\n",numOf_Steps);
    return sortedArr;
}

int* maxHeapify(int parent, int size, int* to_beHeapified){
    int leftChild = parent*2+1;
    int rightChild;
    int largest;

    if(size % 2 != 0 || parent != size/2-1 )
        rightChild = parent*2+2;
    else
        rightChild = 0;


    if(parent == -1 || size <= leftChild || size <= rightChild)
        return to_beHeapified;

    if(rightChild && to_beHeapified[rightChild] > to_beHeapified[leftChild])
        largest = rightChild;
    else
        largest = leftChild;

    if(to_beHeapified[largest] > to_beHeapified[parent]){
        swap(&to_beHeapified[largest],&to_beHeapified[parent]);
        maxHeapify(largest,size,to_beHeapified);
    }

    return maxHeapify(parent-1,size,to_beHeapified);
}

void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void start(void){
    int arrSize;
    int* array;
    int* sorted;
    int input;
    while(1){
        printf("\n****************************************\n");
        printf("1 for Selection Sort\n");
        printf("2 for Heap Sort\n");
        printf("Any other number EXCEPT \"0\" to EXIT.\n");
        printf("****************************************\n\n");
        printf("Type in the number of a sorting algorithm you want to use (e.g. 2): ");


        input = getInt();

        if(input == 1 || input == 2){

            printf("Type in your array size: ");

            arrSize = getInt();
            array = getArray(arrSize);
            printf("\n");
            switch(input){
                case 1:
                    selectionSort(arrSize,array);
                    break;
                case 2:
                    heapSort(arrSize,array);
                    break;
            }
        }else{
            printf("Good Bye!\n");
            break;
        }
    }
}

int getInt(){
   int input;
   char buffer[100];
   char* endptr;
   while(fgets(buffer,200,stdin)) {
       if ((!(input = (int) strtol(buffer, &endptr, 10)) ) || endptr == buffer || *endptr != '\n' ) {
           printf("Please try again: ");
           continue;
       } else {
           break;
       }
   }
   return input;
}

int* getArray(int size){
    unsigned int bufferSize = size*10*sizeof(char);
    char* buffer = malloc(bufferSize);
    int* array = malloc(size*sizeof(int));
    char* endptr;
    int loopFlag = 0;
    printf("\n*********************************************************\n");
    printf("* Type in your array with only \'one\' space between numbers!\n");
    printf("* For example: 1 2 3 87 52 21(then hit enter)\n");
    printf("********************************************************\n");
    printf("Type in your array: ");

    while(fgets(buffer,bufferSize,stdin)){
        for(int i = 0; i < size; i++){
            array[i] = (int) strtol(buffer,&endptr,10);
            if((!array[i] && *endptr != ' ') && (!array[i] && *endptr != '\n') || endptr == buffer || *endptr != ' ' && *endptr != '\n'){
                loopFlag = 1;
                break;
            }else{
                buffer = endptr+1;
            }
        }
        if(loopFlag) {
            loopFlag = 0;
            printf("You've typed something wrong!\n");
            printf("Please try again: ");
            continue;
        }
        break;
    }
    return array;
}