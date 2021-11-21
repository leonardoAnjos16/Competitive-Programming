#include <iostream>

using namespace std;

#define long long long int

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long ans[MAX] = {0LL};
    for (int i = 2; i < MAX; i++)
        ans[i] = i;

    for (int i = 2; i < MAX; i++)
        if (ans[i] == i)
            for (int j = i; j < MAX; j += i) {
                ans[j] /= i;
                ans[j] *= i - 1;
            }

    for (int i = 1; i < MAX; i++)
        ans[i] += ans[i - 1];

    int n;
    while (cin >> n, n)
        cout << ans[n] << "\n";
}