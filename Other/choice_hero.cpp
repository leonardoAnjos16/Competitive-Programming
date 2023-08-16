#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, f;
    cin >> n >> f;

    bool possible = true;
    for (int i = 0; i < n && possible; i++) {
        int a, b;
        cin >> a >> b;

        int chosen = -1;
        if (a <= f) chosen = a;
        if (b <= f && (chosen == -1 || b > a)) chosen = b;

        if (chosen == -1) possible = false;
        else f += chosen;
    }

    cout << (possible ? "S" : "N") << "\n";
}