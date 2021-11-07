#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int w, h;
        cin >> w >> h;

        cout << (w == h ? "Square" : "Rectangle") << "\n";
    }
}