#include <iostream>

using namespace std;

void print(int *A,int size);
void shellsort (int *A, int size);
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

  shellsort(A, size);
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

void shellsort (int *A, int size) {
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
