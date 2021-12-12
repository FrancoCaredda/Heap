#include "heap.h"
#include <iostream>

#include <ctime>
#include <cstdlib>

int main(void)
{
    std::vector<int> Array = {5, 6, 7, 8, 2, 10, 100, 12, 13};

    Heap heap;

    for (int i = 0; i < Array.size(); i++)
        heap.Push(Array[i]);

    while (!heap.IsEmpty())
        std::cout << heap.Pop() << " ";

    return 0;
}