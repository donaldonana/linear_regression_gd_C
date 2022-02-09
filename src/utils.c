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


/**
* MSE (Mean Square Error) function
* @param y_pred : The predicted values
* @param y : Real values
* @param n : y_pred and y length
* @description : This function compute the MSE beetwen the real and  predicted values
* @return: The MSE beetwen y_pred, y 
**/
float MSE(double *y_pred , double *y, int n) {

	float diff, sum_sq = 0.0 ;

	for (int i = 0; i < n; ++i)
	{
		diff = y_pred[i] - y[i] ;
		sum_sq += pow(diff,2) ;

	}

	return sum_sq / n ;
}


/**
* prediction function
* @param X : double array represent the dependent variable
* @param theta : double array were thetha[0] a.k.a (a) is a slope and thetha[1] a.k.a (b) is the intercept
* @param n : X length
* @description : This function compute the independent variables with the actual theta parameters
* @return : Compute and return y = aX + b 
**/
double* prediction(double* X, double *theta, int n){

	double* Y = malloc(sizeof(double)*n) ;

	for (int i = 0; i < n; ++i)
	{
		Y[i] = theta[0] + theta[1]*X[i];
	}

	return Y;

}


/**
* prediction grad_descent
* @param y_pred : The predicted values
* @param y : Real values
* @param x : double array represent the dependent variable
* @param theta : double array parameters were thetha[0] a.k.a (a) is a slope and thetha[1] a.k.a (b) is the intercept
* @param n : y_pred , y and x length
* @description : the gradient descent algoritm to update the parameters
* @return : void function, he juste update the theta array parameters *
*/
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


float **allocate_dynamic_float_matrix(int row, int col)
{
    float **ret_val;
    int i;

    ret_val = malloc(sizeof(float *) * row);
    if (ret_val == NULL)
    {
        perror("memory allocation failure");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < row; ++i)
    {
        ret_val[i] = malloc(sizeof(float) * col);
        if (ret_val[i] == NULL)
        {
            perror("memory allocation failure");
            exit(EXIT_FAILURE);
        }
    }

    return ret_val;
}

void deallocate_dynamic_float_matrix(float **matrix, int row)
{
    int i;

    for (i = 0; i < row; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
}


float **bacht_data(double *y, double *x , int bacht_size, int n) 
{
	
	int num_bacht, i = -1;
	num_bacht = n / bacht_size;
	float **bacht_y = allocate_dynamic_float_matrix(num_bacht, bacht_size);
	float **bacht_x = allocate_dynamic_float_matrix(num_bacht, bacht_size);
	
	for(int row = 0 ; row < num_bacht ; row++)
	{
	
		for( int col = 0 ; col < bacht_size;  col++)
		{
			i = i + 1;
			bacht_y[row][col] = y[i];
			bacht_x[row][col] = x[i];
			
		}
	
	
	}
	
	return bacht_y ;






}
