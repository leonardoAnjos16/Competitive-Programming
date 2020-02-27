#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int a, b; scanf("%d %d", &a, &b);

        int num_moves = 0;
        bool odd_a = a % 2;
        bool odd_b = b % 2;

        if (a < b) {
            if (!odd_a && !odd_b) num_moves = 2;
            else if (!odd_a && odd_b) num_moves = 1;
            else if (!odd_b) num_moves = 1;
            else num_moves = 2;
        } else if (a > b) {
            if (!odd_a && !odd_b) num_moves = 1;
            else if (!odd_a && odd_b) num_moves = 2;
            else if (!odd_b) num_moves = 2;
            else num_moves = 1;
        }

        printf("%d\n", num_moves);
    }
}