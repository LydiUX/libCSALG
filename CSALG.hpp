//
//  CSALG.hpp
//  CSALG
//
//  Created by Jack Shi on 2023-09-11.
//
//  link with g++ example.cpp -lCSALG

#ifndef CSALG_
#define CSALG_

/* The classes below are exported */
#pragma GCC visibility push(default)

typedef long double ld;

namespace CSALG{
    class SortingAlgorithm{
        public:
            static void BubbleSort(int arr[], int n);
            static void BucketSort(float arr[], int n);
            static void CountingSort(int arr[], int n);
            static void GnomeSort(int arr[], int n);
            static void HeapSort(int arr[], int n);
            static void InsertionSort(int arr[], int n);
            static void MergeSort(int arr[], int min, int max);
            static void PigeonHoleSort(int arr[], int n);
            static void QuickSort(int arr[], int min, int max);
            static void SelectionSort(int arr[], int n);
    };
    class Analysis{
        public:
            static ld RungeKutta1(ld (*f)(ld, ld), ld initx, ld inity, ld evaluatedx, int steps);
            static ld RungeKutta2(ld (*f)(ld, ld), ld initx, ld inity, ld evaluatedx, int steps);
            static ld RungeKutta3(ld (*f)(ld, ld), ld initx, ld inity, ld evaluatedx, int steps);
            static ld RungeKutta4(ld (*f)(ld, ld), ld initx, ld inity, ld evaluatedx, int steps);
            static ld NumericIntegrate(ld (*f)(ld, ld), ld xi, ld xf, int steps, int method);
            static ld Newton(ld (*f)(ld), ld guess, int steps);
            static ld NumericDifferentiate(ld (*f)(ld), ld evalpoint, ld steps);
    };
    class MathAlgorithm{
        public:
            static int EulerPhi(int n);
            static int GCD(int a, int b);
            static int LCM(int a, int b);
    };
    class SearchAlgorithm{
        public:
            static void BreathFirst(int arr[], int n);
            static void DepthFirst(int arr[], int n);
    };
}

#pragma GCC visibility pop
#endif
