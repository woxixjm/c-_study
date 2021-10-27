
#ifndef __SA_H__
#define __SA_H__ 
#include </home/xian/Desktop/c++_study/SP+SA/sp.h>
#include <stdlib.h>
#define T0 10000000000      //SA temperature
#define T_min 5
#define EACH_T_NUM 50
#define ALPHA 0.5 // costfunction select parameter
#define RATE 0.999 // the rate of SA
#define random(x) (rand()%x)

// struct sol
// {
//     char S1[BLOCK_NUM];
//     char S2[BLOCK_NUM];

//     int widths[BLOCK_NUM]; 
//     int heights[BLOCK_NUM];
//     /* data */
//     char Standard[BLOCK_NUM] = {'a', 'b', 'c', 'd', 'e'};
// };

double Cost(SP curr_sol);
SP Perturb(SP curr_sol);
#endif