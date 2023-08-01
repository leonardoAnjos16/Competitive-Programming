vector<pair<int, int>> floor_ranges(int n) {
    vector<pair<int, int>> ranges;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ranges.emplace_back(l, r);
    }

    return ranges;
}

vector<pair<int, int>> ceil_ranges(int n) {
    vector<pair<int, int>> ranges;
    for (int l = 1, r; l <= n; l = r + 1) {
        int x = (n + l - 1) / l;
        if (x == 1) r = n;
        else r = (n - 1) / (x - 1);

        ranges.emplace_back(l, r);
    }

    return ranges;
}