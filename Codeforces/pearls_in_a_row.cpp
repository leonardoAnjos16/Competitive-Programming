#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> aux;
    vector<pair<int, int>> ans;

    int last = 1;
    for (int i = 0; i < n; i++) {
        if (!aux.count(a[i])) aux.insert(a[i]);
        else {
            aux.clear();
            ans.push_back(make_pair(last, i + 1));
            last = i + 2;
        }
    }

    bool possible = true;
    if (last <= n) {
        if (ans.empty()) possible = false;
        else {
            pair<int, int> p = ans.back();
            ans.pop_back();
            ans.emplace_back(p.first, n);
        }
    }

    if (!possible) cout << "-1\n";
    else {
        int cnt = ans.size();
        cout << cnt << "\n";

        for (auto p: ans)
            cout << p.first << " " << p.second << "\n";
    }
}