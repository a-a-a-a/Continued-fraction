// Akm Rubel
// CS 211
// Continued fraction assignment.

#include<cstdlib>
#include<iostream>
#include<iomanip>
using namespace std;

/*
*  The basic algorithm is that at first we simply take the reciprocal of the last
*  element of the array and store it somewhere. Then we add it to the
*  previous term. Then we take the reciprocal of the sumand
*  take its reciprocal and set it to be our new current. we keep on doing this
*  untill we reach the first element in the array.
*/
double fraction (int a[], int size) {
  double current = 1.0/a[size-1];
	double sum;

	for(int i=size-2; i>=0; --i) {
    sum=(a[i]*1.0+current);
    current=1.0/sum;
  }

	return sum;
}

/*
*  This function will take an integer array and the size of the array
*  as its arugments. it then return an array of size two that contains the
*  numerator of the fraction at its 0th index and deonominator at its
*  1th index.
*  The way this function works is that at first we set our numerator to
*  be the last element of the array and the denomninator to be one.
*  and then we initialize i to the second last element of the array.
*  then we calculate the numerator and use a temporary variable to change the current
*  value of the denominator to the previous value of the numerator.we keep on continuing until
*  we reached the first element in the array.
*/
int *continuedFraction(int a[], int size) {
    int* array = new int [2];
    int i=size-1;
    int temp;
    array[0]=a[size-1];
    array[1]=1;
    i=size-2;

    while (i>=0) {
      temp=array[0];
      array[0]=(temp*a[i])+array[1];
      array[1]=temp;
      i--;
    }

    return array;
}
/*
*  This recursive function starts with an array of size n and the base case is
*  when the size of the array is 1. Every recursive itertion it gets an array
*  with smaller size and calculates p and q.
*/
int* recursiveFraction(int arr[], int n) {
	int* b = new int[2];

  // Base case
	if (n == 1) {
		b[0] = arr[0];
    b[1] = 1;

		return b;
	}

  // recursive part
	int* out = recursiveFraction( (arr+1), (n-1) );
	b[0] = arr[0] * out[0] + out[1];
	b[1] = out[0];
	delete[] out;
	return b;
}

int main() {
   //part one
  int a[3]= {2,3,4};
  cout<<"The result is: "<<setprecision(5)<<fraction(a,3)<<endl;

  //part two
  int d[3]= {2,3,4};
  int*pt = continuedFraction(d,3);
  cout<<"The fraction using iteration: "<<*(pt+0)<<"/"<<*(pt+1)<<endl;

  // part three
  int c[3]= {2,3,4};
  int*ptr = recursiveFraction(c,3);
  cout<<"The fraction using recursion: "<<*(ptr+0)<<"/"<<*(ptr+1)<<endl;

  system("PAUSE");
  return 0;
}
