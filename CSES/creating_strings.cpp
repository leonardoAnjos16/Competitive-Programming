#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    sort(s.begin(), s.end());

    vector<string> ans;
    do ans.push_back(s);
    while (next_permutation(s.begin(), s.end()));

    int size = ans.size();
    cout << size << "\n";

    for (int i = 0; i < size; i++)
        cout << ans[i] << "\n";
}