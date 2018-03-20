#include <iostream>

using namespace std;

void print(int *A,int size);
void quicksort(int *A, int left, int right);
void insertion(int *&A, int &size, int a);

int main(){
  int a;
  int size;
  int *A = new int[size];

  cout << "Enter size of array: " << endl;
  cin >> size;

  for (int i = 0; i < size; i ++) {
    cout << "Enter element: " << endl;
    cin >> A[i];
  }

  cout << "Enter element to insert: " << endl;
  cin >> a;

  cout << endl;

  cout << "Your  array is: ";
  print (A, size);

  cout << endl;

  quicksort(A, 0, size - 1);
  cout << "Your  array after quicksort is: ";
  print (A, size);

  cout << endl;

  insertion(A, size, a);
  cout << "Your  array after insertion is: ";
  print (A, size);
  return 0;
}

void print (int *A,int size) {
  for (int i = 0; i < size; i++) {
    cout << A[i] << " ";
  }
}

void quicksort(int *A, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = A[(left + right) / 2];

    while (i <= j) {
      while (A[i] < pivot)
        i++;
      while (A[j] > pivot)
        j--;
      if (i <= j) {
        tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        i++;
        j--;
      }
    };
    // rec
    if (left < j)
      quicksort(A, left, j);
    if (i < right)
      quicksort(A, i, right);
}

void insertion(int *&A, int &size, int a) {
 int *B = new int[size + 1];
 int i = 0;
 while (A[i] < a) {
   B[i] = A[i];
   i++;
 }

 B[i] = a;
 while (i < size) {
   B[i + 1] = A[i];
   i++;
 }
 delete [] A;
  size ++;
 A = B;
}
