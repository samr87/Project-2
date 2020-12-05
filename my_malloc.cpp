#include "my_malloc.h"
#include<iostream>
#include<stdio.h>

using namespace std;

void my_malloc(int processesMemory[], long long blockSize[], int processNum) {
  int orderOfProcesses[processNum];
  
  for(int i = 0; i < 40; i++) {
    for(int j = 0; j < 40; j++) {
      //if the block size is greater than the process's memory then it fits
      if(blockSize[j] >= processesMemory[i]) {
      //to keep track of which processes are fit where  
        orderOfProcesses[i] = j;
      //subtract from the total blockSize so you know how much is left to fit the other processes  
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
