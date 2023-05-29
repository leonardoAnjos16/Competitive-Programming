llong inversions(vector<int> &a) {
    int n = a.size();

    llong ans = 0LL;
    FenwickTree tree(n);

    for (int i = 0; i < n; i++) {
        ans += tree.sum(a[i], n);
        tree.add(a[i], 1);
    }

    return ans;
}

llong inversions(vector<int> &a, vector<int> &b) {
    int n = a.size();

    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[a[i] - 1] = i;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        c[i] = pos[b[i] - 1];

    return inversions(c);
}
