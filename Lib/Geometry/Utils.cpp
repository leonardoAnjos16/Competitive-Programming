const long double EPS = 1e-6;

int sign(llong x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

int sign(long double x) {
    return fabsl(x) <= EPS ? 0 : (x < -EPS ? -1 : 1);
}
