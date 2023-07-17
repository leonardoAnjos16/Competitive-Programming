#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    if (1LL * M * K <= N) cout << "Iron fist Ketil\n";
    else cout << "King Canute\n";
}