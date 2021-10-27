# include</home/xian/Desktop/c++_study/SP+SA/sp.h>
# include<iostream>
# include<map>
# include</home/xian/Desktop/c++_study/SP+SA/sp_recons.h>

using namespace std;

result 
SP::Sp2Res()
{
    char S1_R[BLOCK_NUM];
    x_y_result x_ret;
    x_y_result y_ret;
    // result ret;

    x_ret = this->LCS(m_S1, m_S2, m_widths); //compute x-coordinates,total W
    // x_ret = x.get_result();
    for(int i=0;i<BLOCK_NUM;i++){    // reverse S1
        S1_R[i] = m_S1[BLOCK_NUM -1 - i]; 
    }
    y_ret = this->LCS(S1_R, m_S2, m_heights);//compute y-coordinates,total H
    // y_ret = y.get_result();

    for(int i = 0;i < BLOCK_NUM;i++){ //save x and y coordinates
        ret.x_coordinates[i] = x_ret.coordinates[i];
    }
    for(int i = 0;i < BLOCK_NUM;i++){
        ret.y_coordinates[i] = y_ret.coordinates[i];
    }
    for(int i = 0;i < BLOCK_NUM;i++){ //save x and y coordinates
        ret.res_widths[i] = m_widths[i];
    }
    for(int i = 0;i < BLOCK_NUM;i++){
        ret.res_height[i] = m_heights[i];
    }
    ret.W = x_ret.L;
    ret.H  = y_ret.L;

    return ret;
}

x_y_result 
SP::LCS(char S1[], 
        char S2[], 
        int weights[])
{
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
    return ret;
}

void 
SP::set_value(char S1[BLOCK_NUM], 
              char S2[BLOCK_NUM], 
              int widths[BLOCK_NUM], 
              int heights[BLOCK_NUM])
{
    for(int i=0; i<BLOCK_NUM; i++){   //初始化成员变量
    m_S1[i] = S1[i];
    m_S2[i] = S2[i];
    m_widths[i] = widths[i];
    m_heights[i] = heights[i];
    }
}
// x_y_result SP::get_result(){
//     return ret_xy;
// }

void
SP::exchange_blocks()
{
    int r;
    int r_0;
    char container_char;

    r = random(5);
    r_0 = random(5);
    container_char = m_S1[r];
    m_S1[r] = m_S1[r_0];
    m_S1[r_0] = container_char;
    container_char = m_S2[r];
    m_S2[r] = m_S2[r_0];
    m_S2[r_0] = container_char;
}

void 
SP::revolve_blocks()
{
    int r;
    int container_int;

    r = random(5);
    container_int = m_heights[r];
    m_heights[r] = m_widths[r];
    m_widths[r] = container_int;
};

void
SP::random_disruption() 
{
    int r;
    int r_0;

    r = random(5); // exchang S2 sp character from r index  to r_0 index 
    r_0 = random(5);
    char container_char;
    container_char = m_S1[r];
    m_S1[r] = m_S1[r_0];
    m_S1[r_0] = container_char;

    r = random(5); // exchang S2 sp character from r index  to r_0 index 
    r_0 = random(5);
    container_char = m_S2[r];
    m_S2[r] = m_S2[r_0];
    m_S2[r_0] = container_char;
}