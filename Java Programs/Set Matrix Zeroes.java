/*
Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
*/
class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int col0 = 1;
        for(int i=0;i<n;++i){
            if(matrix[i][0]==0)col0=0;
            for(int j=1;j<m;++j){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=1;--j)
                if(matrix[i][0]==0 || matrix[0][j]==0)matrix[i][j]=0;
            
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
}