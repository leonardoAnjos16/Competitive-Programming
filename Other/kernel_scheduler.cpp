#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int inc = 0, dec = 0;
    vector<int> iedges, dedges;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (a < b) {
            inc++;
            iedges.push_back(i);
        } else {
            dec++;
            dedges.push_back(i);
        }
    }

    cout << "YES\n";
    cout << max(inc, dec) << "\n";

    vector<int> &edges = inc > dec ? iedges : dedges;
    for (int i = 0; i < max(inc, dec); i++) {
        if (i) cout << " ";
        cout << (edges[i] + 1);
    }

    cout << "\n";
}