//
//  03_maze.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/16.
//
#include <iostream>
using namespace std;

int success=0;    //初始值为0
int a[5][5] = {
    {0,1,0,0,0},
    {0,1,0,1,0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}
};      //迷宫数组
int judge(int i,int j,int x,int y)            //judge函数，i，j为每次判断格子坐标；x，y是终点坐标
{
    a[i][j]=1;                            //每个当前可行格标记为‘1’
    if(i==x && j==y){
        success=1;
        return success;
    }//到达终点时标记success为1
    if(success!=1 && a[i][j+1]==0) judge(i,j+1,x,y);      //以下是四个方位格子可行性的判断
    if(success!=1 && a[i+1][j]==0) judge(i+1,j,x,y);
    if(success!=1 && a[i-1][j]==0) judge(i-1,j,x,y);
    if(success!=1 && a[i][j-1]==0) judge(i,j-1,x,y);
    if(success!=1)              //每次返回时若此路不通将‘1’还原为‘0’
        a[i][j]=0;
    return success;             //返回值为success
}

int test_maze(){
    cout<<judge(0, 0, 4, 4)<<endl;
    return 0;
}
