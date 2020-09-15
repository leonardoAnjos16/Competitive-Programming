#include <bits/stdc++.h>

using namespace std;

int get_best_divisor(int n) {
    set<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }

    int best_div = 1, max_sum = 1;
    for (set<int>::iterator it = divisors.begin(); it != divisors.end(); it++) {
        int div = *it, sum = 0;
        while (div) sum += div % 10, div /= 10;

        if (sum > max_sum) best_div = *it, max_sum = sum;
    }

    return best_div;
}

int main() {
    int n; scanf("%d", &n);
    printf("%d\n", get_best_divisor(n));
}