#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    int rounds = 0, score = n;
    for (int i = 0; i < k; i++) {
        if (!score) rounds++, score = n;

        int a; cin >> a;
        if (score - a >= 0) score -= a;
    }

    if (!score) rounds++;
    cout << rounds << "\n";
    cout << score << "\n";
}