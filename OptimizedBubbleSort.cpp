#include "OptimizedBubbleSort.h"
#include <vector>
#include <algorithm>

template<typename T>
void optimizedBubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

template void optimizedBubbleSort<int>(std::vector<int>&);
template void optimizedBubbleSort<double>(std::vector<double>&);
template void optimizedBubbleSort<float>(std::vector<float>&);