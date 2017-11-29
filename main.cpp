#include <iostream>
#include <cassert>

using namespace std;

// a = the array of values to sort
// x =  a temporary array for merging 2 sorted sub-arrays
// s = start of range to sort
// e = end of range to sort

template <class T>
void merge(T a[], T x[], int s, int midpoint, int e){
	int i = s;
	int m = midpoint;
	int j = m + 1;
	int k = 0;

	while (i <= m && j <= e){
	   if (a[i] < a[j]){
	      x[k] = a[i];
	      i++;
	      k++;
	   }
	   else  
	      x[k] = a[j];
	      j++;
	      k++;
	   
	}

	while (i <= m){
	   x[k] = a[i];
	   k++;
	   i++;
	}

	while (j <= e){
	   x[k] = a[j];
	   k++;
	   j++;
	   
	}

	for (i = s; i <= e; i++) {
	   int k = 0;
	   a[i] = x[k];
	   k++;
	}
}


template <class T>
void msort(T a[], T x[], int s, int e){
	int midpoint;
	if (e - s < 1) return;
	   midpoint = (s + e)/2;
	   msort(a, x, s, midpoint);
	   msort(a, x, midpoint + 1, e);
	   merge(a, x, s, midpoint, e);

	   
	   
}

template <class T>
void mergesort(T a[], int len){
	T *x = new T[len];
	int s = 0;
	msort(a, x, s, len - 1);
	delete [] x;
}

template <class T>
bool sorted (T a[], int len){
	for (int i = 0; i < len - 1; i++) {
		if (a[i] > a[i +1]) {
			return false;
		}
	}
	return true;
}


int main(int argc, char * args[]){
	int a[] = {2};
	mergesort<int>(a,1);
	assert(sorted<int>(a,1));

	int b[] = {1, 2, 3, 4, 5,};
	mergesort<int>(b, 5);
	assert(sorted<int>(b, 5));

	int c[1000];
	for (int i = 0; i < 1000; i++) c[i] = -50 + rand() % 100;
	mergesort<int>(c, 1000);
	assert(sorted<int>(c, 1000));

	int d[1001];
	for (int i = 0; i < 1001; i++) d[i] = -50 + rand() % 100;
	mergesort<int>(d, 1001);
	assert(sorted<int>(d, 1001));

	cout << "All int tests passed." << endl;

	double e[] = {5.876};
	mergesort<double>(e,1);
	assert(sorted<double>(e,1));

	double g[] = {2.343, 5.345, 6.33, 7.764, 1.345, 4.345};
	mergesort<double>(g, 6);
	assert(sorted<double>(g, 6));

	double f[1000];
	for (int i = 0; i < 1000; i++) f[i] = -50.234 + rand() % 100;
	mergesort<double>(f, 1000);
	assert(sorted<double>(f, 1000));

	cout << "All douible tests passed" << endl;

	return 0;
}




