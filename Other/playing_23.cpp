#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 13;

int points(int card) {
    if (card <= 10)
        return card;

    return 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int cnt[MAX] = {0}, john = 0, mary = 0;
    for (int i = 0; i < 2; i++) {
        int c; cin >> c;

        cnt[c - 1]++;
        john += points(c);
    }

    for (int i = 0; i < 2; i++) {
        int c; cin >> c;

        cnt[c - 1]++;
        mary += points(c);
    }

    for (int i = 0; i < N; i++) {
        int c; cin >> c;

        cnt[c - 1]++;
        john += points(c);
        mary += points(c);
    }

    int ans = -1;
    for (int i = 0; i < MAX && mary + points(i + 1) <= 23 && ans == -1; i++)
        if (cnt[i] < 4 && (john + points(i + 1) > 23 || mary + points(i + 1) == 23))
            ans = i + 1;

    cout << ans << "\n";
}