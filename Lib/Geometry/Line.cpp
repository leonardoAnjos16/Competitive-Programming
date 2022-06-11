struct Line {
    Point P;
    Vector v;

    Line(Point P, Point Q) {
        if (Q < P) swap(P, Q);
        this->P = P;
        v = Q - P;
    }

    pair<Point, bool> intersection(Line &other) {
        long double den = v ^ other.v;
        if (zero(den)) return make_pair(Point(), false);

        long double t = ((other.P - P) ^ other.v) / den;
        return make_pair(P + v * t, true);
    }

    bool contains(Point Q) {
        return zero((Q - P) ^ v);
    }
};