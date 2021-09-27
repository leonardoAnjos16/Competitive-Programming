#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    cin >> X >> Y;

    int Z, prob = 0;
    for (int i = 1; i <= 100; i++) {
        if (i == X || i == Y) continue;

        int cnt = 0;
        for (int j = 1; j <= 100; j++)
            cnt += abs(i - j) < abs(X - j) && abs(i - j) < abs(Y - j);

        if (cnt > prob) {
            Z = i;
            prob = cnt;
        }
    }

    cout << Z << "\n";
}