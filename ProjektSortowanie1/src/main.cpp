#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <functional>

#include "algorithms/mergesort.h"
#include "algorithms/shellsort.h"
#include "algorithms/quicksort.h"

using namespace std::chrono;



int n = 50000;

void sortPercentageOfVector(std::vector<int>& vec, double percent) {
    if (percent < 0.0 || percent > 100.0) {
        std::cerr << "Percentage must be between 0 and 100." << std::endl;
        return;
    }
    size_t elementsToSort = static_cast<size_t>(percent / 100.0 * vec.size());

    if (elementsToSort > vec.size()) elementsToSort = vec.size();

    std::sort(vec.begin(), vec.begin() + elementsToSort);
}

std::vector<int> getTestData()
{
    std::vector<int> values;
    for (int i = 0; i < 10; i++) {
        int random_number = rand() % 10;
        values.push_back(random_number);
    }

    return values;
}

std::vector<int> getSortedData()
{
    std::vector<int> data = getTestData();
    std::sort(data.begin(), data.end());
    return data;
}


int main(int argc, char* argv[])
{
    std::cout << "Tu wykonujemy testy efektywnosci algorytmow" << std::endl;


    srand(time(NULL));
    //MergeSort<int> sort;
    //ShellSort<int> sort;
    QuickSort<int> sort;
    long dur0 = 0;
    long dur25 = 0;
    long dur50 = 0;
    long dur75 = 0;
    long dur95 = 0;
    long dur99 = 0;
    long dur997 = 0;
    long durRev = 0;


    for (int i = 0; i < 3; i++) {




        std::vector<int> values(n);
        auto data = []() -> int { return rand() % n; };
        generate(values.begin(), values.end(), data);


        std::vector<int> valuesSorted25(n);
        auto data1 = []() -> int { return rand() % n; };
        generate(valuesSorted25.begin(), valuesSorted25.end(), data1);
        sortPercentageOfVector(valuesSorted25, 25.0);

        std::vector<int> valuesSorted50(n);
        auto data2 = []() -> int { return rand() % n; };
        generate(valuesSorted50.begin(), valuesSorted50.end(), data2);
        sortPercentageOfVector(valuesSorted50, 50.0);

        std::vector<int> valuesSorted75(n);
        auto data3 = []() -> int { return rand() % n; };
        generate(valuesSorted75.begin(), valuesSorted75.end(), data3);
        sortPercentageOfVector(valuesSorted75, 75.0);

        std::vector<int> valuesSorted95(n);
        auto data4 = []() -> int { return rand() % n; };
        generate(valuesSorted95.begin(), valuesSorted95.end(), data4);
        sortPercentageOfVector(valuesSorted95, 95.0);

        std::vector<int> valuesSorted99(n);
        auto data5 = []() -> int { return rand() % n; };
        generate(valuesSorted99.begin(), valuesSorted99.end(), data5);
        sortPercentageOfVector(valuesSorted99, 99.0);

        std::vector<int> valuesSorted997(n);
        auto data6 = []() -> int { return rand() % n; };
        generate(valuesSorted997.begin(), valuesSorted997.end(), data6);
        sortPercentageOfVector(valuesSorted997, 99.7);

        std::vector<int> valuesSortedRev(n);
        auto data7 = []() -> int { return rand() % n; };
        generate(valuesSortedRev.begin(), valuesSortedRev.end(), data7);
        std::sort(valuesSortedRev.begin(), valuesSortedRev.end(), std::greater<int>());

        auto start = high_resolution_clock::now();
        sort.sort(values.begin(), values.end());
        auto stop = high_resolution_clock::now();
        auto duration0 = duration_cast<microseconds>(stop - start);
        dur0 += duration0.count();

        start = high_resolution_clock::now();
        sort.sort(valuesSorted25.begin(), valuesSorted25.end());
        stop = high_resolution_clock::now();
        auto duration25 = duration_cast<microseconds>(stop - start);
        dur25 += duration25.count();

        start = high_resolution_clock::now();
        sort.sort(valuesSorted50.begin(), valuesSorted50.end());
        stop = high_resolution_clock::now();
        auto duration50 = duration_cast<microseconds>(stop - start);
        dur50 += duration50.count();

        start = high_resolution_clock::now();
        sort.sort(valuesSorted75.begin(), valuesSorted75.end());
        stop = high_resolution_clock::now();
        auto duration75 = duration_cast<microseconds>(stop - start);
        dur75 += duration75.count();

        start = high_resolution_clock::now();
        sort.sort(valuesSorted95.begin(), valuesSorted95.end());
        stop = high_resolution_clock::now();
        auto duration95 = duration_cast<microseconds>(stop - start);
        dur95 += duration95.count();

        start = high_resolution_clock::now();
        sort.sort(valuesSorted99.begin(), valuesSorted99.end());
        stop = high_resolution_clock::now();
        auto duration99 = duration_cast<microseconds>(stop - start);
        dur99 += duration99.count();

        start = high_resolution_clock::now();
        sort.sort(valuesSorted997.begin(), valuesSorted997.end());
        stop = high_resolution_clock::now();
        auto duration997 = duration_cast<microseconds>(stop - start);
        dur997 += duration997.count();

        start = high_resolution_clock::now();
        sort.sort(valuesSortedRev.begin(), valuesSortedRev.end());
        stop = high_resolution_clock::now();
        auto durationRev = duration_cast<microseconds>(stop - start);
        durRev += durationRev.count();


        std::cout << "wait.." << std::endl;
    }

    std::cout << "Average time taken by function on unsorted vector: " << dur0 / 3 << " microseconds" << std::endl;
    std::cout << "Average time taken by function on vector sorted by 25%: " << dur25 / 3 << " microseconds" << std::endl;
    std::cout << "Average time taken by function on vector sorted by 50%: " << dur50 / 3 << " microseconds" << std::endl;
    std::cout << "Average time taken by function on vector sorted by 75%: " << dur75 / 3 << " microseconds" << std::endl;
    std::cout << "Average time taken by function on vector sorted by 95%: " << dur95 / 3 << " microseconds" << std::endl;
    std::cout << "Average time taken by function on vector sorted by 99%: " << dur99 / 3 << " microseconds" << std::endl;
    std::cout << "Average time taken by function on vector sorted by 99.7%: " << dur997 / 3 << " microseconds" << std::endl;
    std::cout << "Average time taken by function on reverse sorted vector: " << durRev / 3 << " microseconds" << std::endl;




















    /*std::vector<int> values(n);
    auto data = []() -> int { return rand() % n; };
    generate(values.begin(), values.end(), data);


    for (int num : values) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sort.sort(values.begin(), values.end());

    for (int num : values) {
        std::cout << num << " ";
    }
    std::cout << std::endl;*/









    /*std::vector<int> values(n);
    auto data = []() -> int { return rand() % n; };
    generate(values.begin(), values.end(), data);

    std::vector<int> valuesSorted25(n);
    auto data1 = []() -> int { return rand() % n; };
    generate(valuesSorted25.begin(), valuesSorted25.end(), data1);
    sortPercentageOfVector(valuesSorted25, 25.0);

    std::vector<int> valuesSorted50(n);
    auto data2 = []() -> int { return rand() % n; };
    generate(valuesSorted50.begin(), valuesSorted50.end(), data2);
    sortPercentageOfVector(valuesSorted50, 50.0);

    std::vector<int> valuesSorted75(n);
    auto data3 = []() -> int { return rand() % n; };
    generate(valuesSorted75.begin(), valuesSorted75.end(), data3);
    sortPercentageOfVector(valuesSorted75, 75.0);

    std::vector<int> valuesSorted95(n);
    auto data4 = []() -> int { return rand() % n; };
    generate(valuesSorted95.begin(), valuesSorted95.end(), data4);
    sortPercentageOfVector(valuesSorted95, 95.0);

    std::vector<int> valuesSorted99(n);
    auto data5 = []() -> int { return rand() % n; };
    generate(valuesSorted99.begin(), valuesSorted99.end(), data5);
    sortPercentageOfVector(valuesSorted99, 99.0);

    std::vector<int> valuesSorted997(n);
    auto data6 = []() -> int { return rand() % n; };
    generate(valuesSorted997.begin(), valuesSorted997.end(), data6);
    sortPercentageOfVector(valuesSorted997, 99.7);

    std::vector<int> valuesSortedRev(n);
    auto data7 = []() -> int { return rand() % n; };
    generate(valuesSortedRev.begin(), valuesSortedRev.end(), data7);
    std::sort(valuesSortedRev.begin(), valuesSortedRev.end(), std::greater<int>());*/


    /*for (int num : values) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : valuesSorted25) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : valuesSorted50) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : valuesSorted75) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : valuesSorted95) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : valuesSorted99) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : valuesSorted997) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : valuesSortedRev) {
        std::cout << num << " ";
    }
    std::cout << std::endl;*/















    /*auto start = high_resolution_clock::now();
    shellSort.sort(values.begin(), values.end());
    auto stop = high_resolution_clock::now();
    auto durationShell = duration_cast<microseconds>(stop - start);


    start = high_resolution_clock::now();
    mergeSort.sort(values.begin(), values.end());
    stop = high_resolution_clock::now();
    auto durationMerge = duration_cast<microseconds>(stop - start);


    start = high_resolution_clock::now();
    quickSort.sort(values.begin(), values.end());
    stop = high_resolution_clock::now();
    auto durationQuick = duration_cast<microseconds>(stop - start);



   std::cout << "Time taken by quick function: " << durationQuick.count() << " microseconds" << std::endl;
   std::cout << "Time taken by merge function: " << durationMerge.count() << " microseconds" << std::endl;
   std::cout << "Time taken by shell function: " << durationShell.count() << " microseconds" << std::endl;*/
    return 0;
}