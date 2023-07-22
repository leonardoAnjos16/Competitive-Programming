template<typename T = llong>
bool inside(vector<Point<T>> &vertices, Point<T> P) {
    int n = vertices.size();
    for (int i = 0; i < n; i++)
        if (left_turn(vertices[(i + 1) % n] - vertices[i], P - vertices[i]))
            return false;

    return true;
}

template<typename T = llong>
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

template<typename T = llong>
vector<Point<T>> convex_hull(vector<Point<T>> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<Point<T>> hull = half_hull(points, 0, n, 1);
    vector<Point<T>> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}

template<typename T>
int max_dot_product(vector<Point<T>> &hull, Vector<T> v) {
    int n = hull.size();
    if (n < 3) {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (hull[i] * v > hull[ans] * v)
                ans = i;

        return ans;
    }

    int ans = 0;
    if (hull[1] * v > hull[ans] * v)
        ans = 1;

    for (int i = 0; i < 2; i++) {
        int l = 2, r = n - 1;
        while (l != r) {
            int mid = (l + r + 1) / 2;

            bool check = hull[mid] * v >= hull[mid - 1] * v;
            if (!i) check &= hull[mid] * v >= hull[0] * v;
            else check |= hull[mid - 1] * v < hull[0] * v;

            if (check) l = mid;
            else r = mid - 1;
        }

        if (hull[l] * v > hull[ans] * v)
            ans = l;
    }

    return ans;
}

template<typename T = llong>
T area(Point<T> A, Point<T> B, Point<T> C) {
    return (B - A) / (C - B);
}

template<typename T = llong>
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