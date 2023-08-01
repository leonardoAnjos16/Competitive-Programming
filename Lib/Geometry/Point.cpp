#define Vector Point

template<typename T>
struct Point {
    T x, y;

    Point(T x = 0, T y = 0): x(x), y(y) {}

    Vector<T> operator -() {
        return Vector<T>(-x, -y);
    }

    Point<T> operator +(Vector<T> v) {
        return Point<T>(x + v.x, y + v.y);
    }

    Vector<T> operator -(Point<T> other) {
        return Point<T>(x - other.x, y - other.y);
    }

    Vector<T> operator *(T k) {
        return Vector<T>(x * k, y * k);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }

    template<typename U>
    operator Point<U>() const {
        return Point<U>(U(x), U(y));
    }

    bool operator <(const Point<T> &other) const {
        if (!sign(x - other.x))
            return sign(y - other.y) < 0;

        return sign(x - other.x) < 0;
    }
};

template<typename T>
long double abs(Vector<T> v) {
    return sqrtl(v * v);
}

template<typename T>
long double angle(Vector<T> u, Vector<T> v) {
    return acosl(u * v / abs(u) / abs(v));
}

template<typename T>
bool left_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) > 0;
}

template<typename T>
bool right_turn(Vector<T> u, Vector<T> v) {
    return sign(u / v) < 0;
}

template<typename T>
long double oriented_angle(Vector<T> u, Vector<T> v) {
    if (!right_turn(u, v)) return angle(u, v);
    return 2 * PI - angle(u, v);
}

template<typename T>
Vector<T> proj(Vector<T> u, Vector<T> v) {
    return v * ((u * v) / (v * v));
}

template<typename T>
Point<T> proj_line(Point<T> P, Point<T> A, Point<T> B) {
    Vector<T> u = P - A, v = B - A;
    return A + proj(u, v);
}

template<typename T>
Vector<ldouble> rotate(Vector<T> v, ldouble theta) {
    return Vector<ldouble>(v.x * cosl(theta) - v.y * sinl(theta), v.x * sinl(theta) + v.y * cosl(theta));
}

template<typename T>
Vector<ldouble> bisect(Vector<T> u, Vector<T> v) {
    ldouble theta = angle(u, v);
    return left_turn(u, v) ? rotate(u, theta / 2.0L) : rotate(v, theta / 2.0L);
}

template<typename T>
pair<Point<ldouble>, ldouble> incircle(Point<T> A, Point<T> B, Point<T> C) {
    Vector<T> AB = B - A, BC = C - B, CA = A - C;
    ldouble a = abs(AB), b = abs(BC), c = abs(CA), s = (a + b + c) / 2.0L;
    ldouble r = sqrtl(s - a) * sqrtl(s - b) * sqrtl(s - c) / sqrtl(s);

    Vector<ldouble> u = bisect(AB, C - A);
    Line<ldouble> l(A, u);

    Vector<ldouble> v = bisect(BC, A - B);
    Line<ldouble> m(B, v);

    auto [P, has_intersection] = l.intersection(m);
    assert(has_intersection);
    return make_pair(P, r);
}

// Checks if P lies inside segment AB (assuming it lies inside line AB)
template<typename T>
bool between(Point<T> P, Point<T> A, Point<T> B) {
    auto [lx, rx] = minmax(A.x, B.x);
    auto [ly, ry] = minmax(A.y, B.y);
    return sign(lx - P.x) <= 0 && sign(P.x - rx) <= 0 && sign(ly - P.y) <= 0 && sign(P.y - ry) <= 0;
}

template<typename T>
bool k_lines(vector<Point<T>> points, int k) {
    if (!k) return points.empty();
    if ((int) points.size() <= k) return true;

    for (int i = 0; i <= k; i++)
        for (int j = i + 1; j <= k; j++) {
            vector<Point<T>> rem;
            for (Point<T> P: points)
                if ((P - points[i]) / (points[j] - points[i]))
                    rem.push_back(P);

            if (k_lines(rem, k - 1)) return true;
        }

    return false;
}
