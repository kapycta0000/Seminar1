#include "../catch2/catch.hpp"
#include "ExchangeSort.cpp"
#include <vector>
#include <algorithm>

TEST_CASE("Сортировка обменом - базовый функционал", "[exchange][sorting]") {
    std::vector<int> arr = { 5, 2, 8, 1, 9 };
    std::vector<int> expected = { 1, 2, 5, 8, 9 };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка обменом - пустой массив", "[exchange][edge]") {
    std::vector<int> arr = {};

    exchangeSort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Сортировка обменом - один элемент", "[exchange][edge]") {
    std::vector<int> arr = { 100 };

    exchangeSort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 100);
}

TEST_CASE("Сортировка обменом - два элемента отсортированны", "[exchange][edge]") {
    std::vector<int> arr = { 1, 2 };

    exchangeSort(arr);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
}

TEST_CASE("Сортировка обменом - два элемента не отсортированны", "[exchange][edge]") {
    std::vector<int> arr = { 2, 1 };

    exchangeSort(arr);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
}

TEST_CASE("Сортировка обменом - три элемента", "[exchange][edge]") {
    std::vector<int> arr = { 3, 1, 2 };
    std::vector<int> expected = { 1, 2, 3 };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка обменом - одинаковые элементы", "[exchange][edge]") {
    std::vector<int> arr = { 5, 5, 5, 5 };

    exchangeSort(arr);
    REQUIRE(std::all_of(arr.begin(), arr.end(), [](int x) { return x == 5; }));
}

TEST_CASE("Сортировка обменом - отрицательные числа", "[exchange][edge]") {
    std::vector<int> arr = { -1, -3, -2, -5 };
    std::vector<int> expected = { -5, -3, -2, -1 };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка обменом - отрицательные и положительные числа", "[exchange][edge]") {
    std::vector<int> arr = { 0, -1, 1, -2, 2 };
    std::vector<int> expected = { -2, -1, 0, 1, 2 };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Сортировка обменом - double", "[exchange][types][double]") {
    std::vector<double> arr = { 3.14, 1.41, 2.71, 0.57 };
    std::vector<double> expected = { 0.57, 1.41, 2.71, 3.14 };

    exchangeSort(arr);

    for (size_t i = 0; i < arr.size(); i++) {
        REQUIRE(arr[i] == Approx(expected[i]));
    }
}

TEST_CASE("Сортировка обменом - char", "[exchange][types]") {
    std::vector<char> arr = { 'd', 'a', 'c', 'b' };
    std::vector<char> expected = { 'a', 'b', 'c', 'd' };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}