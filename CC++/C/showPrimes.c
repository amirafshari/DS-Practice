#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



int isPrime(int n) {
    for (int i = 2; i < n-1; ++i)
    {
        if (n%i == 0)
        {
            return 0;
        }
    }
    return 1;    
}



int showPrimes(int n) {
    for (int i = 2; i < n; i++) {
        if (isPrime(i) == 1) {
            printf("%i\n", i);
        }
    }
}



int main() {
    printf("%i\n",showPrimes(17));
    return 0;
}