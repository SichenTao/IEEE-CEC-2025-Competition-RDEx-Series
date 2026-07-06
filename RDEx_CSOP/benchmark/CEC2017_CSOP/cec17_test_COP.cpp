/*
  CEC2017 Constrained Optimization Test Suite
  Guohua Wu (email: guohuawu@nudt.edu.cn, National University of Defense Technology)
  Sep. 10th 2016
*/

#include <stdio.h>
#include <math.h>
#if defined(__APPLE__)
#include <stdlib.h>
#else
#include <malloc.h>
#endif
#include <iostream>
using namespace std;

extern double *OShift,*M,*M1,*M2,*y,*z,*z1,*z2;
extern int ini_flag,n_flag,func_flag,f5_flag;

#define INF 1.0e99
#define EPS 1.0e-14
#define E  2.7182818284590452353602874713526625
#define PI 3.1415926535897932384626433832795029

void COP_01 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_O1 */
void COP_02 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_O2 */
void COP_03 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_O3 */
void COP_04 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_O4 */
void COP_05 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_O5 */
void COP_06 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_O6 */
void COP_07 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_O7 */
void COP_08 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_O8 */
void COP_09 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_O9 */
void COP_10 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_10 */
void COP_11 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_11 */
void COP_12 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_12 */
void COP_13 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_13 */
void COP_14 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_14 */
void COP_15 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_15 */
void COP_16 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_15 */
void COP_17 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_17 */
void COP_18 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_18 */
void COP_19 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_19 */
void COP_20 (double *, double *, double *, double *, int , double *,double *, int, int); /* COP_20 */
// Note that COP21-COP28 are  the rotated versioins of COP12-COP18.
void loadShiftData(int fun_num, int dim, double *pV );
void loadRotateData(int func_num, int dim, double *pM );
void shiftfunc (double*,double*,int,double*);
void rotatefunc (double*,double*,int, double*);
void sr_func (double *, double *, int, double*, double*, double, int, int); /* shift and rotate */
int  sgn(double val);
double round(double val);


