#include <iostream>

using namespace std;

void print(int *A, int size);
void del(int *&A, int &size);
void quicksort(int *A, int left, int right);

int main(){
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

  del(A, size);
  cout << "Your  array after deleting is: ";
  print (A, size);

  cout << endl;

  quicksort(A, 0, size - 1);
  cout << "Your  array after quicksort is: ";
  print (A, size);
 return 0;
}

void print (int *A,int size) {
  for (int i = 0; i < size; i++) {
    cout << A[i] << " ";
  }
}

void del (int *&A, int &size) {
  int n = 0;
  for(int i = 0; i <= size; i++){
    if (A[i] >= 0) {
      n++;

    }
  }
  int *B = new int[n];

  int counter = 0;

  for(int i = 0; i < size; i++) {
    if (A[i] >= 0) {
        B[counter] = A[i];
        counter++;
      }
    }
  delete []A;
  size = n - 1;
  A = B;

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
