#include <iostream>
#include "algorithms/quicksort.h"
#include <ctime>
#include <fstream>
#include "algorithms/testName.h" //dodatkowy plik. Zwraca nazwy dla poszczególnych klas, aby ułatwić tworzenie plików
#include <algorithm>
#include "algorithms/quicksort2.h"
#include "algorithms/shellsort.h"

template <typename testClass>
void testAndSave( std::vector<int>  sizeVec, float per) {
    testClass test;
    std::string name = testName<testClass>();
    int ilT=100;
    std::ofstream testCzas("wyniki/dobre/"+name+"_"+std::to_string(per)+"_procent.csv");
    for(auto size :sizeVec) {
        long avgCzas = 0;
        for (int i = 0; i < ilT; i++) {
            std::vector<int> tablica;
            for (int j = 0; j < size; j++) {
                tablica.push_back(rand());
            }
            std::sort(tablica.begin(), tablica.begin() + tablica.size() * per / 100);
            //std::sort(tablica.rbegin(),tablica.rend());
            long czas = clock();
            test.sort(tablica.begin(), tablica.end());
            czas = clock() - czas;
            avgCzas += czas;
        }
        avgCzas =avgCzas/100;
        avgCzas = avgCzas * 1000 / (CLOCKS_PER_SEC);
        testCzas << avgCzas << ", " << size << std::endl;
    }
    testCzas.close();
}



int main(int argc, char* argv[])
{
    std::vector<float> percentList = {0,25,50,75,95,99,99.7};
    std::vector<int> sizeList = {10000, 50000, 100000, 500000, 1000000};
    srand(time(NULL));
    std::vector<int> testvec;


        for (auto perVal: percentList) {
            testAndSave<QuickSort2<int>>(sizeList, perVal); 
            testAndSave<MergeSort<int>>(sizeList, perVal);
            testAndSave<QuickSort<int>>(sizeList, perVal);
            testAndSave<ShellSort<int>>(sizeList, perVal);
        }
    
    for(int i=0;i<10;i++) {
        testvec.push_back(rand());
    }
    for(auto val : testvec) {
        std::cout<<val << " ";

    }
    QuickSort2<int> quick2; //algorytm do graficznego testu
    quick2.sort(testvec.begin(),testvec.end());
    for(auto val : testvec) {
        std::cout<<val << " ";

    }




    return 0;
}
