#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        string A; cin >> A;
        string B; cin >> B;

        int n = A.size();

        int ans = 0;
        bool rev = false;
        bool possible = !(n % 2) || A[n / 2] == B[n / 2];

        for (int i = 0; i < n / 2 && possible; i++) {
            if (!((A[i] == B[i] && A[n - i - 1] == B[n - i - 1]) || (A[i] == B[n - i - 1] && A[n - i - 1] == B[i])))
                possible = false;

            if (B[i] == A[i] && A[i] != A[n - i - 1] && rev) ans++, rev = false;
            else if (B[i] != A[i] && !rev) ans++, rev = true;
        }

        cout << (possible ? ans : -1) << "\n";
    }
}