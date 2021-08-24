#include <bits/stdc++.h>

using namespace std;

#define long long long int

/* int S, k;
map<int, int> factors;

bool possible(int i = 0, int s = 0) {
    if (i + 1 >= k) {
        int last = 1;
        for (auto p: factors)
            for (int j = 0; j < p.second; j++)
                last *= p.first;

        return s + last == S;
    }

    for (int j = 0)
} */

int n;
vector<int> factors;

int get_num(int mask) {
    int ans = 1;
    for (int i = 0; i < n; i++)
        if (mask & (1 << i)) ans *= factors[i];

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S, P, k;
    cin >> S >> P >> k;

    if (k == 1) {
        if (S != P) cout << "NO\n";
        else cout << S << "\n";
        return 0;
    }

    for (int i = 2; i * i <= P; i++)
        while (!(P % i)) factors.push_back(i), P /= i;

    if (P > 1) factors.push_back(P);
    n = factors.size();

    if (k == 2) {
        for (int i = 0; i < (1 << n); i++) {
            int n1 = get_num(i);
            int n2 = get_num(~i);

            if (n1 + n2 == S) {
                cout << n1 << " " << n2 << "\n";
                return 0;
            }
        }
    } else if (k == 3) {
        for (int i = 0; i < (1 << n); i++) {
            int n1 = get_num(i);
            for (int j = 0; j < (1 << n); j++)
                if (!(i & j)) {
                    int n2 = get_num(j);
                    int n3 = get_num(~(i | j));

                    if (n1 + n2 + n3 == S) {
                        cout << n1 << " " << n2 << " " << n3 << "\n";
                        return 0;
                    }
                }
        }
    } else {
        for (int i = 0; i < (1 << n); i++) {
            int n1 = get_num(i);
            for (int j = 0; j < (1 << n); j++)
                if (!(i & j)) {
                    int n2 = get_num(j);
                    for (int l = 0; l < (1 << n); l++)
                        if (!(i & l) && !(j & l)) {
                            int n3 = get_num(l);
                            int n4 = get_num(~(i | j | l));

                            if (n1 + n2 + n3 + n4 == S) {
                                cout << n1 << " " << n2 << " " << n3 << " " << n4 << "\n";
                                return 0;
                            }
                        }
                }
        }
    }

    cout << "NO\n";
}