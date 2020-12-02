#include <stdio.h>
#include <iostream>
#include <random>

using namespace std;

int main() {

    long long seedValue;
    // This value is a seed which governs the random numbers selected by the program.

    cout << "Enter a seed value: ";
    // This line prompts the user to input an integer through an output message on the screen.

    cin >> seedValue;
    // This line allows the user to input an integer, whch will be used as the seed.

    srand(seedValue);
    // This initializes the users input as the random number generator's seed.

    //mt19937_64 seed(seedValue);

    long memSum = 0;
    // Tracks the total memory used (should be equal 10,000 kb.)

    long processNum = 0;
    // Tracks the number of processes.

    long totalMem = 9960;
    // "Total Memory" in kb - 40 (since each process will have at least 1 kb of memory.)

    int totalProcLeft = 40;

    //uniform_int_distribution<long long> serv(1000000, 1000000000000);
    //uniform_int_distribution<int> mem(1, 250);

    for(int i = 0; i < 40; i++) {
    // This for-loop allocates blocks of memory to the 40 processes.
        
        /*long long servTime = serv(seed);
        long memSize = mem(seed);
        memSum = memSum + memSize;
        cout << processNum << "\t" << servTime << "\t" << memSize << "\n";*/


        long n;
        // n represents the amount of memory being allocated to a process.

        processNum += 1;
        // Increase the number of processes by 1.

        totalProcLeft = totalProcLeft - 1;
        // Reduce the number of unassigned process by 1.

        if (totalMem <= totalProcLeft) {
        // If the total amount of memory left is less than or equal to the number of processes still awaiting assignment,
        // then the system stops assigning a random amount and starts assigning 1.

            n = 1;

        } // End of if-statement

        else {

            n = (rand() % totalMem + 1);
            // A random amount of the memory is assigned to the process.

        } //end of else-statement

        memSum = memSum + n;
        // The total amount of memory currently in use is increased by n.

        totalMem = totalMem - n;
        // The total amount of memory left is reduced by n.

        cout << "\nProcess Number: " << processNum << "  Process Size: " << n;
        // Prints the process number and the amount of memory assigned to it.

  } // End of for-loop.

    cout << "\nTotal Amount: " << memSum;

} // End of main().

