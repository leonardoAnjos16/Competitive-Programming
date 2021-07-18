#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e6 + 5;

int m;
vector<pair<string, int>> items;
vector<vector<int>> memo;

bool done;
vector<vector<int>> vis;
vector<vector<vector<int>>> wti;

int mn_weight(int sum, int i = 0) {
    if (sum <= 0) return 0;
    if (i >= m) return INF;

    int &ans = memo[sum][i];
    if (~ans) return ans;

    return ans = min(mn_weight(sum, i + 1), items[i].second + mn_weight(sum - items[i].second, i + 1));
}

vector<int> get_items(int sum, int i = 0) {
    if (!sum) done = true;
    if (sum <= 0 || (sum > 0 && i >= m)) return vector<int>();

    if (vis[sum][i]) {
        if (vis[sum][i] > 0)
            done = true;

        return wti[sum][i];
    }

    vector<int> ans = get_items(sum, i + 1);
    if (!done) {
        ans = get_items(sum - items[i].second, i + 1);
        ans.push_back(i);
    }

    vis[sum][i] = done ? 1 : -1;
    if (!done) return vector<int>();
    return wti[sum][i] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int wkit;
    cin >> wkit >> m;

    int sum = 0;
    items.resize(m);

    for (int i = 0; i < m; i++) {
        string s; int w;
        cin >> s >> w;

        sum += w;
        items[i] = make_pair(s, w);
    }

    memo.assign(2e3 + 5, vector<int>(m + 5, -1));
    vis.assign(2e3 + 5, vector<int>(m + 5, 0));
    wti.assign(2e3 + 5, vector<vector<int>>(m + 5, vector<int>()));

    int n; cin >> n;
    while (n--) {
        int wsi; cin >> wsi;
        wsi = (wsi + 1) / 2;
        wsi -= wkit;

        if (wsi > sum) cout << "-1\n";
        else {
            int sum = mn_weight(wsi);
            done = false;

            vector<int> ans = get_items(sum);
            cout << ((int) ans.size());

            for (int i: ans) cout << " " << items[i].first;
            cout << "\n";
        }
    }
}