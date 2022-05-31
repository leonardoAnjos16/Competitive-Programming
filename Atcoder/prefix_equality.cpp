#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> b(N);
    for (int i = 0; i < N; i++)
        cin >> b[i];

    int idx = 0;
    set<int> first, second;
    vector<pair<int, int>> range(N, make_pair(-1, -1));

    for (int i = 0; i < N; i++) {
        if (first.count(a[i])) range[i] = range[i - 1];
        else {
            first.insert(a[i]);
            while (idx < N && first.count(b[idx]) && first.size() > second.size())
                second.insert(b[idx++]);

            if (first.size() > second.size()) continue;

            range[i].first = idx - 1;
            while (idx < N && first.count(b[idx])) idx++;
            range[i].second = idx;
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;

        bool equal = y - 1 >= range[x - 1].first && y - 1 < range[x - 1].second;
        cout << (equal ? "Yes" : "No") << "\n";
    }
}