#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;

void QuickSort(int*, int, int);
int Partition(int*, int, int);
void InsertionSort(int* , int);
int str2int(string);

int main(){
  ifstream fin;
  fin.open("nearlySort_10000.txt");
  string line;
  getline(fin,line);

  int len = str2int(line);
  int array1[len], array2[len];
  int i = 0;
  while(getline(fin,line)){
    array1[i] = str2int(line);
    array2[i] = str2int(line);
    i++;
  }
  
  double start_s = clock();
  InsertionSort(array1, len);
  double stop_s = clock();
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

  start_s = clock();
  QuickSort(array2, 0, len-1);
  stop_s = clock();
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}

int str2int(string numStr){
  stringstream ss;
  int num;
  ss << numStr;
  ss >> num;
  return num;
}


void InsertionSort(int*  myArray, int length){
  for(int i = 1;i < length; i++){
    int key = myArray[i];
    int j = i - 1;
    while (j >= 0 && myArray[j] > key){
      myArray[j + 1] = myArray[j];
      j--;
    }
    myArray[j + 1] = key;
  }
}
void QuickSort(int*  A, int p, int r){
  if(p < r){
    int q = Partition(A, p, r);
    QuickSort(A, p, q - 1);
    QuickSort(A, q + 1, r);
  }
}

int Partition(int* A, int p, int r){
  int x = A[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(A[j] <= x){
      i++;
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  i++;
  A[r] = A[i];
  A[i] = x;
  return i;
}
