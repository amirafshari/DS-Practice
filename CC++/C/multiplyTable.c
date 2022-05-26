#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



int main() {
    
    for (int i=1; i < 10; i++) {
        for (int j =1; j < 10; j++) {
            printf("%5i", j*i);
        }
        printf("\n");
    }

    return 0;
}