#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;

    vector<tuple<int, int, string>> ornaments(A);
    for (int i = 0; i < A; i++) {
        string S; int V, X;
        cin >> S >> V >> X;
        ornaments[i] = make_tuple(V, -X, S);
    }

    sort(ornaments.begin(), ornaments.end());

    int idx = 0, sum = 0;
    while (idx < A && sum + get<0>(ornaments[idx]) <= B) {
        cout << get<2>(ornaments[idx]) << "\n";
        sum += get<0>(ornaments[idx++]);
    }
}