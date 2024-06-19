#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include <vector>

// quicksort

template <typename T>
class QuickSort
{
public:

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        if (start >= end - 1)
            return;

        auto pivot = start + (end - start) / 2;
        auto pivotValue = *pivot;

        typename std::vector<T>::iterator left = start;
        typename std::vector<T>::iterator right = end - 1;

        while (left <= right) {
            while (left <= right && *left < pivotValue) {
                left++;
            }
            while (left <= right && *right > pivotValue) {
                right--;
            }
            if (left <= right) {
                auto temp = *left;
                *left = *right;
                *right = temp;
                left++;
                if (right != start) {
                    right--;
                }
            }
        }

        sort(start, right + 1);
        sort(left, end);
    }


};
#endif //SORTING_ALGORITHMS_QUICKSORT_H