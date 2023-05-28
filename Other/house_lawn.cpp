#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<string> split(string &s) {
    string curr = "";
    vector<string> ans;

    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] != ',') curr += s[i];
        else {
            ans.push_back(curr);
            curr = "";
        }
    }

    ans.push_back(curr);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, m;
    cin >> l >> m;
    cin.ignore();

    vector<string> ans;
    int price = INT_MAX;

    for (int i = 0; i < m; i++) {
        string line;
        getline(cin, line);

        vector<string> lawnmover = split(line);

        string name = lawnmover[0];
        int p = stoi(lawnmover[1]);
        int c = stoi(lawnmover[2]);
        int t = stoi(lawnmover[3]);
        int r = stoi(lawnmover[4]);

        if (10080LL * c * t < 1LL * l * (t + r)) continue;

        if (p == price) ans.push_back(name);
        else if (p < price) {
            price = p;
            vector<string>(1, name).swap(ans);
        }
    }

    if (ans.empty()) cout << "no such mower\n";
    else {
        for (string name: ans)
            cout << name << "\n";
    }
}