#include <iostream>
#include "SortedArray.h"
using namespace std;

SortedArray::SortedArray(unsigned n) {
  this->capacity_ = n;
  this->arr_ = new unsigned [this->capacity_];
  this->nElem_ = 0;
}

SortedArray::SortedArray(const SortedArray& s) {
  this->deepCopy(s);
}

SortedArray::~SortedArray() {
  this->clear();
}

SortedArray& SortedArray::operator=(const SortedArray& s) {
  this->clear();
  this->deepCopy(s);
  return *this;
}

void SortedArray::deepCopy(const SortedArray& s) {
  this->capacity_ = s.capacity_;
  this->arr_ = new unsigned [this->capacity_];
  this->nElem_ = s.nElem_;
  for (unsigned i = 0; i < this->nElem_; i++) {
    this->arr_[i] = s.arr_[i];
  }
} //end of deepCopy

void SortedArray::clear() {
  delete [] this->arr_;
}

void SortedArray::insert(unsigned val) {
  unsigned comparisons = 0;
  unsigned shifts = 0;
  unsigned i = this->nElem_;
  while (i > 0 && this->arr_[i - 1] > val) {
    comparisons++;
    shifts++;
    this->arr_[i] = this->arr_[i - 1];
    i--;
  }
  this->arr_[i] = val;
  this->nElem_ += 1;
  cout << "Sorted Array\t\t" << comparisons << " comparisons\t\t" << shifts << " shifts\n";
} //end of insert

bool SortedArray::search(unsigned key) const {
  unsigned comparisons = 0;
  bool found = false;
  int start = 0;
  int end = this->nElem_;
  while (!found && start <= end) {
    int middle = (start + end) / 2;
    comparisons++;
    if (this->arr_[middle] == key) {
      found = true;
    } else if (this->arr_[middle] > key) {
      end = middle - 1;
    } else {
      start = middle + 1;
    }
  }
  cout << "Sorted Array\t\t" << comparisons << " comparisons\t";
  if (found) {
    cout << "found\n";
  } else {
    cout << "not found\n";
  }
  return found;
}

ostream& operator<<(ostream& output, const SortedArray& s) {
  for (unsigned i = 0; i < s.nElem_; i++) {
    output << s.arr_[i] << ' ';
  }
  output << endl;
  return output;
}