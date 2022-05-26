#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int fibonacci(int n) {
    if (n==1 || n==2) {
        return 1;
    } else {
        return fibonacci(n-1)+n;
    }
}



int main() {
    printf("%i\n", fibonacci(5));

    return 0;
}