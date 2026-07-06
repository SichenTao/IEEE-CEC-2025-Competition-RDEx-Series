/*
  CEC2026 CMOP SDC Test Suite
  C++ implementation of the current MATLAB SDC1-SDC15 test suite.
*/

#ifndef CMOP_CEC2026_TEST_H
#define CMOP_CEC2026_TEST_H

extern "C" {

int cmop_cec2026_nobj(int func_num);
int cmop_cec2026_ng(int func_num);
int cmop_cec2026_nh(int func_num);
void cmop_cec2026_bounds(double *lower, double *upper, int nx, int func_num);
void cmop_cec2026_test(double *x, double *f, double *g, double *h, int nx, int mx, int func_num);

}

#endif
