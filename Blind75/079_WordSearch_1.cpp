/*
    Author: Aghamarsh Varanasi
    Date: Jan 18, 2026
    Description: Iterative solution for word search problem
*/
#include<iostream>
#include <vector>
using namespace std;

int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

struct Frame {
    int r, c, idx;
    bool exit;
};

class Solution {
    public:

        bool dfs (vector<vector<char>>& board, int row, int col, string& word) {
            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
            int n = board.size();
            int m = board[0].size();

            stack<Frame> st;
            st.push({row, col, 0, false});

            while (!st.empty()) {
                auto cur = st.top();
                st.pop();

                if (!cur.exit) {
                    if (visited[cur.r][cur.c]) continue;
                    if (board[cur.r][cur.c] != word[cur.idx]) continue;

                    visited[cur.r][cur.c] = true;

                    if (cur.idx == word.size() - 1) {
                        return true;
                    }

                    st.push({cur.r, cur.c, cur.idx, true});

                    for (auto dir : dirs) {
                        int nr = cur.r + dir[0];
                        int nc = cur.c + dir[1];
                        bool inBounds = (nr > -1) && (nr < n) && (nc > -1) && (nc < m);
                        if (inBounds && !visited[nr][nc]) {
                            st.push({nr, nc, cur.idx + 1, false});
                        }
                    }
                } else {
                    visited[cur.r][cur.c] = false;
                }
            }

            return false;
        }

        bool exist(vector<vector<char>>& board, string word) {
            bool ans = false;

            for (int row = 0; row < board.size(); row++) {
                for (int col = 0; col < board[row].size(); col++) {
                    if (board[row][col] == word[0]) {
                        ans = ans || dfs(board, row, col, word);
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

    string word = "SEEEFE";

    cout << s.exist(board, word);
}