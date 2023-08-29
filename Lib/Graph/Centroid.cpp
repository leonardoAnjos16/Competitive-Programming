pair<int, int> centroids(int node = 0, int parent = -1) {
    for (int child: tree[node])
        if (child != parent && 2 * sz[child] > n)
            return centroids(child, node);

    for (int child: tree[node])
        if (child != parent && 2 * sz[child] == n)
            return make_pair(node, child);

    return make_pair(node, node);
}

void get_size(int node, int p = -1) {
    sz[node] = 1;
    for (int child: tree[node])
        if (child != p && !rem[child]) {
            get_size(child, node);
            sz[node] += sz[child];
        }
}

int centroid(int size, int node, int p = -1) {
    for (int child: tree[node])
        if (child != p && !rem[child] && 2 * sz[child] > size)
            return centroid(size, child, node);

    return node;
}

int decompose(int node = 0) {
    get_size(node);
    int c = centroid(sz[node], node);

    rem[c] = true;
    for (int child: tree[c])
        if (!rem[child])
            cparent[decompose(child)] = c;

    return c;
}
