#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX = 1e4 + 5;

int nodes = 1;
vector<int> c, p;

int build(int k, int node = 0) {
    if (k == 1) return c[node] = 1;

    int aux = k - 1;
    vector<int> primes;

    if (aux == 1) primes.push_back(1);
    else {
        for (int i = 2; i * i <= aux; i++)
            while (!(aux % i)) {
                aux /= i;
                primes.push_back(i);
            }

        if (aux > 1) primes.push_back(aux);
    }

    for (int prime: primes) {
        int child = nodes++;
        p.push_back(node + 1);
        c.push_back(0);

        c[node] += build(prime, child);
    }

    return c[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K; cin >> K;

    if (K == 1) {
        cout << "2\n";
        cout << "1\n";
        cout << "2 1\n";
        return 0;
    }

    c.assign(1, 0);
    p.assign(1, -1);

    build(K);

    cout << nodes << "\n";
    for (int i = 1; i < nodes; i++) {
        if (i > 1) cout << " ";
        cout << p[i];
    }

    cout << "\n";

    for (int i = 0; i < nodes; i++) {
        if (i) cout << " ";
        cout << c[i];
    }

    cout << "\n";
}