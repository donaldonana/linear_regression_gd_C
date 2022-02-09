
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

double theta[]={0.0,0.0};
int total_samples = DATA_SIZE;
double x[DATA_SIZE], y[DATA_SIZE];

int main()
{

    int epoch=0,total_epochs = EPOCHS;
	double cost;
    int count = 0;

    /**
    *****************************
    *                           *
    *       Load THE DATA       *
    *                           *
    *****************************
    **/
    printf("Loading Dataset from dataset/theData.csv ...\n\n");
	FILE* stream = fopen("data/theData.csv", "r");
    if (stream == NULL) {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }
    while (fscanf(stream, "%lf,%lf", &x[count], &y[count]) == 2) {

        count = count+1;
    }
    // Uncomment to display loaded data
    // for (int i = 0; i < (int)total_samples; i++) {
    //   printf(" x[%d]:%lf , y[%d]:%lf\n", i,x[i], i,y[i]);
    // }



    /**
    ******************************
    *                            *
    *       Trainning Phase      *
    *                            *
    ******************************
    **/


    // float ***bacht_datas = bacht_data(y, x , BACHT_SIZE, DATA_SIZE) ;
    // float **bacht_y = bacht_datas[0];
    // float **bacht_x = bacht_datas[1];
    //
    // int num_bacht = DATA_SIZE / BACHT_SIZE ;


    printf("Training parameters using Gradient Descent..\n\n");

    double* y_pred = prediction(x, theta, DATA_SIZE);
    cost=MSE(y_pred, y, (int)total_samples);
    printf("-----Initialisation with Theta0: %lf Theta1: %lf Cost: %lf-----\n", theta[0], theta[1], cost);

    while(epoch < total_epochs){

        grad_descent(y_pred, y, x, theta, (double)total_samples);
        y_pred = prediction(x, theta, DATA_SIZE);
        cost=MSE(y_pred, y, (int)total_samples);
        printf("\nEpoch: %d Theta0: %lf Theta1: %lf Cost: %lf \n",epoch,theta[0],theta[1],cost);
        epoch++;

    }


    printf("\n\n\n Results after %d iterations",epoch);
    printf("\n\tTheta0 (a) : %lf    Theta1 (b) :  %lf    MSE :  %lf \n", theta[0],theta[1],cost);
    //



	return 0 ;

}
