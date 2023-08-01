#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int get_bit(int x, int bit) {
    return x & (1 << bit) ? 1 : 0;
}

vector<int> indices(int n, int bit, int v) {
    vector<int> p;
    for (int i = 1; i <= n; i++)
        if (get_bit(i, bit) == v)
            p.push_back(i);

    return p;
}

int ask(vector<int> &p, int prefix = -1) {
    if (prefix == -1) prefix = (int) p.size() - 1;

    cout << "? " << (prefix + 1);
    for (int i = 0; i <= prefix; i++)
        cout << " " << p[i];

    cout << "\n";
    cout.flush();

    int _xor;
    cin >> _xor;
    return _xor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    vector<int> bits;
    for (int i = 0; (1 << i) <= n; i++) {
        vector<int> p = indices(n, i, 1);

        int _xor = ask(p);
        int sz = p.size();

        if (!(sz & 1) && _xor == (x ^ y)) bits.push_back(i);
        else if ((sz & 1) && _xor == y) bits.push_back(i);
    }

    assert(!bits.empty());

    vector<int> off = indices(n, bits[0], 0);
    vector<int> on = indices(n, bits[0], 1);
    vector<int> &p = off.size() < on.size() ? off : on;

    int l = 0, r = (int) p.size() - 1, p1 = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        int _xor = ask(p, mid);
        if (_xor == 0 || _xor == x) l = mid + 1;
        else r = mid - 1, p1 = p[mid];
    }

    assert(p1 != -1);

    int p2 = p1;
    for (int bit: bits)
        p2 ^= (1 << bit);

    if (p1 > p2) swap(p1, p2);

    cout << "! " << p1 << " " << p2 << "\n";
    cout.flush();
}