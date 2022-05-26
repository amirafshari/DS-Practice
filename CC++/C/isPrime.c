#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int isPrime(int n) {
    for (int i = 2; i < n/2; ++i)
    {
        if (n%i == 0)
        {
            return 0;
        }
    }
    return 1;    
}



int main() {
    printf("%i\n",isPrime(8));
    return 0;
}