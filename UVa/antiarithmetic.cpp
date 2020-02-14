#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

int main() {
    int size;
    while (scanf("%d", &size), size) {
        scanf(":");

        int positions[MAX];
        for (int i = 0; i < MAX; i++)
            positions[i] = -1;

        int numbers[MAX];
        for (int i = 0; i < size; i++) {
            scanf("%d", &numbers[i]);
            positions[numbers[i]] = i;
        }

        bool antiarithmetic = true;
        for (int i = 0; i < size && antiarithmetic; i++) {
            for (int j = i + 1; j < size && antiarithmetic; j++) {
                int next = numbers[j] + (numbers[j] - numbers[i]);
                if (next >= 0 && next < MAX && positions[next] > j)
                    antiarithmetic = false;
            }
        }

        printf("%s\n", antiarithmetic ? "yes" : "no");
    }
}