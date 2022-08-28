#include <bits/stdc++.h>

using namespace std;

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    vector<int> occs[MAX];
    for (int i = 0; i < n; i++)
        occs[s[i] - 'a'].push_back(i);

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < MAX; j++)
            if (j != s[i] - 'a') {
                auto nxt = upper_bound(occs[s[i] - 'a'].begin(), occs[s[i] - 'a'].end(), i);
                auto fst = upper_bound(occs[j].begin(), occs[j].end(), i);
                if (fst != occs[j].end() && (nxt == occs[s[i] - 'a'].end() || *nxt > *fst)) ans++;
            }

    cout << ans << "\n";
}