#ifndef SORTING_ALGORITHMS_SHELLSORT_H
#define SORTING_ALGORITHMS_SHELLSORT_H
#include <vector>

// sortowanie Shella

template <typename T>
class ShellSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        int size = std::distance(start, end);
        for (int gap = size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; ++i) { //ustawiamy i na gap
                T temp = *(start + i); //zapisujemy tymczasowo wartość z miejsca iteratora
                int j = i;
                while (j >= gap && *(start + j - gap) > temp) { //dopoki j>gap i temp mniejsze niz wartośc z pozycji j-gap
                    *(start + j) = *(start + j - gap); // zastepujemy j wartoscia z j-gap
                    j -= gap; //cofam j gap do tyłu
                }
                *(start + j) = temp; //gdy wartości zostały przesunięte wstawiamy temp w miejscu j
            }
        }
    }
};
#endif //SORTING_ALGORITHMS_SHELLSORT_H
