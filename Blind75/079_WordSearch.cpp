/*
    Author: Aghamarsh Varanasi
    Date: Jan 17, 2026
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool dfs (vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, string& word, int index) {
            if (board[row][col] == word[index] && visited[row][col] == false) {
                visited[row][col] = true;

                if (index + 1 == word.length()) {
                    return true;
                }

                bool ans = false;
                if (row + 1 < board.size()) {
                    ans = ans || dfs(board, visited, row + 1, col, word, index + 1);
                }

                if (row - 1 >= 0) {
                    ans = ans || dfs(board, visited, row - 1, col, word, index + 1);
                }

                if (col - 1 >= 0) {
                    ans = ans || dfs(board, visited, row, col - 1, word, index + 1);
                }

                if (col + 1 < board[0].size()) {
                    ans = ans || dfs(board, visited, row, col + 1, word, index + 1);
                }

                if (! ans) {
                    visited[row][col] = false;
                }

                return ans;
            }

            return false;
        }

        bool exist(vector<vector<char>>& board, string word) {
            bool ans = false;

            for (int row = 0; row < board.size(); row++) {
                for (int col = 0; col < board[row].size(); col++) {
                    if (board[row][col] == word[0]) {
                        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

                        ans = ans || dfs(board, visited, row, col, word, 0);
                    }
                }
            }

            return ans;
        }
};

int main () {
    Solution s;
    vector<vector<char>> board = {
       {'A','B','C','E'},
       {'S','F','E','S'},
       {'A','D','E','E'} 
    };

    string word = "ABCESEEEFSAD";

    cout << s.exist(board, word);
}