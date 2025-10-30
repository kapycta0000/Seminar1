#include "../catch2/catch.hpp"
#include "OptimizedBubbleSort.cpp"
#include <vector>
#include <algorithm>

TEST_CASE("Улучшенный пузырёк - базовый функционал", "[optimized_bubble][sorting]") {
    std::vector<int> arr = { 5, 2, 8, 1, 9 };
    std::vector<int> expected = { 1, 2, 5, 8, 9 };

    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Улучшенный пузырёк - пустый массив", "[optimized_bubble][edge]") {
    std::vector<int> arr = {};

    optimizedBubbleSort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Улучшенный пузырёк - один элемент", "[optimized_bubble][edge]") {
    std::vector<int> arr = { 42 };

    optimizedBubbleSort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 42);
}

TEST_CASE("Улучшенный пузырёк - отсортирован", "[optimized_bubble][edge]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };

    optimizedBubbleSort(arr);

    for (size_t i = 1; i < arr.size(); i++) {
        REQUIRE(arr[i] >= arr[i - 1]);
    }
}

TEST_CASE("Улучшенный пузырёк - обратно отсортирован", "[optimized_bubble][edge]") {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Улучшенный пузырёк - нужна одна перестановка", "[optimized_bubble][edge]") {
    std::vector<int> arr = { 1, 2, 3, 5, 4 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Улучшенный пузырёк - одинаковые элементы", "[optimized_bubble][edge]") {
    std::vector<int> arr = { 6, 6, 6, 6 };

    optimizedBubbleSort(arr);
    REQUIRE(std::all_of(arr.begin(), arr.end(), [](int x) { return x == 6; }));
}

TEST_CASE("Улучшенный пузырёк - отрицательные элементы", "[optimized_bubble][edge]") {
    std::vector<int> arr = { -3, -1, -2, -5 };
    std::vector<int> expected = { -5, -3, -2, -1 };

    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Улучшенный пузырёк - проверка на ранне завершение работы(из-за улучшенного пузырька)", "[optimized_bubble][optimization]") {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };

    optimizedBubbleSort(arr);
    REQUIRE(std::is_sorted(arr.begin(), arr.end()));
}

TEST_CASE("Улучшенный пузырёк - char", "[optimized_bubble][types]") {
    std::vector<char> arr = { 'z', 'a', 'c', 'b' };
    std::vector<char> expected = { 'a', 'b', 'c', 'z' };

    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Улучшенный пузырёк - string", "[optimized_bubble][types]") {
    std::vector<std::string> arr = { "banana", "apple", "cherry", "date" };
    std::vector<std::string> expected = { "apple", "banana", "cherry", "date" };

    optimizedBubbleSort(arr);
    REQUIRE(arr == expected);
}