template<typename T = long>
bool inside(vector<Point<T>> &vertices, Point<T> P) {
    int n = vertices.size();
    for (int i = 0; i < n; i++)
        if (left_turn(vertices[(i + 1) % n] - vertices[i], P - vertices[i]))
            return false;

    return true;
}

template<typename T = long>
vector<Point<T>> half_hull(vector<Point<T>> &points, int l, int r, int d) {
    vector<Point<T>> hull;
    for (int i = l; i != r; i += d) {
        int size = hull.size();
        while (size > 1 && !right_turn(hull[size - 1] - hull[size - 2], points[i] - hull[size - 2]))
            hull.pop_back(), size--;

        hull.push_back(points[i]);
    }

    return hull;
}

template<typename T = long>
vector<Point<T>> convex_hull(vector<Point<T>> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<Point<T>> hull = half_hull(points, 0, n, 1);
    vector<Point<T>> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}

template<typename T = long>
T area(Point<T> A, Point<T> B, Point<T> C) {
    return (B - A) / (C - B);
}

template<typename T = long>
long double area(vector<Point<T>> &points) {
    Point<T> O(0, 0);
    int n = points.size();

    T ans = 0;
    for (int i = 0; i < n; i++) {
        Point<T> P = points[i], Q = points[(i + 1) % n];
        ans += area(O, P, Q);
    }

    return ans / 2.0L;
}