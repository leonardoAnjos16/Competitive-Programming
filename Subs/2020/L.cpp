#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<string> grid;
vector<vector<vector<bool>>> part;

string build(int i, int j, int n, int row, int col) {
    string t = "";
    for (int k = 0; k < n; k++)
        t += grid[i + row * k][j + col * k];

    sort(t.begin(), t.end());
    return t;
}

void mark(int i, int j, int n, int row, int col, int idx) {
    for (int k = 0; k < n; k++)
        part[i + row * k][j + col * k][idx] = true;
}

void find(string s, int idx) {
    int n = s.size();
    sort(s.begin(), s.end());

    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++) {
            if (C - j >= n) {
                string t = build(i, j, n, 0, 1);
                if (s == t) mark(i, j, n, 0, 1, idx);
            }

            if (L - i >= n) {
                string t = build(i, j, n, 1, 0);
                if (s == t) mark(i, j, n, 1, 0, idx);
            }

            if (C - j >= n && L - i >= n) {
                string t = build(i, j, n, 1, 1);
                if (s == t) mark(i, j, n, 1, 1, idx);
            }

            if (j + 1 >= n && L - i >= n) {
                string t = build(i, j, n, 1, -1);
                if (s == t) mark(i, j, n, 1, -1, idx);
            }
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;

    grid.resize(L);
    for (int i = 0; i < L; i++)
        cin >> grid[i];

    int N; cin >> N;

    part.assign(L, vector<vector<bool>>(C, vector<bool>(N, false)));
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        find(word, i);
    }

    int ans = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++) {
            int cnt = 0;
            for (int k = 0; k < N; k++)
                cnt += part[i][j][k];

            if (cnt > 1) ans++;
        }

    cout << ans << "\n";
}