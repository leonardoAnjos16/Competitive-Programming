#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b;
    cin >> n >> b;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        sum += c;
    }

    if (sum > b) cout << "Success\n";
    else if (sum == b) cout << "Just enough\n";
    else cout << "More funding required\n";
}