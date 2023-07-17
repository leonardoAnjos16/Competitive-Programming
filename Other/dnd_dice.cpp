#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

template<typename T>
struct Polynomial {
    int deg;
    vector<T> coeffs;

    Polynomial(int deg, T v = 0) {
        this->deg = deg;
        coeffs.assign(deg + 1, v);
    }

    T& operator [](int index) {
        return coeffs[index];
    }

    Polynomial<T> operator *(Polynomial<T> other) {
        Polynomial<T> ans(deg + other.deg);
        for (int i = 0; i <= deg; i++)
            for (int j = 0; j <= other.deg; j++)
                ans[i + j] += coeffs[i] * other[j];

        return ans;
    }
};

template<typename T>
Polynomial<T> exp(Polynomial<T> &p, int n) {
    if (!n) return Polynomial<T>(0, 1);

    Polynomial<T> ans = exp(p, n >> 1);
    ans = ans * ans;

    if (!(n & 1)) return ans;
    return ans * p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, c, o, d, i;
    cin >> t >> c >> o >> d >> i;

    Polynomial<ldouble> pt(4, 1.0L / 4.0L);
    Polynomial<ldouble> pc(6, 1.0L / 6.0L);
    Polynomial<ldouble> po(8, 1.0L / 8.0L);
    Polynomial<ldouble> pd(12, 1.0L / 12.0L);
    Polynomial<ldouble> pi(20, 1.0L / 20.0L);

    pt[0] = pc[0] = po[0] = pd[0] = pi[0] = 0.0L;
    Polynomial<ldouble> p = exp(pt, t) * exp(pc, c) * exp(po, o) * exp(pd, d) * exp(pi, i);

    int mn = t + c + o + d + i;
    int mx = 4 * t + 6 * c + 8 * o + 12 * d + 20 * i;

    vector<pair<ldouble, int>> ans(mx - mn + 1);
    for (int i = mn; i <= mx; i++)
        ans[i - mn] = make_pair(p[i], i);

    sort(ans.rbegin(), ans.rend());

    for (int i = 0; i < mx - mn + 1; i++) {
        if (i) cout << " ";
        cout << ans[i].second;
    }

    cout << "\n";
}