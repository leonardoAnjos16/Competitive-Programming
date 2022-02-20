#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long Vk, Jk;
    cin >> Vk >> Jk;

    long Vg, Jg;
    cin >> Vg >> Jg;

    long Vh, Dh, Jh;
    cin >> Vh >> Dh >> Jh;

    long ans = Vk * Jk + Vg * Jg;
    ans *= Vh * Dh * Jh;
    cout << ans << "\n";
}