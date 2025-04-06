#ifndef SORTING_ALGORITHMS_TESTNAME_H
#define SORTING_ALGORITHMS_TESTNAME_H

#include <string>
#include "algorithms/QuickSort.h"
#include "algorithms/MergeSort.h"
#include "algorithms/IntroSort.h"
#include "algorithms/quicksort2.h"
#include "algorithms/shellsort.h"
template <typename T>
std::string testName();

template <>
std::string testName<QuickSort<int>>() {
return "QuickSort";
}

template <>
std::string testName<QuickSort2<int>>() {
    return "QuickSort2";
}

template <>
std::string testName<MergeSort<int>>() {
return "MergeSort";
}

template <>
std::string testName<IntroSort<int>>() {
    return "IntroSort";
}

template <>
std::string testName<ShellSort<int>>() {
    return "ShellSort";
}


#endif //SORTING_ALGORITHMS_TESTNAME_H
