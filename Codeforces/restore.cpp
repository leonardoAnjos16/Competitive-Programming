#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    long A[MAX][MAX], sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            sum += A[i][j];
        }
    }

    sum /= (n - 1);

    for (int i = 0; i < n; i++) {
        long row = 0;
        for (int j = 0; j < n; j++)
            row += A[i][j];

        A[i][i] = sum - row;
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";

        cout << "\n";
    }
}