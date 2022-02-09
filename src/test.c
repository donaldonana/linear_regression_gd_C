// #include <stdio.h>
// #include <stdlib.h>
// #include "utils.h"
//
// int main()
// {
//
//    // int loop = 500 ;
//     // float x, alpha = 0.005 ;
//     // x = 0.1 ;
//     // for (int i = 0; i < loop; ++i)
//     // {
//     //   x = x - alpha*d_f(x);
//     // }
//
// //    double y[5] = {1 , 2 , 3 , 4 };
// //    double x[5] = {1 , 2 , 3 , 4 };
// //
// //    float ***bacht_datas = bacht_data(y, x , 2, 4) ;
// //    float **bacht_y = bacht_datas[0];
// //    float **bacht_x = bacht_datas[1];
// //
// //
// // printf("%lf",bacht_y[1][1]);
// // printf("%lf",bacht_x[1][1]);
//
// // for (int b  = 0; b < num_bacht; b++) {
// //
// //   printf("y = %lf",bacht_y[b][0]);
// //   printf(" and x = %lf \n",bacht_x[b][0]);
// //   // printf(" x[%d]:%lf , y[%d]:%lf\n", i,x[i], i,y[i]);
// //
// // }
//     srand(time(NULL));
//     int randomnumber;
//     randomnumber = (rand() % 10) + 1;
//     printf("%d\n", randomnumber);
//     return 0;
//
// }



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


    double ***bacht_datas = bacht_data(y, x , BACHT_SIZE, DATA_SIZE) ;
    double **bacht_y = bacht_datas[0];
    double **bacht_x = bacht_datas[1];

    int num_bacht = DATA_SIZE / BACHT_SIZE ;
    printf("(****%d****)\n", num_bacht);





    printf("Training parameters using Gradient Descent..\n\n");

    srand(time(NULL));
    int randombacht;
    randombacht= (rand() % num_bacht);

    double* y_pred = prediction(bacht_x[randombacht], theta, DATA_SIZE);
    printf("(****%d****)\n", num_bacht);
    cost=MSE(y_pred, bacht_y[randombacht], (int)total_samples);
    printf("-----Initialisation with Theta0: %lf Theta1: %lf Cost: %lf-----\n", theta[0], theta[1], cost);

    while(epoch < total_epochs){

      srand(time(NULL));
      int randombacht;
      randombacht= (rand() % num_bacht) ;

        grad_descent(y_pred, bacht_y[randombacht], bacht_x[randombacht], theta, (double)total_samples);
        y_pred = prediction(bacht_x[randombacht], theta, DATA_SIZE);
        cost=MSE(y_pred, bacht_y[randombacht], (int)total_samples);
        printf("\nEpoch: %d Theta0: %lf Theta1: %lf Cost: %lf \n",epoch,theta[0],theta[1],cost);
        epoch++;

    }


    printf("\n\n\n Results after %d iterations",epoch);
    printf("\n\tTheta0 (a) : %lf    Theta1 (b) :  %lf    MSE :  %lf \n", theta[0],theta[1],cost);
    //



	return 0 ;

}
