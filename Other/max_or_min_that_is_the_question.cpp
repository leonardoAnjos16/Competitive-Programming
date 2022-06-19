#include <bits/stdc++.h>

using namespace std;

const int MAX = 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int A[MAX];
        for (int i = 0; i < 5; i++)
            cin >> A[i];

        sort(A, A + MAX);

        int ans = A[4] * A[3];
        cout << ans << "\n";
    }
}