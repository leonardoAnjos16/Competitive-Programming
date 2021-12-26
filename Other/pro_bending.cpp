#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    bool win = true;
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        if (e > k) win = false;
    }

    cout << (win ? "Easy Win!" : "Difficult Loss") << "\n";
}