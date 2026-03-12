#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong MAX = 1e15 + 5;

map<llong, string> memo;

string solve(vector<pair<llong, int>> &divs, llong n) {
    if (n == 1) return "";

    if (memo.count(n))
        return memo[n];

    string ans = "IMPOSSIBLE";
    for (auto [fib, idx]: divs)
        if (!(n % fib)) {
            string suffix = solve(divs, n / fib);
            if (suffix == "IMPOSSIBLE") continue;

            string nans = string(idx - 1, 'A') + "B" + suffix;
            if (ans == "IMPOSSIBLE" || nans < ans) ans = nans;
        }

    return memo[n] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<llong> fibs;
    llong a = 1LL, b = 1LL;

    while (a + b < MAX) {
        fibs.push_back(a + b);
        llong aux = b;
        b = a + b;
        a = aux;
    }

    llong N; cin >> N;

    vector<pair<llong, int>> divs;
    for (int i = 0; i < (int) fibs.size(); i++)
        if (!(N % fibs[i]))
            divs.emplace_back(fibs[i], i + 2);

    string ans = solve(divs, N);
    cout << ans << "\n";
}