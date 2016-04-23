// Meysam Aghighi
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, i = 1;
	while (cin >> n) cout << "Case " << i++ << ": " << ceil(log10(3)+n*log10(1.5)) << endl;
	return 0;
}