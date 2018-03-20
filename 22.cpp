#include <iostream>

using namespace std;

void print(double *A, int size);
void shellsort(double *A, int size);
void insertion(double *&A, int &size);

int main(){
  int size;
  double *A = new double[size];

  cout << "Enter size of array: " << endl;
  cin >> size;

  for (int i = 0; i < size; i ++) {
    cout << "Enter element: " << endl;
    cin >> A[i];
  }

  cout << "Your  array is: ";
  print (A, size);

  cout << endl;

  shellsort(A, size);
  cout << "Your  array after shellsort is: ";
  print (A, size);

  cout << endl;

  insertion(A, size);
  cout << "Your  array after insertion is: ";
  print (A, size);
  return 0;
}

void print (double *A,int size) {
  for (int i = 0; i < size; i++) {
    cout << A[i] << " ";
  }
}

void shellsort (double *A, int size) {
int step = size / 2;
int tmp;
while(step > 0) {
    for (int i = 0; i < size - step; i++) {
      int j = i;
      while(j >= 0 && A[j] > A[j + step]) {
        tmp = A[j];
        A[j] = A[j + step];
        A[j + step] = tmp;
        j--;
      }
    }
    step = step / 2;
  }
}

void insertion(double *&A, int &size){
  int newSize = size * 2 - 1;
  double *B = new double[newSize];
  int j = 0;
  for (int i = 0; i < size; i++) {
      B[j] = A[i];
      B[j + 1] = (A[i] + A[i + 1]) / 2;
      j+= 2;
  }
  delete []A;
  size = newSize;
  A = B;
}
