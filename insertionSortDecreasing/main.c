#include <stdio.h>

int main() {
    int a = 5;

    int arr[14] = {10,9,3,8,7,23,24,30,21,20,20,25,37,1};
    for(int i = 1; i<14; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j]<key){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }
    for(int i = 0;i<14;i++){
        printf("Eleman %d  = %d\n",i,arr[i]);
    }
    return 0;
}