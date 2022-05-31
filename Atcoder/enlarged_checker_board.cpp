#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;

    vector<string> grid(N * A, string(N * B, '.'));
    for (int i = 0; i < N * A; i++)
        for (int j = 0; j < N * B; j++)
            if (((i / A) & 1) != ((j / B) & 1))
                grid[i][j] = '#';

    for (string row: grid)
        cout << row << "\n";
}