#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define Vector Point

int sign(llong x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Fraction {
    T num, den;

    Fraction(T num = 0, T den = 1) {
        assert(sign(den) != 0);

        if (sign(num) != sign(den) && sign(num) != 0 && sign(den) < 0) {
            num = -num;
            den = -den;
        }

        T g = gcd(abs(num), abs(den));
        this->num = num / g;
        this->den = den / g;
    }

    Fraction<T> operator-() const {
        return Fraction<T>(-num, den);
    }

    Fraction<T> operator +(Fraction<T> other) const {
        T nnum = num * other.den + other.num * den;
        T nden = den * other.den;

        return Fraction<T>(nnum, nden);
    }

    Fraction<T> operator -(Fraction<T> other) const {
        return *this + -other;
    }

    Fraction<T> operator *(Fraction<T> other) const {
        T nnum = num * other.num;
        T nden = den * other.den;
        return Fraction<T>(nnum, nden);
    }

    Fraction<T> operator /(Fraction<T> other) const {
        Fraction<T> iother = Fraction<T>(other.den, other.num);
        return *this * iother;
    }

    bool operator <(Fraction<T> const &other) const {
        return num * other.den < other.num * den;
    }

    bool operator ==(Fraction<T> const &other) const {
        return num * other.den == other.num * den;
    }

    bool is_integer() {
        return num % den == 0;
    }
};

template<typename T>
int sign(Fraction<T> f) {
    return sign(f.num);
}
template<typename T>
ostream& operator <<(ostream& cout, Fraction<T> f) {
    cout << f.num << "/" << f.den;
    return cout;
}

template<typename T>
struct Point {
    T x, y;

    Point<T>(T x = T(), T y = T()): x(x), y(y) {}

    Point<T> operator +(Vector<T> v) {
        return Point<T>(x + v.x, y + v.y);
    }

    Vector<T> operator -(Point<T> P) {
        return Vector<T>(x - P.x, y - P.y);
    }

    Vector<T> operator *(T k) {
        return Vector<T>(x * k, y * k);
    }

    T operator /(Vector<T> other) {
        return x * other.y - other.x * y;
    }

    bool operator <(Point<T> const &other) const {
        if (x == other.x)
            return y < other.y;

        return x < other.x;
    }

    bool operator ==(Point<T> const &other) const {
        return x == other.x && y == other.y;
    }
};

template<typename T>
ostream& operator <<(ostream& cout, Point<T> P) {
    cout << "(" << P.x << ", " << P.y << ")";
    return cout;
}

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
struct Segment {
    Point<T> A, B;

    Segment(Point<T> A = Point<T>(), Point<T> B = Point<T>()): A(A), B(B) {}

    bool operator <(Segment<T> const &other) const {
        if (A == other.A)
            return B < other.B;

        return A < other.A;
    }

    bool operator ==(Segment<T> const &other) const {
        return A == other.A && B == other.B;
    }

    bool is_point() {
        return A == B;
    }

    // Assumes there is intersection
    Segment<T> intersect(Segment<T> &other) {
        if (is_point()) return Segment(A, A);
        if (other.is_point()) return Segment(other.A, other.A);

        // cout << "Intersection between (" << A << ", " << B << ") and (" << other.A << ", " << other.B << "):\n";
        if ((B - A) / (other.A - A) == 0 && (B - A) / (other.B - A) == 0) {
            vector<Point<T>> points = { A, B, other.A, other.B };
            sort(points.begin(), points.end());

            return Segment(points[1], points[2]);
        }

        Vector<T> v = B - A, other_v = other.B - other.A;
        T t = ((other.A / other_v) + (other_v / A)) / (v / other_v);

        Point<T> P = A + v * t;
        return Segment(P, P);
    }
};

template<typename T>
struct Diamond {
    T x, y, d;

    Diamond() {}
    Diamond(T x, T y, T d): x(x), y(y), d(d) {}

    vector<Segment<T>> segments() {
        Point<T> A(x, y + d), B(x + d, y), C(x, y - d), D(x - d, y);
        return { Segment(A, B), Segment(B, C), Segment(C, D), Segment(D, A) };
    }
};

template<typename T>
vector<Segment<Fraction<T>>> integer_intersections(vector<Segment<Fraction<T>>> &segments, Diamond<Fraction<T>> &diamond) {
    vector<Segment<Fraction<T>>> diamond_segments = diamond.segments(), ans;
    for (auto s1: segments)
        for (auto s2: diamond_segments)
            if (seg_seg(s1.A, s1.B, s2.A, s2.B)) {
                Segment<Fraction<T>> s = s1.intersect(s2);
                if (!s.is_point() || (s.A.x.is_integer() && s.A.y.is_integer()))
                    ans.push_back(s);
            }

    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

template<typename T>
vector<Point<T>> integer_points(Segment<Fraction<T>> s) {
    assert(s.A.x.is_integer() && s.A.y.is_integer() && s.B.x.is_integer() && s.B.y.is_integer());

    if (s.is_point()) return { Point<T>(s.A.x.num, s.A.y.num) };

    Vector<Fraction<T>> v = s.B - s.A;
    T g = gcd(abs(v.x.num), abs(v.y.num));
    T dx = v.x.num / g, dy = v.y.num / g;

    vector<Point<T>> ans;
    T x = s.A.x.num, y = s.A.y.num;

    while (x != s.B.x.num && y != s.B.y.num) {
        ans.emplace_back(x, y);
        x += dx; y += dy;
    }

    ans.emplace_back(x, y);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    using IF = Fraction<int>;

    vector<Diamond<IF>> diamonds(N);
    for (int i = 0; i < N; i++) {
        int X, Y, D;
        cin >> X >> Y >> D;
        diamonds[i] = Diamond<IF>(IF(X), IF(Y), IF(D));
    }

    vector<Segment<IF>> intersections = diamonds[0].segments();
    for (int i = 1; i < N; i++)
        intersections = integer_intersections(intersections, diamonds[i]);

    vector<Point<int>> ans;
    for (Segment<IF> s: intersections) {
        vector<Point<int>> points = integer_points(s);
        for (Point<int> P: points) ans.push_back(P);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto [x, y]: ans)
        cout << x << " " << y << "\n";
}