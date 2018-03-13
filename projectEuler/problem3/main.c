#include <stdio.h>
#include <math.h>
#include <time.h>


int isPrime(long int number){
    long int squareRoot = (long int) sqrt(number/1.0);
    if(number == 1 || number <= 0){
        return 0;
    }
    for(long int i=2; i<=squareRoot; i++){
        if(number%i == 0)
            return 0;
    }
    return 1;
}

int main() {
    clock_t tic = clock();
    long int number = 600851475143;
    for(int i=0;i<=number;i++){
        if(isPrime(i)){
            while(number%i == 0){
                printf("Prime Factor = %u\n",i);
                number /= i;
            }
        }
    }

    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}