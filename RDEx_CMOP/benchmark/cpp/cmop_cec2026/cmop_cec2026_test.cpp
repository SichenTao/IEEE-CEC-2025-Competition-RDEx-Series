/*
  CEC2026 CMOP SDC Test Suite
  C++ implementation of the current MATLAB SDC1-SDC15 test suite.

  The public entry follows the CEC2017 COP pointer style used by the CSOP
  codebase: x stores mx individuals, each with nx consecutive variables.
*/

#include "cmop_cec2026_test.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef CMOP_CEC2026_STANDALONE
#include <iostream>
#include <vector>
using namespace std;
#endif

#define CMOP_INF 1.0e99
#define CMOP_EPS 1.0e-14
#define CMOP_E  2.7182818284590452353602874713526625
#define CMOP_PI 3.1415926535897932384626433832795029
#define CMOP_MAX_NX 256
#define CMOP_MAX_CEC_N 32
#define CMOP_NFUNC 15

static const int SDC_CEC_PROBLEM[CMOP_NFUNC] = {1,2,3,6,9,10,11,12,14,18,19,24,15,5,1};
static const int SDC_DISTANCE_PROBLEM[CMOP_NFUNC] = {2,1,4,4,3,5,5,3,3,2,1,3,5,1,2};
static const int SDC_HCT_TYPE[CMOP_NFUNC] = {1,2,1,1,2,2,2,2,1,1,1,2,2,2,1};
static const int SDC_DCT_TYPE[CMOP_NFUNC] = {2,1,1,2,2,2,1,1,2,2,1,1,1,1,2};
static const int SDC_SHAPE_PROBLEM[CMOP_NFUNC] = {1,2,1,2,1,2,1,2,1,2,1,2,2,1,1};
static const double SDC_B[CMOP_NFUNC] = {10,100,15,115,19,125,10,100,15,115,19,115,125,15,10};

static inline double sqr(double x)
{
    return x * x;
}

static inline double cube(double x)
{
    return x * x * x;
}

static inline double clamp01(double x)
{
    if (x < 0.0) return 0.0;
    if (x > 1.0) return 1.0;
    return x;
}

static inline double matlab_mod_positive(double x, double y)
{
    double r = fmod(x, y);
    if (r < 0.0) r += y;
    return r;
}

static inline double matlab_mod_half_for_sdc(double x, int count)
{
    if (count >= 5)
    {
        double nearest = 0.5 * floor(x / 0.5 + 0.5);
        double tol = 64.0 * CMOP_EPS * fmax(1.0, fabs(x));
        if (fabs(x - nearest) <= tol) return 0.0;
    }
    return matlab_mod_positive(x, 0.5);
}

static inline double matlab_atan_ratio(double numerator, double denominator)
{
    double angle = atan(numerator / denominator);
    if (isnan(angle)) angle = 1.0;
    return angle;
}

int cmop_cec2026_nobj(int func_num)
{
    if (func_num == 15) return 3;
    return 2;
}

int cmop_cec2026_ng(int func_num)
{
    if (func_num < 1 || func_num > CMOP_NFUNC) return 0;
    return 3;
}

int cmop_cec2026_nh(int func_num)
{
    (void)func_num;
    return 0;
}

void cmop_cec2026_bounds(double *lower, double *upper, int nx, int func_num)
{
    (void)func_num;
    for (int i = 0; i < nx; ++i)
    {
        lower[i] = 0.0;
        upper[i] = 1.0;
    }
}

static int cec2006_raw_ng(int problem)
{
    switch (problem)
    {
    case 1: return 9;
    case 2: return 2;
    case 3: return 1;
    case 5: return 5;
    case 6: return 2;
    case 9: return 4;
    case 10: return 6;
    case 11: return 1;
    case 12: return 1;
    case 14: return 3;
    case 15: return 2;
    case 18: return 13;
    case 19: return 5;
    case 24: return 2;
    default: return 0;
    }
}

