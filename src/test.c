#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
   
   // int loop = 500 ;
    // float x, alpha = 0.005 ; 
    // x = 0.1 ; 
    // for (int i = 0; i < loop; ++i)
    // {
    //   x = x - alpha*d_f(x);
    // }
   
   double y[5] = {1 , 2 , 3 , 4 };
   double x[5] = {1 , 2 , 3 , 4 };
   
   float **bacht_y = bacht_data(y, x , 2, 4) ;
   
printf("%lf",bacht_y[1][1]);
   
}
	
