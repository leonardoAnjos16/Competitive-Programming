#include <bits/stdc++.h>

using namespace std;

#define long long long int

int x;
vector<int> primes;
vector<long> ans;

bool is_prime(int n) {
    if (n == 1) return false;

    for (int i = 2; (long) i * i <= n; i++)
        if (!(n % i)) return false;

    return true;
}

void solve(int i = 0, long phi = 1LL, long num = 1LL) {
    if (phi == x) ans.push_back(num);
    else if (i >= (int) primes.size() || phi * (primes[i] - 1) > x) return;
    else {
        solve(i + 1, phi, num);

        long new_phi = phi * (primes[i] - 1);
        long new_num = num * primes[i];

        while (new_phi <= x) {
            solve(i + 1, new_phi, new_num);
            new_phi *= primes[i];
            new_num *= primes[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> x) {
        if (x == 1) {
            cout << "1 2\n";
            continue;
        }

        set<int> divs;
        for (int i = 1; (long) i * i <= x; i++)
            if (!(x % i)) {
                divs.insert(i);
                divs.insert(x / i);
            }

        primes.clear();
        for (auto d: divs)
            if (is_prime(d + 1))
                primes.push_back(d + 1);

        ans.clear();
        solve();

        if (ans.empty()) cout << "No solution.\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < (int) ans.size(); i++) {
                if (i) cout << " ";
                cout << ans[i];
            }

            cout << "\n";
        }
    }
}