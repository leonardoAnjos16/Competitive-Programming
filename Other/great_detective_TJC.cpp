#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        set<int> seen;
        bool possible = false;

        for (int i = 0; i < N; i++) {
            int A; cin >> A;
            if (seen.count(A ^ 1))
                possible = true;

            seen.insert(A);
        }

        cout << (possible ? "Yes" : "No") << "\n";
    }
}