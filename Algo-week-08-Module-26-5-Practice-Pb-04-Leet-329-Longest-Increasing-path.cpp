#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& Matrix) {
        vector<vector<int>>memo(Matrix.size(),vector<int>(Matrix[0].size(),0));//0->initially all col value = 0
        int Max =0;
        for(int i = 0;i<Matrix.size();i++)
        {
            for(int j=0;j<Matrix[0].size();j++)
            {
                Max = max(Max,lip(Matrix,i,j,memo));
            }
        }
        
        return Max;
    }
    
    
    int lip(vector<vector<int>>& Matrix,int i,int j,vector<vector<int>>& memo)
    {
        if(i<0 || j<0 || i>=Matrix.size() || j>=Matrix[0].size())
            return 0;
        if(memo[i][j]>0) return memo[i][j];
        
        int currentmax = 1;
        
        //down neighbour  ---helpful neighbour
        
        if(i+1<Matrix.size() && i+1>=0 && Matrix[i+1][j]>Matrix[i][j])
        {
            currentmax = max(currentmax, 1+lip(Matrix,i+1,j,memo));
        }
        //right neighbour ->i,j+1
        if(j+1 < Matrix[0].size() && j+1>=0 && Matrix[i][j+1] > Matrix[i][j])
        {
            currentmax = max(currentmax, 1+lip(Matrix,i,j+1,memo));
        }
        //left neighbour ->i,j-1
        if(j-1 < Matrix[0].size() && j-1>=0 && Matrix[i][j-1] > Matrix[i][j])
        {
            currentmax = max(currentmax, 1+lip(Matrix,i,j-1,memo));
        }
        //top neighbour ->i-1,j
        
        if(i-1 < Matrix.size() && i-1>=0 && Matrix[i-1][j] > Matrix[i][j])
        {
            currentmax = max(currentmax, 1+lip(Matrix,i-1,j,memo));
        }
        memo[i][j] = currentmax;
        return currentmax;
    }
};
int main()
{
    
}