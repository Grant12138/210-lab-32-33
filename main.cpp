#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

const int INITIAL_QUEUE_SIZE = 2;

int main()
{
    srand(time(0));

    deque<Car> tollQueue {};
    for (int i = 0; i < INITIAL_QUEUE_SIZE; i++)
        tollQueue.push_back(Car());

    cout << "Initial queue:\n";
    for (auto& car : tollQueue)
        car.print();
    cout << "\n\n";

    int step = 1;
    while (!tollQueue.empty())
    {
        cout << "Step " << step << ":\n";

        int probability = 1 + rand() % 99;

        if (probability < 55)
        {
            Car departingCar = tollQueue.front();
            tollQueue.pop_front();
            cout << "Car departing: ";
            departingCar.print();
            cout << "\n";
        }
        else
        {
            tollQueue.push_back(Car());
            cout << "New car joined the queue: ";
            tollQueue.back().print();

            cout << "\n";
        }

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

    return 0;
}