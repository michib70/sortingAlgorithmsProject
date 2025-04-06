#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include <vector>
#include <random>
// quicksort

template <typename T>
class QuickSort {
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        auto size = std::distance(start, end);
        if (size <= 1) return;
        //auto pivot = *(end - 1); klasyczny quickosrt
        auto pivot = *(start+rand()% size); //random aby zapobiec worstr case
        std::vector<T> w1;
        std::vector<T> w2;
        std::vector<T> wPiv; //3 wektora na elementy < od pivota = i >
        for (auto i = start; i != end; i++) {
            if (*i > pivot) { //porównujemy elementy z końca wektora do pivota i dzielimy zakres
                w2.push_back(*i);

            } else if (*i < pivot) {
                w1.push_back(*i);
            } else {
                wPiv.push_back(*i);
            }
        }
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        auto it1 = w1.begin();
        auto it2 = w2.begin();
        auto itP = wPiv.begin();//podobnie do merge sort scalamy poprzednie wektory, teraz bez sprawdzania warunków.
        auto i = start;
        while (it1 != w1.end()) {
            *i++ = *it1++;
        }
        while (itP != wPiv.end()) {
            *i++ = *itP++;
        }
        while (it2 != w2.end()) {
            *i++ = *it2++;
        }
    }
};



#endif //SORTING_ALGORITHMS_QUICKSORT_H