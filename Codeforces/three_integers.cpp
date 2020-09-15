#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e4;


int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int triple[3];
        for (int i = 0; i < 3; i++)
            scanf("%d", &triple[i]);

        int min_moves = INT_MAX, sol[3] = {0};
        for (int a = 1; a <= MAX; a++) {
            for (int b = a; b <= MAX; b += a) {
                int quot = triple[2] / b;

                int first = quot * b;
                int second = (quot + 1) * b;

                int c = triple[2] - first < second - triple[2] ? first : second;
                c = max(b, c);

                int num_moves = abs(a - triple[0]) + abs(b - triple[1]) + abs(c - triple[2]);
                if (num_moves < min_moves) {
                    min_moves = num_moves;
                    sol[0] = a; sol[1] = b; sol[2] = c;
                }
            }
        }

        printf("%d\n", min_moves);
        printf("%d %d %d\n", sol[0], sol[1], sol[2]);
    }
}