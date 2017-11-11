#ifndef prime_H
#define prime_H
#include <iostream>
#include <fstream>

#include <iomanip>  
using namespace std;

#include <assert.h>
#include <time.h>
#include <math.h> 
#include <string.h> 

#define EPSILON 0.0000001 // least minimum value for comparison



class prime{
	public:
		prime(int types, int n);
		~prime();
		int get_prime_number(int alg, int idx);
		int number_of_primes(int alg); 
		int number_of_steps(int alg);
		void set_value(int& x,int y);
		void set_value(double& x, double y);
		void set_value(char& x, char y);
		void sieveE(int n);
		void upToPrime(int n);
		void schoolMethod(int n);
	private:
		int _alg_no;
		int* _arr0;
		int* _arr1;
		int* _arr2;
		int _count[3];
		int _steps[3];
		int _len;
};

int sqrt(int _val) ;
bool isPrime(int n, int& steps);

#endif