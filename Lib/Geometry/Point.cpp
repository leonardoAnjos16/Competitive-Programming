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
