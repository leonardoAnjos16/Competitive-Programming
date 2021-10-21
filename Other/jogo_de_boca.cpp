#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N; cin >> N;

    int sum = 0;
    for (auto c: N)
        sum += c - '0';

    int ans = sum % 3;
    cout << ans << "\n";
}