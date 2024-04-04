#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, constants[2];
    cin >> n >> constants[0] >> constants[1];

    int turn = 1;
    while (gcd(n, constants[turn]) <= n) {
        n -= gcd(n, constants[turn]);
        turn = 1 - turn;
    }

    cout << turn << "\n";
}