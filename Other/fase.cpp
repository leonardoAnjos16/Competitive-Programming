#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    int K; cin >> K;

    vector<int> score(N);
    for (int i = 0; i < N; i++)
        cin >> score[i];

    sort(score.rbegin(), score.rend());

    int ans = K;
    while (ans < N && score[ans] == score[ans - 1]) ans++;
    cout << ans << "\n";
}