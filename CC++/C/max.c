#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 10

int main() {
    int array[] = {1,3,2,6,9,3,5,7,10,100};
    int size = sizeof(array)/sizeof(int);

    int max = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    printf("%i", max);

}