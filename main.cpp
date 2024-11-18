/***************************************************************************
* COMSC-210 | Lab 32 & 33 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

// Probabilities
const int DEPARTURE = 46;
const int JOIN = 39;
const int SHIFT = 15;
// Other CONST
const int NUM_OF_LANES = 4;
const int SIMULATION_STEPS = 20;
const int INITIAL_QUEUE_SIZE = 2;

void print_id(string const& lab_desc);
int getRandomInt(int min, int max);

int main()
{
    print_id("Lab 32 & 33: Toll Booth & Plaza");

    srand(time(0));

    // Initialize an array of deque with two cars in each deque (lane)
    deque<Car> tollQueue[NUM_OF_LANES] {};
    for (int i = 0; i < NUM_OF_LANES; i++)
    {
        tollQueue[i].push_back(Car());
        tollQueue[i].push_back(Car());
    }

    // Display the initial queue
    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_OF_LANES; ++i)
    {
        cout << "Lane " << i << ":" << '\n';
        for (int j = 0; j < INITIAL_QUEUE_SIZE; j++)
        {
            setw(4);
            tollQueue[i][j].print();
        }
    }
    cout << "\n\n";

    // Simulation loop
    int step = 0;
    while (step++ < 20)
    {
        cout << "Time: " << step << "\n";

        int probability = 1 + rand() % 99;

        // 55% probability the Car at the head leaves the queue
        if (probability < 55)
        {
            Car departingCar = tollQueue.front();
            tollQueue.pop_front();
            cout << "Car departing: ";
            departingCar.print();
            cout << "\n";
        }
        else // 45% probability a new Car joins at the back of the queue
        {
            tollQueue.push_back(Car());
            cout << "New car joined the queue: ";
            tollQueue.back().print();

            cout << "\n";
        }

        // Display the current queue
        if (!tollQueue.empty())
        {
            cout << "Current queue:\n";
            for (auto& car : tollQueue)
                car.print();
            cout << "\n";
        }
        else
            cout << "The queue is now empty.\n";

        cout << "---------------------------------------\n";
        step++;
    }

    cout << "\n";
    return 0;
}

int getRandomInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void print_id(string const& lab_desc)
{
    cout << "\nCOMSC210 | Grant Luo | " << lab_desc << "\n";
    cout << "Editor: CLion\n";
    cout << "Compiler: Apple clang version 16.0.0\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}