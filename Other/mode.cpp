#include <bits/stdc++.h>

using namespace std;

#define llong long long int

map<multiset<int>, llong> memo[20];

llong sum(int size, multiset<int> freqs) {
    if (size == 0) return *freqs.rbegin();

    if (memo[size].count(freqs))
        return memo[size][freqs];

    multiset<int> nfreqs = freqs;

    llong ans = 0LL;
    for (auto f: freqs) {
        nfreqs.erase(nfreqs.find(f));
        nfreqs.insert(f + 1);

        ans += sum(size - 1, nfreqs);

        nfreqs.erase(nfreqs.find(f + 1));
        nfreqs.insert(f);
    }

    return memo[size][freqs] = ans;
}

llong solve(llong x) {
    llong aux = x;

    vector<int> digits;
    while (x) {
        digits.push_back(x % 10LL);
        x /= 10LL;
    }

    reverse(digits.begin(), digits.end());

    llong ans = 0LL;
    vector<int> freqs(10, 0);

    for (int i = 0; i < (int) digits.size(); i++) {
        for (int j = 0; j < digits[i]; j++) {
            if (i > 0 || j > 0) {
                freqs[j]++;
                multiset<int> mfreqs;

                for (int k = 0; k < 10; k++)
                    mfreqs.insert(freqs[k]);

                ans += sum((int) digits.size() - i - 1, mfreqs);
                freqs[j]--;
            }
        }

        freqs[digits[i]]++;
    }

    multiset<int> mfreqs;
    for (int i = 1; i < 10; i++)
        mfreqs.insert(0);

    mfreqs.insert(1);
    for (int i = 1; i < (int) digits.size(); i++)
        ans += 9LL * sum(i - 1, mfreqs);

    if (aux > 0) ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        llong l, r;
        cin >> l >> r;

        llong ans = solve(r + 1);
        ans -= solve(l);

        cout << ans << "\n";
    }
}