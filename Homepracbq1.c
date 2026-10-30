#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;
    int q;
    int r;
} TestCase;
char get_spiral_char(int p, int q, int r) {
    if (q == p) {
        return '*';
    } 
    else if (q == p - 1) {
        if (r == 1 || r == p) {
            return '*';
        } else {
            return '+';
        }
    } 
    else {
        int max_col = 2 * ((q + 1) / 2);
        
        if (q == p - 3) {
            max_col = p - 1;
        }

        if (r <= max_col) {
            if (r % 2 == 1) {
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
    int w;
    if (scanf("%d", &w) != 1) return 0;
    TestCase *tests = (TestCase *)malloc(w * sizeof(TestCase));
    char *results = (char *)malloc(w * sizeof(char));
    for (int d = 0; d < w; d++) {
        scanf("%d %d %d", &tests[d].p, &tests[d].q, &tests[d].r);
    }
    for (int d = 0; d < w; d++) {
        results[d] = get_spiral_char(tests[d].p, tests[d].q, tests[d].r);
    }
    for (int d = 0; d < w; d++) {
        printf("%c\n", results[d]);
    }

    free(tests);
    free(results);
    return 0;
}