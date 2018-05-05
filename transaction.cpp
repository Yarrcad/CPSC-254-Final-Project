#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class transaction{
public:
		long long from;
		long long to;
		long long numCoins;
		time_t time;
		transaction(long long from, long long to, long long numCoins, time_t time){
			this->from = from;
			this->to = to;
			this->numCoins = numCoins;
			this->time = time;
		}
		transaction(){
			this->from = 0;
			this->to = 0;
			this->numCoins = 0;
			this->time = 0;
		}

		friend istream &operator>>(istream& i, transaction& t){
			i >> t.from >> t.to >> t.numCoins >> t.time;
			return i;
		}

		friend ostream &operator<<(ostream& o, transaction& t){
			o << t.from << " " << t.to << " " << t.numCoins << " " << t.time << "\n";
			return o;
		}
};


/*
int main(){
	transaction x(100,200,1,12345);
	ofstream f("test.txt");
	f << x;
	f.close();
	transaction a;
	ifstream ff("test.txt");
	ff >> a;
	cout << a;
	ff.close();
	return 1;
}
*/