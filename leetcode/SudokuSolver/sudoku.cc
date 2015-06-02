#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<vector<char> >& board) {
  bool row[9][9], col[9][9], cube[9][9];
  fill(*row, *row + 81, false);
  fill(*col, *col + 81, false);
  fill(*cube, *cube + 81, false);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        int idx = board[i][j] - '1';
        if (row[i][idx] == true) return false;
        else row[i][idx] = true;

        if (col[idx][j] == true) return false;
        else col[idx][j] = true;

        int area = (i / 3) * 3 + (j / 3);
        if (cube[area][idx] == true) return false;
        else cube[area][idx] = true;
      }
    }
  }
  return true;
}

bool solveInternal(vector<vector<char> >& board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '.') {
        for (int k = 0; k < 9; k++) {
          board[i][j] = k + '1';
          if (isValid(board) && solveInternal(board))
            return true;
        }
        board[i][j] = '.';
        return false;
      }
    }
  }
  return true;
}


void solveSudoku(vector<vector<char> >& board) {
  solveInternal(board);
}

int main() {
  vector<vector<char> > board;
  solveSudoku(board);
}
