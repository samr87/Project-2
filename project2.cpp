
#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>
#include "my_malloc.h"
#include "my_free.h"

using namespace std;

int main() {
	
//gets seed value from the user
    long long seedValue;
    cout << "Enter a seed value: ";
    cin >> seedValue;
        
    mt19937_64 seed(seedValue);
    
    int processNum = 0;
    int totalMemUsed = 40;
    int processesMemory[40];
    int *p[10000];
    
    uniform_int_distribution<long long> serv(1000000, 1000000000000);
    uniform_int_distribution<int> memReq(0, 249);
    
//initializes all the processes to have at least 1 MB
    for(int i = 0; i < 40; i++) {
        processesMemory[i] = 1;
    }
    
//while the total mem is not 10000, grab a random # and add it to that specific process in processesMemory
    while(totalMemUsed != 10000) {
        int mem = memReq(seed);
        processesMemory[processNum] = processesMemory[processNum] + mem;
        totalMemUsed = totalMemUsed + mem;
//if the total memory over 10000 breaks the loop       
        if(totalMemUsed > 10000) {
            break;
        }
        processNum++;
    }
	
//subtract from the last process given memory until 10000 
    while(totalMemUsed > 10000) {
        processesMemory[processNum] = processesMemory[processNum] - 1;
        totalMemUsed = totalMemUsed - 1;
    }
//Output the processes generated    
    for(int i = 0; i < 40; i++) {
        long long servTime = serv(seed);
        int process = processesMemory[i];
        cout << "Process Number\t" << i+1 << "\tProcess Size\t" << process << "\tService Time\t" << servTime << "\n";
    }
    cout <<  "\n" << totalMemUsed << "\n";

//so complete simulation runs    
    bool running = true;
    
//while boolean is true run all of the scenarios, otherwise program will end
    while(running != false) {
        bool scenario1 = true;
        //run scenario until false
        while(scenario1 != false) {
            auto start = chrono::steady_clock::now();
            
            for(int i = 0; i < 40; i++) {
                processesMemory[i] = 1;
            }
            
            processNum == 0;
            
            for(int i = 0; i < 40; i++) {
                
		//in the block of mem locations malloc handles where the processes go
		p[i] = (int*)malloc(sizeof(int));
		//take the random seed # generated and store it in the processes memory
                int mem = memReq(seed);
                processesMemory[i] = processesMemory[i] + mem;
                totalMemUsed = totalMemUsed + mem;

            }
            processNum++;
            
	//freeing processes
            for(int i = 0; i < 40; i++) {
                free(p[i]);
            }
            auto end = chrono::steady_clock::now();
       //outputting data     
            for(int i = 0; i < 40; i++) {
                long long servTime = serv(seed);
                int process = processesMemory[i];
                cout << "\nProcess ID: " << i+1 << "\tService Time: " << servTime << "\tMemory Requirement: " << process;
            }
            cout << "\nTime elapsed (nanoseconds): \n" << chrono::duration_cast<chrono::nanoseconds>(end-start).count();
            
            scenario1 = false;
        }
	    
	bool scenario2 = true;
	long long blockSize[10000];    
	while(scenario2 != false) {
		auto start = chrono::steady_clock::now();
		
		for(int i = 0; i < 40; i++) {
			processesMemory[i] = 1;
		}
		
		processNum = 40;
	
		//call my_malloc to allocate first fit with the random seed # generated
		for(int i = 0; i < 40; i++) {
			int mem = memReq(seed);
			processesMemory[i] = processesMemory[i] + mem;
			my_malloc(processesMemory, blockSize, processNum);
		}
		auto end = chrono::steady_clock::now();
		cout<< "Time elpased (nanoseconds): " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << "\n";
		scenario2 = false;
	}    
        running = false;
    }
}
    
    
