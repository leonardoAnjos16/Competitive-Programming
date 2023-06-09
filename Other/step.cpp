#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e7 + 5;

int last_prime[MAX] = {0};

llong modinverse(llong a, llong b, llong s0 = 1, llong s1 = 0) {
    return b == 0 ? s0 : modinverse(b, a % b, s1, s0 - s1 * (a / b));
}

llong mul(llong a, llong b, llong m) {
    llong q = (long double) a * (long double) b / (long double) m;
    llong r = a * b - q * m;
    return (r + m) % m;
}

struct Equation {
    llong mod, ans;
    bool valid;

    Equation(llong a, llong m) {
        mod = m;
        ans = a;
        valid = true;
    }

    Equation() {
        valid = false;
    }

    Equation(Equation a, Equation b) {
        if (!a.valid || !b.valid) {
            valid = false;
            return;
        }

        llong g = gcd(a.mod, b.mod);
        if ((a.ans - b.ans) % g != 0) {
            valid = false;
            return;
        }

        valid = true;
        mod = a.mod * (b.mod / g);
        ans = a.ans + mul(mul(a.mod, modinverse(a.mod, b.mod), mod), (b.ans - a.ans) / g, mod);
        ans = (ans % mod + mod) % mod;
    }
};

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans *= ans;

    if (!(n & 1)) return ans;
    return ans * a;
}

llong solve(vector<pair<int, int>> &lcm) {
    int sz = lcm.size();
    llong ans = LLONG_MAX;

    for (int i = 0; i < (1 << sz); i++) {
        Equation eq;
        if (lcm[0].first == 2) {
            int m = exp(2, lcm[0].second + 1);
            eq = Equation((i & 1) ? 0 : m - 1, m);
        } else {
            int m = exp(lcm[0].first, lcm[0].second);
            eq = Equation((i & 1) ? 0 : m - 1, m);
        }

        for (int j = 1; j < sz; j++) {
            int m = exp(lcm[j].first, lcm[j].second);
            eq = Equation(eq, Equation((i & (1 << j)) ? 0 : m - 1, m));
        }

        assert(eq.valid);
        ans = min(ans, eq.ans ? eq.ans : eq.mod);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for (int i = 2; i < MAX; i++)
        if (!last_prime[i])
            for (int j = i; j < MAX; j += i)
                last_prime[j] = i;

    vector<pair<int, int>> primes;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;

        int last = -1, cnt = 0;
        while (p > 1) {
            if (last == -1 || last_prime[p] == last) last = last_prime[p], cnt++;
            else {
                primes.emplace_back(last, cnt);
                last = last_prime[p];
                cnt = 1;
            }

            p /= last_prime[p];
        }

        if (last != -1)
            primes.emplace_back(last, cnt);
    }

    sort(primes.begin(), primes.end());

    int idx = 0;
    vector<pair<int, int>> lcm;

    while (idx < (int) primes.size()) {
        while (idx + 1 < (int) primes.size() && primes[idx + 1].first == primes[idx].first) idx++;
        lcm.push_back(primes[idx++]);
    }

    if (lcm.empty()) {
        cout << "1\n";
        return 0;
    }

    llong ans = solve(lcm);
    cout << ans << "\n";
}