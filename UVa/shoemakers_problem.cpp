#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<1>(a) * get<0>(b) > get<1>(b) * get<0>(a);
}

int main() {
    int T; scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        if (i) printf("\n");
        int N; scanf("%d", &N);

        tuple<int, int, int> A[MAX];
        for (int j = 0; j < N; j++) {
            int Ti, Si; scanf("%d %d", &Ti, &Si);
            A[j] = {Ti, Si, j + 1};
        }

        stable_sort(A, A + N, cmp);
        for (int j = 0; j < N; j++) {
            if (j) printf(" ");
            printf("%d", get<2>(A[j]));
        }

        printf("\n");
    }
}