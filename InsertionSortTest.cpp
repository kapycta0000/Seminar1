#include "../catch2/catch.hpp"
#include "InsertionSort.cpp"
#include <vector>
#include <algorithm>

TEST_CASE("Сортировка вставками - базовый функционал", "[insertion][sorting]") {
    std::vector<int> arr = { 5, 2, 8, 1, 9 };
    std::vector<int> expected = { 1, 2, 5, 8, 9 };

    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка вставками - пустой массив", "[insertion][edge]") {
    std::vector<int> arr = {};

    insertionSort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Сортировка вставками - один элемент", "[insertion][edge]") {
    std::vector<int> arr = { 7 };

    insertionSort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 7);
}

TEST_CASE("Сортировка вставками - два элемента отсортированы", "[insertion][edge]") {
    std::vector<int> arr = { 1, 2 };

    insertionSort(arr);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
}

TEST_CASE("Сортировка вставками - два элемента не отсортированны", "[insertion][edge]") {
    std::vector<int> arr = { 2, 1 };

    insertionSort(arr);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
}

TEST_CASE("Сортировка вставками - почти отсортирован", "[insertion][edge]") {
    std::vector<int> arr = { 1, 2, 3, 5, 4 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка вставками - два элемента не на своём месте", "[insertion][edge]") {
    std::vector<int> arr = { 5, 1, 2, 3, 4 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка вставками - 3 элемента не на своём месте", "[insertion][edge]") {
    std::vector<int> arr = { 2, 3, 4, 5, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка вставками - одинаковые элементы", "[insertion][edge]") {
    std::vector<int> arr = { 3, 3, 3, 3 };

    insertionSort(arr);
    REQUIRE(std::all_of(arr.begin(), arr.end(), [](int x) { return x == 3; }));
}

TEST_CASE("Сортировка вставками - отрицательные числа", "[insertion][edge]") {
    std::vector<int> arr = { -1, -3, -2, -5 };
    std::vector<int> expected = { -5, -3, -2, -1 };

    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка вставками - дубликаты", "[insertion][edge]") {
    std::vector<int> arr = { 3, 1, 2, 3, 1 };

    insertionSort(arr);

    for (size_t i = 1; i < arr.size(); i++) {
        REQUIRE(arr[i] >= arr[i - 1]);
    }

    REQUIRE(std::count(arr.begin(), arr.end(), 1) == 2);
    REQUIRE(std::count(arr.begin(), arr.end(), 2) == 1);
    REQUIRE(std::count(arr.begin(), arr.end(), 3) == 2);
}

TEST_CASE("Сортировка вставками - char", "[insertion][types]") {
    std::vector<char> arr = { 'z', 'a', 'c', 'b' };
    std::vector<char> expected = { 'a', 'b', 'c', 'z' };

    insertionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка вставками - double", "[insertion][types][double]") {
    std::vector<double> arr = { 3.14, 1.41, 2.71, 0.57 };
    std::vector<double> expected = { 0.57, 1.41, 2.71, 3.14 };

    insertionSort(arr);

    for (size_t i = 0; i < arr.size(); i++) {
        REQUIRE(arr[i] == Approx(expected[i]));
    }
}