class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int xr = 0;
        int m = n * n; // total numbers from 1 to n^2

        // First pass: XOR all the elements of the grid and their expected index (1 to n^2)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                xr ^= grid[i][j] ^ (n * i + j + 1); // +1 for 1-based index
            }
        }

        // Find the rightmost set bit in the xor result
        int bitno = 0;
        while ((xr & (1 << bitno)) == 0) {
            bitno++;
        }

        int zero = 0, ones = 0;

        // Separate the numbers based on the rightmost set bit
        for (int i = 1; i <= m; i++) {
            if ((i & (1 << bitno)) == 0) {
                zero ^= i;
            } else {
                ones ^= i;
            }
        }

        // Separate the grid elements based on the same bit
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((grid[i][j] & (1 << bitno)) == 0) {
                    zero ^= grid[i][j];
                } else {
                    ones ^= grid[i][j];
                }
            }
        }

        // Check which one is missing and which one is duplicated
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == zero) count++;
            }
        }

        // If zero appears in the grid, it's the duplicate, otherwise, ones is the duplicate
        if (count == 0) return {ones, zero}; // zero is missing, ones is duplicate
        return {zero, ones}; // zero is duplicate, ones is missing
    }
};
