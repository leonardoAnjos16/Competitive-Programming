#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 30;

int dis[MAX][MAX];

void get_dis() {
    for (int i = 0; i < 26; i++)
        dis[i][i] = 0;

    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            cin >> dis[i][j];

    get_dis();

    string nick;
    cin >> nick;

    long ans = 0, n = size(nick);
    for (int i = 0; i < n / 2; i++) {
        int cost = INT_MAX;
        for (int j = 0; j < 26; j++)
            cost = min(cost, dis[nick[i] - 'a'][j] + dis[nick[n - i - 1] - 'a'][j]);

        ans += cost;
    }

    cout << ans << "\n";
}