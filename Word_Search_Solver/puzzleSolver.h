#ifndef PUZZLE_SOLVER
#define PUZZLE_SOLVER
#include "utils.h"
#include "/cslab/home/JonathanJames/CS246/Data Structures/Trie/Trie.h"

struct Directions {
  static const std::string UP;
  static const std::string DOWN;
  static const std::string LEFT;
  static const std::string RIGHT;
  static const std::string DIAG_RIGHT_DOWN;
  static const std::string DIAG_lEFT_DOWN;
  static const std::string DIAG_RIGHT_UP;
  static const std::string DIAG_LEFT_UP;
};

  const std::string Directions::UP = "up";
  const std::string Directions::DOWN = "down";
  const std::string Directions::LEFT = "Left";
  const std::string Directions::RIGHT = "right";
  const std::string Directions::DIAG_RIGHT_DOWN = "diag_right_down";
  const std::string Directions::DIAG_lEFT_DOWN = "diag_left_down";
  const std::string Directions::DIAG_RIGHT_UP = "diag_right_up";
  const std::string Directions::DIAG_LEFT_UP = "diag_left_up";

class PuzzleSolver {
  public:
    PuzzleSolver();
    PuzzleSolver(int, int);
    void fillMatrixWithPuzzle(std::string);
    std::set<std::string> solvePuzzle(Trie);
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

    void solvePuzzleRecursive(Trie trie, std::set<std::string> &result, string str,
      int startX, int startY) {
        findWords(trie, result, str, startX, startY, Directions::UP); //Search Up
        findWords(trie, result, str, startX, startY, Directions::DOWN); //Search Down
        findWords(trie, result, str, startX, startY, Directions::LEFT); //Search Left
        findWords(trie, result, str, startX, startY, Directions::RIGHT); //Search Right
        findWords(trie, result, str, startX, startY, Directions::DIAG_RIGHT_DOWN); //Search Diag_Right_Down
        findWords(trie, result, str, startX, startY, Directions::DIAG_lEFT_DOWN); //Search Diag_Left_Down
        findWords(trie, result, str, startX, startY, Directions::DIAG_RIGHT_UP); //Search Diag_Right_Up
        findWords(trie, result, str, startX, startY, Directions::DIAG_LEFT_UP); //Search Diag_Left_Up
  }

  void findWords(Trie trie, std::set<std::string> &result, string str,
    int startX, int startY, std::string direction) {

      // Check if startX and startY are in bound
      if(!isSolvable(startX, startY)){
        return;
      }
      str += matrix[startX][startY];
      // Add to array if complete word is found
      if(trie.find(str)){
        result.insert(str);
        str = "";
      }
      changeDirection(startX, startY, direction);
      findWords(trie, result, str, startX, startY, direction);
  }

  void changeDirection(int &startX, int &startY, std::string direction) {
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
    }
    else if(direction == Directions::DIAG_lEFT_DOWN) {
      startX++;
      startY--;
    }
    else if(direction == Directions::DIAG_RIGHT_UP) {
      startX--;
      startY++;
    }
    else if(direction == Directions::DIAG_LEFT_UP) {
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
  memset(this->matrix,0,sizeof(int));
}

PuzzleSolver::PuzzleSolver(int row, int col) : ROW(row), COLUMN(col){
  this->matrix = generateMatrix(row, col);
}

void PuzzleSolver::fillMatrixWithPuzzle(std::string puzzleChars) {
  assert(puzzleChars.length()-1 == ROW * COLUMN);
  int iter = 0;
    for(int i=0; i<ROW; i++){
      for(int j=0; j<COLUMN; j++){
        matrix[i][j] = puzzleChars[iter++];
    }
  }
}

std::set<std::string> PuzzleSolver::solvePuzzle(Trie trie) {
  std::set<std::string> captureWords ;//= std::set<std::string>();
  for(int i=0; i<ROW; i++){
    for(int j=0; j<COLUMN; j++){
      solvePuzzleRecursive(trie, captureWords, "", i, j);
    }
  }
  return captureWords;
}

void PuzzleSolver::printMatrix(){
  for(int i=0; i<ROW; i++){
    for(int j=0; j<COLUMN; j++){
      std::cout<<matrix[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}

#endif //PUZZLE_SOLVER
