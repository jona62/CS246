#include "puzzleSolver.h"
#include "Trie.h"
#include "utils.h"
#define ROW 14
#define COL 16

const char *PUZZLE_FILE = "puzzleFile.txt";
const char *ANSWER_fILE = "answers.txt";

int main() {
  Trie trieTree;
  // Read words into vector
  vector <string> words = FileOperations::readFileIntoStringArray(ANSWER_fILE);
  int words_size = (int) words.size();
  // Insert words into Trie
  for(int i=0; i<words_size; i++) {
    trieTree.insert(words[i]);
  }

  // Create a 2D array with ROW & COL
  PuzzleSolver puzzle(ROW,COL);
  string puzzleCharacters = FileOperations::readFileIntoString(PUZZLE_FILE);
  // Populates the 2D array with the puzzle characters read
  // From the PUZZLE_FILE
  puzzle.fillMatrixWithPuzzle(puzzleCharacters);
  puzzle.printMatrix();
  FileOperations::save_words_to_file(puzzle.solvePuzzle(trieTree));
  cout<<"Answers have been saved to file\n";
  return 0;
}
