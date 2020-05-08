#include <bits/stdc++.h>

using namespace std;

bool prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;

    return true;
}

int main() {
    vector<int> primes;
    for (int i = 2; i < 100; i++)
        if (prime(i)) primes.push_back(i);

    int n, m; scanf("%d %d", &n, &m);

    int next = *upper_bound(primes.begin(), primes.end(), n);
    printf("%s\n", m == next ? "YES" : "NO");
}