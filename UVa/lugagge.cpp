#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 25;
const int MAX_W = 205;

int n, w[MAX_N];
int memo[MAX_W][MAX_W][MAX_N];

void weights(string input) {
    string num = "";
    int idx = -1; n = 0;

    while (++idx < (int) input.size()) {
        if (input[idx] != ' ') num += input[idx];
        else w[n++] = stoi(num), num = "";
    }

    w[n++] = stoi(num);
}

bool possible(int w1 = 0, int w2 = 0, int i = 0) {
    if (i >= n && w1 == w2) return true;
    if (i >= n) return false;

    int &ans = memo[w1][w2][i];
    if (ans != -1) return ans;

    return ans = possible(w1 + w[i], w2, i + 1) || possible(w1, w2 + w[i], i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input; getline(cin, input);
    int m = stoi(input);
    
    while (m--) {
        getline(cin, input);
        weights(input);

        memset(memo, -1, sizeof memo);
        printf("%s\n", possible() ? "YES" : "NO");
    }
}