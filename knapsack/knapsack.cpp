#include<iostream>
using namespace std;

int knapsack(int n, int w, int* value, int* weight){
  int c[n + 1][w + 1] ;   // prevent c[-1][w]
  for(int i = 0; i < n+1; i++)
    for(int j = 0; j < w+1; j++)
      c[i][j] = 0;
  
  for (int i = 0; i < n; ++i){   
    for (int j = 0; j <= w; ++j){
      // too heavy to carry
      if (j - weight[i] < 0){
        c[i + 1][j] = c[i][j];
      }else{
        // carry, if it's more value than carry other item
        c[i + 1][j] = max(c[i][j], c[i][j - weight[i]] + value[i]);
      }
    }
  } 
  
  return c[n][w];
}

int main(){
  const int N = 3;       // number of items to be packed
  const int W = 50;      // total weight knapsack can carry

  // initailize items
  int value[N] = {60, 100, 120};
  int weight[N] = {10, 20, 30};
  
  cout << "The most value knapsack can carry :" << knapsack(N, W, value, weight);
}
