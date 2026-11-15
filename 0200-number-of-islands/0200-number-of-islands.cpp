class Solution {
public:

    void DFS(vector<vector<char>>& grid, int i, int j, int row, int col) {

        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] != '1'){
            return;
        }

        grid[i][j] = '0';

        DFS(grid, i-1, j, row, col);
        DFS(grid, i+1, j, row, col);
        DFS(grid, i, j-1, row, col);
        DFS(grid, i, j+1, row, col);
    }

    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                if(grid[i][j] == '1'){
                    count++;
                    DFS(grid, i, j, row, col);
                }
            }
        }

        return count;
    }
};