static void cec2006_info(int problem, int *n, double *lower, double *upper, double *optimal)
{
    int i;
    for (i = 0; i < CMOP_MAX_CEC_N; ++i)
    {
        lower[i] = 0.0;
        upper[i] = 0.0;
    }

    switch (problem)
    {
    case 1:
        *n = 13;
        for (i = 0; i < 13; ++i) lower[i] = 0.0;
        for (i = 0; i < 9; ++i) upper[i] = 1.0;
        upper[9] = 100.0; upper[10] = 100.0; upper[11] = 100.0; upper[12] = 1.0;
        *optimal = -15.0;
        break;
    case 2:
        *n = 20;
        for (i = 0; i < 20; ++i) { lower[i] = 0.0; upper[i] = 10.0; }
        *optimal = -0.803619;
        break;
    case 3:
        *n = 10;
        for (i = 0; i < 10; ++i) { lower[i] = 0.0; upper[i] = 1.0; }
        *optimal = -1.0;
        break;
    case 5:
        *n = 4;
        lower[0] = 0.0; lower[1] = 0.0; lower[2] = -0.55; lower[3] = -0.55;
        upper[0] = 1200.0; upper[1] = 1200.0; upper[2] = 0.55; upper[3] = 0.55;
        *optimal = 5126.4981;
        break;
    case 6:
        *n = 2;
        lower[0] = 13.0; lower[1] = 0.0;
        upper[0] = 100.0; upper[1] = 100.0;
        *optimal = -6961.81388;
        break;
    case 9:
        *n = 7;
        for (i = 0; i < 7; ++i) { lower[i] = -10.0; upper[i] = 10.0; }
        *optimal = 680.6300573;
        break;
    case 10:
        *n = 8;
        lower[0] = 100.0; lower[1] = 1000.0; lower[2] = 1000.0;
        for (i = 3; i < 8; ++i) lower[i] = 10.0;
        upper[0] = 10000.0; upper[1] = 10000.0; upper[2] = 10000.0;
        for (i = 3; i < 8; ++i) upper[i] = 1000.0;
        *optimal = 7049.2480;
        break;
    case 11:
        *n = 2;
        lower[0] = -1.0; lower[1] = -1.0; upper[0] = 1.0; upper[1] = 1.0;
        *optimal = 0.75;
        break;
    case 12:
        *n = 3;
        for (i = 0; i < 3; ++i) { lower[i] = 0.0; upper[i] = 10.0; }
        *optimal = -1.0;
        break;
    case 14:
        *n = 10;
        for (i = 0; i < 10; ++i) { lower[i] = 0.0; upper[i] = 10.0; }
        *optimal = -47.7648884595;
        break;
    case 15:
        *n = 3;
        for (i = 0; i < 3; ++i) { lower[i] = 0.0; upper[i] = 10.0; }
        *optimal = 961.7150222899;
        break;
    case 18:
        *n = 9;
        for (i = 0; i < 8; ++i) { lower[i] = -10.0; upper[i] = 10.0; }
        lower[8] = 0.0; upper[8] = 20.0;
        *optimal = -0.8660254038;
        break;
    case 19:
        *n = 15;
        for (i = 0; i < 15; ++i) { lower[i] = 0.0; upper[i] = 10.0; }
        *optimal = 32.6555929502;
        break;
    case 24:
        *n = 2;
        lower[0] = 0.0; lower[1] = 0.0; upper[0] = 3.0; upper[1] = 4.0;
        *optimal = -5.5080132716;
        break;
    default:
        *n = 0;
        *optimal = 0.0;
        break;
    }
}

