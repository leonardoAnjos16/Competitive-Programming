#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define Vector Point

const ldouble EPS = 1e-9;

int sign(ldouble x) {
    return fabsl(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    Point<T> operator +(Vector<T> v) {
        return Point<T>(x + v.x, y + v.y);
    }

    Vector<T> operator -(Point<T> other) {
        return Vector<T>(x - other.x, y - other.y);
    }

    Vector<T> operator *(T k) {
        return Vector<T>(x * k, y * k);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }
};

template<typename T>
ldouble abs(Vector<T> v) {
    return sqrtl(v * v);
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int Ax, Ay, Bx, By, D;
    cin >> Ax >> Ay >> Bx >> By >> D;

    Point<ldouble> A(Ax, Ay), B(Bx, By);
    if (Ax == Bx && Ay == By && !D) cout << "NO\n";
    else {
        vector<Point<ldouble>> intersections = circle_circle(A, 1.0L * D, B, abs(B - A));
        if ((int) intersections.size() != 2) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < 2; i++) {
                if (i) cout << " ";
                cout << intersections[i].x << " " << intersections[i].y;
            }

            cout << "\n";
        }
    }
}