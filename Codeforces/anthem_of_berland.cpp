#include <bits/stdc++.h>

using namespace std;

#define llong long long int

string s, t;
vector<int> border;
vector<vector<int>> memo;

void get_border() {
    int n = t.size();
    border.assign(n, 0);

    for (int i = 1; i < n; i++) {
        int j = border[i - 1];
        while (j > 0 && t[j] != t[i])
            j = border[j - 1];

        if (t[j] == t[i])
            border[i] = j + 1;
    }
}

int occurrences(int i = 0, int j = 0) {
    if (j >= (int) t.size()) return occurrences(i, border[j - 1]) + 1;
    if (i >= (int) s.size()) return 0;

    int &ans = memo[i][j];
    if (~ans) return ans;

    ans = 0;
    if (j) ans = occurrences(i, border[j - 1]);
    if (s[i] == t[j]) ans = max(ans, occurrences(i + 1, j + 1));

    if (s[i] != '?') ans = max(ans, occurrences(i + 1));
    else ans = max(ans, occurrences(i + 1, j + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    get_border();
    memo.assign((int) s.size() + 5, vector<int>((int) t.size() + 5, -1));

    int ans = occurrences();
    cout << ans << "\n";
}