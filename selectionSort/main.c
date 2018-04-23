#include <stdio.h>
#include <memory.h>
#include "sort.h"
#include <stdlib.h>

#if defined(_WIN32)
#define PLATFORM_NAME "windows"
#else
#define PLATFORM_NAME NULL
#endif


int main() {
    if(PLATFORM_NAME == "windows"){
        printf("****************************************\n");
        printf("You are using Windows!\n"
               "We recommend you to run this program on Unix-like systems to be able to view the output properly.\n");
        printf("Changing code page to \'650001\'\n");
        system("chcp 65001");
        printf("****************************************\n");
    }

    start();

    return 0;
}
