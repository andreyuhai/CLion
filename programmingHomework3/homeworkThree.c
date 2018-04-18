#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "homeworkThree.h"

char* sifrele(char* input){
    char* cyphered = strdup(input);
    int i=0;
    int counter = 1;
    while(cyphered[i] != '\0'){
        if(counter < 5)
            cyphered[i] += counter;
        else{
            counter = 1;
            cyphered[i] += counter;
        }
        i++;
        counter++;
    }
    return cyphered;
}

char* sifreCoz(char* input){
    char* deciphered = strdup(input);
    int i=0;
    int counter = 1;
    while(deciphered[i] != '\0'){
        if(counter < 5)
            deciphered[i] -= counter;
        else{
            counter = 1;
            deciphered[i] -= counter;
        }
        i++;
        counter++;
    }
    return deciphered;
}

char* getUserInput(){
    int size = 200;
    char* input = NULL;
    char tempbuf[size]; //Buffer for fgets.
    size_t inputlen = 0, templen = 0;
    do {
        fgets(tempbuf, size, stdin);
        templen = strlen(tempbuf);
        inputlen += templen;
        input = realloc(input, inputlen+1);
        strcat(input, tempbuf);
    } while (templen==size-1 && tempbuf[size-2]!='\n');
    input[inputlen-1] = '\0';
    return input;
}

int isPalindrome ( char* str )
{
    char* str2 = str + strlen ( str) - 1;

    while ( str < str2 )
    {
        if ( *str++ != *str2-- )
        {
            return 0;
        }
    }
    return 1;
}
FILE* fileOpen(char* name){
    FILE* test;
    if(test = fopen(name,"r")){
        return test;
    }
    return NULL;
}

int palindrome(char* name){
    FILE* file = fileOpen(name);
    int palCounter = 0;
    if(file) {
        char buffer[1024];
        char* palindromes[20];
        FILE* hedef = fopen("hedef.txt","a+");
        while(fscanf(file,"%1023s",buffer) == 1){
            if(isPalindrome(buffer)){
                palindromes[palCounter++] = buffer;
                fprintf(hedef,"\"%s\" kelimesi palindromdur.\n",buffer);
            }
        }
        fprintf(hedef,"Toplam palindrom kelime sayısı = %d\n",palCounter);
        fclose(hedef);
        fclose(file);
    }else{
        printf("Yanlış ya da hatalı dosya ismi!");
    }
    return palCounter;
}

int anagram(char* name){
    FILE* file = fileOpen(name);
    int anaCounter = 0;
    int anaCounter2 = 0;
    if(file) {
        char buffer[1024];
        char* anagrams[50];
        int i = 0;
        while(fscanf(file,"%1023s",buffer) == 1){
            anagrams[anaCounter++] = strdup(buffer);
        }
        for(int i=0; i < anaCounter-1; i++){
            for(int j=i+1; j< anaCounter; j++){
                if(isAnagram(anagrams[i], anagrams[j])){
                    printf("%s ile %s anagramdır.\n",anagrams[i],anagrams[j]);
                    anaCounter2++;
                    if(i < anaCounter-2)
                        i++;
                    else
                        break;
                }
            }
        }
        fclose(file);
    }else{
        printf("Yanlış ya da hatalı dosya ismi!");
    }
    return anaCounter2;
}

int isAnagram(char *firstString, char *secondString){
    int firstCharCounter[256] = {0}, secondCharCounter[256] = {0};
    int counter;

    if(strlen(firstString) != strlen(secondString)){
        return 0;
    }

    for(counter = 0; firstString[counter] != '\0'; counter++){
        firstCharCounter[firstString[counter]]++;
    }

    for(counter = 0; secondString[counter] != '\0'; counter++){
        secondCharCounter[secondString[counter]]++;
    }

    for(counter = 0; counter < 256; counter++){
        if(firstCharCounter[counter] != secondCharCounter[counter])
            return 0;
    }
    return 1;
}
