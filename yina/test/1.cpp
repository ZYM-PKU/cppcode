#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int matrix[m+1][n+1]={0};
        for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1])+grid[i-1][j-1];
        }
        return matrix[m][n];
    }
};