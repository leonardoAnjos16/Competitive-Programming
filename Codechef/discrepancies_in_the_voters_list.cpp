#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N1, N2, N3;
    cin >> N1 >> N2 >> N3;

    map<int, int> cnt;
    for (int i = 0; i < N1 + N2 + N3; i++) {
        int id;
        cin >> id;
        cnt[id]++;
    }

    vector<int> ans;
    for (auto p: cnt)
        if (p.second >= 2)
            ans.push_back(p.first);

    cout << ((int) ans.size()) << "\n";
    for (auto id: ans) cout << id << "\n";
}