#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 10

int main() {
    int array[N];

    for (int i = 0; i < N; i++) {
        scanf("%i", &array[i]);
    }

    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += array[i];
    }
    float average = sum/N;
    printf("The average is: %f\n", average);
    return 0;
}