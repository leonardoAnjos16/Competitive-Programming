#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;

        int pos[10] = { -1 };
        for (int i = 1; i < 10; i++)
            pos[s[i] - '0'] = i;

        if (pos[1] < pos[3]) cout << "13\n";
        else cout << "31\n";
    }
}