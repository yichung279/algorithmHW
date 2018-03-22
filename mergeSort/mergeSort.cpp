#include<iostream>
#include <math.h>
using namespace std;

void Merge(int* , int , int , int);
void MergeSort(int* , int , int);

int main(){
  int len = 6;
  int array[] = {3, 4, 8, 1, 68, 1};
  MergeSort(array, 0, len-1);
  for (int i = 0; i < len; i++){
    cout << array[i];
  }
}

void MergeSort(int* array, int p, int r){
  if(p<r){
    int q = floor((p + r) / 2);
    MergeSort(array, p, q);
    MergeSort(array, q+1, r);
    Merge(array, p, q, r);
  }
}

void Merge(int* array, int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1 + 1];
  int R[n2 + 1];
  for(int i = 0; i < n1; i++) L[i]=array[p + i];
  for(int i = 0; i < n2; i++) R[i]=array[q + 1 + 1];
  L[n1] = 0x7fffffff;
  R[n2] = 0x7fffffff;
  int I = 0;
  int J = 0;
  for(int i = p; i <= r ; i++ ){
    if(L[I]<R[J]){
      array[i] = L[I];
      I++;
    }else{
      array[i] = L[J];
      J++;
    }
  }
}
