#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater

int main() {
    // Create a priority_queue that acts as a min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;

    // Add elements to the min-heap
    minHeap.push(10);
    minHeap.push(4);
    minHeap.push(15);
    minHeap.push(7);

    // Print and remove elements from the min-heap
    std::cout << "Elements in min-heap order:" << std::endl;
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;

    return 0;
}

