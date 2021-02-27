#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

bool cmp(pair<long long int, long long int> &a, pair<long long int, long long int> &b) {
    return 2 * a.first + a.second > 2 * b.first + b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    long long int sum = 0LL;
    pair<long long int, long long int> voters[MAX];

    for (int i = 0; i < N; i++) {
        long long int A, B; cin >> A >> B;
        voters[i] = { A, B };
        sum += A;
    }

    sort(voters, voters + N, cmp);

    int ans = 0, idx = 0;
    long long int votes = 0LL;

    while (votes <= sum) {
        votes += voters[idx].first + voters[idx].second;
        sum -= voters[idx++].first; ans++;
    }

    cout << ans << "\n";
}