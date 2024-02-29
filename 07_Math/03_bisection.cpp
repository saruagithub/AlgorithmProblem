//
//  03_bisection.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/11/14.
//  中值定理

#include <stdio.h>
#include <math.h>
#define EPSILON 0.0000001

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);

int test_bisection() {
    int p = -50;
    int q = 12;
    //scanf("%d%d", &p, &q);
    printf("%.4f\n", bisection(p, q, f));
    return 0;
}

//abs是取绝对值后再取整，而fabs是取绝对值
double bisection(int p, int q, double (*func)(int, int, double)) {
    double l = -20.0, r = 20.0;
    double mid = 0.0;
    while (l < r) {
        mid = (l + r) / 2;
        if (fabs(func(p,q,mid)) < EPSILON) {
            break;
        } else {
            if (func(p,q,l) * func(p,q,mid) < 0) r = mid;
            else l = mid;
        }
    }
    return mid;
}

double f(int p, int q, double x) {
    return p * x + q;
}
