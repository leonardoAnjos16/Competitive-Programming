#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> h(2, vector<int>(m));
        for (int i = 0; i < m; i++)
            cin >> h[0][i] >> h[1][i];

        bool possible = true;
        vector<int> table(n, -1);

        for (int i = 0; i < m && possible; i++) {
            bool done = false;
            int pos = 0, word = i;
            vector<vector<bool>> seen(2, vector<bool>(m, false));

            while (!seen[pos][word] && !done) {
                if (table[h[pos][word]] == -1) {
                    done = true;
                    table[h[pos][word]] = word;
                } else if (table[h[1 - pos][word]] == -1) {
                    done = true;
                    table[h[1 - pos][word]] = word;
                } else {
                    int nword = table[h[pos][word]];
                    int npos = h[0][nword] == h[pos][word] ? 1 : 0;

                    table[h[pos][word]] = word;
                    seen[pos][word] = true;
                    word = nword;
                    pos = npos;
                }
            }

            if (!done) possible = false;
        }

        cout << (possible ? "successful hashing" : "rehash necessary") << "\n";
    }
}