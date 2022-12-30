#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<MAX> composite;
    for (int i = 2; i < MAX; i++)
        if (!composite[i])
            for (int j = 2 * i; j < MAX; j += i)
                composite[j] = true;

    vector<int> primes;
    for (int i = 2; i < MAX; i++)
        if (!composite[i])
            primes.push_back(i);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<llong> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool possible = true;
        set<int> restrictions[MAX];

        for (int i = 0; i < n && possible; i++)
            for (int j = i + 1; j < n && possible; j++) {
                if (a[i] == a[j]) possible = false;
                for (int k = 0; k < (int) primes.size() && primes[k] <= n && possible; k++)
                    if (!(abs(a[i] - a[j]) % primes[k]))
                        restrictions[primes[k]].insert((primes[k] - (min(a[i], a[j]) % primes[k])) % primes[k]);
            }

        for (int i = 2; i <= n && possible; i++)
            if ((int) restrictions[i].size() >= i)
                possible = false;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}