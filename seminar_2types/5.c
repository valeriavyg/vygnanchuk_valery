#include <stdio.h>
#include <math.h>

#define MIN 1e-5

int main()
{
    double x1, y1, r1, x2, y2, r2;

    scanf("%lf %lf %lf", &x1, &y1, &r1);
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(dx*dx + dy*dy);
    double sum = r1 + r2;
    double diff = fabs(r1 - r2);
    
    if (d > sum + MIN) {
        printf("Do not intersect\n");
    } else if (d < diff - MIN) {
        printf("Do not intersect\n");
    } else if (fabs(d - sum) < MIN || fabs(d - diff) < MIN) {
        printf("Touch\n");
    } else {
        printf("Intersect\n");
    }
}