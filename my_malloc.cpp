#include "my_malloc.h"
#include<iostream>
#include<stdio.h>

using namespace std;

void my_malloc(int processesMemory[], long long blockSize[], int processNum) {
  int orderOfProcesses[processNum];
  
  for(int i = 0; i < 40; i++) {
    for(int j = 0; j < 40; j++) {
      if(blockSize[j] >= processesMemory[i]) {
        orderOfProcesses[i] = j;
        
        blockSize[j] - processesMemory[i];
      }
    }
  }
  cout << "Allocation Complete\n" << "The order the processes were processed are: \n";
  for(int i = 0; i < 40; i++) {
    int order = orderOfProcesses[i];
    cout << order;
  }
}
