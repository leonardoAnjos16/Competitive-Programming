#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e8;

bool works(long long int N, long long int X) {
    long long int aux = N, pow = 1LL;
    while (aux) {
        pow *= 10LL;
        aux /= 10LL;
    }

    pow /= 10LL;
    aux = (N % pow) * 10LL + N / pow;
    return N * X == aux * 10000LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double X_double; cin >> X_double;
    long long int X = X_double * 10000LL + .5;

    vector<int> ans;
    for (int i = 1; i < MAX; i++)
        if (works(i, X)) ans.push_back(i);

    if (ans.empty()) cout << "No solution\n";
    else for (auto a: ans) cout << a << "\n";
}