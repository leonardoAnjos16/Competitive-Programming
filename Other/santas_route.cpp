#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<tuple<char, llong, string>> children(N);
    for (int i = 0; i < N; i++) {
        string name; char region; llong distance;
        cin >> name >> region >> distance;
        children[i] = make_tuple(region, distance, name);
    }

    sort(children.begin(), children.end());
    for (auto [region, distance, name]: children)
        cout << name << "\n";
}