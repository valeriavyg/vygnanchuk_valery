#include <stdio.h>
#include <math.h>

#define STEP 1e-2
#define EPS 1e-10

double gamma(double x)
{
    double result = 0.0;
    double prev_area = 0.0;
    double t = 0.0;
    while (1)
    {
        double f_current = pow(t, x-1) * exp(-t);
        double f_next = pow(t + STEP, x-1) * exp(-(t + STEP));
        double area = (f_current + f_next) * STEP / 2.0;
        if (area < EPS && t > 10.0) 
            break;
        result += area;
        t += STEP;
        }
    return result;
}
int main()
{
    double x;
    scanf("%lf", &x);
    printf("%.6f\n", gamma(x));
}