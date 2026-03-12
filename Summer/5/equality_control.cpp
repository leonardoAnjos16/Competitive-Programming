#include <bits/stdc++.h>

using namespace std;

void get_list(string &s, int &idx, vector<int> &list) {
    int brackets = 0, element = 0;
    while (idx < (int) s.size() && (s[idx] != ',' || brackets > 0)) {
        if (s[idx] == '(' || s[idx] == '[') brackets++;
        else if (s[idx] >= '0' && s[idx] <= '9') element = 10 * element + s[idx] - '0';
        else {
            if (s[idx] == ')' || s[idx] == ']') brackets--;
            if (element) {
                list.push_back(element);
                element = 0;
            }
        }

        idx++;
    }
}

void solve(string &s, int &idx, vector<int> &ans) {
    if (s[idx] == '[') return get_list(s, idx, ans);

    string op = "";
    while (s[idx] >= 'a' && s[idx] <= 'z')
        op += s[idx++];

    if (op == "sorted") {
        int size = ans.size();
        get_list(s, idx, ans);
        sort(ans.begin() + size, ans.end());
        return;
    }

    if (op == "shuffle") {
        int size = ans.size();
        ans.push_back(-1);
        get_list(s, idx, ans);
        sort(ans.begin() + size + 1, ans.end());
        ans.push_back(-1);
        return;
    }

    solve(s, ++idx, ans);
    solve(s, ++idx, ans);
}

vector<int> remove_wrong_shuffles(vector<int> &list) {
    int idx = 0;
    vector<int> ans;

    while (idx < (int) list.size()) {
        if (list[idx] != -1) ans.push_back(list[idx++]);
        else {
            int end = idx + 1;
            while (list[end] != -1) end++;

            if (list[idx + 1] != list[end - 1]) ans.push_back(-1);
            for (int i = idx + 1; i < end; i++) ans.push_back(list[i]);
            if (list[idx + 1] != list[end - 1]) ans.push_back(-1);

            idx = end + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A; cin >> A;
    string B; cin >> B;

    int idx = 0;
    vector<int> first;
    solve(A, idx, first);
    first = remove_wrong_shuffles(first);

    idx = 0;
    vector<int> second;
    solve(B, idx, second);
    second = remove_wrong_shuffles(second);

    cout << (first == second ? "equal" : "not equal") << "\n";
}