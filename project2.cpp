#include<iostream>
#include<rand>

using namespace std;

int main() {
  long long seedValue;
  cout << "Enter a seed value: ";
  cin >> seedValue;
  
  mt19937_64 seed(seedValue);
  
  int memSum = 0;
  int processNum = 0;
  
  uniform_int_distribution<long long> serv(1000000, 1000000000000);
  uniform_int_distribution<int> mem(1, 250);
  
  for(int i = 0; i < 40; i++) {
    long long servTime = serv(seed);
    processNum += 1;
    long memSize = mem(seed);
    memSum = memSum + memSize;
    cout << processNum << "\t" << servTime << "\t" << memSize << "\n";
  }
  cout << " " << memSum << "\n";

}
