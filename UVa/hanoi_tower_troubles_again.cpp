#include <bits/stdc++.h>

using namespace std;

#define MAX 55

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_pegs;
        scanf("%d", &num_pegs);

        int top[MAX], num_used = 0, number = 1;
        while (true) {
            bool done = false;
            for (int i = 0; i < num_used && !done; i++) {
                int sum = top[i] + number;
                int root = sqrt(sum);

                if (root * root == sum) {
                    top[i] = number++;
                    done = true;
                }
            }

            if (!done && num_used < num_pegs) top[num_used++] = number++;
            else if (!done) break;
        }

        printf("%d\n", number - 1);
    }
}