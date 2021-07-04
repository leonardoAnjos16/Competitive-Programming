#include <bits/stdc++.h>

using namespace std;

#define long long long int

int K;
vector<int> N;

bool solve(int i = 0, int sum = 0, long prod = 1LL) {
    if (i >= K) return prod >= sum;

    for (int j = 1; j < 10; j++)
        if (solve(i + 1, sum + j, prod * j)) {
            N[i] = j;
            return true;
        }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> K;

        N.resize(K);
        assert(solve());

        for (int i: N)
            cout << i;

        cout << "\n";
    }
}