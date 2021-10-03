#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (!(S & 1) && 2 * a == S)
            cnt++;
    }

    if (cnt <= 2) cout << "yes\n";
    else cout << "no\n";
}