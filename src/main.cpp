#include <iostream>
#include "algorithms/bubblesort.h"
#include "algorithms/quicksort.h"
#include <ctime>
#include <fstream>
#include "algorithms/testName.h"
#include <algorithm>
#include "algorithms/quicksort2.h"
#include "algorithms/shellsort.h"
template <typename testClass>
void testAndSave(int size) {
    testClass test;
    std::string name = testName<testClass>();
    int ilT=100;
    std::ofstream testCzas("wyniki/dobre/bezproc/"+name+"_"+std::to_string(size)+"_elementow.txt");
    long avgCzas = 0;
    for(int i=0;i<ilT;i++) {
        std::vector<int> tablica;
        for (int j=0;j<size;j++) {
            tablica.push_back(rand());
        }
        long czas=clock();
        test.sort(tablica.begin(),tablica.end());
        czas = clock()-czas;
        //testCzas << czas <<std::endl;
        avgCzas += czas;
    }
    avgCzas = avgCzas*1000/(CLOCKS_PER_SEC*100);
    testCzas<<avgCzas<<std::endl;
    testCzas.close();
}
template <typename testClass>
void testAndSave( std::vector<int>  sizeVec, float per) {
    testClass test;
    std::string name = testName<testClass>();
    int ilT=100;
    std::ofstream testCzas("wyniki/dobre/"+name+"reverse.csv");
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
template <typename testClass>
void testAndSaveRev(int size) {
    testClass test;
    std::string name = testName<testClass>();
    int ilT=100;
    std::ofstream testCzas("wyniki/dobre/"+name+".txt");
    long avgCzas = 0;
    for(int i=0;i<ilT;i++) {
        std::vector<int> tablica;
        for (int j=0;j<size;j++) {
            tablica.push_back(rand());
        }
        std::sort(tablica.rbegin(),tablica.rend());
        long czas=clock();
        test.sort(tablica.begin(),tablica.end());
        czas = clock()-czas;
        //testCzas << czas <<std::endl;
        avgCzas += czas;
    }
    avgCzas = avgCzas*1000/(CLOCKS_PER_SEC*100);
    testCzas<<avgCzas<<std::endl;
    testCzas.close();
}


int main(int argc, char* argv[])
{
    std::vector<float> percentList = {0,25,50,75,95,99,99.7};
    std::vector<int> sizeList = {10000, 50000, 100000, 500000, 1000000};
    srand(time(NULL));
    std::vector<int> testvec;
    for(int i=0;i<10;i++) {
        testvec.push_back(rand());
    }
    for(auto val : testvec) {
        std::cout<<val << " ";

    }
    QuickSort2<int> quick2;
    quick2.sort(testvec.begin(),testvec.end());
       // for (auto perVal: percentList) {
            testAndSave<QuickSort2<int>>(sizeList, 0); //stack overflow przy reversie

            testAndSave<MergeSort<int>>(sizeList, 0);
           testAndSave<QuickSort<int>>(sizeList, 0);//overflow przy 10000 rev
            testAndSave<ShellSort<int>>(sizeList, 0);
       // }

    for(auto val : testvec) {
        std::cout<<val << " ";

    }




    return 0;
}
