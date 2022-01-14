#ifndef DEF_UTILS
#define DEF_UTILS

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define DATA_SIZE 100
#define EPOCHS 450
#define LEARNING_RATE 0.005





void grad_descent(double *y_pred , double *y, double *x , double *theta , int n);

double* prediction(double* X, double *theta, int n);

float MSE(double *y_pred , double *y, int n) ; 

float f( float x ) ; 

float d_f(float x) ;






#endif
