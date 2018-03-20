#include <iostream>

using namespace std;

void print(int *A,int size);
void shellsort (int *A, int size);
void swap(int *&A, int &size);

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

    cout << "Your  array is: ";
  print (A, size);

  cout << endl;

  shellsort (A, size);
  cout << "Your  array after quicksort is: ";
  print (A, size);

  cout << endl;

  swap(A, size);
  cout << "Your  array after swap is: ";
  print (A, size);

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

void swap(int *&A, int &size) {
  int *B = new int[size];
  int j = size - 1;
  for (int i = 0; i < size; i++){
    B[i] = A [j];
    j--;
  }
  delete []A;
  A = B;
}
