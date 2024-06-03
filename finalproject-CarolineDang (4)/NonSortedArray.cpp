#include <iostream>
#include "NonSortedArray.h"
using namespace std;

NonSortedArray::NonSortedArray(unsigned n) {
  this->capacity_ = n;
  this->arr_ = new unsigned [this->capacity_];
  this->nElem_ = 0;
}

NonSortedArray::NonSortedArray(const NonSortedArray& s) {
  this->deepCopy(s);
}

NonSortedArray::~NonSortedArray() {
  this->clear();
}

NonSortedArray& NonSortedArray::operator=(const NonSortedArray& s) {
  this->clear();
  this->deepCopy(s);
  return *this;
}

void NonSortedArray::deepCopy(const NonSortedArray& s) {
  this->capacity_ = s.capacity_;
  this->arr_ = new unsigned [this->capacity_];
  this->nElem_ = s.nElem_;
  for (unsigned i = 0; i < this->nElem_; i++) {
    this->arr_[i] = s.arr_[i];
  }
} //end of deepCopy

void NonSortedArray::clear() {
  delete [] this->arr_;
}

void NonSortedArray::insert(unsigned val) {
  this->arr_[this->nElem_] = val;
  this->nElem_ += 1;
  //cout << "Non Sorted Array\t0 comparison\t\t0 shift\n";  
} //end of insert

bool NonSortedArray::search(unsigned key) const {
  unsigned comparisons = 0;
  bool found = false;
  for (unsigned i = 0; i < this->nElem_ && !found; i++) {
    comparisons++;
    if (this->arr_[i] == key) {
      found = true;
    } 
  }
  cout << "Non Sorted Array\t" << comparisons << " comparisons\t";
  if (found) {
    cout << "found\n";
  } else {
    cout << "not found\n";
  }
  return found;
}

ostream& operator<<(ostream& output, const NonSortedArray& s) {
  for (unsigned i = 0; i < s.nElem_; i++) {
    output << s.arr_[i] << ' ';
  }
  output << endl;
  return output;
}