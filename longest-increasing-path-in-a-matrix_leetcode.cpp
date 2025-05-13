//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/?envType=problem-list-v2&envId=graph


class Solution {
public:
    int solve(vector<vector<int>>&mat,int row,int col,int com,vector<vector<int>>&visit,vector<vector<int>>&dp){
        if(row>=mat.size() or col>=mat[0].size()) return 0;
        if(com>=mat[row][col]) return 0;
        if(visit[row][col]==1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        visit[row][col]=1;
        int k=max(solve(mat,row-1,col,mat[row][col],visit,dp),solve(mat,row+1,col,mat[row][col],visit,dp));
        k=max(k,solve(mat,row,col+1,mat[row][col],visit,dp));
        k=max(k,solve(mat,row,col-1,mat[row][col],visit,dp));
        visit[row][col]=0;
        return dp[row][col]=1+k;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>visit(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,solve(matrix,i,j,matrix[i][j]-1,visit,dp));
                // cout<<solve(matrix,i,j,matrix[i][j]-1,visit)<<endl;
            }
        }
        return ans;
    }
};
