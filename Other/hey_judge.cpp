#include <bits/stdc++.h>

using namespace std;

const int MAX = 8;

int memo[MAX][MAX][MAX][MAX][MAX][5];

bool possible(vector<int> &cnt, int i = 0) {
    for (int i = 0; i < 5; i++)
        if (cnt[i] < 0)
            return false;

    if (i >= 5) return true;

    int &ans = memo[cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]][i];
    if (~ans) return ans;

    cnt[i]--;
    ans = possible(cnt, i + 1);
    cnt[i]++;

    for (int j = 0, k = i - 1; j <= k && !ans; j++, k--) {
        cnt[j]--;
        cnt[k]--;

        ans |= possible(cnt, i + 1);

        cnt[j]++;
        cnt[k]++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof memo);

    int T; cin >> T;
    while (T--) {
        string S; cin >> S;

        vector<int> cnt(5, 0);
        for (char c: S)
            cnt[c - 'A']++;

        bool ans = possible(cnt);
        cout << (ans ? "YES" : "NO") << "\n";
    }
}