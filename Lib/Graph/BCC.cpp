void get_bridges(int v = 0, int prev = -1) {
    vis[v] = true;
    tin[v] = low[v] = t++;

    for (auto [u, id]: g[v]) {
        if (u == prev) continue;

        if (vis[u]) low[v] = min(low[v], tin[u]);
        else {
            get_bridges(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > tin[v]) bridge[id] = true;
        }
    }
}

void get_cutpoints(int v = 0, int prev = -1) {
    vis[v] = true;
    tin[v] = low[v] = t++;

    int children = 0;
    for (int u: g[v]) {
        if (u == prev) continue;

        if (vis[u]) low[v] = min(low[v], tin[u]);
        else {
            children++;
            get_cutpoints(u, v);
            low[v] = min(low[v], low[u]);

            if (low[u] >= tin[v] && prev != -1)
                cutpoint[v] = true;
        }
    }

    if (prev == -1 && children > 1)
        cutpoint[v] = true;
}
