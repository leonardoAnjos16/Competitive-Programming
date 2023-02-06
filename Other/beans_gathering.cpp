#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> a(N + 1);
    for (int i = 0; i <= N; i++)
        cin >> a[i];

    llong sum = 0LL;
    bool possible = true;

    for (int i = N; i > 0 && possible; i--) {
        if ((a[i] + sum) % i) possible = false;
        else sum += (a[i] + sum) / i;
    }

    cout << (possible ? "Yes" : "No") << "\n";
}