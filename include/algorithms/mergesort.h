#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>

// sortowanie przez scalanie

template <typename T>
class MergeSort
{
public:
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        auto size = std::distance(start, end); //wielkosc wektora
        if(size <= 1) return;
        auto mid = start + size/2; //wybieramy srodek na ktorym wystepuje podział
        std::vector<T> w1(start, mid);
        std::vector<T> w2(mid, end); //dzielimy na 2 wektory
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        merge(w1,w2,start);
    }
private:
    void merge(const std::vector<T>& w1, const std::vector<T>& w2, typename std::vector<T>::iterator i) {
        auto it1 =w1.begin();
        auto it2 =w2.begin();
        while(it1 != w1.end() && it2 != w2.end()) { //póki w wektorach są elemnty porównujemy wartości.
            if (*it1 < *it2) //jeśli wartość iteratora 2 jest większa to dodajemy it1 do glownego wektora i przesuwamy wskaźniki
                *i++ = *it1++;
            else
                *i++ = *it2++;
        }
        while (it1 != w1.end()) //jeśli w 1 z wektorów są elemnty do dodajemy wszystkie(już posortowane)
            *i++ = *it1++;
        while (it2 != w2.end())
            *i++ = *it2++;
    }
};

#endif //SORTING_ALGORITHMS_MERGESORT_H
