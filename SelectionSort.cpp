#include "SelectionSort.h"
#include <vector>
#include <algorithm>

template<typename T>
void selectionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

template void selectionSort<int>(std::vector<int>&);
template void selectionSort<double>(std::vector<double>&);
template void selectionSort<float>(std::vector<float>&);