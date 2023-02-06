#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, N;
    cin >> p >> N;

    vector<int> a(N + 1);
    for (int i = 0; i <= N; i++)
        cin >> a[i];

    int x = -1;
    for (int i = 0; i < p * p && x == -1; i++) {
        int sum = 0;
        for (int j = 0; j <= N; j++) {
            sum = (1LL * sum * i) % (p * p);
            sum = (sum + a[j]) % (p * p);
        }

        if (!sum) x = i;
    }

    cout << x << "\n";
}