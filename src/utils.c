#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"




float f( float x ) {

	return pow(x,4) - 3*pow(x,3) + 2 ;
}

float d_f(float x){

	return 4*pow(x,3) - 9*pow(x,2) ;
}

float MSE(double *y_pred , double *y, int n) {

	float diff, sum_sq = 0.0 ;

	for (int i = 0; i < n; ++i)
	{
		diff = y_pred[i] - y[i] ;
		sum_sq += pow(diff,2) ;

	}

	return sum_sq / n ;
}


double* prediction(double* X, double *theta, int n){

	double* Y = malloc(sizeof(double)*n) ;

	for (int i = 0; i < n; ++i)
	{
		Y[i] = theta[0] + theta[1]*X[i];
	}

	return Y;

}

void grad_descent(double *y_pred , double *y, double *x , double *theta , int n){

	
	double da , db ; 
	double suma = 0.0 , sumb = 0.0 ;

	// double* params = malloc(sizeof(double)*2);

	for (int i = 0; i < n; ++i)
	{
		// printf("----%lf----\n", (y_pred[i] - y[i]));
		suma += ( (y[i] - y_pred[i]) ) ; 
	}

	for (int i = 0; i < n; ++i)
	{
		sumb = ( sumb + (x[i]*(y[i] - y_pred[i])) );
	}

	da = ( (-2.0/(double)n) * (suma) );
	db = ( (-2.0/(double)n) * (sumb) );

	// printf("%lf---%lf\n", da, db);

	theta[0] = ( theta[0] - ((LEARNING_RATE)*da) );
	theta[1] = ( theta[1] - ((LEARNING_RATE)*db) );
	printf("Theta0: %lf Theta1: %lf",theta[0],theta[1]);
	
}
