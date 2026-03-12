#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

void print_rounded(ldouble x) {
    string aux = to_string(x);
    // cout << aux << "\n";

    int idx = 0;
    llong integer = 0LL;

    while (idx < (int) aux.size() && aux[idx] != '.') {
        int d = aux[idx++] - '0';
        integer = 10LL * integer + d;
    }

    bool should_add = false;
    string decimal = aux.substr(idx + 1);

    while ((int) decimal.size() > 5) decimal.pop_back();

    if ((int) decimal.size() > 4) {
        char last = decimal.back();
        decimal.pop_back();

        if (last >= '5') {
            int idx = (int) decimal.size() - 1;
            while (idx >= 0 && decimal[idx] == '9')
                decimal[idx] = '0';

            if (idx < 0) should_add = true;
            else decimal[idx]++;
        }
    }

    while ((int) decimal.size() < 4)
        decimal += '0';

    if (should_add) integer++;
    cout << integer << "." << decimal << "g\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; cin >> X;
    while (X--) {
        string calc; cin >> calc;

        cout << "A massa do precipitado e: ";
        if (calc == "calc1") {
            ldouble MM; int e, Q;
            cin >> MM >> e >> Q;

            ldouble ans = (MM * Q) / (96500.0L * e);
            print_rounded(ans);
        } else {
            ldouble M, i; int nox, t;
            cin >> M >> nox >> i >> t;

            ldouble ans = ((M / nox) * i * t) / 96500.0L;
            print_rounded(ans);
        }
    }
}