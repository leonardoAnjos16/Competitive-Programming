#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int aux = n / 3;
        int c1 = aux;
        int c2 = aux;

        if (n % 3 == 1) c1++;
        else if (n % 3 == 2) c2++;

        cout << c1 << " " << c2 << "\n";
    }
}