//
// Created by jiang-ziyang on 22-7-4.
//

#ifndef MAIN_CPP_FUNCTION_H
#define MAIN_CPP_FUNCTION_H

#include <cmath>

struct quadratic_params
{
    double a, b, c;
};
double quadratic (double , void *);
double quadratic_deriv (double , void *);
void quadratic_fdf (double , void *,
                    double *, double *);

#endif //MAIN_CPP_FUNCTION_H
