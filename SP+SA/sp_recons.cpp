// # include</home/xian/Desktop/c++_study/sp.h>
// # include<iostream>
// # include<map>
// # include</home/xian/Desktop/c++_study/sp_recons.h>

using namespace std;

result Sp2Res(char S1[BLOCK_NUM], char S2[BLOCK_NUM], int widths[BLOCK_NUM], int heights[BLOCK_NUM]){
    char S1_R[BLOCK_NUM];
    x_y_result x_ret;
    x_y_result y_ret;
    result ret;

    x_ret = LCS(S1, S2, widths); //compute x-coordinates,total W
    for(int i=0;i<BLOCK_NUM;i++){    // reverse S1
        S1_R[i] = S1[BLOCK_NUM -1 - i]; 
    }
    y_ret = LCS(S1_R, S2, heights);//compute y-coordinates,total H

   for(int i = 0;i < BLOCK_NUM;i++){ //save x and y coordinates
        ret.x_coordinates[i] = x_ret.coordinates[i];
    }
   for(int i = 0;i < BLOCK_NUM;i++){
        ret.y_coordinates[i] = y_ret.coordinates[i];
    }
    ret.W = x_ret.L;
    ret.H  = y_ret.L;

    return ret;
}

void SP :: LCS(char S1[], char S2[], int weights[]){
    map<char, int> block_order;
    map<char, int> position;
    map<char, int>weight;

    char Standard[BLOCK_NUM] = {'a', 'b', 'c', 'd', 'e'};
    int lenghts[BLOCK_NUM];
    char block;
    int index;
    int t_span;
    static x_y_result ret;
    // static int coordinates[BLOCK_NUM];
    // static int *L;

    for(int i = 0;i < BLOCK_NUM;i++){
        weight[Standard[i]] = weights[i];
        block_order[S2[i]] = i;
        lenghts[i] = 0;
    }
    
    for(int i = 0;i < BLOCK_NUM;i++){ 
        block = S1[i];
        index = block_order[block];
        position[block] = lenghts[index];
        // coordinates[Standard[i]] = position[block]; // save each coordinates
        t_span = position[block] + weight[block];
        for(int j = index;j<BLOCK_NUM;j++){
            if(t_span > lenghts[j]){
               lenghts[j] = t_span; 
            }
            else{
                break;
            }
        }
    }
ret.L = lenghts[4];
for(int i = 0;i < BLOCK_NUM;i++){
ret.coordinates[i] = position[Standard[i]];// save each coordinates
}
return  ret;
}

