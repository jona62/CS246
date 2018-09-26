#ifndef PUZZLE_SOLVER
#define PUZZLE_SOLVER
#include "utils.h"
#include "Trie.h"
using std::stringstream;
using std::string;
using std::vector;
using std::pair;
using std::cout;

namespace Directions {
  const string UP = "up";
  const string DOWN = "down";
  const string LEFT = "Left";
  const string RIGHT = "right";
  const string DIAG_RIGHT_DOWN = "diag_right_down";
  const string DIAG_lEFT_DOWN = "diag_left_down";
  const string DIAG_RIGHT_UP = "diag_right_up";
  const string DIAG_LEFT_UP = "diag_left_up";
}

class PuzzleSolver {
  public:
    PuzzleSolver();
    PuzzleSolver(int, int);
    void fillMatrixWithPuzzle(string);
    vector<pair<string, pair<pair<int,int>, pair<int,int>>>> solvePuzzle(Trie);
    void printMatrix();
    char **generateMatrix(int, int);

  private:
    char **matrix;
    int ROW;
    int COLUMN;

    bool isSolvable(int startX, int startY){
      return ((startX >= 0 && startX < ROW)  &&
      (startY >= 0 && startY < COLUMN));
    }

    void solvePuzzleRecursive(Trie trie, vector<pair<string, pair<pair<int,int>, pair<int,int>>>> &result, string str,
      int startX, int startY) {
        pair<pair<int,int>, pair<int,int>> pair_coord;
        findWords(trie, result, str, pair_coord, startX, startY, Directions::UP, true); 
        findWords(trie, result, str, pair_coord, startX, startY, Directions::DOWN, true); 
        findWords(trie, result, str, pair_coord, startX, startY, Directions::LEFT, true); 
        findWords(trie, result, str, pair_coord, startX, startY, Directions::RIGHT, true); 
        findWords(trie, result, str, pair_coord, startX, startY, Directions::DIAG_RIGHT_DOWN, true); 
        findWords(trie, result, str, pair_coord, startX, startY, Directions::DIAG_lEFT_DOWN, true); 
        findWords(trie, result, str, pair_coord, startX, startY, Directions::DIAG_RIGHT_UP, true); 
        findWords(trie, result, str, pair_coord, startX, startY, Directions::DIAG_LEFT_UP, true); 
  }

  void findWords(Trie trie, vector<pair<string, pair<pair<int,int>, pair<int,int>>>> &result,
    string str, pair<pair<int,int>, pair<int,int>> pair_coord, int startX, int startY, string direction, bool mark_start) {
      // Check if startX and startY are in bound
      if(!isSolvable(startX, startY)){
        return;
      }

      str += matrix[startX][startY];

      if(trie.findPartial(str) && mark_start){
        pair<int, int> start_coord(startX, startY);
        pair_coord.first = start_coord;
        mark_start = false;
      }

      if(trie.find(str)){
        pair<int, int> end_coord (startX, startY);
        pair_coord.second = end_coord;
        pair<string, pair<pair<int,int>, pair<int,int>>> wordAndCoords(str, pair_coord);
        result.push_back(wordAndCoords);
        str = "";
      }
      changeDirection(startX, startY, direction);
      findWords(trie, result, str, pair_coord, startX, startY, direction, mark_start);
  }

  void changeDirection(int &startX, int &startY, string direction) {
    if(direction == Directions::UP)
      startX--;
    else if(direction == Directions::DOWN)
      startX++;
    else if(direction == Directions::LEFT)
      startY--;
    else if(direction == Directions::RIGHT)
      startY++;
    else if(direction == Directions::DIAG_RIGHT_DOWN) {
      startX++;
      startY++;
    }  else if(direction == Directions::DIAG_lEFT_DOWN) {
      startX++;
      startY--;
    } else if(direction == Directions::DIAG_RIGHT_UP) {
      startX--;
      startY++;
    } else if(direction == Directions::DIAG_LEFT_UP) {
      startX--;
      startY--;
    }
  }

};

char **PuzzleSolver::generateMatrix(int row, int col){
    char **matrix = NULL;
    matrix = new char *[row];
    for(int i=0; i<row; i++){
      matrix[i] = new char[col];
      for(int j=0; j<col; j++){
        matrix [i][j] = '0';
      }
    }
    return matrix;
  }

PuzzleSolver::PuzzleSolver(): ROW(0), COLUMN(0){
  this->matrix = generateMatrix(ROW, COLUMN);
}

PuzzleSolver::PuzzleSolver(int row, int col) : ROW(row), COLUMN(col){
  this->matrix = generateMatrix(ROW, COLUMN);
}

void PuzzleSolver::fillMatrixWithPuzzle(string puzzleChars) {
  assert(puzzleChars.length()-1 == ROW * COLUMN);
  int iter = 0;
    for(int i=0; i<ROW; i++){
      for(int j=0; j<COLUMN; j++){
        matrix[i][j] = puzzleChars[iter++];
    }
  }
}

vector<pair<string, pair<pair<int,int>, pair<int,int>>>> PuzzleSolver::solvePuzzle(Trie trie) {
  vector<pair<string, pair<pair<int,int>, pair<int,int>>>> captureWords;
  for(int i=0; i<ROW; i++){
    for(int j=0; j<COLUMN; j++){
      solvePuzzleRecursive(trie, captureWords, "", i, j);
    }
  }
  return captureWords;
}

void PuzzleSolver::printMatrix(){
  stringstream ss;
  ofstream ofile;
  ofile.open("Solved.txt");
  for(int i=0; i<ROW; i++){
    for(int j=0; j<COLUMN; j++){
      cout<<matrix[i][j]<<" ";
      ss<<matrix[i][j]<<" ";
    }
    cout<<"\n";
    ss <<"\n";
  }
  if(ofile.is_open()){
    ofile<<ss.str();
  }
}

#endif //PUZZLE_SOLVER
