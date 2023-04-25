#include <iostream>
#include <vector>

using namespace std;

vector<int> findPrimes(vector<int> inputList) {

    vector<int> primes;

    vector<bool> isPrime(inputList.size(), true);
    isPrime[0] = false;
    isPrime[1] = false;


    for (int i = 2; i * i < inputList.size(); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < inputList.size(); j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 0; i < inputList.size(); i++) {
        if (isPrime[i]) {
            primes.push_back(inputList[i]);
        }
    }

    return primes;
}

int main() {
    vector<int> inputList = {2, 3, 4,5,6, 7, 9, 11, 13, 14,15,32,45};
    vector<int> primes = findPrimes(inputList);

    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << " ";
    }
    cout << endl;

    return 0;
}
