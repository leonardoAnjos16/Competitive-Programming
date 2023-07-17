#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K; cin >> K;
    string N; cin >> N;

    int ans = 0;
    for (int i = 0; i < K; i++)
        if (N[i] != '0' && N[i] != '6' && N[i] != '8')
            ans++;

    cout << ans << "\n";
}