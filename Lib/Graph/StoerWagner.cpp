template<typename T>
T min_cut(int n, vector<vector<T>> g, bool weighted = true) {
    T ans = numeric_limits<T>::max();
    for (int i = 1; i < n; i++) {
        vector<T> w(n, 0);
        vector<bool> vis(n, false);

        T cut;
        int curr = 0, prev;

        for (int j = 0; j < n - i; j++) {
            vis[curr] = true;
            int nxt = -1;
            cut = 0;

            for (int k = 0; k < n; k++) {
                w[k] += g[curr][k];
                if (!vis[k] && w[k] > cut)
                    nxt = k, cut = w[k];
            }

            prev = curr;
            curr = nxt;
        }

        if (!weighted) return cut;
        ans = min(ans, cut);

        for (int j = 0; j < n; j++) {
            if (j != prev) {
                g[prev][j] += g[curr][j];
                g[j][prev] += g[j][curr];
            }

            g[curr][j] = 0;
        }
    }

    return ans;
}