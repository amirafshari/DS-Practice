#include <stdio.h>

// iterative
int fact(int n) {
    int m = n;
    while (m != 1) {
        n = n*(m-1);
        m--;
    }
    return n;
}

// recursive
int rFact(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n*rFact(n-1);
    }
}


// MAIN
int main() {
    printf("%i\n", fact(5));
    printf("%i\n", rFact(5));
    return 0;
}