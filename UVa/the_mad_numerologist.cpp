#include <bits/stdc++.h>

using namespace std;

bool vowel(char c) {
    switch (c) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

int main() {
    vector<char> cons, vows;
    for (int i = 0; i < 9; i++) {
        char letter = (char) (i + 'A');
        while (letter <= 'Z') {
            if (vowel(letter)) vows.push_back(letter);
            else cons.push_back(letter);
            letter += 9;
        }
    }

    int N; scanf("%d", &N);
    int case_num = 1;

    while (N--) {
        int n; scanf("%d", &n);

        string even = "";
        int idx = 0, cnt = 21;

        for (int i = 0; i < (n / 2) + (n % 2); i++) {
            even += vows[idx];
            if (--cnt == 0) idx++, cnt = 21;
        }

        string odd = "";
        idx = 0, cnt = 5;

        for (int i = 0; i < n / 2; i++) {
            odd += cons[idx];
            if (--cnt == 0) idx++, cnt = 5;
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (i & 1) ans += odd[i / 2];
            else ans += even[i / 2];
        }

        printf("Case %d: %s\n", case_num++, ans.c_str());
    }
}