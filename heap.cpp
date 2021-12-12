#include "heap.h"
#include <cmath>
#include <algorithm>
#include <iostream>

void Heap::Push(int value)
{
    m_Values.push_back(value);

    int index = m_Values.size() - 1;
    int parent = Parent(index);

    while (m_Values[index] > m_Values[parent])
    {
        std::swap(m_Values[index], m_Values[parent]);   

        index = parent;
        parent = Parent(index);
    }
}

int Heap::Pop()
{
    int result = m_Values[0];
    int index = m_Values.size() - 1;

    std::swap(m_Values[index], m_Values[0]);
    m_Values.pop_back();

    Melt(0);

    return result;
}

void Heap::Melt(int index) noexcept
{
    int leftChild = LeftChild(index);
    int rightChild = RightChild(index);

    if (leftChild >= m_Values.size() || rightChild >= m_Values.size())
        return;

    if (m_Values[leftChild] > m_Values[rightChild] && m_Values[leftChild] > m_Values[index])
    {
        std::swap(m_Values[leftChild], m_Values[index]);
        Melt(leftChild);
    }
    else if (m_Values[leftChild] < m_Values[rightChild] && m_Values[rightChild] > m_Values[index])
    {
        std::swap(m_Values[rightChild], m_Values[index]);
        Melt(rightChild);   
    }
}

void Heap::Print() const noexcept
{
    for (int i = 0; i < m_Values.size(); i++)
        std::cout << m_Values[i] << " ";
}
