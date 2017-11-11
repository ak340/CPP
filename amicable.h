#ifndef amicable_H
#define amicable_H
/*----------------------------------------------------------------
Basic include files
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip> 
using namespace std;

#include <assert.h>
#include <time.h>
#include <math.h> 
#include <string.h> 

class amicable{
	public:
		amicable(int n);
		~amicable();
		static bool display;

	private:
		int * _array;
		int _order;
		int _limit;
		void _start(int n);
		void _print();
};

#endif