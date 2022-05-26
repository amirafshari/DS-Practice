#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



int random(int n, int m) {
    srand(time(NULL));
    int a = m-n;
    int r = rand() % a;
    r += n;
    return r;
}




int main() {
    printf("%i\n",random(10,27));
    return 0;
}