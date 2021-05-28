#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; getline(cin, s);
    string t; getline(cin, t);

    set<char> ans;
    int l = 0, r = 0;

    while (l < size(s) && r < size(t)) {
        int cnt_l = 1;
        while (l + 1 < size(s) && s[l + 1] == s[l]) l++, cnt_l++;

        int cnt_r = 1;
        while (r + 1 < size(t) && t[r + 1] == t[r]) r++, cnt_r++;

        if (cnt_r > cnt_l)
            ans.insert(s[l]);

        l++; r++;
    }

    for (char c: ans)
        cout << c;

    cout << "\n";
}