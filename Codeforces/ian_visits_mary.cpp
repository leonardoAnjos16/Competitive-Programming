#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (!a) cout << "2\n1 " << b << "\n0 " << b << "\n";
        else if (!b) cout << "2\n" << a << " 1\n" << a << " 0\n";
        else if (a == 1000000000) cout << "2\n999999999 1\n1000000000 " << b << "\n";
        else cout << "2\n" << (a + 1) << " 1\n" << a << " " << b << "\n";
    }
}