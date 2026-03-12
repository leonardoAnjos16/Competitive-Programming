#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate(int n, vector<vector<int>> &A) {
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rotated[i][j] = A[j][n - i - 1];

    return rotated;
}

bool is_original(int n, vector<vector<int>> &A) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i > 0 && A[i][j] <= A[i - 1][j]) return false;
            if (j > 0 && A[i][j] <= A[i][j - 1]) return false;
        }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<vector<int>> K(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> K[i][j];

    int ans = 0;
    bool done = false;

    do {
        assert(ans < 4);
        if (is_original(N, K)) done = true;
        else {
            ans++;
            K = rotate(N, K);
        }
    } while (!done);

    cout << ans << "\n";
}