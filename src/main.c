#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_DEPTH = 0;

int proper_round(const int n, const int d)
{
  return ((n < 0) ^ (d < 0)) ? ((n - d/2)/d) : ((n + d/2)/d);
}

int main() {
    printf("max depth:");
    scanf("%d", &MAX_DEPTH);
    printf("max depth is %d\n", MAX_DEPTH);

    long long** depths;
    depths = (long long**)malloc(sizeof(long long*) * MAX_DEPTH);
    for(int i = 0; i < MAX_DEPTH; i++) {
        depths[i] = (long long*)malloc(sizeof(long long) * MAX_DEPTH);
        memset(depths[i], 0, sizeof(long long) * MAX_DEPTH);
    }

    depths[0][0] = 1;
    depths[1][0] = 1;
    depths[1][1] = 1;

    int c = 2;
    while (c < MAX_DEPTH) {
        int d = 0;
        int z = 0;
        depths[c][d++] = 1;
        while (d < MAX_DEPTH) {
            depths[c][d++] = depths[c - 1][z] + depths[c - 1][(z + 1) % MAX_DEPTH];
            z++;
        }
        c++;
    }

    for (int i = 0; i < MAX_DEPTH; i++) {
        int off = proper_round(MAX_DEPTH * 2, 2) - i;
        for (int j = 0; j < off; j++) {
            printf(" ");
        }
        for (int j = 0; j < MAX_DEPTH; j++) {
            if (depths[i][j] != 0) {
                printf(" %d", depths[i][j]);
            }
        }
        printf("\n");
    }


    return 0;
}