static double distance_function(const double *x, int n, int problem)
{
    int i;
    double f = 0.0;

    if (n <= 0) return 0.0;

    if (problem == 1)
    {
        for (i = 0; i < n; ++i)
        {
            double v = 10.0 * x[i];
            f += v * v;
        }
    }
    else if (problem == 2)
    {
        for (i = 0; i < n; ++i)
        {
            double v = fabs(10.0 * x[i]);
            if (v > f) f = v;
        }
    }
    else if (problem == 3)
    {
        for (i = 0; i < n; ++i)
        {
            double v = 10.0 * x[i];
            f += v * v - 10.0 * cos(2.0 * CMOP_PI * v) + 10.0;
        }
    }
    else if (problem == 4)
    {
        double sumsq = 0.0;
        double prod = 1.0;
        for (i = 0; i < n; ++i)
        {
            double v = 10.0 * x[i];
            sumsq += v * v;
            prod *= cos(v / sqrt((double)(i + 1)));
        }
        f = sumsq / 4000.0 - prod + 1.0;
    }
    else if (problem == 5)
    {
        double sumsq = 0.0;
        double sumcos = 0.0;
        for (i = 0; i < n; ++i)
        {
            double v = 10.0 * x[i];
            sumsq += v * v;
            sumcos += cos(2.0 * CMOP_PI * v);
        }
        f = 20.0 - 20.0 * exp(-0.2 * sqrt(sumsq / (double)n)) - exp(sumcos / (double)n) + CMOP_E;
    }

    if (f < 1.0e-8) f = 0.0;
    return f;
}

