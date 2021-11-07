#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long MAX = 1e15 + 5;

map<long, string> res;
vector<string> ans;

bool solve(map<long, string>::reverse_iterator it, long N) {
    if (it == res.rend()) return N == 1LL;

    if (!(N % it->first)) {
        ans.push_back(it->second);
        if (solve(it, N / it->first))
            return true;

        ans.pop_back();
    }

    if (solve(next(it), N))
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string last = "B";
    long a = 1LL, b = 1LL;

    while (a + b <= MAX) {
        long c = a + b;
        res[c] = "A" + last;
        last = res[c];

        b = a;
        a = c;
    }

    long N; cin >> N;

    /* string ans = "";
    for (auto it = res.rbegin(); it != res.rend(); it++)
        while (!(N % it->first)) {
            ans += it->second;
            N /= it->first;
        }

    if (N > 1LL) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n"; */

    if (!solve(res.rbegin(), N)) cout << "IMPOSSIBLE\n";
    else {
        // reverse(ans.begin(), ans.end());
        for (auto s: ans) cout << s;
        cout << "\n";
    }
}