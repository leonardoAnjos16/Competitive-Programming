#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b, c, t = 1;
    while (cin >> b >> c, b || c) {
        vector<vector<int>> ballots(b, vector<int>(c));
        for (int i = 0; i < b; i++)
            for (int j = 0; j < c; j++)
                cin >> ballots[i][j];

        vector<vector<int>> rank(c, vector<int>(b));
        for (int i = 0; i < b; i++)
            for (int j = 0; j < c; j++)
                rank[ballots[i][j]][i] = j;

        int ans = 0;
        bool found = false;

        while (ans < c && !found) {
            found = true;
            for (int i = 0; i < c && found; i++) {
                if (i == ans) continue;

                int cnt = 0;
                for (int j = 0; j < b; j++)
                    if (rank[ans][j] < rank[i][j])
                        cnt++;

                if (cnt <= b / 2) found = false;
            }

            if (!found) ans++;
        }

        cout << "Case " << t++ << ": ";
        if (found) cout << ans << "\n";
        else cout << "No Condorcet winner\n";
    }
}