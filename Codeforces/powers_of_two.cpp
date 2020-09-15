#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int n, k; scanf("%d %d", &n, &k);

    priority_queue<int> powers;
    int idx = 0;

    while (n) {
        if (n & 1) powers.push(1 << idx);
        n = n >> 1; idx++;
    }

    int num_powers = powers.size();
    while (num_powers < k && powers.top() > 1) {
        int power = powers.top() / 2; powers.pop();
        powers.push(power); powers.push(power);
        num_powers++;
    }

    if (num_powers != k) printf("NO\n");
    else {
        printf("YES\n");
        while (!powers.empty())
            printf("%d ", powers.top()), powers.pop();

        printf("\n");
    }
}