static void cec2006_fitness(const double *p, int problem, double *obj_f, double *con_v)
{
    double g[40];
    double f = 0.0;
    double lower[CMOP_MAX_CEC_N], upper[CMOP_MAX_CEC_N], optimal;
    int n, i;
    int ng = cec2006_raw_ng(problem);

    (void)lower;
    (void)upper;
    cec2006_info(problem, &n, lower, upper, &optimal);
    for (i = 0; i < 40; ++i) g[i] = 0.0;

    switch (problem)
    {
    case 1:
        g[0] = 2.0 * p[0] + 2.0 * p[1] + p[9] + p[10] - 10.0;
        g[1] = 2.0 * p[0] + 2.0 * p[2] + p[9] + p[11] - 10.0;
        g[2] = 2.0 * p[1] + 2.0 * p[2] + p[10] + p[11] - 10.0;
        g[3] = -8.0 * p[0] + p[9];
        g[4] = -8.0 * p[1] + p[10];
        g[5] = -8.0 * p[2] + p[11];
        g[6] = -2.0 * p[3] - p[4] + p[9];
        g[7] = -2.0 * p[5] - p[6] + p[10];
        g[8] = -2.0 * p[7] - p[8] + p[11];
        f = 5.0 * (p[0] + p[1] + p[2] + p[3])
          - 5.0 * (sqr(p[0]) + sqr(p[1]) + sqr(p[2]) + sqr(p[3]))
          - (p[4] + p[5] + p[6] + p[7] + p[8] + p[9] + p[10] + p[11] + p[12]);
        break;
    case 2:
    {
        double prodp = 1.0, sump = 0.0, sumcos4 = 0.0, prodcos2 = 1.0, denom = 0.0;
        for (i = 0; i < n; ++i)
        {
            double c = cos(p[i]);
            prodp *= p[i];
            sump += p[i];
            sumcos4 += sqr(sqr(c));
            prodcos2 *= sqr(c);
            denom += (double)(i + 1) * sqr(p[i]);
        }
        g[0] = 0.75 - prodp;
        g[1] = sump - 7.5 * (double)n;
        f = -fabs(sumcos4 - 2.0 * prodcos2) / sqrt(1.0e-30 + denom);
        break;
    }
    case 3:
    {
        double sumsq = 0.0, prodp = 1.0;
        for (i = 0; i < n; ++i)
        {
            sumsq += sqr(p[i]);
            prodp *= p[i];
        }
        g[0] = fabs(sumsq - 1.0) - 0.0001;
        f = -pow(sqrt(10.0), 10.0) * prodp;
        break;
    }
    case 5:
        g[0] = -p[3] + p[2] - 0.55;
        g[1] = -p[2] + p[3] - 0.55;
        g[2] = fabs(1000.0 * sin(-p[2] - 0.25) + 1000.0 * sin(-p[3] - 0.25) + 894.8 - p[0]) - 0.0001;
        g[3] = fabs(1000.0 * sin(p[2] - 0.25) + 1000.0 * sin(p[2] - p[3] - 0.25) + 894.8 - p[1]) - 0.0001;
        g[4] = fabs(1000.0 * sin(p[3] - 0.25) + 1000.0 * sin(p[3] - p[2] - 0.25) + 1294.8) - 0.0001;
        f = 3.0 * p[0] + 0.000001 * cube(p[0]) + 2.0 * p[1] + 0.000002 / 3.0 * cube(p[1]);
        break;
    case 6:
        g[0] = -sqr(p[0] - 5.0) - sqr(p[1] - 5.0) + 100.0;
        g[1] = sqr(p[0] - 6.0) + sqr(p[1] - 5.0) - 82.81;
        f = cube(p[0] - 10.0) + cube(p[1] - 20.0);
        break;
    case 9:
        g[0] = -127.0 + 2.0 * sqr(p[0]) + 3.0 * pow(p[1], 4.0) + p[2] + 4.0 * sqr(p[3]) + 5.0 * p[4];
        g[1] = -282.0 + 7.0 * p[0] + 3.0 * p[1] + 10.0 * sqr(p[2]) + p[3] - p[4];
        g[2] = -196.0 + 23.0 * p[0] + sqr(p[1]) + 6.0 * sqr(p[5]) - 8.0 * p[6];
        g[3] = 4.0 * sqr(p[0]) + sqr(p[1]) - 3.0 * p[0] * p[1] + 2.0 * sqr(p[2]) + 5.0 * p[5] - 11.0 * p[6];
        f = sqr(p[0] - 10.0) + 5.0 * sqr(p[1] - 12.0) + pow(p[2], 4.0) + 3.0 * sqr(p[3] - 11.0)
          + 10.0 * pow(p[4], 6.0) + 7.0 * sqr(p[5]) + pow(p[6], 4.0) - 4.0 * p[5] * p[6] - 10.0 * p[5] - 8.0 * p[6];
        break;
    case 10:
        g[0] = -1.0 + 0.0025 * (p[3] + p[5]);
        g[1] = -1.0 + 0.0025 * (p[4] + p[6] - p[3]);
        g[2] = -1.0 + 0.01 * (p[7] - p[4]);
        g[3] = -p[0] * p[5] + 833.33252 * p[3] + 100.0 * p[0] - 83333.333;
        g[4] = -p[1] * p[6] + 1250.0 * p[4] + p[1] * p[3] - 1250.0 * p[3];
        g[5] = -p[2] * p[7] + 1250000.0 + p[2] * p[4] - 2500.0 * p[4];
        f = p[0] + p[1] + p[2];
        break;
    case 11:
        g[0] = fabs(p[1] - sqr(p[0])) - 0.0001;
        f = sqr(p[0]) + sqr(p[1] - 1.0);
        break;
    case 12:
    {
        double best = CMOP_INF;
        f = -(100.0 - sqr(p[0] - 5.0) - sqr(p[1] - 5.0) - sqr(p[2] - 5.0)) / 100.0;
        for (int a = 1; a <= 9; ++a)
        {
            for (int b = 1; b <= 9; ++b)
            {
                for (int c = 1; c <= 9; ++c)
                {
                    double d = sqr(p[0] - (double)a) + sqr(p[1] - (double)b) + sqr(p[2] - (double)c);
                    if (d < best) best = d;
                }
            }
        }
        g[0] = best - 0.0625;
        break;
    }
    case 14:
    {
        static const double c[10] = {-6.089,-17.164,-34.054,-5.914,-24.721,-14.986,-24.1,-10.708,-26.662,-22.179};
        double sump = 0.0;
        for (i = 0; i < 10; ++i) sump += p[i];
        g[0] = fabs(p[0] + 2.0 * p[1] + 2.0 * p[2] + p[5] + p[9] - 2.0) - 0.0001;
        g[1] = fabs(p[3] + 2.0 * p[4] + p[5] + p[6] - 1.0) - 0.0001;
        g[2] = fabs(p[2] + p[6] + p[7] + 2.0 * p[8] + p[9] - 1.0) - 0.0001;
        f = 0.0;
        for (i = 0; i < 10; ++i)
        {
            f += p[i] * (c[i] + log(1.0e-30 + p[i] / (1.0e-30 + sump)));
        }
        break;
    }
    case 15:
        g[0] = fabs(sqr(p[0]) + sqr(p[1]) + sqr(p[2]) - 25.0) - 0.0001;
        g[1] = fabs(8.0 * p[0] + 14.0 * p[1] + 7.0 * p[2] - 56.0) - 0.0001;
        f = 1000.0 - sqr(p[0]) - 2.0 * sqr(p[1]) - sqr(p[2]) - p[0] * p[1] - p[0] * p[2];
        break;
    case 18:
        g[0] = sqr(p[2]) + sqr(p[3]) - 1.0;
        g[1] = sqr(p[8]) - 1.0;
        g[2] = sqr(p[4]) + sqr(p[5]) - 1.0;
        g[3] = sqr(p[0]) + sqr(p[1] - p[8]) - 1.0;
        g[4] = sqr(p[0] - p[4]) + sqr(p[1] - p[5]) - 1.0;
        g[5] = sqr(p[0] - p[6]) + sqr(p[1] - p[7]) - 1.0;
        g[6] = sqr(p[2] - p[4]) + sqr(p[3] - p[5]) - 1.0;
        g[7] = sqr(p[2] - p[6]) + sqr(p[3] - p[7]) - 1.0;
        g[8] = sqr(p[6]) + sqr(p[7] - p[8]) - 1.0;
        g[9] = p[1] * p[2] - p[0] * p[3];
        g[10] = -p[2] * p[8];
        g[11] = p[4] * p[8];
        g[12] = p[5] * p[6] - p[4] * p[7];
        f = -0.5 * (p[0] * p[3] - p[1] * p[2] + p[2] * p[8] - p[4] * p[8] + p[4] * p[7] - p[5] * p[6]);
        break;
    case 19:
    {
        static const double a[10][5] = {
            {-16, 2, 0, 1, 0},
            {0, -2, 0, 0.4, 2},
            {-3.5, 0, 2, 0, 0},
            {0, -2, 0, -4, -1},
            {0, -9, -2, 1, -2.8},
            {2, 0, -4, 0, 0},
            {-1, -1, -1, -1, -1},
            {-1, -2, -3, -2, -1},
            {1, 2, 3, 4, 5},
            {1, 1, 1, 1, 1}
        };
        static const double b[10] = {-40,-2,-0.25,-4,-4,-1,-40,-60,5,1};
        static const double c[5][5] = {
            {30,-20,-10,32,-10},
            {-20,39,-6,-31,32},
            {-10,-6,10,-6,-10},
            {32,-31,-6,39,-20},
            {-10,32,-10,-20,30}
        };
        static const double d[5] = {4,8,10,6,2};
        static const double e[5] = {-15,-27,-36,-18,-12};
        double sumc[5];
        for (int k = 0; k < 5; ++k)
        {
            double sc = 0.0, sa = 0.0;
            for (int r = 0; r < 5; ++r) sc += c[r][k] * p[10 + r];
            for (int r = 0; r < 10; ++r) sa += a[r][k] * p[r];
            sumc[k] = sc;
            g[k] = -2.0 * sc - 3.0 * d[k] * sqr(p[10 + k]) - e[k] + sa;
        }
        f = 0.0;
        for (int k = 0; k < 5; ++k) f += sumc[k] * p[10 + k];
        for (int k = 0; k < 5; ++k) f += 2.0 * d[k] * cube(p[10 + k]);
        for (int r = 0; r < 10; ++r) f -= b[r] * p[r];
        break;
    }
    case 24:
        g[0] = -2.0 * pow(p[0], 4.0) + 8.0 * cube(p[0]) - 8.0 * sqr(p[0]) + p[1] - 2.0;
        g[1] = -4.0 * pow(p[0], 4.0) + 32.0 * cube(p[0]) - 88.0 * sqr(p[0]) + 96.0 * p[0] + p[1] - 36.0;
        f = -p[0] - p[1];
        break;
    default:
        f = 0.0;
        break;
    }

    *con_v = 0.0;
    for (i = 0; i < ng; ++i)
    {
        if (g[i] > 0.0) *con_v += g[i];
    }

    *obj_f = f - optimal;
    if (fabs(*obj_f) <= 0.001) *obj_f = 0.0;
}

