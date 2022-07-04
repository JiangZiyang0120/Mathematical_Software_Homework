//
// Created by jiang-ziyang on 22-7-4.
//

#ifndef MAIN_CPP_FUNCTION_H
#define MAIN_CPP_FUNCTION_H

#include <cmath>

struct quadratic_params{
    double a;
};

double exp_quadratic(double x, void *params);
double exp_quadratic_deriv(double x, void *params);
void exp_quadratic_fdf(double x);

double sqrt_quadratic(double x, void *params);
double sqrt_quadratic_deriv(double x, void *params);
void sqrt_quadratic_fdf(double x);

#endif //MAIN_CPP_FUNCTION_H
