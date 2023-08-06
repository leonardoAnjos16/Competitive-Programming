#include <bits/stdc++.h>

using namespace std;

vector<pair<char, char>> moves;

void solve(int N, char A = 'A', char B = 'B', char C = 'C') {
    if (N == 1) moves.emplace_back(A, C);
    else {
        solve(N - 1, A, C, B);
        moves.emplace_back(A, C);
        solve(N - 1, B, A, C);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    solve(N);

    int sz = moves.size();
    if (K < sz) cout << "N\n";
    else {
        if ((K - sz) & 1) {
            auto [A, B] = moves.back();
            moves.pop_back();

            if (A == 'A') {
                moves.emplace_back('A', 'B');
                moves.emplace_back('B', 'C');
            } else {
                moves.emplace_back('B', 'A');
                moves.emplace_back('A', 'C');
            }

            K--;
        }

        reverse(moves.begin(), moves.end());
        while (K > sz) {
            moves.emplace_back('B', 'A');
            moves.emplace_back('A', 'B');
            K -= 2;
        }

        reverse(moves.begin(), moves.end());

        cout << "Y\n";
        for (auto [A, B]: moves)
            cout << A << " " << B << "\n";
    }
}