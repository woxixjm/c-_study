#ifndef __SP_H__
#define __SP_H__ 
#include <cmath>

#define random(x) (rand()%x)
#define BLOCK_NUM 5

struct x_y_result
{
    int coordinates[BLOCK_NUM];
    int L;
};

struct result
{
    int x_coordinates[BLOCK_NUM];
    int y_coordinates[BLOCK_NUM];
    double W;
    double H;
    int res_widths[BLOCK_NUM];
    int res_height[BLOCK_NUM];
};


class SP{
private:
    x_y_result ret_x;
    x_y_result ret_y;
    result ret;
    char m_S1[BLOCK_NUM];
    char m_S2[BLOCK_NUM];
    int m_widths[BLOCK_NUM];
    int m_heights[BLOCK_NUM];
    char m_Standard[BLOCK_NUM] = {'a', 'b', 'c', 'd', 'e'};

public:
    void set_value(char S1[BLOCK_NUM], char S2[BLOCK_NUM], int widths[BLOCK_NUM], int heights[BLOCK_NUM]);
    void exchange_blocks();
    void revolve_blocks();
    void random_disruption();
    result Sp2Res();
    x_y_result LCS(char S1[], char S2[], int weights[]);
    result get_result();

};

#endif