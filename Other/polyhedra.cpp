#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int F = 2 - V + E;
        cout << F << "\n";
    }
}