/*
    Abril Marina Gonzalez Ramirez
    DATA STRUCTURES AND ALGORITHMS SPECIALIZATION
    Week 1 - Maximum Pairwise Product
    May 17, 2019

    Find the maximum product of two numbers in an array of numbers.

    Includes stress tests (randomly generated numbers testing both fast and naive solution) to ensure correctness
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Naive Solution for stress test
long long MaxPairwiseProduct(const vector<int>& numbers){
    long long result = 0;
    int n = numbers.size();

    // Compare all pairs of numbers against each other
    for(int i=0; i < n; i++){
        for(int j= i + 1; j < n; j++){
            if(((long long)(numbers[i]) * numbers[j]) > result ){
                result = ((long long)(numbers[i])) * numbers[j];
            }
        }
    }
    return result;
}

// Faster solution that finds the two largest numbers
long long MaxPairwiseProductFast(const vector<int>& numbers){
    long long result=0;
    int n = numbers.size();

    // Get largest number in vector
    int max_index1 = -1;
    for(int i=0; i < n; i++){
        if((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
            max_index1 = i;
    }

    // Get second largest number in vector
    int max_index2 = -1;
    for(int j=0; j < n; j++){
        if((max_index1 != j) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
            max_index2 = j;
    }
    
    result = numbers[max_index1] * numbers[max_index2];
    return result;
}

int main(){
    /* 
    // Stress tests
    while(true){
        // Generate random n from 2 to 11
        int randomN = rand() % 10 + 2;
        cout << randomN << endl;

        // Fill vector of size n with random numbers
        vector<int> numbers;
        for(int i=0; i < randomN; i++){
            numbers.push_back(rand() % 1000);
        }
        // Print test vector
        for(int i=0; i < randomN; i++){
            cout << numbers[i] << ' ';
        }
        cout << "\n";

        // Test both solutions (naive and fast)
        long long result1 = MaxPairwiseProduct(numbers);
        long long result2 = MaxPairwiseProductFast(numbers);

        if(result1 != result2){
            cout << "Incorrect answer: " << result1 << ' ' << result2 << endl;
            break;
        }
        else{
            cout << "Test passed." << endl; 
        }
    }
    */

    // Get numbers vector size
    int n;
    cin >> n;

    // Ensure at least two numbers in vector
    if (n < 2){
        cout << "Array should have at least two numbers." << endl;
        return 0;
    }

    // Write numbers to vector
    vector<int> numbers(n);
    for(int i=0; i < n; i++){
        cin >> numbers[i];
    }

    // Output answer
    cout << MaxPairwiseProductFast(numbers) << endl;

    return 0;
}