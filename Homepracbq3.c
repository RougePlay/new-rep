#include <stdio.h>

void print_cols(int n, int r, int c) {
    if (c > 2 * n) {
        return;
    }
    
    if (r == n || c == n || r == c || r + c == 2 * n) {
        printf("$");
    } else {
        printf("#");
    }
    
    print_cols(n, r, c + 1);
}

void print_rows(int n, int r) {
    if (r > 2 * n) {
        return;
    }
    
    print_cols(n, r, 0);
    printf("\n");
    
    print_rows(n, r + 1);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        print_rows(n, 0);
    }
    return 0;
}