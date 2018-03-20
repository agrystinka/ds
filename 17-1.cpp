#include <iostream>

using namespace std;

void print(int *A, int n);
void sort(int *&A, int *B, int &size);
void quicksort(int *A,  int left, int right);

int main(){
  int size;
  int *A = new int[size];
  int *B = new int[size];

  cout << "Enter size of array: " << endl;
  cin >> size;

  for (int i = 0; i < size; i ++) {
    cout << "Enter element: " << endl;
    cin >> A[i];
  }

  cout << "Your  array is: ";
  print (A, size);

  cout << endl;

  sort(A, B, size);
  cout << "Array after sorting is: ";
  print (B, size);


}

void print (int *A,int n) {
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
}

void sort(int *&A, int *B, int &size) {
  for (int i = 0; i < size; i++){
    B[i] = A [i];
    quicksort(B, 0, i - 1);
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