void cec17_test_COP(double *x, double *f, double *g,double *h,int nx, int mx,int func_num)
{
	// x points to a matrix (population) with nx rows and mx columns.
	// nx is actually the dimension size and mx is the population size.
	// f points to objective function values.
	// g points to inequality constraint values.
	// h points to equality constraints values.
	int ng_A[28]={1,1,1,2,2,1,1,1,1,1,1,2,3,1,1,1,1,2,2,2,2,3,1,1,1,1,2,2};
	int nh_A[28]={1,1,1,1,1,6,2,2,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int ng,nh;
	ng = ng_A[func_num-1];
	nh = nh_A[func_num-1];
	int i;
	if (ini_flag==1)
	{
        if ((n_flag!=nx)||(func_flag!=func_num))
		{
			ini_flag=0;
		}
	}
	if (ini_flag==0)
	{
        if (M!=NULL){
            free(M);
            M = NULL;
        }
        if (M1!=NULL){
            free(M1);
            M1 = NULL;
        }
        if (M2!=NULL){
            free(M2);
            M2 = NULL;
        }
        if (z1!=NULL){
            free(z1);
            z1 = NULL;
        }
        if (z2!=NULL){
            free(z2);
            z2 = NULL;
        }
		free(OShift);
        OShift = NULL;
		free(y);
        y = NULL;
		free(z);
        z = NULL;
		y=(double *)malloc(sizeof(double)  *  nx);
		z=(double *)malloc(sizeof(double)  *  nx);
		if (!(nx==10||nx==30||nx==50||nx==100))
		{
			printf("\nError: Test functions are only defined for D=10,30,50,100.\n");
		}
		/* Load shift_data */
       OShift=(double *)malloc(nx*sizeof(double));
       loadShiftData(func_num, nx, OShift);
		/* Load Matrix M*/
       if (func_num==2 || func_num>20)
       {
           M=(double*)malloc(nx*nx*sizeof(double));
           loadRotateData(func_num, nx, M);
       }
       if (func_num==5)
       {
           z1 = (double *)malloc(sizeof(double)  *  nx);
           z2 = (double *)malloc(sizeof(double)  *  nx);
           M1 = (double*)malloc(nx*nx*sizeof(double));
           f5_flag = 1;
           loadRotateData(func_num, nx, M1);
           f5_flag = 2;
           M2 = (double*)malloc(nx*nx*sizeof(double));
           loadRotateData(func_num, nx, M2);

       }
		n_flag=nx;
		func_flag=func_num;
		ini_flag=1;
	}
	for (i = 0; i < mx; i++) // mx is the number of columns  of x
	{
		switch(func_num)
		{
        case 1:
 			COP_01(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 2:
			COP_02(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
        case 3:
 			COP_03(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 4:
 			COP_04(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 5:
 			COP_05(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
        case 6:
 			COP_06(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 7:
 			COP_07(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 8:
 			COP_08(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 9:
 			COP_09(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 10:
 			COP_10(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 11:
 			COP_11(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 12:
 			COP_12(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 13:
 			COP_13(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 14:
 			COP_14(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 15:
 			COP_15(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 16:
 			COP_16(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 17:
 			COP_17(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 18:
 			COP_18(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 19:
 			COP_19(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 20:
 			COP_20(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,0);
 			break;
        case 21:
 			COP_12(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
        case 22:
 			COP_13(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
        case 23:
 			COP_14(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
        case 24:
 			COP_15(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
        case 25:
 			COP_16(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
        case 26:
 			COP_17(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
        case 27:
 			COP_18(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
        case 28:
 			COP_19(&x[i*nx],&f[i],&g[i*ng],&h[i*nh],nx,OShift,M,1,1);
 			break;
		default:
			printf("\nError: There are only 30 test functions in this test suite!\n");
			f[i] = 0.0;
			break;
		}
	}
}
void COP_01 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i,j;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=1; i<nx+1; i++)
	{
		double t;
		t = 0.0;
		for(j=0;j<i;j++)
		{
			t += z[j];
		}
		f[0] += t*t;
	}
	g[0] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + (z[i]*z[i]-5000*cos(0.1*PI*z[i])-4000);
	}
    *h = 0;
}
void COP_02 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O2 */
{
	int i,j;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */

	f[0] = 0.0;
	for (i=1; i<nx+1; i++)
	{
		double t;
		t = 0.0;
		for(j=0;j<i;j++)
		{
			t += (x[j]-Os[j]);
		}
		f[0] += t*t;
	}
	g[0] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + (z[i]*z[i]-5000*cos(0.1*PI*z[i])-4000);
	}
    *h = 0;
}
void COP_03 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O3 */
{
	int i,j;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=1; i<nx+1; i++)
	{
		double t;
		t = 0.0;
		for(j=0;j<i;j++)
		{
			t += z[j];
		}
		f[0] = f[0] + t*t;
	}
	g[0] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + (z[i]*z[i]-5000*cos(0.1*PI*z[i])-4000);
	}
    h[0]=0.0;
	for (i=0;i<nx; i++)
	{
		h[0] = h[0] + z[i]*sin(0.1*PI*z[i]);
	}
	h[0] = -h[0];
}
void COP_04 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O4 */
{
	int i;
     sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=0; i<nx; i++)
	{
		f[0] += (z[i]*z[i] - 10.0*cos(2.0*PI*z[i]) + 10.0);
	}
	g[0] = 0.0;
	g[1] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + z[i]*sin(2*z[i]);
	}
	g[0] = -g[0];
	for (i=0;i<nx; i++)
	{
		g[1] = g[1] + z[i]*sin(z[i]);
	}
	 *h = 0;
}
void COP_05 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O5 */
{
	int i;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, 1, 0); /* shift and rotate */
    sr_func (x, z1, nx, Os, M1, 5.12/100.0, 1, 1); /* shift and rotate */
    sr_func (x, z2, nx, Os, M2, 5.12/100.0, 1, 1); /* shift and rotate */

	f[0] = 0.0;
	for (i=0; i<nx-1; i++)
	{
		f[0] += (100*(z[i]*z[i]-z[i+1])*(z[i]*z[i]-z[i+1]) + (z[i]-1)*(z[i]-1));
	}
	g[0] = 0.0;
	g[1] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + (z1[i]*z1[i] - 50.0*cos(2.0*PI*z1[i]) - 40.0);
	}
	for (i=0;i<nx; i++)
	{
		g[1] = g[1] + (z2[i]*z2[i] - 50.0*cos(2.0*PI*z2[i]) - 40.0);
	}
	 *h = 0;
}
void COP_06 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O6 */
{
	int i;
     sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=0; i<nx; i++)
	{
		f[0] += (z[i]*z[i] - 10.0*cos(2.0*PI*z[i]) + 10.0);
	}
	h[0] = 0.0;
	h[1] = 0.0;
	h[2] = 0.0;
	h[3] = 0.0;
	h[4] = 0.0;
	h[5] = 0.0;
	for (i=0;i<nx; i++)
	{
		h[0] = h[0] +  z[i]*sin(z[i]);
	}
	h[0] = -h[0];
	for (i=0;i<nx; i++)
	{
		h[1] = h[1] + z[i]*sin(PI*z[i]);
	}
	for (i=0;i<nx; i++)
	{
		h[2] = h[2] +  z[i]*cos(z[i]);
	}
	h[2] = -h[2];
	for (i=0;i<nx; i++)
	{
		h[3] = h[3] +  z[i]*cos(PI*z[i]);
	}
	for (i=0;i<nx; i++)
	{
		h[4] = h[4] +  z[i]*sin(2*sqrt(fabs(z[i])));
	}
	for (i=0;i<nx; i++)
	{
		h[5] = h[5] +  z[i]*sin(2*sqrt(fabs(z[i])));
	}
	h[5] = -h[5];
	*g = 0;
}
void COP_07 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O7 */
{
	int i;
     sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=0; i<nx; i++)
	{
		f[0] += z[i]*sin(z[i]);
	}
	h[0] = 0.0;
	h[1] = 0.0;
	for (i=0;i<nx; i++)
	{
		h[0] = h[0] +  (z[i]-100*cos(0.5*z[i])+100);
	}
	for (i=0;i<nx; i++)
	{
		h[1] = h[1] + (z[i]-100*cos(0.5*z[i])+100);
	}
	h[1] = -h[1];
	*g = 0;
}
void COP_08 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O8 */
{
	int i,j;
     sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	double t;
	t = z[0];
	for (i=0; i<nx; i++)
	{
		if(z[i]>t)
			t=z[i];
	}
	f[0]=t;
	h[0] = 0.0;
	h[1] = 0.0;
	for (i=1; i<nx/2+1; i++)
	{
		double m;
		m = 0.0;
		for(j=0;j<i;j++)
		{
			m += z[2*j];
		}
		h[0] += m*m;
	}
	for (i=1; i<nx/2+1; i++)
	{
		double m;
		m = 0.0;
		for(j=0;j<i;j++)
		{
			m += z[2*j+1];
		}
		h[1] += m*m;
	}
	*g = 0;
}
void COP_09 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O9 */
{
	int i;
     sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	double t;
	t = z[0];
	for (i=0; i<nx; i++)
	{
		if(z[i]>t)
			t=z[i];
	}
	f[0]=t;
	h[0] = 0.0;
	g[0] = 1.0;
	for (i=1; i<nx/2; i++)
	{
		h[0] += (z[2*i]*z[2*i]-z[2*i+1])*(z[2*i]*z[2*i]-z[2*i+1]);

	}
	for (i=1; i<nx/2+1; i++)
	{
		g[0] *= z[2*i -1];
	}
}
void COP_10 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_10 */
{
	int i,j;
     sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	double t;
	t = z[0];
	for (i=0; i<nx; i++)
	{
		if(z[i]>t)
			t=z[i];
	}
	f[0]=t;
	h[0] = 0.0;
	h[1] = 0.0;
	for (i=1; i<nx+1; i++)
	{
		double m;
		m = 0.0;
		for(j=0;j<i;j++)
		{
			m += z[j];
		}
		h[0] += m*m;
	}
	for (i=0; i<nx-1; i++)
	{
		h[1] += (z[i]-z[i+1])*(z[i]-z[i+1]);
	}
    *g = 0;
}

void COP_11 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i;
     sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=0; i<nx; i++)
	{
		f[0] += z[i];
	}
	g[0] = 1.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] *z[i];
	}
	h[0]=0;
	for (i=0;i<nx-1; i++)
	{
		h[0] += (z[i]-z[i+1]) *(z[i]-z[i+1]);
	}
}

void COP_12 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_12 */
{
	int i;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=0; i<nx; i++)
	{
		f[0] += (z[i]*z[i] - 10.0*cos(2.0*PI*z[i]) + 10.0);
	}
	g[0] = 0.0;
	g[1] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + fabs(z[i]);
	}
	g[0] = -g[0] + 4;
	for (i=0;i<nx; i++)
	{
		g[1] = g[1] + z[i]*z[i];
	}
	g[1] = g[1] -4;
    *h = 0;
}

void COP_13 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=0; i<nx-1; i++)
	{
		f[0] += (100*(z[i]*z[i]-z[i+1])*(z[i]*z[i]-z[i+1])+(z[i]-1)*(z[i]-1));
	}
	g[0] = 0.0;
	g[1] = 0.0;
	g[2] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] += z[i]*z[i]-10*cos(2*PI*z[i]) + 10;
	}
	g[0] = g[0] - 100;
	for (i=0;i<nx; i++)
	{
		g[1] += z[i];
	}
	g[1] = g[1] -2*nx;
	for (i=0;i<nx; i++)
	{
		g[2] += z[i];
	}
	g[2] = -g[2] +5;
    *h = 0;
}

void COP_14 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i;
	double num1,num2;
	num1=0.0;
	num2=0.0;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=0; i<nx; i++)
	{
		num1=num1+z[i]*z[i];
	}
	num1=sqrt(num1/nx);
	for (i=0; i<nx; i++)
	{
		num2=num2+cos(2*PI*z[i]);
	}
	num2=num2/nx;
    f[0] = -20*exp(-0.2*num1)+20-exp(num2)+exp(1.0);
	h[0] = 0.0;
	g[0] = 0.0;
	for (i=0;i<nx; i++)
	{
		h[0] += z[i]*z[i];
	}
	h[0] = h[0] - 4;
	for (i=1;i<nx; i++)
	{
		g[0] = g[0] + z[i]*z[i];
	}
	g[0] = g[0] +1-fabs(z[0]);
}

void COP_15 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
    f[0] = z[0];
    for (i=1;i<nx; i++)
    {
       if (f[0] < z[i])
       {
           f[0] = z[i];
       }
    }
	h[0] = 0.0;
	h[0] =cos(f[0])+sin(f[0]);
	g[0] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + z[i]*z[i];
	}
	g[0] = g[0] -100*nx;
}

void COP_16 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i;
	double num1;//,num2;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	num1=0.0;
	for (i=0; i<nx; i++)
	{
		num1=num1+fabs(z[i]);
	}
	f[0]=f[0]+num1;
	g[0] = 0.0;
	h[0] =(cos(f[0])+sin(f[0]))*(cos(f[0])+sin(f[0]))-exp(cos(f[0])+sin(f[0]))-1+exp(1.0);
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + z[i]*z[i];
	}
	g[0] = g[0] -100*nx;
}

