#include <stdio.h>
#include <math.h>

#define EPS 1e-10

int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    
    double dis = b * b - 4 * a * c;
    
    if (dis < -EPS) 
        return 0;
    
    else if (fabs(dis) < EPS) 
    {
        *px1 = -b / (2 * a);
        return 1; 
    }
    
    double sqrt_dis = sqrt(dis);
    *px1 = (-b - sqrt_dis) / (2 * a);
    *px2 = (-b + sqrt_dis) / (2 * a);
    return 2; 
}

int main() 
{
    double x1, x2;
    
    int result = solve_quadratic(1, 7, 12, &x1, &x2);
    printf("x^2+7x+12: %i корня, x1=%.2f, x2=%.2f\n", result, x1, x2);
    
    result = solve_quadratic(1, -4, 4, &x1, &x2);
    printf("x^2-4x+4: %i корня, x1=%.2f\n", result, x1);
}