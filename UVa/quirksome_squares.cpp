#include <bits/stdc++.h>

using namespace std;

int pow(int base, int exp) {
    if (exp == 0) return 1;
    else return base * pow(base, exp - 1);
}

int main() {
    vector<int> outputs[4];
    int num_digits;

    while (scanf("%d", &num_digits) != EOF) {
        int half = num_digits / 2;
        if (outputs[half - 1].empty()) {
            int max = (int) sqrt(pow(10, num_digits) - 1);
            int max_half = pow(10, half);

            for (int i = 0; i <= max; i++) {
                for (int j = 0; j <= max - i; j++) {
                    int sum = i + j, number = (i * max_half) + j;
                    if (sum * sum == number) {
                        printf("%0*d\n", num_digits, number);
                        outputs[half - 1].push_back(number);
                    }
                }
            }
        } else {
            for (int i = 0; i < (int) outputs[half - 1].size(); i++)
                printf("%0*d\n", num_digits, outputs[half - 1][i]);
        }
    }
}