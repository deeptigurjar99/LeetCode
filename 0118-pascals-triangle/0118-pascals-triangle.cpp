class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        // First base case; if user requests zero rows, they get an empty triangle
        if (numRows == 0) {
            return triangle;
        }
        
        // Start the first row with a single 1
        triangle.push_back({1});
        
        // Iterate to build each row
        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            vector<int> prevRow = triangle[i - 1];
            
            // The first element of each row is always 1
            row.push_back(1);
            
            // Each triangle element (except the first and last of each row) is equal
            // to the sum of the elements above-and-to-the-left and above-and-to-the-right.
            for (int j = 1; j < i; j++) {
                row.push_back(prevRow[j - 1] + prevRow[j]);
            }
            
            // The last element of each row is always 1
            row.push_back(1);
            
            triangle.push_back(row);
        }
        
        return triangle;
    }
};
