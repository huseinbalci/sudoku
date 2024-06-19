#include <iostream>
#include <vector>

using namespace std;

vector<string> board = {"6..874.1.",
                        "..9.36...",
                        "...19.8..",
                        "7946.....",
                        "..1.894..",
                        "...41..69",
                        ".7..5..9.",
                        ".539.76..",
                        "9.2.61.47"};

bool isValid(int row, int col, char num) {
    for (int c = 0; c < board.size(); ++c) {
        if (board[row][c] == num) {
            return false;
        }
    }

    for (int r = 0; r < board.size(); ++r) {
        if (board[r][col] == num) {
            return false;
        }
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
            if (board[startRow + j][startCol + k] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku() {
    for (int row = 0; row < board.size(); ++row) {
        for (int col = 0; col < board[0].size(); ++col) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku()) {
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }return true;
}

int main() {
    if (solveSudoku()) {
        for (const string& row : board) {
            cout << row << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}