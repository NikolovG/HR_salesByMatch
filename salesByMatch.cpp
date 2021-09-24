// Challange Description: There is a large pile of socks that must be paired
// by color. Given an array of integers representing the color of each sock, 
// determine how many pairs of socks with matching colors there are.
//
// Created on: Sep 24, 2021
// Solution by: Georgi Nikolov
//
// Credits: HackerRank challenge "Sales by Match"
//

#include <iostream>
#include <vector>

using namespace std;
/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, vector<int> ar) {
    int numPair = 0;
    int size = ar.size();
    
    // O(N^2) Algorithmic Complexity
    for (int i = 0;i < size;i++) {
        for (int j = i+1;j < size;j++) {
            if (ar[i] > ar[j]) {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    } // Sorted Array
    
    int *x = &ar[0];  // Pointers to arr
    int *y = &ar[1];  // ^

    // O(N) Algorithmic Complexity
    for (int i = 0; i < ar.size() - 1; i++) {
        if (*x == *y) {
			// NOTE: For Debugging
            // cout<<*x<<" "<<*y<<endl;
            if (*x != 0 || *y != 0) {
            numPair++;
            }
            x += 2;
            y += 2;
        } else {
            x++;
            y++;
        }
    }

    return numPair;
}
int main() {
    int n;
	vector<int> ar;

	cout<<"Size of vector : ";
	cin>>n;

	int input;
	for(int i = 0; i < n; i++){
		cin>>input;
		ar.push_back(input);
	}

	int pairs = sockMerchant(n, ar);
	cout << "Pairs : " << pairs << endl;

    return 0;
}