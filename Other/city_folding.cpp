#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; llong P, H;
    cin >> N >> P >> H;
    P--; H--;

    llong top = 0LL;
    for (int i = N - 1; i >= 0; i--)
        if (H >= (1LL << i)) {
            top |= 1LL << i;
            H = (2LL << i) - H - 1LL;
        }

    assert(!H);

    string ans(N, 'L');
    for (int i = 0; i < N; i++) {
        if (!(top & (1LL << i)) && P < (1LL << (N - i - 1))) ans[i] = 'R';
        else if ((top & (1LL << i)) && P >= (1LL << (N - i - 1))) ans[i] = 'R';

        if (P >= (1LL << (N - i - 1)) && (top & (1LL << i))) P = (1LL << (N - i)) - P - 1LL;
        else if (P >= (1LL << (N - i - 1))) P -= 1LL << (N - i - 1);
        else if (top & (1LL << i)) P = (1LL << (N - i - 1)) - P - 1LL;
    }

    assert(!P);

    cout << ans << "\n";
}