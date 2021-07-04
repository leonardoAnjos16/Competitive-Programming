#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> d[i][j];

    int edges = n * (n - 1);
    cout << edges << "\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                cout << (i + 1) << " " << (j + 1) << " " << d[i][j] << "\n";
}