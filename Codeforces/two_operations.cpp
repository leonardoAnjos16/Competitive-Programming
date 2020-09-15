#include <bits/stdc++.h>

using namespace std;

bool is_prime(int number) {
    int root = (int) sqrt(number);
    for (int i = 2; i <= root; i++)
        if (number % i == 0) return false;

    return true;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int n; scanf("%d", &n);

        int num_ops = 0;
        while (n > 1 && !is_prime(n)) {
            int divisor = 1;
            while (n % ++divisor);

            n /= divisor--;
            num_ops += divisor;
        }

        num_ops += n;
        printf("%d\n", num_ops);
    }
}