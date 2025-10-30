#include "../catch2/catch.hpp"
#include "ExchangeSort.cpp"
#include <vector>
#include <algorithm>

TEST_CASE("���������� ������� - ������� ����������", "[exchange][sorting]") {
    std::vector<int> arr = { 5, 2, 8, 1, 9 };
    std::vector<int> expected = { 1, 2, 5, 8, 9 };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ������� - ������ ������", "[exchange][edge]") {
    std::vector<int> arr = {};

    exchangeSort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("���������� ������� - ���� �������", "[exchange][edge]") {
    std::vector<int> arr = { 100 };

    exchangeSort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 100);
}

TEST_CASE("���������� ������� - ��� �������� ��������������", "[exchange][edge]") {
    std::vector<int> arr = { 1, 2 };

    exchangeSort(arr);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
}

TEST_CASE("���������� ������� - ��� �������� �� ��������������", "[exchange][edge]") {
    std::vector<int> arr = { 2, 1 };

    exchangeSort(arr);
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
}

TEST_CASE("���������� ������� - ��� ��������", "[exchange][edge]") {
    std::vector<int> arr = { 3, 1, 2 };
    std::vector<int> expected = { 1, 2, 3 };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ������� - ���������� ��������", "[exchange][edge]") {
    std::vector<int> arr = { 5, 5, 5, 5 };

    exchangeSort(arr);
    REQUIRE(std::all_of(arr.begin(), arr.end(), [](int x) { return x == 5; }));
}

TEST_CASE("���������� ������� - ������������� �����", "[exchange][edge]") {
    std::vector<int> arr = { -1, -3, -2, -5 };
    std::vector<int> expected = { -5, -3, -2, -1 };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ������� - ������������� � ������������� �����", "[exchange][edge]") {
    std::vector<int> arr = { 0, -1, 1, -2, 2 };
    std::vector<int> expected = { -2, -1, 0, 1, 2 };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ������� - double", "[exchange][types][double]") {
    std::vector<double> arr = { 3.14, 1.41, 2.71, 0.57 };
    std::vector<double> expected = { 0.57, 1.41, 2.71, 3.14 };

    exchangeSort(arr);

    for (size_t i = 0; i < arr.size(); i++) {
        REQUIRE(arr[i] == Approx(expected[i]));
    }
}

TEST_CASE("���������� ������� - char", "[exchange][types]") {
    std::vector<char> arr = { 'd', 'a', 'c', 'b' };
    std::vector<char> expected = { 'a', 'b', 'c', 'd' };

    exchangeSort(arr);
    REQUIRE(arr == expected);
}