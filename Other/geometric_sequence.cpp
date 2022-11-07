#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int sign(llong x) {
    return x < 0 ? -1 : (x > 0 ? 1 : 0);
}

bool cmp(llong a, llong b) {
    return abs(a) < abs(b);
}

llong pow(llong a, int n) {
    llong ans = 1LL;
    while (n--) {
        if (ans > LLONG_MAX / a) ans = LLONG_MAX;
        else ans *= a;
    }

    return ans;
}

llong factor(llong n, int exp) {
    llong l = 1LL, r = n, ans = -1LL;
    while (l <= r) {
        llong mid = (l + r) / 2LL;
        if (pow(mid, exp) > n) r = mid - 1LL;
        else l = mid + 1LL, ans = mid;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(10) << fixed;

    int N; cin >> N;

    vector<llong> seq(N);
    bool neg = false, pos = false;

    for (int i = 0; i < N; i++) {
        cin >> seq[i];
        if (seq[i] < 0) neg = true;
        else pos = true;
    }

    sort(seq.begin(), seq.end(), cmp);

    int mx = 1, equal = 1, cntn = seq[0] < 0, cntp = seq[0] > 0;
    for (int i = 1; i < N; i++) {
        if (abs(seq[i]) == abs(seq[i - 1])) equal++;
        else mx = max(mx, equal), equal = 1;

        cntn += seq[i] < 0;
        cntp += seq[i] > 0;
    }

    mx = max(mx, equal);
    if (mx > 1 && mx < N) cout << "0\n";
    else if (mx == N) {
        if (!neg || !pos) cout << "1\n";
        else if (abs(cntn - cntp) > 1) cout << "0\n";
        else cout << "-1\n";
    }
    else {
        vector<pair<llong, llong>> ratios;
        pair<llong, llong> mn = make_pair(LLONG_MAX, LLONG_MAX);

        for (int i = 1; i < N; i++) {
            llong g = gcd(abs(seq[i - 1]), abs(seq[i]));
            ratios.emplace_back(abs(seq[i]) / g, abs(seq[i - 1]) / g);
            mn = min(mn, ratios.back());
        }

        for (int i = 1; i <= 60; i++) {
            llong num = factor(mn.first, i);
            llong den = factor(mn.second, i);

            if (pow(num, i) == mn.first && pow(den, i) == mn.second) {
                bool possible = true;
                for (int i = 1; i < N; i++) {
                    auto [a, b] = ratios[i - 1];
                    if (a > 1 && num == 1) {
                        possible = false;
                        break;
                    }

                    if (b > 1 && den == 1) {
                        possible = false;
                        break;
                    }

                    int ca = -1;
                    if (num > 1) {
                        llong aux = a;
                        while (aux) {
                            ca++;
                            aux /= num;
                        }
                    }

                    int cb = -1;
                    if (den > 1) {
                        llong aux = b;
                        while (aux) {
                            cb++;
                            aux /= den;
                        }
                    }

                    if ((ca != -1 && pow(num, ca) != a) || (cb != -1 && pow(den, cb) != b) || (ca != -1 && cb != -1 && ca != cb)) {
                        possible = false;
                        break;
                    }

                    int mid = ca != -1 ? ca - 1 : (cb != -1 ? cb - 1 : -1);
                    if (!neg || !pos || mid == -1) continue;
                    
                    if ((!(mid & 1) && sign(seq[i - 1]) == sign(seq[i])) || ((mid & 1) && sign(seq[i - 1]) != sign(seq[i]))) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    long double ans = 1.0L * num / den;
                    if (neg && pos) ans *= -1.0L;
                    cout << ans << "\n";
                    return 0;
                }
            }
        }

        cout << "0\n";
    }
}