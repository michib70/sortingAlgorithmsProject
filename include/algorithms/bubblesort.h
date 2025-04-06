#ifndef SORTING_ALGORITHMS_BUBBLESORT_H
#define SORTING_ALGORITHMS_BUBBLESORT_H
#include <vector>

// sortowanie bąbelkowe

template <typename T>
class BubbleSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        auto size = std::distance(start, end);
        if(size <= 1) return;
            auto mid = start + size/2;
            std::vector<T> w1(start, mid);
            std::vector<T> w2(mid, end);
            sort(w1.begin(),w1.end());
            sort(w2.begin(),w2.end());
            merge(w1,w2,start);
    }
private:
    void merge(const std::vector<T>& w1, const std::vector<T>& w2, typename std::vector<T>::iterator i) {
        auto it1 =w1.begin();
        auto it2 =w2.begin();
        while(it1 != w1.end() && it2 != w2.end()) {
            if (*it1 < *it2)
                *i++ = *it1++;
            else
                *i++ = *it2++;
        }
        while (it1 != w1.end())
            *i++ = *it1++;
        while (it2 != w2.end())
            *i++ = *it2++;
    }
};



#endif //SORTING_ALGORITHMS_BUBBLESORT_H
