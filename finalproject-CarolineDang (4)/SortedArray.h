#ifndef SORTED_ARRAY
#define SORTED_ARRAY
#include <iostream>
using namespace std;

class SortedArray {
  private:
    unsigned *arr_;
    unsigned capacity_;
    unsigned nElem_;

    void deepCopy(const SortedArray& s);
    void clear();
  public:
    SortedArray(unsigned n);
    SortedArray(const SortedArray& s);
    ~SortedArray();
    SortedArray& operator=(const SortedArray& s);

    void insert(unsigned val);
    bool search(unsigned key) const;
    friend ostream& operator<<(ostream&, const SortedArray&);
};

#endif