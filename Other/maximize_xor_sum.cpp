#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 62;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    llong XA = 0LL;
    vector<llong> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        XA ^= A[i];
    }

    llong XB = 0LL;
    vector<llong> B(n);

    for (int i = 0; i < n; i++) {
        cin >> B[i];
        XB ^= B[i];
    }

    int index[MAX];
    llong used[MAX] = {0LL};
    llong basis[MAX] = {0LL};

    for (int i = 0; i < n; i++) {
        bool done = false;
        llong C = (A[i] ^ B[i]) & ~(XA ^ XB);

        llong curr = 0LL;
        for (int j = MAX - 1; j >= 0 && !done; j--) {
            if (!(C & (1LL << j))) continue;

            if (basis[j]) {
                C ^= basis[j];
                curr ^= used[j];
            } else {
                basis[j] = C;
                index[j] = i;
                curr ^= (1LL << j);
                used[j] = curr;
                done = true;
            }
        }
    }

    llong X = 0LL;
    llong curr = 0LL;

    for (int i = MAX - 1; i >= 0; i--)
        if (basis[i] && (XA & (1LL << i)) == (X & (1LL << i))) {
            X ^= basis[i];
            curr ^= used[i];
        }

    XA ^= X;
    XB ^= X;

    vector<int> swaps;
    for (int i = 0; i < MAX; i++)
        if (curr & (1LL << i))
            swaps.push_back(index[i] + 1);

    llong sum = XA + XB;
    int cnt = swaps.size();

    cout << sum << " " << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        if (i) cout << " ";
        cout << swaps[i];
    }

    cout << "\n";
}