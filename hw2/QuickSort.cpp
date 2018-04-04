#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <math.h>
using namespace std;

void QuickSort(int*, int, int);
int Partition(int*, int, int);
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
  QuickSort(array, 0, len - 1);
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

