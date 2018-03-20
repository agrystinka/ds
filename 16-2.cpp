#include <iostream>

using namespace std;

void print(int *A, int size);
void del(int *&A, int &size);
void shellsort(int *A, int size);

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

  shellsort(A, size);
  cout << "Your  array after shellsort is: ";
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
