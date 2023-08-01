#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e3 + 5;

struct Binary {
    bitset<MAX> bits;

    Binary() {}
    Binary(bitset<MAX> bits): bits(bits) {}

    void add_pow(int exp) {
        while (exp < MAX && bits[exp])
            bits[exp++] = false;

        if (exp < MAX) bits[exp] = true;
    }

    Binary operator -() const {
        Binary ans(~bits);
        ans.add_pow(0);
        return ans;
    }

    Binary operator -(Binary const &other) const {
        int carry = 0;
        Binary complement = -other, ans;

        for (int i = 0; i < MAX; i++) {
            ans.bits[i] = bits[i] ^ complement.bits[i] ^ carry;
            if (bits[i] && complement.bits[i]) carry = 1;
            else if (carry && (bits[i] || complement.bits[i])) carry = 1;
            else carry = 0;
        }

        return ans;
    }

    bool operator <(Binary const &other) const {
        for (int i = MAX - 1; i >= 0; i--) {
            if (bits[i] < other.bits[i]) return true;
            if (bits[i] > other.bits[i]) return false;
        }

        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<bitset<MAX>> groups(m, bitset<MAX>());
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        while (k--) {
            int id; cin >> id;
            groups[i][id - 1] = true;
        }
    }

    vector<int> sz(1 << m, 0);
    for (int i = 0; i < (1 << m); i++) {
        bitset<MAX> in;
        for (int j = 0; j < m; j++)
            if (i & (1 << j))
                in |= groups[j];

        for (int j = 0; j < n; j++)
            sz[i] += in[j];
    }

    vector<pair<Binary, int>> sums(n);
    for (int i = 0; i < n; i++) {
        Binary add, rem;
        sums[i].second = -i;

        for (int j = 1; j < (1 << m); j++) {
            bool valid = true;
            for (int k = 0; k < m && valid; k++)
                if ((j & (1 << k)) && groups[k][i])
                    valid = false;

            if (!valid) continue;

            if (__builtin_popcount(j) & 1) add.add_pow(n - sz[j] - 1);
            else rem.add_pow(n - sz[j] - 1);
        }

        sums[i].first = add - rem;
    }

    sort(sums.rbegin(), sums.rend());
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << (-sums[i].second + 1);
    }

    cout << "\n";
}