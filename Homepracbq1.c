#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int s;
    int i;
    int j;
} TestCase;
char get_spiral_char(int s, int i, int j) {
    if (i == s) {
        return '*';
    } 
    else if (i == s - 1) {
        if (j == 1 || j == s) {
            return '*';
        } else {
            return '+';
        }
    } 
    else {
        int max_col = 2 * ((i + 1) / 2);
        
        if (i == s - 3) {
            max_col = s - 1;
        }

        if (j <= max_col) {
            if (j % 2 == 1) {
                return '*';
            } else {
                return '+';
            }
        } else {
            return '*';
        }
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    TestCase *tests = (TestCase *)malloc(t * sizeof(TestCase));
    char *results = (char *)malloc(t * sizeof(char));
    for (int k = 0; k < t; k++) {
        scanf("%d %d %d", &tests[k].s, &tests[k].i, &tests[k].j);
    }
    for (int k = 0; k < t; k++) {
        results[k] = get_spiral_char(tests[k].s, tests[k].i, tests[k].j);
    }
    for (int k = 0; k < t; k++) {
        printf("%c\n", results[k]);
    }

    free(tests);
    free(results);
    return 0;
}