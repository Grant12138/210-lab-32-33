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
    for (const auto& car : tollQueue)
        car.print();

    return 0;
}