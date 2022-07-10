void extended_euclidean(llong a, llong b, llong &x, llong &y) {
    if (!b) {
        x = 1LL;
        y = 0LL;
    } else {
        extended_euclidean(b, a % b, x, y);
        llong aux = x; x = y;
        y = aux - a / b * y;
    }
}

llong mod_mult_inv(llong a, llong m) {
    llong x, y;
    extended_euclidean(a, m, x, y);
    return (x % m + m) % m;
}