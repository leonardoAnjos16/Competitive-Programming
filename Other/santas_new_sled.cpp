#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long x, y;
    cin >> x >> y;

    string s; cin >> s;
    int n = s.size();

    vector<int> right(n + 1, 0), up(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        right[i] = right[i - 1];
        up[i] = up[i - 1];

        if (s[i - 1] == 'U') up[i]++;
        else if (s[i - 1] == 'R') right[i]++;
        else if (s[i - 1] == 'D') up[i]--;
        else right[i]--;
    }

    bool possible = false;
    for (int i = 0; i <= n && !possible; i++) {
        long nx = x - right[i];
        long ny = y - up[i];

        if (!nx && !ny) possible = true;
        else {
            if (!nx && right[n]) continue;
            if (!ny && up[n]) continue;

            if (nx < 0 && right[n] >= 0) continue;
            if (nx > 0 && right[n] <= 0) continue;
            if (ny < 0 && up[n] >= 0) continue;
            if (ny > 0 && up[n] <= 0) continue;

            if (nx && abs(nx) % abs(right[n])) continue;
            if (ny && abs(ny) % abs(up[n])) continue;

            if (!nx || !ny || nx / right[n] == ny / up[n])
                possible = true;
        }
    }

    cout << (possible ? "Yes" : "No") << "\n";
}