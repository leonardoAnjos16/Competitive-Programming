#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D, C, R;
    cin >> D >> C >> R;

    queue<int> tiring;
    for (int i = 0; i < C; i++) {
        int Ci; cin >> Ci;
        tiring.push(Ci);
    }

    queue<int> invigorating;
    for (int i = 0; i < R; i++) {
        int Ri; cin >> Ri;
        invigorating.push(Ri);
    }

    int ans = 0;
    while (!tiring.empty() || !invigorating.empty()) {
        if (tiring.empty()) {
            ans++;
            D += invigorating.front();
            invigorating.pop();
        } else if (tiring.front() <= D) {
            ans++;
            D -= tiring.front();
            tiring.pop();
        } else if (!invigorating.empty()) {
            ans++;
            D += invigorating.front();
            invigorating.pop();
        } else {
            break;
        }
    }

    cout << ans << "\n";
}