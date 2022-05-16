#include <stdio.h>
// Amir Afshari
// Triangle

int main() {
    int n=10;
    for (int i=1; i<=n; i+=2) {
        for (int j=1; j<=n; j++) {
            printf(" ");
        }
        n--;
        for (int r=1; r<=i; r++) {
            printf("*");
        }
        printf("\n");
    }
    
}