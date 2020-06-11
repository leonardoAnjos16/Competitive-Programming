#include <bits/stdc++.h>

using namespace std;

void print_LIS(vector<int> A, vector<int> p, int i) {
    if (p[i] == -1) cout << A[i] << "\n";
    else {
        print_LIS(A, p, p[i]);
        cout << A[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input; getline(cin, input);
    int t = stoi(input); getline(cin, input);

    bool first = true;
    while (t--) {
        if (!first) cout << "\n";
        else first = false;

        vector<int> A;
        while (getline(cin, input) && input != "")
            A.push_back(stoi(input));

        int n = A.size();
        vector<int> LIS, LIS_idx, p(n, -1);
        int last = 0;

        for (int i = 0; i < (int) A.size(); i++) {
            int idx = lower_bound(LIS.begin(), LIS.end(), A[i]) - LIS.begin();

            if (idx >= (int) LIS.size()) {
                LIS.push_back(A[i]);
                LIS_idx.push_back(i);
                last = i;
            } else {
                LIS[idx] = A[i];
                LIS_idx[idx] = i;
            }

            p[i] = idx ? LIS_idx[idx - 1] : -1;
        }

        int ans = LIS.size();
        cout << "Max hits: " << ans << "\n";
        print_LIS(A, p, last);
    }
}