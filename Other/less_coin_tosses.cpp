#include <bits/stdc++.h>

using namespace std;

#define long long long int

long count(long N, long pot) {
    if (pot == 1LL) return 2LL;

    pot >>= 1LL;
    if (N <= pot) return count(N, pot);
    else {
        long ans = count(N - pot, pot);
        ans <<= 1LL;
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N; cin >> N;

    long pot = 1LL, sum = 1LL;
    while (sum < N) {
        pot <<= 1LL;
        sum += pot;
    }


    sum -= pot;
    long ans = count(N - sum, pot);
    cout << ans << "\n";
}