#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int x = 0;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        x ^= A[i];
    }

    if (N & 1) cout << "Win\n";
    else {
        bool win = false;
        for (int i = 0; i < N && !win; i++)
            if (A[i] == x) win = true;

        cout << (win ? "Win" : "Lose") << "\n";
    }
}