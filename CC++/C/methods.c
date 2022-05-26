#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



int main() {

    /*
    RANDOM
    */
    // generate 10 random numbers 0 =< < 50 | rand() srand()
    srand(time(NULL));
    int n;
    for (n = 10; n < 20; n++) {
        int a = rand();
        printf("%i \n", a % 50);
    }
    

    /*
    INPUT
    */
    // string | gets() fgets() puts()
    char s1[20];
    fgets(s1,20,stdin);
    puts(s1);
    printf("Your String: %s", s1);

    // character | getchar() putchar()
    char c1 = getchar();
    putchar(c1);
    printf("Your Character: %c", c1);

    

    return 0;
}