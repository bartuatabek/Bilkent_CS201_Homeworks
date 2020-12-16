//
//  main.cpp
//  CS 201 HW#2
//
//  Created by Bartu Atabek on 11/30/17.
//  21602229 Sec. 03 - Ercüment Çiçek
//

#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include <random>
using namespace std;

int main() {
    
    int arr1[10];
    int arr2[100];
    int arr3[1000];
    int arr4[10000];
    int arr5[100000];
    
    for (int i = 0; i < 10; ++i) {
        arr1[i] = - 100 + rand() % static_cast<int>(100 - 100 + 1);
    }

    for (int i = 0; i < 100; ++i) {
        arr2[i] = - 100 + rand() % static_cast<int>(100 - 100 + 1);
    }

    for (int i = 0; i < 1000; ++i) {
        arr3[i] = - 100 + rand() % static_cast<int>(100 - 100 + 1);
    }

    for (int i = 0; i < 10000; ++i) {
        arr4[i] = - 100 + rand() % static_cast<int>(100 - 100 + 1);
    }
    
    for (int i = 0; i < 100000; ++i) {
        arr5[i] = - 100 + rand() % static_cast<int>(100 - 100 + 1);
    }
    
    cout << "--------------------" << endl;
    cout << "Execution times for the algorithms with input size = 10\n" << endl;
    
    cout << "–– Algorithm 1 ––" << endl;
    double duration;
    clock_t startTime = clock();
    maxSubSum1(vector<int> (arr1, arr1 + sizeof arr1 / sizeof arr1[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 2 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr1, arr1 + sizeof arr1 / sizeof arr1[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 3 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr1, arr1 + sizeof arr1 / sizeof arr1[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 4 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr1, arr1 + sizeof arr1 / sizeof arr1[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "--------------------" << endl;
    cout << "Execution times for the algorithms with input size = 100\n" << endl;
    
    cout << "–– Algorithm 1 ––" << endl;
    startTime = clock();
    maxSubSum1(vector<int> (arr2, arr2 + sizeof arr2 / sizeof arr2[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 2 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr2, arr2 + sizeof arr2 / sizeof arr2[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 3 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr2, arr2 + sizeof arr2 / sizeof arr2[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 4 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr2, arr2 + sizeof arr2 / sizeof arr2[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "--------------------" << endl;
    cout << "Execution times for the algorithms with input size = 1,000\n" << endl;
    
    cout << "–– Algorithm 1 ––" << endl;
    startTime = clock();
    maxSubSum1(vector<int> (arr3, arr3 + sizeof arr3 / sizeof arr3[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 2 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr3, arr3 + sizeof arr3 / sizeof arr3[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 3 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr3, arr3 + sizeof arr3 / sizeof arr3[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 4 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr3, arr3 + sizeof arr3 / sizeof arr3[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "--------------------" << endl;
    cout << "Execution times for the algorithms with input size = 10,000\n" << endl;
    
    cout << "–– Algorithm 1 ––" << endl;
    startTime = clock();
    maxSubSum1(vector<int> (arr4, arr4 + sizeof arr4 / sizeof arr4[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";

    cout << "–– Algorithm 2 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr4, arr4 + sizeof arr4 / sizeof arr4[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 3 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr4, arr4 + sizeof arr4 / sizeof arr4[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 4 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr4, arr4 + sizeof arr4 / sizeof arr4[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "--------------------" << endl;
    cout << "Execution times for the algorithms with input size = 100,000\n" << endl;
    
    cout << "–– Algorithm 1 ––" << endl;
    double duration17;
    clock_t startTime17 = clock();
    maxSubSum1(vector<int> (arr5, arr5 + sizeof arr5 / sizeof arr5[0]));
    duration17 = 1000 * double( clock() - startTime17 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration17 << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 2 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr5, arr5 + sizeof arr5 / sizeof arr5[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 3 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr5, arr5 + sizeof arr5 / sizeof arr5[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    cout << "–– Algorithm 4 ––" << endl;
    startTime = clock();
    maxSubSum2(vector<int> (arr5, arr5 + sizeof arr5 / sizeof arr5[0]));
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "\n";
    
    return 0;
}
