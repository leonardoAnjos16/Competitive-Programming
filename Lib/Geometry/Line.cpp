template<typename T = long>
struct Line {
    Point<T> P;
    Vector<T> v;

    Line(Point<T> P, Point<T> Q) {
        if (Q < P) swap(P, Q);
        this->P = P;
        v = Q - P;
    }

    pair<Point<T>, bool> intersection(Line<T> other) {
        T den = v / other.v;
        if (!sign(den)) return make_pair(Point<T>(), false);

        T t = ((other.P - P) / other.v) / den;
        return make_pair(P + v * t, true);
    }

    bool contains(Point<T> Q) {
        return !sign((Q - P) / v);
    }
};

template<typename T = long>
bool intersect(T a, T b, T c, T d) {
    if (sign(a - b) > 0) swap(a, b);
    if (sign(c - d) > 0) swap(c, d);
    return sign(max(a, c) - min(b, d)) <= 0;
}

template<typename T = long>
bool seg_seg(Point<T> A, Point<T> B, Point<T> C, Point<T> D) {
    Vector<T> CA = A - C, CB = B - C, CD = D - C;
    if (!sign(CA / CD) && !sign(CB / CD))
        return intersect(A.x, B.x, C.x, D.x) && intersect(A.y, B.y, C.y, D.y);

    Vector<T> AB = B - A, AC = C - A, AD = D - A;
    return sign(AB / AC) != sign(AB / AD) && sign(CA / CD) != sign(CB / CD);
}