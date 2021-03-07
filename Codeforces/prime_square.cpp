#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 105;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> primes;
    for (int i = 2; i <= 100; i++)
        if (is_prime(i)) primes.insert(i);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        auto it = primes.upper_bound(n); it--;

        int ans[MAX] = {0};
        for (int i = 0; i < *it; i++)
            ans[i] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << ans[(i + j) % n] << " ";

            cout << "\n";
        }
    }
}