#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 1e3 + 5;

struct Operation {
    int cnt;
    vector<int> curr;
    bitset<MAX> books;

    Operation(int n) {
        cnt = 0;
        curr.assign(n, 0);
        books.reset();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    int curr = 0;
    vector<Operation> operations(1, Operation(n));

    for (int i = 1; i <= q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int shelf, book;
            cin >> shelf >> book;
            shelf--; book--;

            operations.push_back(operations[curr]);
            operations[i].cnt = operations[operations[i].curr[shelf]].cnt;
            operations[i].books = operations[operations[i].curr[shelf]].books;

            if (!operations[i].books[book]) operations[i].cnt++;
            operations[i].books[book] = true;
            operations[i].curr[shelf] = i;
        } else if (op == 2) {
            int shelf, book;
            cin >> shelf >> book;
            shelf--; book--;

            operations.push_back(operations[curr]);
            operations[i].cnt = operations[operations[i].curr[shelf]].cnt;
            operations[i].books = operations[operations[i].curr[shelf]].books;

            if (operations[i].books[book]) operations[i].cnt--;
            operations[i].books[book] = false;
            operations[i].curr[shelf] = i;
        } else if (op == 3) {
            int shelf;
            cin >> shelf;
            shelf--;

            operations.push_back(operations[curr]);
            operations[i].cnt = m - operations[operations[i].curr[shelf]].cnt;
            operations[i].books = operations[operations[i].curr[shelf]].books;

            for (int j = 0; j < m; j++)
                operations[i].books[j] = !operations[i].books[j];

            operations[i].curr[shelf] = i;
        } else if (op == 4) {
            int k; cin >> k;
            operations.push_back(operations[k]);
        }

        int ans = 0;
        for (int j = 0; j < n; j++)
            ans += operations[operations[i].curr[j]].cnt;

        cout << ans << "\n";
        curr = i;
    }
}