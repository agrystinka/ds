#include <iostream>
#include <cstdlib>


using namespace std;

void print(int *A,int n);
void modul(int *&A, int &size);
void quicksort(int *A, int left, int right);
void shellsort (int *A, int size);

int main() {
  int size;
  int *A = new int[size];

  cout << "Enter size of array: " << endl;
  cin >> size;

  srand(time(NULL));
   for (int i = 0; i < size; i++) {
     A[i] = rand() % 198 - 99;
 }

  cout << "Your  array is: ";
  print (A, size);

  cout << endl;

  modul(A, size);
  cout << "Your  array modulo is: ";
  print (A, size);

  cout << endl;

  quicksort(A, 0, size - 1);
  cout << "Your  array in ascending order is: ";
  print (A, size);

  cout << endl;

  shellsort(A, size);
  cout << "Your  array in descending order is: ";
  print (A, size);

}

void print (int *A,int size) {
  for (int i = 0; i < size; i++) {
    cout << A[i] << " ";
  }
}

void modul(int *&A, int &size){
  for (int i = 0; i < size; i++){
    if (A[i] < 0) {
    A[i] = -A[i];
    }
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
