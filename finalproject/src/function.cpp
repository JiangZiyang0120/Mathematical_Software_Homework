//
// Created by jiang-ziyang on 22-7-4.
//

#include "function.h"
double sqrt_quadratic(double x, void *params){
    double a = *(double *)params;
    return sqrt(x) - a;
}

double sqrt_quadratic_deriv(double x, void *params){
    return 1/(2*sqrt(x));
}

void sqrt_quadratic_fdf(double x, void * params, double *y, double *dy){
    double a = *(double *)params;
    double sx = sqrt(x);
    *y = sx - a;
    *dy = 1/(2*sx);
}

double
quadratic (double x, void *params)
{
    struct quadratic_params *p
            = (struct quadratic_params *) params;
    double a = p->a;
    double b = p->b;
    double c = p->c;
    return (a * x + b) * x + c;
}
double
quadratic_deriv (double x, void *params)
{
    struct quadratic_params *p
            = (struct quadratic_params *) params;
    double a = p->a;
    double b = p->b;
    return 2.0 * a * x + b;
}
void
quadratic_fdf (double x, void *params,
               double *y, double *dy)
{
    struct quadratic_params *p
            = (struct quadratic_params *) params;
    double a = p->a;
    double b = p->b;
    double c = p->c;
    *y = (a * x + b) * x + c;
    *dy = 2.0 * a * x + b;
}