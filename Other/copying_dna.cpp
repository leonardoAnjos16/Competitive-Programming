#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;

string T;
vector<bool> froms;
vector<string> strs;
vector<vector<int>> subs, revs;
vector<int> memo;

int index(string &s) {
    return lower_bound(strs.begin(), strs.end(), s) - strs.begin();
}

int copy(int mask = 0) {
    int n = T.size();
    if (mask + 1 == (1 << n)) return 0;

    int &ans = memo[mask];
    if (~ans) return ans;

    int l = 0;
    vector<bool> fromt(strs.size(), false);

    while (l < n) {
        while (l < n && !(mask & (1 << (n - l - 1)))) l++;
        if (l >= n) break;

        int r = l + 1;
        while (r < n && (mask & (1 << (n - r - 1)))) r++;

        for (int i = l; i < r; i++)
            for (int j = i; j < r; j++) {
                int idx = subs[i][j];
                fromt[idx] = true;

                idx = revs[i][j];
                fromt[idx] = true;
            }

        l = r;
    }

    l = 0;
    ans = INF;

    while (l < n) {
        while (l < n && (mask & (1 << (n - l - 1)))) l++;
        if (l >= n) break;

        int r = l + 1;
        while (r < n && !(mask & (1 << (n - r - 1)))) r++;

        for (int i = l; i < r; i++) {
            int j = i;
            bool found = true;

            while (j < r && found) {
                int idx = subs[i][j];
                found = froms[idx] || fromt[idx];
                if (found) j++;
            }

            if (j == i) continue;

            j--;
            int sz = j - i + 1, aux = ((1 << sz) - 1) << (n - j - 1);
            ans = min(ans, copy(mask | aux) + 1);
        }

        l = r;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string S;
        cin >> S >> T;

        strs.clear();

        int n = S.size();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                string s = S.substr(i, j - i + 1);
                strs.push_back(s);

                reverse(s.begin(), s.end());
                strs.push_back(s);
            }

        n = T.size();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                string s = T.substr(i, j - i + 1);
                strs.push_back(s);

                reverse(s.begin(), s.end());
                strs.push_back(s);
            }

        sort(strs.begin(), strs.end());
        strs.erase(unique(strs.begin(), strs.end()), strs.end());

        froms.assign(strs.size(), false);
        subs.assign(n, vector<int>(n));
        revs.assign(n, vector<int>(n));

        n = S.size();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                string s = S.substr(i, j - i + 1);
                froms[index(s)] = true;

                reverse(s.begin(), s.end());
                froms[index(s)] = true;
            }

        n = T.size();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                string s = T.substr(i, j - i + 1);
                subs[i][j] = index(s);

                reverse(s.begin(), s.end());
                revs[i][j] = index(s);
            }

        memo.assign((1 << n) + 5, -1);

        int ans = copy();
        if (ans >= INF) cout << "impossible\n";
        else cout << ans << "\n";
    }
}