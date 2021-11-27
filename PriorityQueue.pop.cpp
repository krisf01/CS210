// Programmer: Kristina Fout
// Programmer ID: 1866884

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include<cassert>
#include<cmath>
#include<ctime>
#include<cstdlib>

#include "PriorityQueue.h"

int main()
{
    cout << "Programmer: Kristina Fout\n";
    cout << "Programmer ID: 1866884\n";
    cout << "file: " << __FILE__ << "\n\n";
    
    int n = 1000000;
    const int reps = n/100;
    double elapsedSecondsNorm = 0;
    
    string bigOh = "O(log n)";
    
    cout.setf(ios::fixed);
    cout.precision(4);
    
    srand(time(0));

    for(int cycle = 0; cycle < 4; cycle++, n*=2)
    {
        PriorityQueue<int> stack;
        
        for(int i = 0; i < n; i++)
        {
            stack.push(rand()%(1000));
        }
        
        assert(stack.size() == n);
        
        for(int i = 0; i < reps; i++)
        {
            stack.push(rand()%(1000));
        }
        
        assert(stack.size() == n + reps);

        clock_t startTime= clock();

        for(int i = 0; i < n + reps; i++)
        {
            stack.pop();
        }
        
        assert(stack.size() == 0);
        
        clock_t endTime = clock();
        
        // compute timing results
        double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        double factor = pow(2.0, double(cycle));
        if (cycle == 0)
            elapsedSecondsNorm = elapsedSeconds;
        double expectedSecondsLog = log(double(n)) / log(n / factor) * elapsedSecondsNorm;
        double expectedSecondsLog_n = log(double(n + reps)) / log( (n + reps) / factor) * elapsedSecondsNorm;
            // reporting block
                cout << elapsedSeconds;
            if (cycle == 0)
                cout << " (expected " << bigOh << ')';
            else
                cout << " (expected " << expectedSecondsLog << " to " << expectedSecondsLog_n << ')';
                cout << " for n = " << n << endl;
    }
    

    return 0;
}
