#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> rem;
    for (int i = 1; i <= n; i++)
        rem.push_back(i);

    vector<bool> doubt(n + 1, true);
    int cnt = n + 1, bit = 0, ans = 0;

    while (cnt > 1) {
        vector<int> zeros, ones;
        for (int idx: rem) {
            cout << "? " << idx << " " << bit << "\n";
            cout.flush();

            int curr; cin >> curr;
            if (curr) ones.push_back(idx);
            else zeros.push_back(idx);
        }

        int expected_zeros = 0;
        for (int i = 0; i <= n; i++)
            if (doubt[i] && !(i & (1 << bit)))
                expected_zeros++;

        int actual_zeros = zeros.size();
        if (actual_zeros == expected_zeros) {
            rem = ones;
            ans |= (1 << bit);

            for (int i = 0; i <= n; i++)
                if (doubt[i] && !(i & (1 << bit)))
                    doubt[i] = false, cnt--;
        } else {
            rem = zeros;
            for (int i = 0; i <= n; i++)
                if (doubt[i] && (i & (1 << bit)))
                    doubt[i] = false, cnt--;
        }

        bit++;
    }

    cout << "! " << ans << "\n";
    cout.flush();
}