class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }

private:
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {
        bool allSame = true;

        for (int i = 0; i < n && allSame; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[r][c] != grid[r + i][c + j]) {
                    allSame = false;
                    break;
                }
            }
        }

        if (allSame) {
            return new Node(grid[r][c] == 1, true);
        }

        int mid = n / 2;
        Node* topLeft = dfs(grid, mid, r, c);
        Node* topRight = dfs(grid, mid, r, c + mid);
        Node* bottomLeft = dfs(grid, mid, r + mid, c);
        Node* bottomRight = dfs(grid, mid, r + mid, c + mid);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};