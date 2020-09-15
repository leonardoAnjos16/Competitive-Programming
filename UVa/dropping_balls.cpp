#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int D, I; scanf("%d %d", &D, &I);

        int node = 1;
        for (int i = 1; i < D; i++) {
            if (I % 2) node *= 2, I = (I / 2) + 1;
            else node = (node * 2) + 1, I /= 2;
        }

        printf("%d\n", node);
    }
}