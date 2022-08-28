#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> problems(n);
    for (int i = 0; i < n; i++)
        cin >> problems[i].second;

    for (int i = 0; i < n; i++)
        cin >> problems[i].first;

    sort(problems.begin(), problems.end());

    int idx = 0;
    while (idx < n && problems[idx].first == -1) idx++;

    int need = 0, ans = 1;
    for (int i = idx; i < n; i++) {
        need += problems[i].second;
        ans = max(ans, (need + problems[i].first  - 1) / problems[i].first);
    }

    cout << ans << "\n";
}