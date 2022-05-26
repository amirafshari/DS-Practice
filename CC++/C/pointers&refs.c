#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 10

int main() {
    int n = 20;
    int *a = &n;
    printf("Value: %i\nMemory Address: %p\nDerefrencing: %i\n", n, a, *a);
}