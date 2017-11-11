/*----------------------------------------------------------------
Author: Aidyn Kemeldinov
file: amicable.cpp
-----------------------------------------------------------------*/
#include "amicable.h"


/*----------------------------------------------------------------
Constructor
-----------------------------------------------------------------*/
amicable::amicable(int n):_order(0){
    _start(n);
    _print();
}
/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
amicable::~amicable(){
    delete [] _array;
}
/*----------------------------------------------------------------
Computes sum of divisors for 1 to n
-----------------------------------------------------------------*/
void amicable::_start(int n){
    _array = new int[n+1];
    _limit = n;
    for (int i = 2; i*i < _limit; i++) {
         _array[i*i] += i;
        int x =_limit/i;
        for (int j=i+1; j < x+1;j++ ) {
            _array[i*j] += i+j;
        } 
    }
}
/*----------------------------------------------------------------
Prints amicable pairs
-----------------------------------------------------------------*/
void amicable::_print(){
    for (int i=2;i<_limit;i++){
        if ((i<_array[i]) && (_array[i]<_limit)){
            if (i == _array[_array[i]+1]+1) {
                cout << _order <<": "<<i<<" and " <<(_array[i]+1)<<endl;
                _order++;
            }
        }  
    }
}

