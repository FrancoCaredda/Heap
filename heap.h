#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap
{
public:
    Heap() = default;

    // Adds element to heap
    void Push(int value);
    // Removes max element from heap
    int Pop();

    // Index of parent
    inline int Parent(int child) const noexcept { return (child - 1) / 2; }
    // Index of left child
    int LeftChild(int parent) const noexcept { return 2 * parent + 1; }
    // Index of right child
    int RightChild(int parent) const noexcept { return 2 * parent + 2; };

    // Returns max element in heap
    inline int Top() const noexcept { return m_Values[0]; }
    inline bool IsEmpty() const noexcept { return m_Values.empty(); }

    void Print() const noexcept;

    ~Heap() = default;
private:
    void Melt(int index) noexcept;
private:
    std::vector<int> m_Values;
};

#endif