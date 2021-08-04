#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool gt(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first && a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> skills[4];
    for (int i = 0; i < 4; i++) {
        int a, b;
        cin >> a >> b;
        skills[i] = make_pair(a, b);
    }

    pair<int, int> t11 = make_pair(skills[0].first, skills[1].second);
    pair<int, int> t12 = make_pair(skills[1].first, skills[0].second);

    pair<int, int> t21 = make_pair(skills[2].second, skills[3].first);
    pair<int, int> t22 = make_pair(skills[3].second, skills[2].first);

    if ((gt(t11, t21) && gt(t11, t22)) || (gt(t12, t21) && gt(t12, t22))) cout << "Team 1\n";
    else if ((gt(t21, t11) || gt(t22, t11)) && (gt(t21, t12) || gt(t22, t12))) cout << "Team 2\n";
    else cout << "Draw\n";
}