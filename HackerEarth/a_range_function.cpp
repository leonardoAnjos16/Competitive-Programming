#include <bits/stdc++.h>

using namespace std;

#define long __int128

struct Node {
    array<long, 4> coeffs;

    Node() {
        for (int i = 0; i < 4; i++)
            coeffs[i] = 0LL;
    }

    Node(long a, long b, long c, long d) {
        coeffs[0] = a;
        coeffs[1] = b;
        coeffs[2] = c;
        coeffs[3] = d;
    }

    Node operator +(Node other) {
        Node ans;
        for (int i = 0; i < 4; i++)
            ans.coeffs[i] = coeffs[i] + other.coeffs[i];

        return ans;
    }

    Node operator *(int c) {
        Node ans;
        for (int i = 0; i < 4; i++)
            ans.coeffs[i] = coeffs[i] * c;

        return ans;
    }
};

struct SegmentTree {
private:
    int n;
    vector<int> a;
    vector<Node> tree;

public:
    SegmentTree(vector<int> &a) {
        this->a = a;
        this->n = a.size();
        tree.resize(4 * n);
        build(1, 1, n);
    }

    void update(int i, long v) {
        return update(1, 1, n, i, v);
    }

    long query(int l, int r) {
        Node node = query(1, 1, n, l, r);

        long ans = node.coeffs[0] * l * r;
        ans += node.coeffs[1] * l;
        ans += node.coeffs[2] * r;
        ans += node.coeffs[3];

        return ans;
    }

private:
    int left(int i) {
        return 2 * i;
    }

    int right(int i) {
        return 2 * i + 1;
    }

    void build(int i, int l, int r) {
        if (l == r) tree[i] = Node(-1LL, l - 1LL, l + 1LL, -(l + 1LL) * (l - 1LL)) * a[l - 1];
        else {
            int m = (l + r) / 2;
            build(left(i), l, m);
            build(right(i), m + 1, r);
            tree[i] = tree[left(i)] + tree[right(i)];
        }
    }

    void update(int i, int l, int r, int j, int v) {
        if (j < l || j > r) return;

        if (l == r) {
            a[l - 1] = v;
            tree[i] = Node(-1LL, l - 1LL, l + 1LL, -(l + 1LL) * (l - 1LL)) * a[l - 1];
        } else {
            int m = (l + r) / 2;
            update(left(i), l, m, j, v);
            update(right(i), m + 1, r, j, v);
            tree[i] = tree[left(i)] + tree[right(i)];
        }
    }

    Node query(int i, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return Node();
        if (ql <= l && r <= qr) return tree[i];

        int m = (l + r) / 2;
        Node left_ans = query(left(i), l, m, ql, qr);
        Node right_ans = query(right(i), m + 1, r, ql, qr);
        return left_ans + right_ans;
    }
};

string to_string(long n) {
    string ans = "";
    while (n) {
        char d = n % 10 + '0';
        ans += d;
        n /= 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        SegmentTree tree(A);

        int Q; cin >> Q;
        while (Q--) {
            int op; cin >> op;
            if (op == 1) {
                int i, val;
                cin >> i >> val;
                tree.update(i, val);
            } else {
                int L, R;
                cin >> L >> R;

                long ans = tree.query(L, R);
                cout << to_string(ans) << "\n";
            }
        }
    }
}