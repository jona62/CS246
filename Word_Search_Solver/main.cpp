#include "puzzleSolver.h"
#include "/cslab/home/JonathanJames/CS246/Data Structures/Trie/Trie.h"
#include "utils.h"
#define ROW 14
#define COL 16

const char *PUZZLE_FILE = "puzzleFile.txt";
const char *ANSWER_fILE = "answers.txt";

int main() {
  Trie trieTree;
  // Read words into vector
  std::vector <std::string> words = FileOperations::readFileIntoStringArray(ANSWER_fILE);
  int words_size = (int) words.size();
  // Insert words into Trie
  for(int i=0; i<words_size; i++) {
    trieTree.insert(words[i]);
  }

  // Create a 2D array with ROW & COL
  PuzzleSolver puzzle(ROW,COL);
  std::string puzzleCharacters = FileOperations::readFileIntoString(PUZZLE_FILE);
  // Populates the 2D array with the puzzle characters read
  // From the PUZZLE_FILE
  puzzle.fillMatrixWithPuzzle(puzzleCharacters);
  puzzle.printMatrix();

  FileOperations::save_words_to_file(puzzle.solvePuzzle(trieTree));
  std::set<string> result_set = puzzle.solvePuzzle(trieTree);
  std::set<string>::iterator it;

  cout<<"\nFound Words\n\n";
  for(it = result_set.begin(); it != result_set.end(); it++)
    cout<< *it<<endl;
  return 0;
}
