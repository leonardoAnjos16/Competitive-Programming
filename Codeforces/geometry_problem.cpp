#include <bits/stdc++.h>

using namespace std;

#define M_PI 3.14159265358979323846

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        double r1, r2;
        scanf("%lf %lf", &r1, &r2);

        double width = r1 + r2;
        double hypo = sqrt((r1 * r1) + (width * width));

        double a = asin(r1 / hypo);
        double b = (M_PI / 2) - a;
        double c = M_PI - (2 * b);
        double d = (M_PI / 2) - c;

        double total_area = r1 * width / 2;
        double right_area = r2 * r2 * a / 2;
        double lower_left_area = r1 * r1 * d / 2;

        double upper_left_base = sqrt(2 * r1 * r1 * (1 - cos(c)));

        double cat = upper_left_base / 2;
        double upper_left_height = sqrt((r1 * r1) - (cat * cat));

        double upper_left_area = upper_left_base * upper_left_height / 2;
        double area = total_area - upper_left_area - lower_left_area - right_area;

        printf("%.10lf\n", area);
    }
}