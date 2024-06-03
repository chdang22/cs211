#ifndef NON_SORTED_ARRAY
#define NON_SORTED_ARRAY

#include <iostream>
using namespace std;

class NonSortedArray {
  private:
    unsigned *arr_;
    unsigned capacity_;
    unsigned nElem_;

    void deepCopy(const NonSortedArray& s);
    void clear();
  public:
    NonSortedArray(unsigned n);
    NonSortedArray(const NonSortedArray& s);
    ~NonSortedArray();
    NonSortedArray& operator=(const NonSortedArray& s);

    void insert(unsigned val);
    bool search(unsigned key) const;
    friend ostream& operator<<(ostream&, const NonSortedArray&);
};

#endif