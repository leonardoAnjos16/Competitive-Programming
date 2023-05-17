template<const int D, typename T>
struct XorGauss {
private:
    T basis[D];

public:
    XorGauss() {
        memset(basis, 0, sizeof basis);
    }

    bool add(T x) {
        for (int i = D - 1; i >= 0; i--) {
            if (!(x & (1LL << i))) continue;

            if (basis[i]) x ^= basis[i];
            else {
                basis[i] = x;
                return true;
            }
        }

        return false;
    }

    T reduce(T x) {
        for (int i = D - 1; i >= 0; i--)
            x = min(x, x ^ basis[i]);
    }

    T augment(T x) {
        return ~reduce(~x);
    }
};