void COP_17 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	double num1,num2;
	num1=0.0;
	num2=1.0;
	for (i=0; i<nx; i++)
	{
		num1 =num1 + z[i]*z[i];
	}
	for (i=0; i<nx; i++)
	{
		num2=num2*cos(z[i]/sqrt(double(i+1)));
	}
	f[0]=num1/4000+1-num2;
	g[0] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + sgn(fabs(z[i])-num1+z[i]*z[i]-1.0);
	}
	g[0] = -g[0] + 1;
	h[0] = num1 - 4*nx;
}

void COP_18 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	double num1,num2;
	num1=0.0;
	num2=1.0;
	g[0] = 0.0;
	g[1] = 0.0;
	for (i=0;i<nx; i++)
	{
		g[0] = g[0] + fabs(z[i]);
	}
	g[0] = -g[0] + 1;
	for (i=0;i<nx; i++)
	{
		g[1] = g[1] + z[i]*z[i];
	}
	g[1] = g[1] -100*nx;
	for(i=0; i<nx-1; i++)
	{
		num1=num1+100*(z[i]*z[i]-z[i+1])*(z[i]*z[i]-z[i+1]);
	}
	for(i=0; i<nx; i++)
	{
		num2=num2*sin((z[i]-1)*PI)*sin((z[i]-1)*PI);
	}
	h[0]=num1+num2;
    double temp = 0.0;
	f[0] = 0.0;
    for (i=0; i<nx; i++)
    {
        if(fabs(z[i])<0.5)
            temp=z[i];
        else
            temp=0.5*round(2*z[i]);
        f[0] += (temp*temp - 10.0*cos(2.0*PI*temp) + 10.0);
    }
}

