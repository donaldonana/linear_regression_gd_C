
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

double theta[]={0.0,0.0};                         //Fitting parameters
int total_samples = DATA_SIZE;

double x[DATA_SIZE],y[DATA_SIZE],err[DATA_SIZE];
double n = 700.0f,sumerr0,sumerr1,sumsqerr;         //Useful variables
// double alpha=LEARNING_RATE;

int main()
{
    
    int epoch=0,total_epochs = EPOCHS;
	double cost;
    int count = 0;

    printf("Loading Dataset from dataset/theData.csv ...\n\n");
	FILE* stream = fopen("data/theData.csv", "r");
    if (stream == NULL) {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }

    // Load Data 
    while (fscanf(stream, "%lf,%lf", &x[count], &y[count]) == 2) {

        count = count+1;
    }


       // Uncomment to display loaded data
	   // for (int i = 0; i < (int)total_samples; i++) {
	   //     printf(" x[%d]:%lf , y[%d]:%lf\n", i,x[i], i,y[i]);
	   // }


	printf("Training parameters using Gradient Descent..\n\n");
	double* y_pred = prediction(x, theta, DATA_SIZE);
    cost=MSE(y_pred, y, (int)total_samples);

    printf("%lf\n", cost);

    while(epoch < total_epochs){
        grad_descent(y_pred, y, x, theta, (double)total_samples);
        y_pred = prediction(x, theta, DATA_SIZE);
        cost=MSE(y_pred, y, (int)total_samples);

        printf("\nEpoch: %d Cost: %lf Theta0: %lf Theta1: %lf \n",epoch,cost,theta[0],theta[1]);

        epoch++;

    }


    printf("\n\n\n Parameters after %d iterations",epoch);
	printf("\n\tTheta0 : %lf    Theta1 :  %lf    MSE :  %lf", theta[0],theta[1],cost);


    // int loop = 500 ;
    // float x, alpha = 0.005 ; 
    // x = 0.1 ; 
    // for (int i = 0; i < loop; ++i)
    // {
    // 	x = x - alpha*d_f(x);
    // }

	return 0 ;

}