static void transform_high_constraint_variables(const double *dec, int m, int high_n,
                                                int max_d_con, int hct_type,
                                                const double *lower, const double *upper,
                                                double *new_p)
{
    for (int j = 0; j < high_n; ++j)
    {
        int count = 0;
        double sum = 0.0;
        for (int idx = j; idx < max_d_con; idx += high_n)
        {
            sum += dec[m + idx];
            ++count;
        }

        if (count > 1)
        {
            double a2 = matlab_mod_half_for_sdc(sum, count);
            double temp;
            if (hct_type == 1)
                temp = -2.0 * a2 + 1.0;
            else
                temp = cos(a2 * CMOP_PI);
            new_p[j] = lower[j] + (upper[j] - lower[j]) * temp;
        }
        else
        {
            new_p[j] = lower[j] + (upper[j] - lower[j]) * dec[m + j];
        }
    }
}

static void evaluate_sdc_one(const double *x, double *f, double *g, int nx, int func_num)
{
    double dec[CMOP_MAX_NX];
    double linked[CMOP_MAX_NX];
    double cec_lower[CMOP_MAX_CEC_N], cec_upper[CMOP_MAX_CEC_N], optimal;
    double new_p[CMOP_MAX_CEC_N];
    double inner_obj, inner_con, distance;
    int idx = func_num - 1;
    int m = cmop_cec2026_nobj(func_num);
    int cec_problem = SDC_CEC_PROBLEM[idx];
    int high_n;

    cec2006_info(cec_problem, &high_n, cec_lower, cec_upper, &optimal);
    (void)optimal;

    for (int j = 0; j < nx; ++j)
    {
        dec[j] = clamp01(x[j]);
        linked[j] = dec[j];
    }

    int max_d_con = high_n + (int)ceil(((double)nx - (double)m - (double)high_n) * 0.5);
    if (max_d_con < high_n) max_d_con = high_n;
    if (m + max_d_con > nx) max_d_con = nx - m;

    transform_high_constraint_variables(dec, m, high_n, max_d_con, SDC_HCT_TYPE[idx],
                                        cec_lower, cec_upper, new_p);
    cec2006_fitness(new_p, cec_problem, &inner_obj, &inner_con);

    int control_d = (int)ceil(((double)nx - (double)high_n - (double)m) * 0.5);
    if (control_d < 0) control_d = 0;
    if (control_d > nx) control_d = nx;
    if (control_d > 0)
    {
        for (int k = 0; k < control_d; ++k)
        {
            int j = nx - control_d + k;
            double frac = (double)(k + 1) / (double)control_d;
            double factor;
            if (SDC_DCT_TYPE[idx] == 1)
                factor = 1.0 + frac;
            else
                factor = 1.0 + cos(0.5 * CMOP_PI * frac);
            linked[j] = factor * linked[j] - linked[0];
        }
    }

    int dist_start = m + high_n;
    if (dist_start > nx) dist_start = nx;
    distance = distance_function(&linked[dist_start], nx - dist_start, SDC_DISTANCE_PROBLEM[idx]);

    if (m == 2)
    {
        double angle = matlab_atan_ratio(fabs(dec[1]), dec[0]);
        double theta = 2.0 / CMOP_PI * angle;
        double scaled = 0.5 * CMOP_PI * theta;
        double q = (SDC_SHAPE_PROBLEM[idx] == 1) ? 4.0 : 2.0;
        double pop1 = q * dec[0];
        double pop2 = q * dec[1];
        double t = sqr(1.0 - sqr(pop1) - sqr(pop2)) + inner_obj + distance;
        double common = 1.0 + t;

        f[0] = cos(scaled) * common;
        f[1] = sin(scaled) * common;

        if (SDC_SHAPE_PROBLEM[idx] == 1)
        {
            double cc = SDC_B[idx] / 10.0;
            g[0] = sqr(cc) * sqr(pop1) + sqr(pop2) - sqr(cc);
            g[1] = -cc * (pop1 - 1.0) - pop2;
        }
        else
        {
            double l = matlab_atan_ratio(pop2, pop1);
            double s4 = sin(4.0 * l);
            double cc = SDC_B[idx] / 100.0;
            g[0] = sqr(pop1) + sqr(pop2) - sqr(cc + 0.05 + 0.4 * pow(s4, 16.0));
            g[1] = sqr(cc - 0.2 * pow(s4, 8.0)) - sqr(pop1) - sqr(pop2);
        }
    }
    else
    {
        double s2 = sqr(dec[1]) + sqr(dec[2]);
        double angle1 = matlab_atan_ratio(sqrt(s2), dec[0]);
        double angle2 = matlab_atan_ratio(sqrt(sqr(dec[2])), dec[1]);
        double q = 4.0;
        double pop1 = q * dec[0];
        double pop2 = q * dec[1];
        double pop3 = q * dec[2];
        double r2 = sqr(pop1) + sqr(pop2) + sqr(pop3);
        double t = sqr(1.0 - r2) + inner_obj + distance;
        double common = 1.0 + t;
        double sa1 = sin(angle1);

        f[0] = cos(angle1) * common;
        f[1] = sa1 * cos(angle2) * common;
        f[2] = sa1 * sin(angle2) * common;
        g[0] = 0.5 - r2;
        g[1] = -2.0 - r2;
    }

    g[2] = inner_con;
}

