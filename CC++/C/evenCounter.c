#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 3

int main() {
    int array[N];

    for (int i = 0; i < N; i++) {
        scanf("%i", &array[i]);
    }

    int n = 0;

    for (int i = 0; i < N; i++) {
        if (array[i]%2 == 0) {
            n++;
        }
    }
    printf("There are %i even numbers\n", n);
    return 0;
}