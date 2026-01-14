/*
    Author: Aghamarsh Varanasi
    Date: Jan 14, 2026
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int runs = n / 2;

        for (int run = 0; run < runs; run++) {
            int start = 0 + run;
            int end = n - run - 1;

            for (int ptr = start; ptr < end; ptr++) {
                int row_a = start;
                int col_a = ptr;

                int row_b = ptr;
                int col_b = end;

                int row_c = end;
                int col_c = end - (ptr - start);
    
                int row_d = end - (ptr - start);
                int col_d = start;

                int temp = matrix[row_b][col_b];
                matrix[row_b][col_b] = matrix[row_a][col_a];

                int temp2 = matrix[row_c][col_c];
                matrix[row_c][col_c] = temp;

                temp = matrix[row_d][col_d];
                matrix[row_d][col_d] = temp2;

                matrix[row_a][col_a] = temp;
            }
        }
    }
};

int main () {
    Solution s;
    vector<vector<int>> matrix = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    s.rotate(matrix);
    cout << "[";
    for (int i =0 ;i < matrix.size();i ++) {
        cout << "[";
        for (int j =0; j< matrix.size() ; j++) {
            cout << matrix[i][j] << ((j == matrix.size()-1) ? "": ","); 
        }
        cout << ((i == matrix.size()-1) ? "]" : "],");
    }
    cout << "]\n";
}