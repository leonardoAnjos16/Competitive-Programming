#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 29;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    long aux = (1LL << M) - 1LL, last = 0LL;
    for (int i = 1; i <= N; i++) {
        int cnt = __builtin_popcount(i - 1);
        long curr = (last << 1) & aux;

        if (!last && !(cnt & 1))
            curr++;
        
        last = curr;
    }

    cout << (!last ? "Free snacks!" : "Pay the bill") << "\n";
}