#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int palindromic(int x) {
    if (!x) return 0;
    if (x == 1) return 1;

    int ans = 1, size = 2;
    while ((1LL << size) - 1 < x) {
        int cnt = (1LL << (size / 2)) / 2;
        if (size & 1) cnt *= 2LL;
        ans += cnt;
        size++;
    }

    int half = size / 2, forward = 0, backward = 0;
    for (int i = 0; i < half; i++)
        if (x & (1LL << (size - i - 1))) {
            forward |= (1LL << (half - i - 1));
            backward |= (1LL << i);
        }

    ans += (forward ^ (1LL << (half - 1))) * ((size & 1) ? 2 : 1);
    if (!(size & 1) && ((forward << half) | backward) <= x) ans++;
    else if (size & 1) {
        if (((forward << (half + 1)) | backward) <= x) ans++;
        if (((forward << (half + 1)) | (1LL << half) | backward) <= x) ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; cin >> Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;

        int ans = palindromic(B);
        if (A) ans -= palindromic(A - 1);
        cout << ans << "\n";
    }
}