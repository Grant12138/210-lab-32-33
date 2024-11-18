/***************************************************************************
* COMSC-210 | Lab 32 & 33 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

const int INITIAL_QUEUE_SIZE = 2;

void print_id(string const& lab_desc);

int main()
{
    print_id("Lab 32 & 33: Toll Booth & Plaza");

    srand(time(0));

    // Initialize the queue with two cars
    deque<Car> tollQueue {};
    for (int i = 0; i < INITIAL_QUEUE_SIZE; i++)
        tollQueue.push_back(Car());

    // Display the initial queue
    cout << "Initial queue:\n";
    for (auto& car : tollQueue)
        car.print();
    cout << "\n\n";

    // Simulation loop
    int step = 1;
    while (!tollQueue.empty())
    {
        cout << "Step " << step << ":\n";

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

void print_id(string const& lab_desc)
{
    cout << "\nCOMSC210 | Grant Luo | " << lab_desc << "\n";
    cout << "Editor: CLion\n";
    cout << "Compiler: Apple clang version 16.0.0\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}