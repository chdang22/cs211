#include <iostream>
#include <queue>
#include "BinarySearchTree.h"
using namespace std;
//unsigned count=0;
//heleprs
void BinarySearchTree::insert(unsigned val, TreeNode*& nodePtr, unsigned& count){
  if (nodePtr == nullptr) {
    TreeNode *t = new TreeNode;
    t->value = val;
    t->left = t->right = nullptr;
    nodePtr = t;
    return;
  }
  //nodePtr= this->root_;
  if (val == nodePtr->value)
    return;
  else if (val < nodePtr->value){
    count++;
    insert(val, nodePtr->left,count);
  }else{
    count++;
    insert(val, nodePtr->right,count);
  }
}




//helper
bool BinarySearchTree::search(unsigned key,TreeNode* nodePtr, unsigned& tally ) const {
   if (nodePtr == nullptr)
    return false;
     
  //nodePtr != nullptr, recursive case
  if (key == nodePtr->value){
    //The key is the same as the value in the node.We found the match
    return true;
  }else if (key < nodePtr->value){
    
    //The key is smaller  than the value in the node.
    //Search for key in the left subtree.
    tally++;
    return search(key, nodePtr->left,tally);
  }else{
    //The key is larger than the value in the node.
    //Search for key in the right subtree.
    tally++;
    return search(key, nodePtr->right,tally);
  }
}

void BinarySearchTree::displayAscending(TreeNode* nodePtr) const{
  if (nodePtr == nullptr){
    return;
  }
  displayAscending(nodePtr->left);
  cout << nodePtr->value<<endl;
  displayAscending(nodePtr->right);

}

unsigned BinarySearchTree::height(TreeNode* nodePtr) const {

   if(root_ == nullptr){
    return 0;
  }else{
    int lHeight= height(nodePtr->left);
    int rHeight= height(nodePtr->right);

    if(lHeight>rHeight){
      return (lHeight+1);
    }else{
      return (rHeight+1);
    }
  }
}
//end helpoer
// Default constructor sets an empty tree
BinarySearchTree::BinarySearchTree()
{
	this->root_= nullptr;
}

// Copy constructor sets an empty tree
BinarySearchTree::BinarySearchTree(const BinarySearchTree& bst)
{
  cout << "Building the copy in the order of:\n";
	this->root_ = this->deepCopy(bst.root_);
  cout << endl;
}

TreeNode* BinarySearchTree::deepCopy(TreeNode* r)  {
  //to be implemented
  if (r == nullptr) {
    return nullptr;
  }

  TreeNode* newRoot = new TreeNode;
  newRoot->value = r->value;
  cout << "Created node:\t" << r->value<<endl;
  newRoot->left = this->deepCopy(r->left);
  newRoot->right = this->deepCopy(r->right);
  return newRoot;
}

//The destructor calls a private recursive destroyAll function to release all nodes in the tree
BinarySearchTree::~ BinarySearchTree () 
{
  cout << "Releasing nodes in the order of:\n";
  this->clear(this->root_); 
  cout << endl;
}
void BinarySearchTree::insert(unsigned val)
{
  unsigned count=0;
  //to be implemented
  this->insert(val, this->root_, count);
  
}

//recursively release all nodes in the tree
void BinarySearchTree::clear(TreeNode *r)
{
  //to be implemented
   if (r == nullptr)
    return;
     
  //this is when nodePtr != nullptr, recursive case
  clear(r->left);  //release all nodes in the left subtree
  clear(r->right); //release all nodes in the right subtree
  cout <<  "Delete:\t" << r->value << endl;
  
  delete r; //release the root

}




BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& bst) {
  cout << "In operator=, first release the nodes in the invoking object:\n";
  this->clear(this->root_);
  cout << endl;
  this->root_ = nullptr;
  cout << "Now copy the nodes from the parameter object:\n";
  this->root_ = this->deepCopy(bst.root_);
  cout << endl;
  return *this;
}


bool BinarySearchTree::search(unsigned key) const
{
  //to be implemented
  unsigned tally=0;
  return this->search(key, root_, tally);
}



 
//the public display method.  
void BinarySearchTree::displayAscending() const
{
  //to be implemented
    this->displayAscending(this->root_);
}


//the public display method.  
unsigned BinarySearchTree::height() const
{
  return this->height(root_);
}


