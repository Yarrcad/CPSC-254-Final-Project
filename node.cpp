#include "chain.cpp"
using namespace std;



int main(){
	string BLOCKSSAVED = "blockessaved.txt";
	string BLOCKSRECEIVED = "blockesreceived.txt";
	string TRANSACTIONSRECIEVED = "transactionsreceived.txt";
	string IDFILE = "id.txt";
	string NODEIPS = "nodes.txt";
	
	chain x;
	x.loadBlocks(BLOCKSSAVED.c_str());
	x.loadBlocks(BLOCKSRECEIVED.c_str());
	ofstream(BLOCKSRECEIVED.c_str()).close();//clear out file;
	
	vector<transaction> vt;
	transaction t;
	ifstream f(TRANSACTIONSRECIEVED.c_str());
	while(f >> t){
		vt.push_back(t);
	}
	f.close();
	ofstream(TRANSACTIONSRECIEVED.c_str()).close();//clear out file;
	
	cout << vt.size() << endl;
	while(vt.size() > 0){
		if(x.ch.size() == 0){
			cout << "OUTER PUSH\n";
			x.ch.push_back(block());
		}
		else {
			cout << "INNER PUSH\n";
			block temp(time(NULL),vt.back(),x.ch.back().time,x.ch.back().hash);
			if(x.ch.size() >= 3){
				temp.getdifficulty(x.ch[x.ch.size()-3],x.ch[x.ch.size()-2]);
			}
			else {
				temp.difficulty = 1;
			}
			long long c = 1;
			while(!x.checkblockvalidity(temp)){
				cout << "CHECk FAILED\n";
				cout << temp.hash << endl << temp.lasthash << endl << x.ch.back().hash << endl;
				temp.makehash(c++);
			}
			x.ch.push_back(temp);
			vt.pop_back();
			
			
			//cout << x.ch[x.ch.size()-1].hash <<endl;
			
		}
		cout << "LOOP DONE!\n";
	}
	cout << "HERE NOW!\n";
	ofstream out(BLOCKSSAVED.c_str());
	for(int i = 0; i < x.ch.size(); i++){
		out << x.ch[i];
	}
	out.close();
}

 