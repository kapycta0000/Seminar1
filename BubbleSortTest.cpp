#include "../catch2/catch.hpp"
#include "BubbleSort.cpp"
#include <vector>
#include <string>
#include <algorithm>

TEST_CASE("���������� ��������� - ������� ����������", "[bubble][sorting]") {
    std::vector<int> arr = { 5, 2, 8, 1, 9 };
    std::vector<int> expected = { 1, 2, 5, 8, 9 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - ������ ������", "[bubble][edge]") {
    std::vector<int> arr = {};

    bubbleSort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("���������� ��������� - ���� �������", "[bubble][edge]") {
    std::vector<int> arr = { 42 };

    bubbleSort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 42);
}

TEST_CASE("���������� ��������� - ��� �������� ��������������", "[bubble][edge]") {
    std::vector<int> arr = { 1, 2 };
    std::vector<int> expected = { 1, 2 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - ��� �������� �� ��������������", "[bubble][edge]") {
    std::vector<int> arr = { 2, 1 };
    std::vector<int> expected = { 1, 2 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - ��� ������������", "[bubble][edge]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - ������� ������������", "[bubble][edge]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - ���������� ��������", "[bubble][edge]") {
    std::vector<int> arr = { 7, 7, 7, 7, 7 };
    std::vector<int> expected = { 7, 7, 7, 7, 7 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - � ������", "[bubble][edge]") {
    std::vector<int> arr = { 0, 5, 0, 2, 0 };
    std::vector<int> expected = { 0, 0, 0, 2, 5 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - ������������� �����", "[bubble][edge]") {
    std::vector<int> arr = { -3, -1, -2, -5, -4 };
    std::vector<int> expected = { -5, -4, -3, -2, -1 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - ������������� � ������������� �����", "[bubble][edge]") {
    std::vector<int> arr = { -3, 5, -1, 0, 2, -4 };
    std::vector<int> expected = { -4, -3, -1, 0, 2, 5 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - ������� �����", "[bubble][edge]") {
    std::vector<int> arr = { 1000000, 999999, 1000001 };
    std::vector<int> expected = { 999999, 1000000, 1000001 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - ���������", "[bubble][edge]") {
    std::vector<int> arr = { 3, 1, 2, 3, 1, 2 };
    std::vector<int> expected = { 1, 1, 2, 2, 3, 3 };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - char", "[bubble][types]") {
    std::vector<char> arr = { 'z', 'a', 'c', 'b' };
    std::vector<char> expected = { 'a', 'b', 'c', 'z' };

    bubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("���������� ��������� - double", "[bubble][types]") {
    std::vector<double> arr = { 3.14, 1.41, 2.71, 0.57 };
    std::vector<double> expected = { 0.57, 1.41, 2.71, 3.14 };

    bubbleSort(arr);

    for (size_t i = 0; i < arr.size(); i++) {
        REQUIRE(arr[i] == Approx(expected[i]));
    }
}