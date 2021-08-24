void extended_euclidean(long a, long b, long &x, long &y) {
    if (!b) {
        x = 1LL;
        y = 0LL;
    } else {
        extended_euclidean(b, a % b, x, y);
        long aux = x; x = y;
        y = aux - a / b * y;
    }
}

long mod_mult_inv(long a, long m) {
    long x, y;
    extended_euclidean(a, m, x, y);
    return (x % m + m) % m;
}