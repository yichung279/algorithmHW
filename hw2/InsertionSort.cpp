#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <math.h>
using namespace std;

void InsertionSort(int* , int);
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
  InsertionSort(array, len);
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
