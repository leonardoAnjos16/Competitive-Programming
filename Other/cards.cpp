#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        long Q; cin >> Q;

        if (Q & 1) cout << "First Box\n";
        else {
            int cnt = 0;
            while (!(Q & 1)) {
                cnt++;
                Q >>= 1;
            }

            if (cnt & 1) cout << "Second Box\n";
            else cout << "First Box\n";
        }
    }
}