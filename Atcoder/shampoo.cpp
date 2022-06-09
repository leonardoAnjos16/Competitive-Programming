#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, mls[3];
    cin >> V >> mls[0] >> mls[1] >> mls[2];

    int turn = 0;
    while (V >= mls[turn]) {
        V -= mls[turn];
        turn = (turn + 1) % 3;
    }

    cout << (turn == 0 ? 'F' : (turn == 1 ? 'M' : 'T')) << "\n";
}