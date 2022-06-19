#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int odd = 0, even = 0;
    while (N--) {
        int A; cin >> A;
        if (A & 1) odd++;
        else even++;
    }

    cout << (abs(odd - even) <= 1 ? "Good" : "Not Good") << "\n";
}