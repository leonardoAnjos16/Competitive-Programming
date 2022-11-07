#include <bits/stdc++.h>

using namespace std;

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char op; cin >> op;
    int s; cin >> s;
    string w; cin >> w;

    for (int i = 0; i < (int) w.size(); i++) {
        if (op == 'D') w[i] = 'a' + ((w[i] - 'a' - s + MAX) % MAX);
        else w[i] = 'a' + ((w[i] - 'a' + s) % MAX);
    }

    cout << w << "\n";
}