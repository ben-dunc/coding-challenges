/*
    Filename: StockPrices.cpp
    Author: Benjamin Duncan
    Date of creation: Nov 15, 2022

    Daily Coding problem # 27
    Difficulty: Medium
    Interviewing company: Facebook

    To run: g++ StockPrices.cpp

    Problem: Given an array of numbers representing the stock prices of a company in chronological order and an integer, k, 
    return the maximum profit you can make from k buys and sells. You must buy the stock before you can sell it, and you 
    must sell the stock before you can buy it again.

    For example, given k = 2 and the array [5,2,4,0,1], you should return 3
*/

/*
    Algorithm:
    1. Make a diff array, subtracting every number by it's previous number.
    2. Instantiate a queue whose size = k, fill it with 0's
    3. Iterate through the diff array
        a. for each number, if the number is greater than the last number in the queue or if it is null, then add it to the queue, popping the last one off
    4. Sum up the numbers in the queue.
    5. Return the sum.
*/

#include <string>
#include <queue>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    const int NUM_PRICES = 10;

    int k = 4;
    int prices[NUM_PRICES] = {5,2,3,4,2,1,0,4,2,5};
    int diff[NUM_PRICES - 1];
    int profit = 0;

    queue<int> bestDiffs = queue<int>();

    for (int i = 0; i < k; i++) {
        bestDiffs.push(0);
    }

    for (int i = 0; i < NUM_PRICES - 1; i++) {
        int diff = prices[i + 1] - prices[i];
        if (diff > bestDiffs.front()) {
            bestDiffs.pop();
            bestDiffs.push(diff);
        }
    }

    for (int i = 0; i < k; i++) {
        profit += bestDiffs.front();
        bestDiffs.pop();
    }

    cout << "Best profit: " << profit << endl;

    return 0;
}



