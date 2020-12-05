
#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>
#include "my_malloc.h"
#include "my_free.h"

using namespace std;

int main() {
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
    
    for(int i = 0; i < 40; i++) {
        processesMemory[i] = 1;
    }
    
    while(totalMemUsed != 10000) {
        int mem = memReq(seed);
        processesMemory[processNum] = processesMemory[processNum] + mem;
        totalMemUsed = totalMemUsed + mem;
        //if the totall memory over 10000 end the loop and subtract from the last process given memory        
        if(totalMemUsed > 10000) {
            break;
        }
        processNum++;
    }
    
    while(totalMemUsed > 10000) {
        processesMemory[processNum] = processesMemory[processNum] - 1;
        totalMemUsed = totalMemUsed - 1;
    }
    
    for(int i = 0; i < 40; i++) {
        long long servTime = serv(seed);
        int process = processesMemory[i];
        cout << "Process Number\t" << i+1 << "\tProcess Size\t" << process << "\tService Time\t" << servTime << "\n";
    }
    cout <<  "\n" << totalMemUsed << "\n";
    
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
                //in the block of 10000 mem locations malloc handles where the processes go

		p[i] = (int*)malloc(sizeof(int));
                int mem = memReq(seed);
                processesMemory[i] = processesMemory[i] + mem;
                totalMemUsed = totalMemUsed + mem;

            }
            processNum++;
            

            for(int i = 0; i < 40; i++) {
                free(p[i]);
            }
            auto end = chrono::steady_clock::now();
            
            for(int i = 0; i < 40; i++) {
                long long servTime = serv(seed);
                int process = processesMemory[i];
                cout << "\nProcess ID: " << i+1 << "\tService Time: " << servTime << "\tMemory Requirement: " << process;
            }
            cout << "\nTime elapsed (nanoseconds): \n" << chrono::duration_cast<chrono::nanoseconds>(end-start).count();
            
            scenario1 = false;
        }
        running = false;
    }
}
    
    
