#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    string s = a.first;
    string t = b.first;

    int cnt[2] = {0};
    for (int i = 0; i < (int) s.size(); i++)
        for (int j = i + 1; j < (int) s.size(); j++)
            cnt[0] += s[j] < s[i], cnt[1] += t[j] < t[i];

    if (cnt[0] == cnt[1]) return a.second < b.second;
    else return cnt[0] < cnt[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M; cin >> M;
    while (M--) {
        int n, m; cin >> n >> m;

        pair<string, int> s[MAX];
        for (int i = 0; i < m; i++)
            cin >> s[i].first, s[i].second = i;

        sort(s, s + m, cmp);
        for (int i = 0; i < m; i++)
            cout << s[i].first << "\n";

        if (M) cout << "\n";
    }
}