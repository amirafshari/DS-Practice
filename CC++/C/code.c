#include <stdio.h>


int summation(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + summation(n-1);
    }
}

int main()
{
    printf("%i\n",summation(10));
    return 0;
}