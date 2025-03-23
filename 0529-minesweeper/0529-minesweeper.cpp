/* 

*******************************************************
Problem becomes simpler onces we understand this logic
*******************************************************

Start at the Click Position:

Begin processing from the cell given by the click.

Check for a Mine:

    If the cell is a mine ('M'):

    Change it to 'X' to indicate a mine was revealed (game over).

    Return the board immediately.

Explore the Grid (if not a mine):

    If the cell is not a mine ('E'):

    You'll start exploring adjacent cells.

    Count Adjacent Mines:

    For the current cell, check all 8 directions (up, down, left, right, and the 4 diagonals).

    Count how many of these adjacent cells contain a mine.

    Update the Current Cell:

    If the mine count > 0:

        Change the current cell to the digit (as a character) corresponding to the count.

        Stop further expansion from this cell.

    If the mine count == 0:

        Change the cell to 'B' (blank).

        Recursively or iteratively (using DFS/BFS) reveal all adjacent unrevealed cells (those marked as 'E').

        Continue Until No More Cells Can be Revealed:

        Process all cells that can be expanded following the same rules.

These are the critical steps expected from candidates when solving the Minesweeper problem. They reflect the need to:

    Handle the base case (clicking on a mine).

    Properly count adjacent mines.

    Use recursion or an iterative approach to reveal the board correctly.
*/
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        if (board[click[0]][click[1]] != 'E') {
            return board;
        }

        queue<pair<int, int>> q;
        q.push({click[0], click[1]});

        const vector<pair<int, int>> directions = {{-1, 0}, {-1, 1}, {0, 1},
                                                   {1, 1},  {1, 0},  {1, -1},
                                                   {0, -1}, {-1, -1}};
        int M = board.size();
        int N = board[0].size();

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            int mineCountAtCurrentLevel = 0;
            vector<pair<int, int>> neighbors;

            for (auto [pr, pc] : directions) {
                int nr = pr + row;
                int nc = pc + col;

                if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                    if (board[nr][nc] == 'M') {
                        mineCountAtCurrentLevel++;
                    }
                    neighbors.push_back({nr, nc});
                }
            }

            if (mineCountAtCurrentLevel > 0) {
                board[row][col] = mineCountAtCurrentLevel + '0';
            } else {
                board[row][col] = 'B';

                for(auto [nr, nc] : neighbors) {
                     if (board[nr][nc] == 'E') {
                        board[nr][nc] = 'B';
                        q.push({nr, nc});
                    }
                }
            }
        }

        return board;
    }
};