void COP_19 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	for (i=0; i<nx; i++)
	{
		f[0] += sqrt(fabs(z[i])) + 2*sin(pow(z[i],3));
	}
	g[0] = 0.0;
	g[1] = 0.0;
	for (i=0;i<nx-1; i++)
	{
		g[0] += -10*exp(-0.2*sqrt(z[i]*z[i]+z[i+1]*z[i+1]));
	}
	g[0] = g[0] + (nx-1)*10/exp(-5.0);
	for (i=0;i<nx; i++)
	{
		g[1] = g[1] + sin(2*z[i])*sin(2*z[i]);
	}
	g[1] = g[1] -0.5*nx;
    *h = 0;
}

void COP_20 (double *x, double *f, double *g, double *h, int nx, double *Os, double *Mr, int s_flag, int r_flag) /* COP_O1 */
{
	int i;//,j;
    sr_func (x, z, nx, Os, Mr, 5.12/100.0, s_flag, r_flag); /* shift and rotate */
	f[0] = 0.0;
	double num1=0.0,num2=0.0;
	for (i=0; i<nx-1; i++)
	{
		num1 = num1+0.5+ (pow(sin(sqrt(z[i]*z[i]+z[i+1]*z[i+1])),2) - 0.5)/ pow((1+0.001*sqrt(z[i]*z[i]+z[i+1]*z[i+1])),2);
	}
    num2=0.5+ (pow(sin(sqrt(z[nx-1]*z[nx-1]+z[0]*z[0])),2) - 0.5)/ pow((1+0.001*sqrt(z[nx-1]*z[nx-1]+z[0]*z[0])),2);
	f[0]=num1+num2;
	double num3=0.0;
	for (i=0;i<nx; i++)
	{
		num3=num3+z[i];
	}
	g[0] = cos(num3)*cos(num3)-0.25*cos(num3)-0.125;
	g[1] = exp(cos(num3))-exp(0.25);
    *h = 0;
}


