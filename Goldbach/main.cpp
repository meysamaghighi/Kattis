#include <iostream>
#include <vector>
using namespace std;

int main() {
	bool is_prime[32000];
	vector <int> p;
	p.push_back(2);
	is_prime[2] = true;
	int temp;
	// Getting all primes
	for (int i=3;i<32001;i++){
		temp = 1;
		for (int j=0;j<p.size();j++){
                    if (i%p.at(j) == 0){
                        temp = 0;
                        j = p.size();
                    }
		}
		if (temp){
			p.push_back(i);
			is_prime[i] = true;
		}
	}
	// Going for Goldbach
	int n,a;
	cin >> n;
	for (int i=0;i<n;i++){
            cin >> a;
//            int n_answer = 0;
            vector <int> answer;
            for (int j=0;p.at(j)<=a/2;j++){
                if (is_prime[a - p.at(j)]){
                    answer.push_back(p.at(j));
                }
            }
            cout << a << " has " << answer.size() << " representation(s)\n";
            for (int j=0;j<answer.size();j++){
                cout << answer.at(j) << "+" << a-answer.at(j) << "\n";
            }
            cout << "\n";
	}
    return 0;
}

