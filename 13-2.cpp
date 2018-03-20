#include <iostream>

using namespace std;

void print(int *A,int n);
void shellsort(int *, int n);

int main() {
  int size;
  int *A = new int[size];
  int *B = new int [size];

  cout << "Enter size of array: " << endl;
  cin >> size;

  for (int i = 0; i < size; i ++) {
    cout << "Enter element: " << endl;
    cin >> A[i];
  }
  //rewrite
  for (int i = 0; i < size; i ++) {
    B[i] = A[i];
  }

  cout << "Your  array is: ";
  print (A, size);

  cout << endl;

  shellsort(B, size);
  cout << "Your  array after shellsort is: ";
  print (B, size);
}


void print (int *A,int n) {
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
}

void shellsort (int *B, int size) {
int step = size / 2;
int tmp;
while(step > 0) {
    for (int i = 0; i < size - step; i++) {
      int j = i;
      while(j >= 0 && B[j] < B[j + step]) {
        tmp = B[j];
        B[j] = B[j + step];
        B[j + step] = tmp;
        j--;
      }
    }
    step = step / 2;
  }
}
