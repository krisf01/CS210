#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

#include "PriorityQueue.h"
#include "Queue.h"
#include "DynamicArray.h"

struct Customer
{
    char id;
    int arrivalTime;
};

struct serverInfo
{
    Customer customer;
    bool status;
};

struct serviceEvent
{
    int serverNum;
    int endTime;
};

bool operator < (const serviceEvent& a, const serviceEvent& b)
{
    return a.endTime < b.endTime ? false : true;
}

bool operator >= (const serviceEvent& a, const serviceEvent& b)
{
    return a.endTime >= b.endTime ? false : true;
}

char getLetter(char &letter)
{
    letter++;
    if (letter > 'Z')
        letter = 'A';
    return letter;
}

int getRandomNumberOfArrivals(double averageArrivalRate)
{
    int arrivals = 0;
    double probOfnArrival = exp(-averageArrivalRate);
    for(double randomValue = (double)rand( ) / RAND_MAX; (randomValue -= probOfnArrival) > 0.0; probOfnArrival *= averageArrivalRate / static_cast<double>(++arrivals));
    return arrivals;
}

int main()
{
    cout << "Programmer: Kristina Fout\n";
    cout << "Programmer ID: 1866884\n";
    cout << "file: " << __FILE__ << "\n\n";
        
    Queue<Customer> waitLine;
    DynamicArray<serverInfo> serving;
    PriorityQueue<serviceEvent> eventList;
    
    Customer cus;
    serviceEvent event;
    fstream openfile;
    
    string stringServers, stringRate, stringTime, stringLength, stringMax_time, stringMin_time,stringServer;
    int servers, totalTime, length, max_time, min_time;
    double rate;
    char letter = 'Z';
    
    srand(time(0));
    rand();
        
    openfile.open("simulation.txt");
    if(!openfile.good())
        cout << "I/O error \n";
    openfile >> stringServers;
    
    while(openfile.good())
    {
        getline(openfile,stringServer, '\n');
        getline(openfile,stringRate, '\n');
        getline(openfile,stringLength, '\n');
        getline(openfile,stringMin_time, '\n');
        getline(openfile,stringMax_time, '\n');
        getline(openfile,stringTime, '\n');
    }
        
    servers = stoi(stringServers);
    rate = stof(stringRate);
    totalTime = stoi(stringTime);
    length = stoi(stringLength);
    min_time = stoi( stringMin_time);
    max_time = stoi(stringMax_time);
    int service_time = rand()%(max_time-min_time) + min_time;

    cout<<"Number of servers: " << servers << endl;
    cout<<"Customer arrival rate " << rate << " per minute, for " << totalTime << " minutes" << endl;
    cout<<"Maximum queue length: " << length << endl;
    cout<<"Minimum service time: " << min_time << " minutes" << endl;
    cout<<"Maximum service time: " << max_time << " minutes" << endl;

    for(int time = 0; ; time++)
    {
        for(int i = 0; i < servers; i++)
        {
            if(!serving[i].status)
            {
                if(eventList.top().endTime == time)
                {
                    serving[i].status = true;
                    serving[i].customer.id = ' ';
                }
            }
        }
    if(time < totalTime)
    {
        int arrivalNum = getRandomNumberOfArrivals(rate);
            for(int j = 0; j < arrivalNum; j++)
            {
                if(waitLine.size() < length)
                {
                    cus.id = getLetter(letter);
                    cus.arrivalTime = time;
                    
                    waitLine.push(cus);
                }
            }
        }
        for(int i = 0; i < servers; i++)
        {
            if(serving[i].status && !waitLine.empty())
            {
                serving[i].customer.id = waitLine.front().id;
                waitLine.pop();
                
                event.endTime = time + service_time;
                event.serverNum = i;
                eventList.push(event);
    
                serving[i].status = false;
            }
        }
            cout << endl << "Time: " << time << endl;

            cout << endl << "server" << " | " << "time for end-of-serivce" << endl;
            cout << "------ + -----------------------------" << endl;
            
        // Copying the Event
            PriorityQueue<serviceEvent> EventCopy = eventList;
            while(!EventCopy.empty())
            {
                cout << EventCopy.top().serverNum<<setw(15) << EventCopy.top().endTime << endl;
                EventCopy.pop();
            }
            cout << endl;
            cout << endl;
            
            cout << "--------------------------------------\n";
            cout << "server" << setw(16)<< "now serving"<< setw(16) << "wait line \n";
            cout << "--------------------------------------- \n";
        
        // Copying the Customer
            Queue<Customer> CustomerCopy = waitLine;
            for(int i = 0; i < servers; i++)
            {
                cout << i << setw(16) << serving[i].customer.id << "         ";
                
                while(!CustomerCopy.empty())
                {
                    cout << CustomerCopy.front().id;
                    CustomerCopy.pop();
                }
                cout << endl;
                
            }
            
            if(time == totalTime)
                break;
        }
        cout << "Simulation End!" << endl;
        return 0;
}
