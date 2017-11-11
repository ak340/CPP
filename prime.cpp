/*----------------------------------------------------------------
Author: Aidyn Kemeldinov
Filename: prime.h
-----------------------------------------------------------------*/

#include "prime.h"

// Constructor
prime::prime(int types, int n):_arr0(NULL),_arr1(NULL),_arr2(NULL){
	int len = (n-1)/2 + 1;
	_arr0 = new int[len];
	_arr1 = new int[len];
	_arr2 = new int[len];
	_len = len;
	sieveE(n);
	schoolMethod(n);
	upToPrime(n);
	
	
}
// Destructor
prime::~prime(){
	delete [] _arr0;
	delete [] _arr1;
	delete [] _arr2;
}
// Setter
void prime::set_value(int& x, int y){
	x = y;
}
void prime::set_value(double&x, double y){
	x = y;
}

void prime::set_value(char& x, char y){
	x = y;
}

// Getter
int prime::get_prime_number(int alg, int idx){
	switch(alg){
		case(0):
			return _arr0[idx];
		case(1):
			return _arr1[idx];
		case(2):
			return _arr2[idx];
		default:
			return -1;
	}
}

int prime::number_of_primes(int alg){
	return _count[alg];
}

int prime::number_of_steps(int alg){
	return _steps[alg];
}	


// Sieve of Eratosthenes Method
void prime::sieveE(int n){
	int steps = 0;
	char* primes = new char[n+1];
	int i=2;
	int count = 0;
	while (i<=sqrt(n)){
		for(int j=i;j*i<=n;j++){
			steps++;
			primes[j*i]='N';
		}
		do {
			i++;
		}
		while (primes[i]=='N');
	}
	for (int k=2;k<=n;k++){
		if (primes[k]!='N') {
			set_value(_arr2[count],k);
			count++;
		}

	}
	delete [] primes;
	set_value(_count[2],count);
	set_value(_steps[2],steps);
}

//  Up to Primes Method
void prime::upToPrime(int n) {
	int len = (n - 1)/2 + 1;
	int* primes = new int[len];
	primes[0] = 2;
	int nextPrime = 3;
    int count = 1;
    int steps = 1;
    set_value(_arr1[0],primes[0]);
    for (int idx=1; idx<len; idx++) {
    	
    	int sqr = sqrt(nextPrime);
        bool isPrime = true;
        for (int i = 0; primes[i] <= sqr; i++){
        	steps++;
            if (nextPrime % primes[i] == 0)
            {   
                isPrime = false;
                break;
            }
        }
        if (isPrime){
            primes[count]=nextPrime;
            set_value(_arr1[count],nextPrime);
            count++;
            steps++;
        }
        nextPrime += 2;
    }
    delete [] primes;
    set_value(_count[1],count);
    set_value(_steps[1],steps);
}


// Brute Force Method
void prime::schoolMethod(int n){
	int len = (n-1)/2 + 1;
	int steps = 0;
	int count = 0;
	for (int j=2;j<n;j++){
		if(isPrime(j,steps)) {
			set_value(_arr0[count],j);
			count++;
			}
	}
	set_value(_count[0],count);
    set_value(_steps[0],steps);
}

//****************************************
// Misc Functions
//****************************************

// Boolean Function for Brute Force Method
bool isPrime(int n, int& steps){
	for (int i=2;i<=sqrt(n);i++){
			steps++;
			if (n%i==0) return false;
		}
	return true;
}

// Square Root Function
// Output: Integer
int sqrt(int _val) {
    double low = 0; 
    double high = (double) _val;
    double mid = 0; 

    while (high - low > EPSILON) {
            mid = low + (high - low) / 2;
            if (mid*mid > _val) {
                high = mid;
            } else {
                low = mid;
            }    
    }
    int output = (int) (mid+0.001);   
    return output;   
}



