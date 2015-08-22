/*
 * Coinchange(total_no_of_ways).cpp
 *
 *  Created on: Aug 22, 2015
 *      Author: Ruthwik
 */

#include <cmath>
#include<climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
using namespace std;
long long int coinchange(long long int s[], int m, int n) {
	long long int temp[n + 1];
	for (int i = 0; i <= n; i++)
		temp[i] = 0;
	temp[0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = s[i]; j <= n; j++) {
			temp[j] += temp[j - s[i]];
		}
	}
	return temp[n];
}

int main() {
	int n, m;
	cin >> n >> m;
	long long int c[m];

	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}
	cout << coinchange(c, m, n);

	return 0;
}
/*
 testcase 1
 250 24
 41 34 46 9 37 32 42 21 7 13 1 24 3 43 2 23 8 45 19 30 29 18 35 11

 O/P:15685693751

 testcase 2
 4 3
 1 2 3

 O/P:4

 testcase 3
 10 4
 2 5 3 6

 O/P:5
 */
