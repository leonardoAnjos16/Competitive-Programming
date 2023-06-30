template<const char op, class T>
vector<T> FWHT(vector<T> a, const bool inv = false) {
    int n = a.size();
    for (int len = 1; len < n; len += len)
        for (int i = 0; i < n; i += 2 * len)
            for (int j = 0; j < len; j++) {
                T u = a[i + j], v = a[i + j + len];
                if (op == '^') {
                    a[i + j] = u + v;
                    a[i + j + len] = u - v;
                } else if (op == '|') {
                    if (!inv) a[i + j + len] += a[i + j];
                    else a[i + j + len] -= a[i + j];
                } else if (op == '&') {
                    if (!inv) a[i + j] += a[i + j + len];
                    else a[i + j] -= a[i + j + len];
                }
            }

    if (op == '^' && inv)
        for (int i = 0; i < n; i++)
            a[i] = a[i] / n;

    return a;
}

int next_power_of_two(int n) {
    int bits = 0;
    while (n) {
        bits++;
        n >>= 1;
    }

    return 1 << (bits + 1);
}

template<const char op, typename T>
vector<T> bitwise_convolution(vector<T> a, vector<T> b) {
    int na = a.size(), nb = b.size();
    int sz = next_power_of_two(na + nb);

    a.resize(sz, 0);
    b.resize(sz, 0);

    a = FWHT<op, T>(a);
    b = FWHT<op, T>(b);

    vector<T> c(sz, 0);
    for (int i = 0; i < sz; i++)
        c[i] = a[i] * b[i];

    return FWHT<op, T>(c, true);
}