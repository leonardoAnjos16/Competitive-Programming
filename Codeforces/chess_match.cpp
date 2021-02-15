#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int a[MAX];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int b[MAX];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    bool ans[2];
    int aux = n / 2 + 1;

    ans[0] = true;
    for (int j = 0; j < aux; j++)
        if (b[j] > a[n - aux + j])
            ans[0] = false;

    ans[1] = true;
    for (int j = 0; j < aux; j++)
        if (a[j] > b[n - aux + j])
            ans[1] = false;

    cout << (ans[0] && ans[1] ? "Both" : (ans[0] ? "First" : (ans[1] ? "Second" : "None"))) << "\n";
}