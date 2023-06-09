#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string s[2];
        cin >> s[0] >> s[1];

        int t, q;
        cin >> t >> q;

        set<int> diff;
        int n = s[0].size();

        for (int i = 0; i < n; i++)
            if (s[0][i] != s[1][i])
                diff.insert(i);

        vector<vector<int>> unblock(q, vector<int>());
        for (int i = 0; i < q; i++) {
            for (int pos: unblock[i])
                if (s[0][pos] != s[1][pos])
                    diff.insert(pos);

            int op; cin >> op;
            if (op == 1) {
                int pos; cin >> pos;
                if (diff.count(pos - 1)) diff.erase(pos - 1);
                if (i + t < q) unblock[i + t].push_back(pos - 1);
            } else if (op == 2) {
                int i1, pos1, i2, pos2;
                cin >> i1 >> pos1 >> i2 >> pos2;

                if (diff.count(pos1 - 1)) diff.erase(pos1 - 1);
                if (diff.count(pos2 - 1)) diff.erase(pos2 - 1);

                swap(s[i1 - 1][pos1 - 1], s[i2 - 1][pos2 - 1]);
                if (s[0][pos1 - 1] != s[1][pos1 - 1]) diff.insert(pos1 - 1);
                if (s[0][pos2 - 1] != s[1][pos2 - 1]) diff.insert(pos2 - 1);
            } else {
                bool equal = diff.empty();
                cout << (equal ? "YES" : "NO") << "\n";
            }
        }
    }
}