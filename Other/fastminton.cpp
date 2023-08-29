#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    bool won = false;
    int g[2] = {0}, p[2] = {0}, server = 0;

    for (char c: s) {
        if (c == 'Q') {
            if (!won) cout << g[0] << " (" << p[0] << (server == 0 ? "*" : "") << ") - " << g[1] << " (" << p[1] << (server == 1 ? "*" : "") << ")\n";
            else {
                cout << g[0] << " ";
                if (g[0] > g[1]) cout << "(winner) ";
                cout << "- " << g[1];
                if (g[1] > g[0]) cout << " (winner)";
                cout << "\n";
            }
        } else {
            if (won) continue;

            int point = c == 'S' ? server : 1 - server;
            p[point]++;

            if (p[point] == 10 || (p[point] >= 5 && p[point] >= p[1 - point] + 2)) g[point]++, p[0] = p[1] = 0;
            if (g[point] == 2) won = true;
            server = point;
        }
    }
}