#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int grundy[MAX], idx = 0, sz = 1;
    while (idx < MAX) {
        for (int i = 0; i < sz && idx < MAX; i++)
            grundy[idx++] = 0;

        for (int i = 0; i < sz && idx < MAX; i++)
            grundy[idx++] = 1;

        sz++;
    }

    int N; cin >> N;

    bool win = grundy[N];
    cout << (win ? "Jane" : "John") << "\n";
}