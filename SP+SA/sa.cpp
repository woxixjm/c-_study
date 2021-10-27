#include <iostream>
#include </home/xian/Desktop/c++_study/SP+SA/sp.cpp> 
#include </home/xian/Desktop/c++_study/SP+SA/sa.h>
#include <cmath>

// yitiantiantian
int main (){
    double T = T0; //initialization
    double curr_cost;
    double trial_cost;
    double delta_cost;
    double r;

    // SP init_sol;
    SP curr_sol;
    SP trial_sol;
    result ret_finally;

    srand((int)time(0));
    // curr_cost = COST(curr_sol);
    // char S1[BLOCK_NUM] = {'a', 'c', 'd', 'b', 'e'};
    // char S2[BLOCK_NUM] = {'c', 'd', 'a', 'e', 'b'};
    char S1[BLOCK_NUM] = {'a', 'b', 'c', 'd', 'e',};
    char S2[BLOCK_NUM] = {'a', 'b', 'c', 'd', 'e', };

    int widths[BLOCK_NUM] = {8, 8, 6, 3, 5,};
    int heights[BLOCK_NUM] = {4, 3, 5, 5, 6,};

    // for (int i = 0;i < BLOCK_NUM;i++){  //initial curr_sol
    //     curr_sol.S1[i] = S1[i];
    //     curr_sol.S2[i] = S2[i];
    //     curr_sol.widths[i] = widths[i];
    //     curr_sol.heights[i] = heights[i];
    // }
    curr_sol.set_value(S1, S2, widths, heights); //initial curr_sol
    int i = 0;
    curr_cost = Cost(curr_sol);
    while(T > T_min) // SA process
    {
        i = 0;
       while(i < EACH_T_NUM)
       {
            i++;
            trial_sol = Perturb(curr_sol);
            trial_cost = Cost(trial_sol);
            delta_cost = trial_cost - curr_cost;
            if(delta_cost < 0)  //accept solutions with reduced costs 
            {
                curr_cost = trial_cost;
                curr_sol = trial_sol;
            }
            else
            {
                r = (double)random(100001)/100000;  //generate a number between 0 and 1
                if(r < exp(-((delta_cost*100)/T)))//accept solutions without reduced costs Under certain probability 
                {
                    curr_cost = trial_cost;
                    curr_sol = trial_sol;
                }
            }
        }
        T = RATE*T;   // the rate of SA
        cout << "rurrent T:" << T;
        cout << "    current cost" << curr_cost << endl;
    }
    ret_finally = curr_sol.Sp2Res();

    for(i = 0;i < BLOCK_NUM;i++)
    {
        cout << ret_finally.x_coordinates[i] << endl;
    }        
    cout << endl;
    for(i = 0;i < BLOCK_NUM;i++){
         cout << ret_finally.y_coordinates[i] << endl;
    }
    cout << endl;
    for(i = 0;i < BLOCK_NUM;i++)
    {
        cout << ret_finally.res_widths[i] << endl;
    }        
    cout << endl;
    for(i = 0;i < BLOCK_NUM;i++){
         cout << ret_finally.res_height[i] << endl;
    }    
    // cout << endl;
    // for(i = 0;i < BLOCK_NUM;i++){
    //      cout << curr_sol.widths[i] << endl;
    // }    

    // for(i = 0;i < BLOCK_NUM;i++){
    //      cout << curr_sol.heights[i] << endl;
    // }    

    cout << Cost(curr_sol) << endl;
} 

double Cost(SP curr_sol){
    double curr_cost;
    result ret;
    ret = curr_sol.Sp2Res();
    curr_cost = ret.H *ret.W; //+ (10*(ret.W-ret.H)*(ret.W-ret.H));
    return curr_cost;
}            

SP Perturb(SP curr_sol){
    SP trial_sol;
    trial_sol = curr_sol;
    switch(random(3)){ // random to perturb the sp
        case 0: // exchange blocks position
            trial_sol.exchange_blocks(); 
            break; //
        case 1: // revolve block 
            trial_sol.revolve_blocks();
            break;
        case 2: // random disruption 
            trial_sol.random_disruption();
            break; 
    default :
    cout << "switch erro"; // 可选的;
    return trial_sol;
    }
}
