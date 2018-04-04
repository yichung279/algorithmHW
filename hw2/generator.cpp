#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <stdlib.h>
using namespace std;

string int2str(int num);

int main(){
  int len = 10000;
  int array[len];
  for(int i = 0; i < len; i++) array[i] = i;
  
  srand(0);//same result every time
  int num_exch = 200; 
  int random[num_exch];
  for(int i = 0; i < num_exch; i++) random[i] = (rand() % len);

  for(int i = 0; i < num_exch; i = i + 2){
    int tmp = array[random[i]];
    array[random[i]] = array[random[i + 1]];
    array[random[i + 1]] = tmp;
  }
  
  ofstream fout;
  fout.open ("nearlySort_10000.txt");
  fout << len << endl;
  for(int i = 0; i < len; i++) fout << int2str(array[i]) << endl;
}

string int2str(int num){
  stringstream ss;
  string numStr;
  ss << num;
  ss >>  numStr; 
  return numStr;
}

