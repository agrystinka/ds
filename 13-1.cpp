#include <iostream>

using namespace std;

void print(int *A,int n);
void quicksort(int *B, int left, int right);

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

  quicksort(B, 0, size - 1);
  cout << "Your  array after quicksort is: ";
  print (B, size);
}


void print (int *A,int n) {
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
}

void quicksort(int *B, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = B[(left + right) / 2];

    while (i <= j) {
      while (B[i] > pivot)
        i++;
      while (B[j] < pivot)
        j--;
      if (i <= j) {
        tmp = B[i];
        B[i] = B[j];
        B[j] = tmp;
        i++;
        j--;
      }
    };
    // rec
    if (left < j)
      quicksort(B, left, j);
    if (i < right)
      quicksort(B, i, right);
}
