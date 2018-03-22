#include<iostream>
#include <math.h>
using namespace std;

void Merge(int* array, int p, int q, int r);
void MergeiSort(int* array, int p, int r);

int main(){
  int len = 6;
  int* array = {3, 4, 8, 1, 68, 1};
  MergeSort(array, 0, len - 1);
  for (int i = 0; i < len; i++){
    cout << array[i];
  }
}

void MergeiSort(int* array, int p, int r){
  if(p<r){
    q = floor((p + t) / 2);
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
  for(int i = 0; i < n1; i++) L[i]=A[p + i];
  for(int i = 0; i < n2; i++) R[i]=A[q + j + 1];
  L[n1] = 0x7fffffff;
  R[n3] = 0x7fffffff;
  int I = 0;
  int J = 0;
  for(int i = p; i <= r ; i++ ){
    if(L[I]<R[J]){
      array[i] = L[I];
      I++;
    }else{
      J++;
    }
  }
}
