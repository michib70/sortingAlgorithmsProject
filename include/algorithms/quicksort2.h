//
// Created by Lenovo on 04.04.2025.
//

#ifndef SORTING_ALGORITHMS_QUICKSORT2_H
#define SORTING_ALGORITHMS_QUICKSORT2_H
#include <iostream>
#include <vector>
template <typename T>
class QuickSort2
{

public:
void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
{
    if (std::distance(start, end) <= 1) return;
    quickSortStep(start, end - 1); // przekazujemy iteratory na początek i przedostatni element
}

private:
void quickSortStep(typename std::vector<T>::iterator left, typename std::vector<T>::iterator right)
{
    if (left >= right) return; //jeśli iterator początkowy = ostatni adres to kończymy

   // auto pivot = *right; klasyczny quicksort
    auto pivot = *(left+ rand()%std::distance(left, right)); //losowy pivot aby zapobiec rev
    auto it1 = left;
    auto it2 = right - 1;

    while (it1 <= it2) {
        while (it1 <= it2 && *it1 < pivot) ++it1; //przesuwamy it1 dopoki mniejszy niz pivot
        while (it1 <= it2 && *it2 >= pivot) --it2; // na odwrot z it2
        if (it1 < it2) std::iter_swap(it1, it2);
    }

    std::iter_swap(it1, right); // umieszczamy pivot na swojej pozycji

    quickSortStep(left, it1 - 1);  // sortujemy el mniejsze
    quickSortStep(it1 + 1, right); // sottujemy el wieksze
}
};







#endif //SORTING_ALGORITHMS_QUICKSORT2_H
