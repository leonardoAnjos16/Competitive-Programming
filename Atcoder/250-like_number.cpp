#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool composite[MAX] = {0};
    for (int i = 2; i * i < MAX; i++)
        if (!composite[i])
            for (int j = i * i; j < MAX; j += i)
                composite[j] = true;

    vector<int> primes;
    for (int i = 2; i < MAX; i++)
        if (!composite[i])
            primes.push_back(i);

    long N; cin >> N;

    int ans = 0;
    for (int i = 1; i < (int) primes.size(); i++) {
        long q3 = 1LL * primes[i] * primes[i] * primes[i];
        if (q3 >= N) break;

        long max_p = N / q3;
        ans += upper_bound(primes.begin(), primes.begin() + i, max_p) - primes.begin();
    }

    cout << ans << "\n";
}