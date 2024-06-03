// Class declaration for a binary search tree

#ifndef BinarySearchTree_H
#define BinarySearchTree_H


struct TreeNode { 
  unsigned value;   // data field 
  TreeNode *left;   // to hold the address of the left child 
  TreeNode *right;  // to hold the address of the right child 
}; 

class BinarySearchTree { 
private: 
  TreeNode *root_;  // Pointer to the root node 
  TreeNode* deepCopy(TreeNode*);
  void clear(TreeNode*);
  //helpers
  void insert(unsigned val, TreeNode*&, unsigned& count); //helper
  unsigned height(TreeNode*) const;//helper
  void displayAscending(TreeNode*) const;
  bool search(unsigned key,TreeNode*, unsigned& tally ) const;

public:
  //unsigned count;
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree& bst);
  ~BinarySearchTree();   
  BinarySearchTree& operator=(const BinarySearchTree& bst);
  void insert(unsigned val); 
  bool search(unsigned key) const;
  void displayAscending() const;
  unsigned height() const;
}; 

#endif