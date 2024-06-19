#ifndef SORTING_ALGORITHMS_SHELLSORT_H
#define SORTING_ALGORITHMS_SHELLSORT_H
#include <vector>

// sortowanie Shella

template <typename T>
class ShellSort
{
public:

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        auto n = std::distance(start, end);

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (typename std::vector<T>::iterator i = start + gap; i != end; ++i) {
                auto temp = *i;
                typename std::vector<T>::iterator j;

                for (j = i; j - start >= gap && *(j - gap) > temp; j -= gap) {
                    *j = *(j - gap);
                }
                *j = temp;
            }
        }
    }


};
#endif //SORTING_ALGORITHMS_SHELLSORT_H