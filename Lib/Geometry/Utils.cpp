const long double EPS = 1e-6;

bool zero(long double n) {
    return fabsl(n) <= EPS;
}

bool positive(long double n) {
    return n > EPS;
}

bool negative(long double n) {
    return n < -EPS;
}