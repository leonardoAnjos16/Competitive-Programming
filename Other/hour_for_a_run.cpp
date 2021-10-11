#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, N;
    cin >> V >> N;

    int total = V * N;
    for (int i = 1; i < 10; i++) {
        if (i > 1) cout << " ";

        int ans = (total * i + 9) / 10;
        cout << ans;
    }

    cout << "\n";
}