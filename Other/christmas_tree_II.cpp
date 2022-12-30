#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<bool> seen(2 * N, false);
    for (int i = 0; i < N; i++) {
        string level; cin >> level;
        if ((int) level.size() >= 2 * N) continue;
        seen[(int) level.size()] = true;
    }

    bool whole = true;
    for (int i = 1; i < 2 * N && whole; i += 2)
        if (!seen[i]) whole = false;

    cout << (whole ? "yes" : "no") << "\n";
}