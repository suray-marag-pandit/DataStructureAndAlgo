#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair <float, int> p1, pair <float, int> p2) {
	return p1.first > p2.first;
}

int fractional_knapsack(vector <int> w, vector <int> v, int c) {
	int len = w.size();
	int total_value = 0;

	vector <pair <float, int>> ratio(len, make_pair(0.0, 0));

	for(int i = 0; i < len; i++)
		ratio[i] = make_pair(v[i]/w[i], i);

	sort(ratio.begin(), ratio.end(), compare);

	for(int i = 0; i < len; i++) {
		if(c == 0)
			break;

		if(w[ratio[i].second] <= c) {
            cout<<w[i]<<endl;
			total_value += v[ratio[i].second];
			c -= w[ratio[i].second];
		}

	}

	return total_value;
}

int main() {
	int n = 3;
	vector <int> w = {10, 20, 40};
	vector <int> p = {90,100,300};
	int given_weight = 180;
	cout << "The maximum value that can be obtained is: " << fractional_knapsack(w, p, given_weight) << endl;
	return 0;
}
