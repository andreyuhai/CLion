#include <stdio.h>


void insertionSort(int array[]){
    int size=6;
    for(int j=0;j<size;j++){
        int key = array[j];
        int i = j-1;
        while(i>-1 && array[i]>key){
            array[i+1] = array[i];
            i-=1;
        }
        array[i+1]=key;
    }
    for(int i=0;i<6;i++){
        printf("Eleman %d = %d\n",i,array[i]);
    }

}

int main() {
    int a[6]={9,7,4,6,20,3};

    //assignment operator shall have a modifiable lvalue as its left operand.
    //A modifiable lvalue is an lvalue that does not have array type, [...]

    //insertionSort(a);

    return 0;
}