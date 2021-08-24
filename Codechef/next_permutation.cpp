#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    while (K--) {
        for (int i = 0; i < N; i++)
            cin >> A[i];

        next_permutation(A.begin(), A.end());
        for (int i = 0; i < N; i++) {
            if (i) cout << " ";
            cout << A[i];
        }

        cout << "\n";
    }
}