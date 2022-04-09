#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        int sum = n > 1;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                sum += i;
                if (i * i < n)
                    sum += n / i;
            }

        if (sum > n) cout << "abundant\n";
        else if (sum < n) cout << "deficient\n";
        else cout << "perfect\n";
    }
}