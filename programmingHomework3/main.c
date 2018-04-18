#include <stdio.h>
#include <string.h>
#include "homeworkThree.h"

int main() {

    char* foo = getUserInput();
    char* sifrelenmis = sifrele(foo);

    printf("Orijinal Kelime = %s\n",foo);
    printf("Şifrelenmiş Kelime = %s\n",sifrele(foo));
    printf("Çözülmüş Kelime = %s\n",sifreCoz(sifrelenmis));

    printf("Toplam anagram kelime sayısı= %d.\n",anagram("kaynak.txt"));

    return 0;
}