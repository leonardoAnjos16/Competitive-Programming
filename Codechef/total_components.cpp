#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e7 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<MAX> prime;
    prime.set();

    for (long i = 3; i * i < MAX; i += 2)
        if (prime[i])
            for (long j = i * i; j < MAX; j += i)
                prime[j] = false;

    vector<int> primes;
    primes.push_back(2);

    for (int i = 3; i < MAX; i += 2)
        if (prime[i]) primes.push_back(i);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        if (N < 4) {
            cout << (N - 1) << "\n";
            continue;
        }

        int last = upper_bound(primes.begin(), primes.end(), N) - primes.begin() - 1;

        int l = 0, r = last, idx;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (primes[mid] * 2 <= N) l = mid + 1;
            else r = mid - 1, idx = mid;
        }

        int ans = last - idx + 2;
        cout << ans << "\n";
    }
}