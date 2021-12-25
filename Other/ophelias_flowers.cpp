#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> d(N);
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        cin >> d[i];
    }

    d.push_back(1);
    sort(d.rbegin(), d.rend());

    long F; cin >> F;

    int curr = 0, cnt = 1;
    while (F && d[curr] > 1) {
        while (d[curr + 1] == d[curr]) curr++, cnt++;

        if (1LL * (d[curr] - d[curr + 1]) * cnt > F) {
            d[curr] -= F / cnt;
            F = 0LL;
        } else {
            F -= 1LL * (d[curr] - d[curr + 1]) * cnt;
            curr++; cnt++;
        }
    }

    cout << d[curr] << "\n";
}