#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define heap(ds, cmp) priority_queue<ds, vector<ds>, cmp>

const int MAX = 105;

string S; int N;
char cubes[MAX][6];
bitset<MAX> used;

bool build(int i = 0) {
    if (i >= (int) S.size()) return true;

    bool possible = false;
    for (int j = 0; j < N && !possible; j++)
        if (!used[j])
            for (int k = 0; k < 6; k++)
                if (cubes[j][k] == S[i]) {
                    used[j] = true;
                    possible = build(i + 1);
                    used[j] = false;
                    break;
                }

    return possible;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 6; j++)
            cin >> cubes[i][j];

    string ans = build() ? "YES" : "NO";
    cout << ans << "\n";
}