//
//  CSALG.cpp
//  CSALG
//
//  Created by Jack Shi on 2023-09-11.
//

#include <iostream>
#include "CSALG.hpp"
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stdexcept>

typedef long double ld;

namespace CSALG{
    void SortingAlgorithm::BubbleSort(int arr[], int n){
        int sorted;
        for (int i = 0; i < n; i++){
            sorted = 1;
            for (int j = 0; j < n - i; j++){
                if (arr[j] > arr[j + 1]){
                    std::swap(arr[j + 1], arr[j]);
                    sorted = 0;
                }
            }
            if (sorted){
                break;
            }
        }
    }
    void SortingAlgorithm::BucketSort(float arr[], int n){
        std::vector<float> bucket[n + 1];
        for (int i = 0; i <= n; i++){
            bucket[int(arr[i] * n)].push_back(arr[i]);
        }
        for (int i = 0; i < n; i++){
            std::sort(bucket[i].begin(), bucket[i].end());
        }
        int index = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < bucket[i].size(); j++){
                arr[index++] = bucket[i][j];
            }
        }
    }
    void SortingAlgorithm::CountingSort(int arr[], int n){
        int max = arr[0];
        for (int i = 0; i <= n; i++){
            if (arr[i] > max){
                max = arr[i];
            }
        }
        int aux[max + 1], ret[n];
        std::memset(aux, 0, sizeof(aux));
        for (int i = 0; i <= n; i++){
            aux[arr[i]]++;
        }
        for (int i = 0; i <= max; i++){
            aux[i] += aux[i - 1];
        }
        for (int i = 0; i <= n; i++){
            ret[aux[arr[i]] - 1] = arr[i];
            aux[arr[i]]--;
        }
        std::copy(ret, ret + n + 1, arr);
    }
    void SortingAlgorithm::GnomeSort(int arr[], int n){
        for(int i = 1; i <= n; ){
            if (i == 0){
                i++;
            }
            if (arr[i] < arr[i - 1]){
                std::swap(arr[i], arr[i - 1]);
                i--;
            }
            else{
                i++;
            }
        }
    }
    void heapify(int arr[], int n, int rootNode){
        int max = rootNode;
        int leftChild = 2 * rootNode + 1;
        int rightChild = 2 * rootNode + 2;
        if (arr[leftChild] > arr[max] && n > leftChild){
            max = leftChild;
        }
        if (arr[rightChild] > arr[max] && n > rightChild){
            max = rightChild;
        }
        if (rootNode != max){
            std::swap(arr[max], arr[rootNode]);
            heapify(arr, n, max);
        }
    }
    void SortingAlgorithm::HeapSort(int arr[], int n){
        for (int i = n / 2; i >= 0; i--){
            heapify(arr, n, i);
        }
        for (int i = n; i >= 0; i--){
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
    void SortingAlgorithm::InsertionSort(int arr[], int n){
        for (int i = 1; i <= n; i++){
            int data = arr[i];
            int index = i;
            while (index > 0 && arr[index - 1] > data){
                arr[index] = arr[index - 1];
                index--;
            }
            arr[index] = data;
        }
    }
    void merge(int arr[], int left, int middle, int right){
        int lenL = middle - left + 1;
        int lenR = right - middle;
        int arr1[lenL], arr2[lenR];
        for (int i = 0; i < lenL; i++){
            arr1[i] = arr[left + i];
        }
        for (int i = 0; i < lenR; i++){
            arr2[i] = arr[middle + i + 1];
        }
        int lIndex = 0, rIndex = 0, arrIndex = left;
        while (lIndex < lenL && rIndex < lenR){
            if (arr1[lIndex] <= arr2[rIndex]){
                arr[arrIndex] = arr1[lIndex];
                lIndex++;
            }
            else{
                arr[arrIndex] = arr2[rIndex];
                rIndex++;
            }
            arrIndex++;
        }
        while (lIndex < lenL || rIndex < lenR){
            if (lIndex < lenL && (rIndex >= lenR || arr1[lIndex] <= arr2[rIndex])){
                arr[arrIndex] = arr1[lIndex];
                lIndex++;
            }
            else{
                arr[arrIndex] = arr2[rIndex];
                rIndex++;
            }
            arrIndex++;
        }
    }
    void SortingAlgorithm::MergeSort(int arr[], int min, int max){
        if (max > min){
            int middle = (max - min) / 2 + min;
            SortingAlgorithm::MergeSort(arr, min, middle);
            SortingAlgorithm::MergeSort(arr, middle + 1, max);
            merge(arr, min, middle, max);
        }
    }
    void SortingAlgorithm::PigeonHoleSort(int arr[], int n){
        int min = arr[0];
        int max = arr[0];
        for (int i = 0; i <= n; i++){
            if (arr[i] > max){
                max = arr[i];
            }
            if (arr[i] < min){
                min = arr[i];
            }
        }
        std::vector<int> hole[max - min + 1];
        for (int i = 0; i <= n; i++){
            hole[arr[i] - min].push_back(arr[i]);
        }
        int index = 0;
        for (int i = 0; i <= max - min; i++){
            for (int j = 0; j < hole[i].size(); j++){
                arr[index++] = hole[i][j];
            }
        }
    }
    int partition(int arr[], int min, int max){
        std::swap(arr[rand() % (max - min + 1) + min], arr[max]);
        int pivot = arr[max];
        int pointer = min;
        for (int j = min; j < max; j++){
            if (arr[j] <= pivot){
                std::swap(arr[j], arr[pointer]);
                pointer++;
            }
        }
        std::swap(arr[pointer], arr[max]);
        return pointer;
    }
    void insertionSortQuickSort(int arr[], int min, int max){
        for (int i = min + 1; i <= max; i++){
            int data = arr[i];
            int index = i;
            while (index > min && arr[index - 1] > data){
                arr[index] = arr[index - 1];
                index--;
            }
            arr[index] = data;
        }
    }
    void SortingAlgorithm::QuickSort(int arr[], int min, int max){
        while (max > min){
            if (8 >= max - min){
                insertionSortQuickSort(arr, min, max);
                break;
            }
            int pivot = partition(arr, min, max);
            if (max - pivot > pivot - min){
                SortingAlgorithm::QuickSort(arr, min, pivot - 1);
                min = pivot + 1;
            }
            else{
                SortingAlgorithm::QuickSort(arr, pivot + 1, max);
                max = pivot - 1;
            }
        }
    }
    void SortingAlgorithm::SelectionSort(int arr[], int n){
        for (int i = 0; i <= n; i++){
            int min = i;
            for (int j = i + 1; j <= n; j++){
                if (arr[min] > arr[j]){
                    min = j;
                }
            }
            std::swap(arr[min], arr[i]);
        }
    }
    ld Analysis::RungeKutta1(ld (*f)(ld, ld), ld initx, ld inity, ld evaluatedx, int steps){
        ld h = (evaluatedx - initx) / steps;
        ld evaluatedy = 0;
        for (int i = 0; i < steps; i++){
            ld evaluatedy = inity + h * (*f)(initx, inity);
            inity = evaluatedy;
            initx += h;
        }
        return evaluatedy;
    }
    ld Analysis::RungeKutta2(ld (*f)(ld, ld), ld initx, ld inity, ld evaluatedx, int steps){
        ld h = (evaluatedx - initx) / steps;
        ld evaluatedy = 0;
        for (int i = 0; i < steps; i++){
            ld k1 = (*f)(initx, inity);
            ld k2 = (*f)(initx + h, inity + h * k1);
            evaluatedy = inity + (h / 2.0) * (k1 + k2);
            inity = evaluatedy;
            initx += h;
        }
        return evaluatedy;
    }
    ld Analysis::RungeKutta3(ld (*f)(ld, ld), ld initx, ld inity, ld evaluatedx, int steps){
        ld h = (evaluatedx - initx) / steps;
        ld evaluatedy = 0;
        for (int i = 0; i < steps; i++){
            ld k1 = (*f)(initx, inity);
            ld k2 = (*f)(initx + 0.5 * h, inity + 0.5 * k1 * h);
            ld k3 = (*f)(initx + h, inity - h * k1 + 2.0 * h * k2);
            evaluatedy = inity + (h / 6.0) * (k1 + 4.0 * k2 + k3);
            inity = evaluatedy;
            initx += h;
        }
        return evaluatedy;
    }
    ld Analysis::RungeKutta4(ld (*f)(ld, ld), ld initx, ld inity, ld evaluatedx, int steps){
        ld h = (evaluatedx - initx) / steps;
        ld evaluatedy = 0;
        for (int64_t i = 0; i < steps; i++){
            ld k1 = h * (*f)(initx, inity);
            ld k2 = h * (*f)(initx + 0.5 * h, inity + 0.5 * k1);
            ld k3 = h * (*f)(initx + 0.5 * h, inity + 0.5 * k2);
            ld k4 = h * (*f)(initx + h, inity + k3);
            evaluatedy = inity + (1 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
            inity = evaluatedy;
            initx += h;
        }
        return evaluatedy;
    }
    ld Analysis::NumericIntegrate(ld (*f)(ld, ld), ld xi, ld xf, int steps, int method){
        ld initx = 0.0;
        ld inity = (*f)(initx, 0);
        switch (method){
            case 1:
                return Analysis::RungeKutta1((*f), initx, inity, xf, steps) - Analysis::RungeKutta1((*f), initx, inity, xi, steps);
            case 2:
                return Analysis::RungeKutta2((*f), initx, inity, xf, steps) - Analysis::RungeKutta2((*f), initx, inity, xi, steps);
            case 3:
                return Analysis::RungeKutta3((*f), initx, inity, xf, steps) - Analysis::RungeKutta3((*f), initx, inity, xi, steps);
            default:
                return Analysis::RungeKutta4((*f), initx, inity, xf, steps) - Analysis::RungeKutta4((*f), initx, inity, xi, steps);
        }
    }
    ld Analysis::Newton(ld (*f)(ld), ld guess, int steps){
        for (int i = 0; i < steps; i++){
            ld derivative = 0.5 * (1 / 0.000001) * ((*f)(guess + 0.000001) - (*f)(guess - 0.000001));
            if (std::fabs(derivative) < 0.00000000000001){
                break;
            }
            ld newGuess = guess - (*f)(guess) / derivative;
            if (std::fabs(newGuess - guess) <= 0.00000001){
                return newGuess;
            }
            guess = newGuess;
        }
        throw std::invalid_argument("Failed to converge");
    }
    ld Analysis::NumericDifferentiate(ld (*f)(ld), ld evalpoint, ld steps){
        return 0.5 * (1 / steps) * ((*f)(evalpoint + steps) - (*f)(evalpoint - steps));
    }
    int MathAlgorithm::EulerPhi(int n){
        int res = n;
        for (int i = 2; i * i < n - 1; i++){
            if (n % i == 0){
                while (n % i == 0){
                    n /= i;
                }
                res -= res / i;
            }
        }
        if (n > 1){
            res -= res / n;
        }
        return res;
    }
    int MathAlgorithm::GCD(int a, int b){
        if (b == 0){
            return a;
        }
        return MathAlgorithm::GCD(b, a % b);
    }
    int MathAlgorithm::LCM(int a, int b){
        return std::abs(a * b) / MathAlgorithm::GCD(a, b);
    }
    void MathAlgorithm::RowEchelon(std::vector<std::vector<ld>>& matrix){
        int size = matrix.size();
        ld ratio = 0;
        if (matrix.size() != matrix[0].size()){
            throw std::runtime_error("Matrix must be square\n");
        }
        for (int i = 0; i < size - 1; i++){
            for (int j = size - 1; j > i; j--){
                if (matrix[i][j] == 0){
                    continue;
                }
                else{
                    try{
                        if (matrix[j - i][i] == 0){
                            throw std::runtime_error("Division by Zero\n");
                        }
                        ratio = matrix[j][i] / matrix[j - 1][i];
                    }
                    catch (std::runtime_error& except){
                        for (int k = 0; k < size; k++){
                            std::swap(matrix[j][k], matrix[j - 1][k]);
                        }
                        continue;
                    }
                    for (int l = 0; l < size; l++){
                        matrix[j][l] = matrix[j][l] - ratio * matrix[j - 1][l];
                    }
                }
            }
        }
    }
    ld MathAlgorithm::Determinant(std::vector<std::vector<ld>> matrix){
        int size = matrix.size();
        ld det = 1;
        MathAlgorithm::RowEchelon(matrix);
        for (int i = 0; i < size; i++){
            det *= matrix[i][i];
        }
        return det;
    }
}