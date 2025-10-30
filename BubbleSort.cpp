#include "BubbleSort.h"
#include <vector>
#include <algorithm>

template<typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template void bubbleSort<int>(std::vector<int>&);
template void bubbleSort<double>(std::vector<double>&);
template void bubbleSort<float>(std::vector<float>&);
template void bubbleSort<char>(std::vector<char>&);
template void bubbleSort<long>(std::vector<long>&);
template void bubbleSort<short>(std::vector<short>&);