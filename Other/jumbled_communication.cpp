#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 8;

int to_byte(int v) {
    return v & ((1 << MAX) - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";

        int b; cin >> b;

        int ans = -1;
        for (int j = 0; j < (1 << MAX) && ans == -1; j++)
            if (to_byte(j ^ (j << 1)) == b)
                ans = j;

        assert(ans != -1);
        cout << ans;
    }
}