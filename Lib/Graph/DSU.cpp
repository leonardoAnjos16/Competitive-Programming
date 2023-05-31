struct DSU {
private:
    int n;
    vector<int> ds, sz;

public:
    DSU(int n) {
        this->n = n;
        ds.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; i++)
            ds[i] = i, sz[i] = 1;
    }

    int find(int i) {
        if (ds[i] == i) return i;
        return ds[i] = find(ds[i]);
    }

    void join(int i, int j) {
        i = find(i); j = find(j);
        if (sz[i] < sz[j]) swap(i, j);
        if (i != j) sz[i] += sz[j];
        ds[j] = i;
    }
};

struct PersistentDSU {
private:
    int n;
    vector<int> ds, sz, tm;

public:
    PersistentDSU(int n) {
        this->n = n;
        sz.assign(n, 1);
        tm.assign(n, 0);

        ds.resize(n);
        iota(ds.begin(), ds.end(), 0);
    }

    int find(int i, int t = INT_MAX) {
        if (ds[i] == i || tm[i] > t) return i;
        return find(ds[i], t);
    }

    void join(int i, int j, int t) {
        i = find(i); j = find(j);
        if (i == j) return;

        if (sz[i] > sz[j]) swap(i, j);
        sz[j] += sz[i];
        ds[i] = j;
        tm[i] = t;
    }
};