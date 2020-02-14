#include <bits/stdc++.h>

using namespace std;

#define MAX 15

int main() {
    int size, case_num = 0;
    while (scanf("%d", &size), size) {
        if (case_num++) printf("\n");

        int S[MAX];
        for (int i = 0; i < size; i++)
            scanf("%d", &S[i]);

        sort(S, S + size);

        for (int a = 0; a < size - 5; a++)
            for (int b = a + 1; b < size - 4; b++)
                for (int c = b + 1; c < size - 3; c++)
                    for (int d = c + 1; d < size - 2; d++)
                        for (int e = d + 1; e < size - 1; e++)
                            for (int f = e + 1; f < size; f++)
                                printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
    }
}