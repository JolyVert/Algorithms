#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"


#include "algorithms/mergesort.h"
#include "algorithms/shellsort.h"
#include "algorithms/quicksort.h"

int n = 1000000;

TEST_CASE("MergeSort")
{
    MergeSort<int> mergesort;
    std::vector<int> values(n);
    auto data = []() -> int { return rand() % n; };
    generate(values.begin(), values.end(), data);
    std::vector<int> valuesSorted = values;
    std::sort(valuesSorted.begin(), valuesSorted.end());

    mergesort.sort(values.begin(), values.end());
    REQUIRE(valuesSorted == values);
}

TEST_CASE("ShellSort")
{
    ShellSort<int> shellsort;
    std::vector<int> values(n);
    auto data = []() -> int { return rand() % n; };
    generate(values.begin(), values.end(), data);
    std::vector<int> valuesSorted = values;
    std::sort(valuesSorted.begin(), valuesSorted.end());

    shellsort.sort(values.begin(), values.end());
    REQUIRE(valuesSorted == values);
}

TEST_CASE("QuickSort")
{
    QuickSort<int> quicksort;
    std::vector<int> values(n);
    auto data = []() -> int { return rand() % n; };
    generate(values.begin(), values.end(), data);
    std::vector<int> valuesSorted = values;
    std::sort(valuesSorted.begin(), valuesSorted.end());

    quicksort.sort(values.begin(), values.end());
    REQUIRE(valuesSorted == values);
}