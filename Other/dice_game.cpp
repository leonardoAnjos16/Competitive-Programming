#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int a3, b3, a4, b4;
    cin >> a3 >> b3 >> a4 >> b4;

    int gunnar = 0, emma = 0;
    for (int i = a1; i <= b1; i++)
        for (int j = a2; j <= b2; j++)
            for (int k = a3; k <= b3; k++)
                for (int l = a4; l <= b4; l++) {
                    if (i + j > k + l) gunnar++;
                    else if (i + j < k + l) emma++;
                }

    if (gunnar > emma) cout << "Gunnar\n";
    else if (emma > gunnar) cout << "Emma\n";
    else cout << "Tie\n";
}