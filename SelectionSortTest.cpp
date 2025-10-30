#include "../catch2/catch.hpp"
#include "SelectionSort.cpp"
#include <vector>
#include <algorithm>

TEST_CASE("Сортировка выбором - базовый функционал", "[selection][sorting]") {
    std::vector<int> arr = { 5, 2, 8, 1, 9 };
    std::vector<int> expected = { 1, 2, 5, 8, 9 };

    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка выбором - пустой массив", "[selection][edge]") {
    std::vector<int> arr = {};

    selectionSort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Сортировка выбором - один элемент", "[selection][edge]") {
    std::vector<int> arr = { 100 };

    selectionSort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 100);
}

TEST_CASE("Сортировка выбором - два элемента", "[selection][edge]") {
    std::vector<int> arr = { 2, 1 };
    std::vector<int> expected = { 1, 2 };

    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка выбором - три элемента", "[selection][edge]") {
    std::vector<int> arr = { 3, 1, 2 };
    std::vector<int> expected = { 1, 2, 3 };

    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка выбором - одинаковые элементы", "[selection][edge]") {
    std::vector<int> arr = { 4, 4, 4, 4 };

    selectionSort(arr);
    REQUIRE(std::all_of(arr.begin(), arr.end(), [](int x) { return x == 4; }));
}

TEST_CASE("Сортировка выбором - с нулями", "[selection][edge]") {
    std::vector<int> arr = { 0, 5, 0, 2, 0 };
    std::vector<int> expected = { 0, 0, 0, 2, 5 };

    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка выбором - отрицательные элементы", "[selection][edge]") {
    std::vector<int> arr = { -3, -1, -2, -5 };
    std::vector<int> expected = { -5, -3, -2, -1 };

    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка выбором - один элемент на правильной позиции", "[selection][edge]") {
    std::vector<int> arr = { 1, 5, 4, 3, 2 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка выбором - char", "[selection][types]") {
    std::vector<char> arr = { 'm', 'a', 'x', 'b' };
    std::vector<char> expected = { 'a', 'b', 'm', 'x' };

    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка выбором - float", "[selection][types]") {
    std::vector<float> arr = { 3.5f, 1.1f, 2.9f, 0.1f };
    std::vector<float> expected = { 0.1f, 1.1f, 2.9f, 3.5f };

    selectionSort(arr);

    for (size_t i = 0; i < arr.size(); i++) {
        REQUIRE(arr[i] == Approx(expected[i]));
    }
}