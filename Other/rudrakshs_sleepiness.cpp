#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7 + 5;

bitset<MAX> composite;

bool two_primes(int n, vector<int> &lengths) {
    bool found = false;
    for (int i = 2; i + 1 < n && !found; i++)
        if (!composite[i] && !composite[n - i]) {
            found = true;
            lengths.push_back(i);
            lengths.push_back(n - i);
        }

    return found;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i * i < MAX; i++)
        if (!composite[i])
            for (int j = i * i; j < MAX; j += i)
                composite[j] = true;

    int t; cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        int sum = x + y;
        vector<int> lengths;

        if (!composite[sum]) lengths.push_back(sum);
        else {
            bool two = two_primes(sum, lengths);
            if (!two) {
                assert(sum & 1);
                lengths.push_back(3);
                assert(two_primes(sum - 3, lengths));
            }
        }

        int n = lengths.size();
        cout << n << "\n";

        int cx = 0, cy = 0;
        for (int i = 0; i < n; i++) {
            cx += lengths[i];
            if (cx > x) {
                cy += cx - x;
                cx = x;
            }

            cout << cx << " " << cy << "\n";
        }
    }
}