void cmop_cec2026_test(double *x, double *f, double *g, double *h, int nx, int mx, int func_num)
{
    (void)h;
    if (func_num < 1 || func_num > CMOP_NFUNC)
    {
        printf("\nError: There are only 15 functions in the CEC2026 CMOP SDC test suite.\n");
        return;
    }
    if (nx <= 0 || nx > CMOP_MAX_NX)
    {
        printf("\nError: CMOP C++ evaluator supports 1 <= nx <= %d.\n", CMOP_MAX_NX);
        return;
    }

    int nf = cmop_cec2026_nobj(func_num);
    int ng = cmop_cec2026_ng(func_num);
    for (int i = 0; i < mx; ++i)
    {
        evaluate_sdc_one(&x[i * nx], &f[i * nf], &g[i * ng], nx, func_num);
    }
}

#ifdef CMOP_CEC2026_STANDALONE
int main(int argc, char **argv)
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage: %s func_num nx mx < x_values\n", argv[0]);
        return 1;
    }
    int func_num = atoi(argv[1]);
    int nx = atoi(argv[2]);
    int mx = atoi(argv[3]);
    int nf = cmop_cec2026_nobj(func_num);
    int ng = cmop_cec2026_ng(func_num);
    vector<double> x((size_t)nx * (size_t)mx);
    vector<double> f((size_t)nf * (size_t)mx);
    vector<double> g((size_t)ng * (size_t)mx);

    for (size_t i = 0; i < x.size(); ++i)
    {
        if (!(cin >> x[i]))
        {
            fprintf(stderr, "Error: expected %zu decision values.\n", x.size());
            return 2;
        }
    }

    cmop_cec2026_test(&x[0], &f[0], &g[0], NULL, nx, mx, func_num);
    for (int i = 0; i < mx; ++i)
    {
        for (int j = 0; j < nf; ++j)
        {
            if (j) printf(" ");
            printf("%.17g", f[(size_t)i * nf + j]);
        }
        for (int j = 0; j < ng; ++j)
        {
            printf(" %.17g", g[(size_t)i * ng + j]);
        }
        printf("\n");
    }
    return 0;
}
#endif
