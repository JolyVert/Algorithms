#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "algorithms/bubblesort.h"
#include "algorithms/insertsort.h"
#include "algorithms/heapsort.h"
#include "algorithms/mergesort.h"
#include "algorithms/shellsort.h"
#include "algorithms/quicksort.h"
#include "algorithms/introsort.h"

using namespace std::string_literals;

std::vector<int> getTestData()
{


    return { 158, 87, 25, 93, 68, 47, 53, 42, 38, 94, 69, 83, 81, 6, 40, 14, 79, 30, 99, 22, 89, 90, 8, 55, 57, 11, 28, 7, 1, 24, 16, 61, 84, 19, 35, 52, 32, 13, 26, 76, 66, 46, 31, 59, 85, 88, 21, 78, 50, 43, 98, 64, 91, 86, 39, 95, 10, 9, 4, 37, 5, 54, 70, 3, 73, 80, 72, 75, 33, 48, 62, 56, 51, 97, 15, 63, 92, 29, 44, 74, 34, 67, 45, 77, 2, 82, 18, 27, 17, 23, 41, 12, 71, 60, 65, 36, 20, 96, 100, 49
    };
}

//std::vector<int> getTestData()
//{
//    return {2, 45 ,2, 23, 6, 24, 56, 3, 8, 324, 6 ,1 ,0};
//}

std::vector<int> getSortedData()
{
    auto data = getTestData();
    std::sort(data.begin(), data.end());
    return data;
}

//TEST_CASE("BubbleSort")
//{
//    auto data = getTestData();
//    auto resultData = getSortedData();
//
//    BubbleSort<int> bubbleSort;
//    bubbleSort.sort(data.begin(),data.end());
//
//    REQUIRE(data == resultData);
//}

//TEST_CASE("InsertSort")
//{
//    auto data = getTestData();
//    auto resultData = getSortedData();
//
//    InsertSort<int> insertSort;
//    insertSort.sort(data.begin(),data.end());
//
//    REQUIRE(data == resultData);
//}

//TEST_CASE("HeapSort")
//{
//    auto data = getTestData();
//    auto resultData = getSortedData();
//
//    HeapSort<int> heapSort;
//    heapSort.sort(data.begin(),data.end());
//
//    REQUIRE(data == resultData);
//}

TEST_CASE("MergeSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    MergeSort<int> mergeSort;
    mergeSort.sort(data.begin(), data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("ShellSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    ShellSort<int> shellSort;
    shellSort.sort(data.begin(), data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("QuickSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    QuickSort<int> quickSort;
    quickSort.sort(data.begin(), data.end());

    REQUIRE(data == resultData);
}

//TEST_CASE("IntroSort")
//{
//    auto data = getTestData();
//    auto resultData = getSortedData();
//
//    IntroSort<int> introSort;
//    introSort.sort(data.begin(),data.end());
//
//    REQUIRE(data == resultData);
//}