/*
 * Coinchange(minimum_no_of_coins_to_make_the_givensum).cpp
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
		temp[i] = INT_MAX;
	temp[0] = 0;
	for (int i = 0; i < m; i++) {
		for (int j = s[i]; j <= n; j++) {
			temp[j] = min(temp[j], temp[j - s[i]] + 1);
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
 11 4
 1 5 6 8

 O/P:2

 testcase 2
 4 3
 1 2 3

 O/P:2

 testcase 3
 10 4
 2 5 3 6

 O/P:2
 */
