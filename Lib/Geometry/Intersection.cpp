template<typename T>
struct Line {
    Point<T> P;
    Vector<T> v;

    Line(Point<T> P, Vector<T> v): P(P), v(v) {}

    pair<Point<T>, bool> intersection(Line<T> other) {
        T den = v / other.v;
        if (!sign(den)) return make_pair(Point<T>(), false);

        T t = ((other.P - P) / other.v) / den;
        return make_pair(P + v * t, true);
    }
};

template<typename T>
bool intersect(T a, T b, T c, T d) {
    if (sign(a - b) > 0) swap(a, b);
    if (sign(c - d) > 0) swap(c, d);
    return sign(max(a, c) - min(b, d)) <= 0;
}

template<typename T>
bool seg_seg(Point<T> A, Point<T> B, Point<T> C, Point<T> D) {
    Vector<T> CA = A - C, CB = B - C, CD = D - C;
    if (!sign(CA / CD) && !sign(CB / CD))
        return intersect(A.x, B.x, C.x, D.x) && intersect(A.y, B.y, C.y, D.y);

    Vector<T> AB = B - A, AC = C - A, AD = D - A;
    return sign(AB / AC) != sign(AB / AD) && sign(CA / CD) != sign(CB / CD);
}

template<typename T>
vector<Point<T>> circle_line(Point<T> C, T r, Point<T> A, Point<T> B) {
    Point<T> P = proj_line(C, A, B);
    ldouble dist = abs(P - C);

    vector<Point<T>> intersections;
    if (!sign(dist - r)) intersections.push_back(P);
    else if (sign(dist - r) < 0) {
        Vector<T> v = B - A;
        ldouble t = sqrtl(r * r - dist * dist);

        intersections.push_back(P + v * (t / abs(v)));
        intersections.push_back(P - v * (t / abs(v)));
    }

    return intersections;
}

template<typename T>
vector<Point<T>> circle_seg(Point<T> C, T r, Point<T> A, Point<T> B) {
    vector<Point<T>> intersections = circle_line(C, r, A, B), nintersections;
    for (Point<T> P: intersections)
        if (between(P, A, B))
            nintersections.push_back(P);

    return nintersections;
}

template<typename T>
vector<Point<T>> circle_circle(Point<T> C1, T r1, Point<T> C2, T r2) {
    if (sign(r1 - r2) > 0) {
        swap(C1, C2);
        swap(r1, r2);
    }

    Vector<T> v = C2 - C1;
    if (sign(abs(v) - r1 - r2) > 0 || sign(abs(v) - r2 + r1) < 0)
        return vector<Point<T>>();

    assert(sign(v.x) || sign(v.y));

    Point<T> A, B;
    T num = v * v - r2 * r2 + r1 * r1;

    if (!sign(v.x)) {
        A = Point<T>(0, num / 2 / v.y);
        B = Point<T>(1, num / 2 / v.y);
    } else if (!sign(v.y)) {
        A = Point<T>(num / 2 / v.x, 0);
        B = Point<T>(num / 2 / v.x, 1);
    } else {
        A = Point<T>(0, num / 2 / v.y);
        B = Point<T>(num / 2 / v.x, 0);
    }

    vector<Point<T>> intersections = circle_line(Point<T>(), r1, A, B);
    for (Point<T> &P: intersections) P = P + C1;
    return intersections;
}
