#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    map<int, int> pos_a;
    for (int i = 0; i < N; i++) {
        int A; cin >> A;
        pos_a[A] = i;
    }

    map<int, int> pos_b;
    for (int i = 0; i < N; i++) {
        int B; cin >> B;
        pos_b[B] = i;
    }

    int same_pos = 0, diff_pos = 0;
    for (auto [v, p]: pos_a) {
        if (!pos_b.count(v)) continue;
        if (pos_b[v] == p) same_pos++;
        else diff_pos++;
    }

    cout << same_pos << "\n";
    cout << diff_pos << "\n";
}