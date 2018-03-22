#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <math.h>
using namespace std;

void Merge(int* , int , int , int);
void MergeSort(int* , int , int);
int str2int(string);
string int2str(int num);

int main(){
  ifstream fin;
  fin.open("test.txt");
  string line;
  getline(fin,line);
  int len = str2int(line);
  int array[len];
  int i = 0;
  while(getline(fin,line)){
    array[i] = str2int(line);
    i++;
  }
  MergeSort(array, 0, len-1);
  ofstream fout;
  fout.open ("output.txt");
  fout << int2str(len) << endl;
  for(int i = 0; i < len; i++) fout << int2str(array[i]) << endl;
}

int str2int(string numStr){
  stringstream ss;
  int num;
  ss << numStr;
  ss >> num;
  return num;
}

string int2str(int num){
  stringstream ss;
  string numStr;
  ss << num;
  ss >>  numStr; 
  return numStr;
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
  for(int i = 0; i < n2; i++) R[i]=array[q + i + 1];
  L[n1] = 0x7fffffff;
  R[n2] = 0x7fffffff;
  int I = 0;
  int J = 0;
  for(int i = p; i <= r ; i++ ){
    if(L[I]<R[J]){
      array[i] = L[I];
      I++;
    }else{   
      array[i] = R[J];
      J++;
    }
  }
}
