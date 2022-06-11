#define Vector Point

struct Point {
    long double x, y;

    Point(): x(0.0L), y(0.0L) {}
    Point(long double x, long double y): x(x), y(y) {}

    Vector operator -() {
        return Vector(-x, -y);
    }

    Point operator +(Vector v) {
        return Point(x + v.x, y + v.y);
    }

    Vector operator -(Point other) {
        return Point(x - other.x, y - other.y);
    }

    Vector operator *(long double k) {
        return Vector(x * k, y * k);
    }

    long double operator ^(Vector &other) {
        return x * other.y - y * other.x;
    }

    bool operator <(const Point &other) const {
        if (zero(x - other.x))
            return negative(y - other.y);

        return negative(x - other.x);
    }
};

bool right_turn(Vector &u, Vector &v) {
    return negative(u ^ v);
}