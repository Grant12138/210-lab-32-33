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
    cout << "---------------------------------------\n\n";

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
    for (int i = 0; i < NUM_OF_LANES; i++)
    {
        cout << "Lane " << i + 1 << ":" << '\n';
        for (int j = 0; j < INITIAL_QUEUE_SIZE; j++)
        {
            cout << "    ";
            tollQueue[i][j].print();
        }
    }
    cout << "\n---------------------------------------\n\n";

    // Simulation loop
    int step = 0;
    while (step++ < SIMULATION_STEPS)
    {
        cout << "Time: " << step << "\n";

        // First list what operations happened in all the lanes
        for (int i = 0; i < NUM_OF_LANES; i++)
        {
            // If the lane is empty, 50/50 chance a new car joins the lane
            if (tollQueue[i].empty())
            {
                int probability = getRandomInt(0, 99);
                if (probability < 50)
                {
                    Car newCar = Car();
                    cout << "Lane: " << i + 1 << " Joined: ";
                    tollQueue[i].push_back(newCar);
                    tollQueue[i].back().print();
                }
            }
            // If the lane is not empty
            else
            {
                int probability = getRandomInt(0, 99);

                // 46% probability that the car at the head of the queue pays its toll and leaves the queue
                if (probability < DEPARTURE)
                {
                    cout << "Lane: " << i + 1 << " Paid: ";
                    tollQueue[i].front().print();
                    tollQueue[i].pop_front();
                }
                // 39% probability that another car joins the queue
                else if (probability < DEPARTURE + JOIN)
                {
                    cout << "Lane: " << i + 1 << " Joined: ";
                    Car newCar = Car();
                    tollQueue[i].push_back(newCar);
                    tollQueue[i].back().print();
                }
                // 15% probability that the rear car will shift lanes
                else
                {
                    cout << "Lane: " << i + 1 << " Switched: ";
                    tollQueue[i].back().print();
                    Car switchedCar = tollQueue[i].back();
                    tollQueue[i].pop_back();
                    int newLane;
                    do
                    {
                        newLane = rand() % 4;
                    }
                    while (newLane == i);
                    tollQueue[newLane].push_back(switchedCar);
                }
            }
        }

        // Display the current queue
        for (int i = 0; i < NUM_OF_LANES; i++)
        {
            cout << "Lane " << i + 1 << " Queue:\n";
            if (tollQueue[i].empty())
                cout << "\tEMPTY\n";
            else
            {
                for (auto& car : tollQueue[i])
                {
                    cout << '\t';
                    car.print();
                }
            }
        }

        cout << "\n---------------------------------------\n\n";
    }

    return 0;
}

/************************************************************************
 * FUNCTION: A helper function that returns an integer between specified min and max
 *
 * @param min
 * @param max
 *
 * @return INT;
 */
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