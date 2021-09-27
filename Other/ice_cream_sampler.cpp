#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 105;

int dist(pair<int, int> &a, pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> pos[MAX];
    pos[0] = make_pair(7, 0);
    pos[101] = make_pair(12, 0);

    for (int i = 1, r = 6; i <= 14; i += 2, r--)
        pos[i] = pos[i + 1] = make_pair(r, 0);

    for (int i = 15, c = 0; i <= 26; i += 2, c++)
        pos[i] = pos[i + 1] = make_pair(0, c);

    for (int i = 27, r = 0; i <= 66; i += 2, r++)
        pos[i] = pos[i + 1] = make_pair(r, 5);

    for (int i = 67, c = 5; i <= 78; i += 2, c--)
        pos[i] = pos[i + 1] = make_pair(19, c);

    for (int i = 79, r = 19; i <= 92; i += 2, r--)
        pos[i] = pos[i + 1] = make_pair(r, 0);

    for (int i = 93, r = 11; i <= 100; i += 2, r--)
        pos[i] = pos[i + 1] = make_pair(r, 0);

    int flavours[10];
    for (int i = 0; i < 10; i++)
        cin >> flavours[i];

    int ans = INT_MAX;
    do {
        int cnt = 0;
        pair<int, int> curr = pos[0];

        for (int i = 0; i < 10; i++) {
            cnt += dist(curr, pos[flavours[i]]);
            curr = pos[flavours[i]];
        }

        cnt += dist(curr, pos[101]);
        ans = min(ans, cnt);
    } while (next_permutation(flavours, flavours + 10));

    cout << ans << "\n";
}