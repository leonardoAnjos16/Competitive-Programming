#include <bits/stdc++.h>

using namespace std;

#define long long long int

int B;
vector<int> divs;
unordered_map<long, long> memo;

long smallest(long N) {
    if (N < B) return N;

    if (memo.count(N))
        return memo[N];

    long &ans = memo[N];
    ans = LLONG_MAX;

    for (int div: divs)
        if (N % div == 0) {
            long aux = smallest(N / div);
            if (aux > LLONG_MAX / B) continue;

            aux *= B;
            if (aux > LLONG_MAX - div) continue;

            aux += div;
            ans = min(ans, aux);
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long N;
    cin >> B >> N;

    for (int i = B - 1; i * i >= B; i--)
        if (N % i == 0)
            divs.push_back(i);

    long ans = smallest(N);
    if (ans < LLONG_MAX) cout << ans << "\n";
    else cout << "impossible\n";
}