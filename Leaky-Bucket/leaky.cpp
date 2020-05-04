#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main(){
	int bucket_size, out_rate, current_bs = 0, q;
	cout << "Enter Ourput rate and Max Bucket size: ";
	cin >> out_rate >> bucket_size;
	cout << "Enter number of queries: ";
	cin >> q;
	for (int i = 0; i < q; i++){
		int in  = out_rate + rand() % q + 10;
		cout << "Input packet size: " << in << "\n";
		if (in < bucket_size - current_bs){
			current_bs += in;
			cout << "Current bucket Size: " << current_bs << "\n\n";
		}
		else {
			cout << "Bucket overflow... loss: " << in - bucket_size + current_bs << endl;
			current_bs = bucket_size;
			cout << "Current bucket Size: " << current_bs << "\n\n"; 
		}
		current_bs -= out_rate;
		cout << "After out, current bucket size: " << current_bs << "\n\n";
	}
	return 0;
}
