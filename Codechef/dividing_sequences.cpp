#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int ans = 1;
    vector<int> lds(N, 1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++)
            if (!(a[i] % a[j]))
                lds[i] = max(lds[i], lds[j] + 1);

        ans = max(ans, lds[i]);
    }

    cout << ans << "\n";
}