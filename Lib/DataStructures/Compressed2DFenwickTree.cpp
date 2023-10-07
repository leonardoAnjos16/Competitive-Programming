template<typename T1, typename T2>
struct Compressed2DFenwickTree {
private:
    int n;
    vector<T1> xs;
    vector<vector<T1>> ys;
    vector<vector<T2>> trees;

public:
    Compressed2DFenwickTree(vector<pair<T1, T1>> points) {
        for (auto [x, _]: points)
            xs.push_back(x);

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        n = (int) xs.size() + 1;
        ys.assign(n, vector<T1>());

        for (auto &[x, y]: points)
            swap(x, y);

        sort(points.begin(), points.end());
        for (auto &[x, y]: points) {
            swap(x, y);

            int i = get_index(xs, x);
            while (i < n) {
                if (ys[i - 1].empty() || ys[i - 1].back() != y)
                    ys[i - 1].push_back(y);

                i += LSO(i);
            }
        }

        trees.resize(n);
        for (int i = 1; i < n; i++) {
            int m = (int) ys[i - 1].size() + 1;
            trees[i].assign(m, 0);
        }
    }

    void add(T1 x, T1 y, T2 v) {
        int i = get_index(xs, x);
        while (i < n) {
            int j = get_index(ys[i - 1], y);
            while (j < (int) trees[i].size()) {
                trees[i][j] += v;
                j += LSO(j);
            }

            i += LSO(i);
        }
    }

    T2 sum(T1 x1, T1 y1, T1 x2, T1 y2) {
        return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    }

private:
    int get_index(vector<T1> &values, T1 v, bool upper = false) {
        if (upper) return upper_bound(values.begin(), values.end(), v) - values.begin();
        return lower_bound(values.begin(), values.end(), v) - values.begin() + 1;
    }

    int LSO(int i) {
        return i & -i;
    }

    T2 sum(T1 x, T1 y) {
        T2 ans = 0;
        int i = get_index(xs, x, true);

        while (i) {
            int j = get_index(ys[i - 1], y, true);
            while (j) {
                ans += trees[i][j];
                j -= LSO(j);
            }

            i -= LSO(i);
        }

        return ans;
    }
};