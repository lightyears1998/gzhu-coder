/**
 * 时间：17-08-15
 *
 * 作者：仙女（学姐）
 * 
 * 题目：
 * 用*号输出一个爱心。例如这样
 *  
 * 哈哈哈哈。
 * 发挥你们想象力输出爱心吧！反正去年我没做出来！
 *
 */

/**
 * 16x6 爱心(?! (´・ω・`) )：
 *
 *     **      **
 *    ****     ****
 *  ****************
 *   **************
 *     **********
 *        ****
 *
 */      

#include <stdio.h>

void drawing_void(int count);
void drawing_stars(int count);

int main(void)
{
    /* 行，列和初始星星 */
    // 行数和列数必须为偶数
    int line = 24;
    int space = 64;
    int star = 4;

    // 在每一行绘制图形
    for(int l=1; l <= line; l++)
    {
        int step;
        int counted_star;
        int counted_void;
        // 前半部分
        if(l <= line/2)
        {
            /* 绘制形式 空格 星星 空格 中轴线 空格 星星 空格 */
            step= (space-star) / (line/2 -1);
            counted_star = space - (line/2 - l) * step;
            counted_void = (line/2 -l) * step;
            drawing_void( counted_void/4 );
            drawing_stars( counted_star/2 );
            drawing_void( counted_void/4 );
            drawing_void( counted_void/4 );
            drawing_stars( counted_star/2 );
            drawing_void( counted_void/4 );
        }
        // 后半部分
        else
        {
            /* 绘制形式 空格 星星 中轴线 星星 空格 */
            step = (space - star) / (line/2);
            counted_star = space - (l-line/2) * step;
            counted_void = (l-line/2) * step;
            drawing_void(counted_void/2);
            drawing_stars(counted_star/2);
            drawing_stars(counted_star/2);
            drawing_void(counted_void/2);
        }
        printf("\n");
    }
    return 0;
}

void drawing_void(int count)
{
    int i = 0;
    while(i<=count)
    {
        printf(" ");
        i++;
    }
}

void drawing_stars(int count)
{
    int i = 0;
    while(i<=count)
    {
        printf("*");
        i++;
    }
}
