#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>

// sortowanie przez scalanie

template <typename T>
class MergeSort
{
public:

    void merge(typename std::vector<T>::iterator start, typename std::vector<T>::iterator mid, typename std::vector<T>::iterator end) {
        typename std::vector<T> left(start, mid);
        typename std::vector<T> right(mid, end);

        auto leftIter = left.begin();
        auto rightIter = right.begin();
        auto mergeIter = start;

        while (leftIter != left.end() && rightIter != right.end()) {
            if (*leftIter <= *rightIter) {
                *mergeIter++ = *leftIter++;
            }
            else {
                *mergeIter++ = *rightIter++;
            }
        }

        while (leftIter != left.end()) {
            *mergeIter++ = *leftIter++;
        }
        while (rightIter != right.end()) {
            *mergeIter++ = *rightIter++;
        }
    }

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        if (std::distance(start, end) > 1) {
            typename std::vector<T>::iterator mid = start + std::distance(start, end) / 2;
            sort(start, mid);
            sort(mid, end);
            merge(start, mid, end);
        }
    }
};
#endif //SORTING_ALGORITHMS_MERGESORT_H