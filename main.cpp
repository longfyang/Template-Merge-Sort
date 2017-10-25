#include <iostream>
#include <cassert>

using namespace std;

// a = the array of values to sort
// x =  a temporary array for merging 2 sorted sub-arrays
// s = start of range to sort
// e = end of range to sort

template <class T>
void merge(T a[], int x[], int s, int midpoint, int e){
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
void msort(T a[], int x[], int s, int e){
	int midpoint;
	if (e - s < 1) return;
	   midpoint = (s + e)/2;
	   msort<T>(a, x, s, midpoint);
	   msort<T>(a, x, midpoint + 1, e);
	   merge<T>(a, x, s, midpoint, e);

	   
	   
}

template <class T>
void mergesort(T a[], int len){
	int *x = new int[len];
	int s = 0;
	msort<T>(a, x, s, len - 1);
	delete [] x;
}

template <class T>
bool sorted (T a[], int len){
	for (int i = 0; i < len; i++){
	   if (a[i] < a[i + 1]){
	      i++;
	   }
	   return true;
	   
	}

	return false;
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

	cout << "All tests passed." << endl;

	return 0;
}


