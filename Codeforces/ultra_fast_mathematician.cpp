#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string num; cin >> num;
    bitset<MAX> a(num);

    cin >> num;
    bitset<MAX> b(num);

    bitset<MAX> ans = a ^ b;
    int n = num.size();

    for (int i = n - 1; i >= 0; i--)
        cout << ans[i];

    cout << "\n";
}