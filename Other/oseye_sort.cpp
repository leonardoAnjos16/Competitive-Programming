#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; char order;
    cin >> N >> order;

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << (order == 'd' ? N - i : i + 1);
    }

    cout << "\n";
}