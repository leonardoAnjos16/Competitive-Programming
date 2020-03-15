#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e2 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int r, c; scanf("%d %d", &r, &c);
        
        int targets[MAX] = {0};
        for (int i = 1; i < r; i++) {
            char row[MAX]; scanf("%s", row);
            for (int j = 0; j < c; j++) {
                if (row[j] == '#') targets[j] = 0;
                else if (row[j] == 'X') targets[j]++;
            }
        }

        int total = 0;
        for (int i = 0; i < c; i++)
            total += targets[i];

        printf("%d\n", total);
    }
}