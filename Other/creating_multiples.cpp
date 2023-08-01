#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int exp(int a, int n, int m) {
    if (!n) return 1 % m;

    int ans = exp(a, n >> 1, m);
    ans = (1LL * ans * ans) % m;

    if (!(n & 1)) return ans;
    return (1LL * ans * a) % m;
}

void extended_euclidean(llong a, llong b, llong &x, llong &y) {
    if (!b) {
        x = 1LL;
        y = 0LL;
    } else {
        extended_euclidean(b, a % b, x, y);
        llong aux = x; x = y;
        y = aux - a / b * y;
    }
}

llong mod_mult_inv(llong a, llong m) {
    llong x, y;
    extended_euclidean(a, m, x, y);
    return (x % m + m) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int B, L;
    cin >> B >> L;

    int sum = 0;
    vector<int> D(L);

    for (int i = 0; i < L; i++) {
        cin >> D[i];

        int add = (1LL * D[i] * exp(B, L - i - 1, B + 1)) % (B + 1);
        sum = (sum + add) % (B + 1);
    }

    if (!sum) {
        cout << "0 0\n";
        return 0;
    }

    bool done = false;
    int idx = -1, digit = -1;

    for (int i = 0; i < L && !done; i++) {
        int power = exp(B, L - i - 1, B + 1);
        int inv = mod_mult_inv(power, B + 1);
        int diff = (1LL * sum * inv) % (B + 1);

        int nd = D[i] - diff;
        if (nd >= 0 && nd < D[i]) {
            digit = nd;
            idx = i + 1;
            done = true;
        }
    }

    cout << idx << " " << digit << "\n";
}