void sr_func (double *x, double *sr_x, int nx, double *Os,double *Mr, double sh_rate, int s_flag,int r_flag) /* shift and rotate */
{
	//int i;
    if (r_flag==1)
    {
        shiftfunc(x, y, nx, Os);
        rotatefunc(y, sr_x, nx, Mr);
    }
    else
    {
        shiftfunc(x, sr_x, nx, Os);
    }
}

void shiftfunc (double *x, double *xshift, int nx,double *Os)
{
	int i;
	for (i=0; i<nx; i++)
	{
		xshift[i]=x[i]-Os[i];
	}
}

void rotatefunc (double *x, double *xrot, int nx,double *Mr)
{
	int i,j;
	for (i=0; i<nx; i++)
	{
		xrot[i]=0;
		for (j=0; j<nx; j++)
		{
 			xrot[i]=xrot[i]+x[j]*Mr[i*nx+j];
		}
	}
}

int  sgn(double val)
{
    if (val<0.0)
            return -1;
    else if (val > 0.0)
            return 1;
    else
        return 0;
}

double round(double val)
{
  return (val>0.0) ? floor(val + 0.5) : ceil (val-0.5);
}


void loadShiftData(int func_num, int dim, double *pV )
{
		/* Load shift_data */
	    FILE *fpt=NULL;
		char FileName[256];
		sprintf(FileName, "inputData/shift_data_%d.txt", func_num);
		fpt = fopen(FileName,"r");
		if (fpt==NULL)
		{
			printf("\n Error: Cannot open input file for reading \n");
		}
		if (pV==NULL)
			printf("\nError: there is insufficient memory available!\n");
		for(int i=0;i<dim;i++)
		{
			fscanf(fpt,"%lf",&pV[i]);
		}
		fclose(fpt);

}

void loadRotateData(int func_num, int dim, double *pM )
{
    FILE *fpt=NULL;
    char FileName[256];

    sprintf(FileName, "inputData/M_%d_D%d.txt",func_num ,dim);
    if ( f5_flag == 1 && func_num == 5)
    {
       sprintf(FileName, "inputData/M1_%d_D%d.txt",func_num ,dim);
    }
    if ( f5_flag == 2 && func_num == 5)
    {
       sprintf(FileName, "inputData/M2_%d_D%d.txt",func_num ,dim);
    }
    fpt = fopen(FileName,"r");
    if (fpt==NULL)
    {
        printf("\n Error: Cannot open input file for reading \n");
    }
    if (pM==NULL)
        printf("\nError: there is insufficient memory available!\n");
    for (int i=0; i<dim*dim; i++)
    {
        fscanf(fpt,"%lf",&pM[i]);
    }
    fclose(fpt);
}
