#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    llong k; cin >> k;

    if (k == 1LL) {
        cout << "1\n1\n";
        return 0;
    }

    vector<llong> factors;
    llong aux = k, sum = 0LL;

    for (int i = 2; 1LL * i * i <= aux && sum <= MAX && i <= MAX; i++) {
        llong factor = 1LL;
        while (!(aux % i) && factor <= MAX) {
            aux /= i;
            factor *= i;
        }

        if (factor > 1LL) {
            sum += factor;
            factors.push_back(factor);
        }
    }

    if (sum <= MAX && aux > 1LL) {
        sum += aux;
        factors.push_back(aux);
    }

    if (sum > MAX) cout << "No solution\n";
    else {
        cout << sum << "\n";

        aux = 1LL;
        bool space = false;

        for (int factor: factors) {
            if (space) cout << " ";
            space = true;

            for (int i = 1; i < factor; i++)
                cout << (aux + i) << " ";

            cout << aux;
            aux += factor;
        }

        cout << "\n";
    }
}