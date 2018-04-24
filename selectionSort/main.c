/*
 * Burak KAYMAKCI
 * 17060605
 *
 */
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
    if(PLATFORM_NAME == "windows"){ // IF using Windows!
        printf("************************** W A R N I N G **************************\n");
        printf("You are using Windows!\n");
        printf("We recommend you to run this program on Unix-like systems to be able to view the output properly.\n");
        printf("The algorithms work properly anyway!\n");
        printf("Changing code page to \'650001\'\n");
        system("chcp 65001");
        printf("*******************************************************************\n");
    }

    start();

    return 0;
}
