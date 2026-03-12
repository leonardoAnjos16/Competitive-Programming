#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, D, M;
    cin >> T >> D >> M;

    vector<int> y(M + 2, 0);
    for (int i = 1; i <= M; i++)
        cin >> y[i];

    y[M + 1] = D;

    bool possible = false;
    for (int i = 1; i <= M + 1 && !possible; i++)
        if (y[i] - y[i - 1] >= T) possible = true;

    cout << (possible ? "Y" : "N") << "\n";
}