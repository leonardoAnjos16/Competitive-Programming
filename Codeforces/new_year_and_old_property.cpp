#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    long a, b;
    scanf("%lld %lld", &a, &b);

    vector<long> years;

    int k = 1;
    while (++k < 64) {
        long curr = (1LL << k) - 1;
        for (int i = k - 2; i >= 0; i--)
            years.push_back(curr ^ (1LL << i));
    }

    int cnt = upper_bound(years.begin(), years.end(), b) - lower_bound(years.begin(), years.end(), a);
    printf("%d\n", cnt);
}