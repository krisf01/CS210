#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

#include "DynamicArray.h"
#include "Queue.h"

struct Customer
{
    char id;
    int arrivalTime;
    int endTime;
};

int getRandomNumberOfArrivals(double);
char genID(char &);
int randTimeAdd(int, int);

int main()
{
    cout << "Programmer: Kristina Fout\n";
    cout << "Programmer ID: 1866884\n";
    cout << "file: " << __FILE__ << "\n\n";
    
    srand(time(0));
    rand();

    int numServers = 0, waitLength = 0, minTime = 0, maxTime = 0, clockStopTime = 0;
    double avgArrivalRate = 0.5;
    char letter = 'A';
    
    ifstream fin;
    fin.open("simulation.txt");

    int switchCount = 0;

    while (fin.good())
    {
        string input;
        getline(fin, input);
        switch (switchCount)
        {
            case 0:
                numServers = atoi(input.c_str());
                cout << "number of servers: " << numServers << endl;
                break;
            case 1:
                avgArrivalRate = atof(input.c_str());
                break;
            case 2:
                waitLength = atoi(input.c_str());
                cout << "maximum queue length: " << waitLength << endl;
                break;
            case 3:
                minTime = atoi(input.c_str());
                cout << "minimum service time: " << minTime << " minutes" << endl;
                break;
            case 4:
                maxTime = atoi(input.c_str());
                cout << "maximum service time: " << maxTime << " minutes" << endl;
                break;
            case 5:
                clockStopTime = atoi(input.c_str());
                cout << "customer arrival rate: " << avgArrivalRate << " per minute, for " << clockStopTime << " minutes" << endl;
                break;
            default:
                throw("Error!");
        }
        switchCount++;
        }
    Queue<Customer> waitLine;
    DynamicArray<Customer> nowServing;
    DynamicArray<int> serversStatus;
    
    for (int time = 0;; time++)
    {
// handle all services scheduled to complete at this clock time
        for (int i = 0; i < numServers; i++)
        {
            if (serversStatus[i])
            { //means is busy
                if (nowServing[i].endTime == time)
                {
                    serversStatus[i] = false;
                }
            }
        }
        if (time < clockStopTime)
        {
            int numArrive = getRandomNumberOfArrivals(avgArrivalRate);
            for (int i = 0; i < numArrive; i++)
            {
                if (waitLine.size() < waitLength)
                {
                    Customer c;
                    c.id = genID(letter);
                    c.arrivalTime = time;
                    waitLine.push(c);
                }
            }
        }
// for idle servers, move customer from wait queue and begin
        for (int i = 0; i < numServers; i++)
        {
            if (!serversStatus[i] && !waitLine.empty())
            {
                nowServing[i] = waitLine.front();
                waitLine.pop();
                nowServing[i].endTime = time + randTimeAdd(minTime, maxTime);
                serversStatus[i] = true;
            }
        }
        
        cout << "\nTime: " << time << endl;
        cout << "---------------------------" << endl;
        cout << "server now serving wait queue" << endl;
        cout << "------ ----------- ----------" << endl;
        for (int i = 0; i < numServers; i++)
        {
            string show = " ";
            if (serversStatus[i])
            {
                show = nowServing[i].id;
            }
            
            cout << setw(2) << i << setw(10) << show;
            
            if (i == 0)
            {
                Queue<Customer> copy(waitLine);
                cout << setw(10);
                while (!copy.empty())
                {
                    cout << copy.front().id;
                    copy.pop();
                }
            }
            cout << endl;
        }
        int numIdle = 0;

        for (int i = 0; i < numServers; i++)
        {
            if (!serversStatus[i])
            {
                numIdle++;
            }
        }
        if (numIdle == numServers && time >= clockStopTime)
        {
            break;
        }
        do
        {
            cout << '\n' << "Press ENTER to continue...";
        }
        while (cin.get() != '\n');
    }
    
system("pause");
}

int randTimeAdd(const int a, const int b)
{
    return a + (rand() % b);
}

char genID(char &letters)
{
    if (letters == 'Z')
    {
        letters = 'A';
        return 'Z';
    }
    return letters++;
}

int getRandomNumberOfArrivals(double averageArrivalRate)
{
    int arrivals = 0;
    double probOfnArrivals = exp(-averageArrivalRate);
    
    for (double randomValue = (double)rand() / RAND_MAX;
         (randomValue -= probOfnArrivals) > 0.0;
         probOfnArrivals *= averageArrivalRate / static_cast<int>(++arrivals));
    
    return arrivals;
}
