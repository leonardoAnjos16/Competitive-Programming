#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<vector<int>> memo;
vector<vector<char>> letter;

int replace(char last = 'a', int i = 0) {
    if (i >= n) return 0;

    int &ans = memo[last - 'a'][i];
    if (~ans) return ans;

    ans = replace(last, i + 1) + 1;
    letter[last - 'a'][i] = last;

    if (s[i] >= last) {
        int aux = replace(s[i], i + 1);
        if (aux < ans) {
            ans = aux;
            letter[last - 'a'][i] = s[i];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> s;

    memo.assign(30, vector<int>(n + 5, -1));
    letter.assign(30, vector<char>(n + 5));

    int cnt = replace();
    cout << cnt << "\n";

    char last = 'a';
    string ans = "";

    for (int i = 0; i < n; i++) {
        ans += letter[last - 'a'][i];
        last = letter[last - 'a'][i];
    }

    cout << ans << "\n";
}