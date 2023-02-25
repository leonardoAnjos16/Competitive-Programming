#include <bits/stdc++.h>

using namespace std;

#define llong long long int

pair<int, int> operator -(pair<int, int> a, pair<int, int> b) {
    return make_pair(b.first - a.first, b.second - a.second);
}

llong operator *(pair<int, int> a, pair<int, int> b) {
    return 1LL * a.first * b.second - 1LL * a.second * b.first;
}

bool collinear(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return (b - a) * (c - a) == 0LL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<pair<int, int>> stars(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        stars[i] = make_pair(X, Y);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++)
                for (int l = k + 1; l < N; l++)
                    if (!collinear(stars[i], stars[j], stars[k]) && 
                        !collinear(stars[i], stars[j], stars[l]) && 
                        !collinear(stars[i], stars[k], stars[l]) && 
                        !collinear(stars[j], stars[k], stars[l]))
                            ans++;

    cout << ans << "\n";
}