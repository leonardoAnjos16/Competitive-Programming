#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    char map[MAX][MAX];
    for (int i = 0; i < n; i++)
        scanf("%s", map[i]);

    vector< pair<int, int> > pos;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == '*')
                pos.push_back({i + 1, j + 1});

    int row = pos[0].first == pos[1].first ? pos[2].first : (pos[0].first == pos[2].first ? pos[1].first : pos[0].first);
    int col = pos[0].second == pos[1].second ? pos[2].second : (pos[0].second == pos[2].second ? pos[1].second : pos[0].second);

    printf("%d %d\n", row, col);
}