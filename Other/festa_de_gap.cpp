#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> as(N), bs(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        as[i] = a;
        bs[i] = b;
    }

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    int a = as[N / 2];
    int b = bs[N / 2];

    long ans = 0LL;
    for (int i = 0; i < N; i++) {
        ans += abs(a - as[i]);
        ans += abs(b - bs[i]);
    }

    cout << ans << "\n";
}