//
// Created by jiang-ziyang on 22-7-4.
//

//方便起见，我们用参数不同的幂函数和开方函数来测试收敛性
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_roots.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include "function.h"

using namespace std;

void dic_a_test(){
    int status;
    int iter = 0, max_iter = 100;
    const gsl_root_fsolver_type *T;
    gsl_root_fsolver *s;
    double r = 0, r_expected = sqrt (9999);
    double x_lo = 0.0, x_hi = 9999;
    gsl_function F;
    struct quadratic_params params = {1.0, 0.0, -9999};
    F.function = &quadratic;
    F.params = &params;
    T = gsl_root_fsolver_brent;
    s = gsl_root_fsolver_alloc (T);
    gsl_root_fsolver_set (s, &F, x_lo, x_hi);
    printf ("using %s method\n",
            gsl_root_fsolver_name (s));
    printf ("%5s [%9s, %9s] %9s %10s %9s\n",
            "iter", "lower", "upper", "root",
            "err", "err(est)");
    do
    {
        iter++;
        status = gsl_root_fsolver_iterate (s);
        r = gsl_root_fsolver_root (s);
        x_lo = gsl_root_fsolver_x_lower (s);
        x_hi = gsl_root_fsolver_x_upper (s);
        status = gsl_root_test_interval (x_lo, x_hi,
                                         0, 0.001);
        if (status == GSL_SUCCESS)
            printf ("Converged:\n");
        printf ("%5d [%.7f , %.7f ] %.7f %+.7f %.7f \n",
                iter, x_lo, x_hi,
                r, r - r_expected,
                x_hi - x_lo);
    }
    while (status == GSL_CONTINUE && iter < max_iter);
    gsl_root_fsolver_free (s);
}

vector<int> dic_test() {
    int status;
    int iter = 0, max_iter = 100;
    const gsl_root_fsolver_type *T;
    gsl_root_fsolver *s;
    double x_lo = 0.0, x_hi = 0;
    gsl_function F;
    F.function = &quadratic;
    T = gsl_root_fsolver_brent;
    s = gsl_root_fsolver_alloc(T);
    vector<int> item_vector;
    item_vector.reserve(10000);
    clock_t start = clock();
    for (int i = 1; i != 10001; ++i) {
        struct quadratic_params params = {1.0, 0.0, -static_cast<double >(i)};
        F.params = &params;
        x_hi = static_cast<double >(i);
        gsl_root_fsolver_set(s, &F, x_lo, x_hi);
        iter = 0;
        do {
            iter++;
            status = gsl_root_fsolver_iterate(s);
            x_lo = gsl_root_fsolver_x_lower(s);
            x_hi = gsl_root_fsolver_x_upper(s);
            status = gsl_root_test_interval(x_lo, x_hi,
                                            1e-3, 1e-3);
            if (status == GSL_SUCCESS)
                break;
        } while (status == GSL_CONTINUE && iter < max_iter);
        item_vector.push_back(iter);
    }
    clock_t end = clock();
    cout << "10000次二分法迭代用时为" << end - start << "毫秒" << endl;
    return item_vector;
}

vector<int> new_test() {
    int status;
    int iter = 0, max_iter = 100;
    const gsl_root_fdfsolver_type *T;
    gsl_root_fdfsolver *s;
    double x0, x = 0;
    gsl_function_fdf FDF;
    FDF.f = &quadratic;
    FDF.df = &quadratic_deriv;
    FDF.fdf = &quadratic_fdf;
    T = gsl_root_fdfsolver_newton;
    s = gsl_root_fdfsolver_alloc(T);
    vector<int> item_vector;
    item_vector.reserve(10000);
    clock_t start = clock();
    for (int i = 1; i != 10001; ++i) {
        x = static_cast<double >(i);
        x0 = x;
        iter = 0;
        struct quadratic_params params = {1.0, 0.0, -static_cast<double >(i)};
        FDF.params = &params;
        gsl_root_fdfsolver_set(s, &FDF, x);
        do {
            iter++;
            status = gsl_root_fdfsolver_iterate(s);
            x0 = x;
            x = gsl_root_fdfsolver_root(s);
            status = gsl_root_test_delta(x, x0, 1e-3, 1e-3);
            if (status == GSL_SUCCESS)
                break;
        } while (status == GSL_CONTINUE && iter < max_iter);
        item_vector.push_back(iter);
    }
    gsl_root_fdfsolver_free(s);
    clock_t end = clock();
    cout << "10000次牛顿法迭代用时为" << end - start << "毫秒" << endl;
    return item_vector;
}


int main() {
    auto V = dic_test();
    auto S = new_test();
    ofstream outfile;
    outfile.open("./src/data.txt");
    for(auto iter = V.begin(); iter != V.end(); ++iter){
        outfile << *iter << " ";
    }
    outfile << endl;
    for(auto iter = S.begin(); iter != S.end(); ++iter){
        outfile << *iter << " ";
    }
    outfile << endl;
    return 0;
}