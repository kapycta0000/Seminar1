#include "ExchangeSort.h"
#include <vector>
#include <algorithm>

template<typename T>
void exchangeSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template void exchangeSort<int>(std::vector<int>&);
template void exchangeSort<double>(std::vector<double>&);
template void exchangeSort<float>(std::vector<float>&);
template void exchangeSort<char>(std::vector<char>&);
template void exchangeSort<long>(std::vector<long>&);