#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int sum = 0;
    while (n--) {
        char type; cin >> type;
        if (type == 'T') cout << sum << "\n";
        else {
            int c; cin >> c;
            sum += c;
        }
    }
}