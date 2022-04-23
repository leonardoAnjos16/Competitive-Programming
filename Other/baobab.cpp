#include <bits/stdc++.h>

using namespace std;

#define long long long int

int h, w, T;
vector<int> t, ss;
vector<string> ans;

bool solve(int rem, int tree = 0) {
    if (tree >= T) return true;
    if (rem < ss[tree]) return false;

    for (int i = t[tree] - 1; i < h; i++)
        for (int j = t[tree] - 1; j < w; j++) {
            bool possible = true;
            for (int k = i - t[tree] + 1; k <= i && possible; k++)
                for (int l = j - t[tree] + 1; l <= j && possible; l++)
                    if (ans[k][l] != '.') possible = false;

            if (possible) {
                for (int k = i - t[tree] + 1; k <= i; k++)
                    for (int l = j - t[tree] + 1; l <= j; l++)
                        ans[k][l] = 'A' + tree;

                if (solve(rem - t[tree] * t[tree], tree + 1))
                    return true;

                for (int k = i - t[tree] + 1; k <= i; k++)
                    for (int l = j - t[tree] + 1; l <= j; l++)
                        ans[k][l] = '.';
            }
        }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;
    cin >> T;

    t.resize(T);
    for (int i = 0; i < T; i++)
        cin >> t[i];

    sort(t.rbegin(), t.rend());

    ss.resize(T);
    ss[T - 1] = t[T - 1] * t[T - 1];

    for (int i = T - 2; i >= 0; i--)
        ss[i] = ss[i + 1] + t[i] * t[i];

    ans.assign(h, string(w, '.'));
    if (!solve(h * w)) cout << "IMPOSSIBLE\n";
    else {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (j) cout << " ";
                cout << ans[i][j];
            }

            cout << "\n";
        }
    }
}