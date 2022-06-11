#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;

    vector<int> primes;
    for (int i = 2; i * i <= q; i++) {
        if (q % i == 0) primes.push_back(i);
        while (q % i == 0) q /= i;
    }

    if (q > 1) primes.push_back(q);

    bool field = primes.size() == 1;
    cout << (field ? "yes" : "no") << "\n";
}