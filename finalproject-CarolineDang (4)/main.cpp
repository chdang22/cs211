#include <iostream>
#include <vector>
#include <algorithm>
#include "BinarySearchTree.h"
#include "SortedArray.h"
#include "NonSortedArray.h"
using namespace std;


int main() {
  //setting up a test case
  srand(time(NULL));
  const unsigned CAP = 31; 
  vector<unsigned> test_case;
  unsigned factor = rand() % 5 + 1;
  for (unsigned i = 0; i < CAP; i++) {
    test_case.push_back(i * factor + 1);
  }
  unsigned shuffles = rand() % CAP + CAP;
  for (unsigned i = 0; i < shuffles; i++) {
    random_shuffle(test_case.begin(), test_case.end());
  }
  cout << "The content of the test case vector:\n";
  for (unsigned i = 0; i < test_case.size(); i++) {
    cout << test_case[i] << ' ';
  }
  cout << endl;

  //ready to compare time complexity of the insert function
  BinarySearchTree bst;
  SortedArray sa(CAP);
  NonSortedArray nsa(CAP);
  for (unsigned i = 0; i < test_case.size(); i++) {
    cout << "Adding " << test_case[i] << endl;
    bst.insert(test_case[i]);
    sa.insert(test_case[i]);
    nsa.insert(test_case[i]);
  }
  cout << endl << endl;
  //display the elements of the resulting BST in descending order
  bst.displayAscending();
  cout << "Values of the sorted array: " << sa;
  cout << "Values of the non sorted array: " << nsa << endl;

  //Ready to compare the time complexity of the search function
  for (unsigned i = 0; i < CAP; i++) {
    unsigned value = rand() % (CAP + 5) + 1;
    cout << "Searching for " << value << endl;
    bst.search(value);
    sa.search(value);
    nsa.search(value);
  }
  cout << endl << endl; 

  //Testing operator=, which includes clear and deepCopy
  BinarySearchTree bstCopy;
  for (unsigned i = 0; i < 3; i++) {
    unsigned value = rand() % 50 + 1;
    cout << "Adding " << value << endl;
    bstCopy.insert(value);
  }
  cout << "Before operator =, bstCopy:\n";
  bstCopy.displayAscending();
  bstCopy = bst;
  cout << "After =, adding 50 to the copy, ";
  bstCopy.insert(50); 
  cout << "Adding 85 to the original, ";
  bst.insert(85);
  cout << "After updating, the original:\n";
  bst.displayAscending(); 
  cout << "the copy:\n";
  bstCopy.displayAscending(); 

  cout << "\nEnd of the program is reached. The BSTs are to be destructed.\n";
  return 0;
}