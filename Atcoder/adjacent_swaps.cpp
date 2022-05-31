#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N), pos(N);
    for (int i = 0; i < N; i++)
        a[i] = i, pos[i] = i;

    while (Q--) {
        int x; cin >> x;
        if (pos[x - 1] + 1 >= N) {
            pos[a[pos[x - 1] - 1]]++;
            swap(a[pos[x - 1] - 1], a[pos[x - 1]]);
            pos[x - 1]--;
        } else {
            pos[a[pos[x - 1] + 1]]--;
            swap(a[pos[x - 1]], a[pos[x - 1] + 1]);
            pos[x - 1]++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << (a[i] + 1);
    }

    cout << "\n";
}