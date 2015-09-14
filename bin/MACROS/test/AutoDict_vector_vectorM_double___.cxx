#include "vector"
#ifdef __CINT__ 
#pragma link C++ nestedclasses;
#pragma link C++ nestedtypedefs;
#pragma link C++ class vector<vectorM<double> >+;
#pragma link C++ class vector<vectorM<double> >::*;
#ifdef G__VECTOR_HAS_CLASS_ITERATOR
#pragma link C++ operators vector<vectorM<double> >::iterator;
#pragma link C++ operators vector<vectorM<double> >::const_iterator;
#pragma link C++ operators vector<vectorM<double> >::reverse_iterator;
#endif
#endif
