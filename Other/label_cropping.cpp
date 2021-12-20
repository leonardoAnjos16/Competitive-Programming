#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N; cin >> N;
    int K; cin >> K;

    int size = N.size();
    reverse(N.begin(), N.end());

    long ans = 0LL;
    vector<int> cnt(K, 0);
    vector<int> mod(size + 1, 0);

    int power = cnt[0] = 1;
    for (int i = 1; i <= size; i++) {
        mod[i] = (mod[i - 1] + (N[i - 1] - '0') * power) % K;
        power = (power * 10) % K;
        ans += cnt[mod[i]]++;
    }

    cout << ans << "\n";
}