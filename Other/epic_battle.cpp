#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    bool constantine = false;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        constantine ^= !(a & 1);
    }

    cout << (constantine ? "Constantine" : "Mike") << "\n";
}