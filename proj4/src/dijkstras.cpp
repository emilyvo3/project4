// dijsktras.cpp

// Main Execution

#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(int argc, char *argv[]) {
	
	int ntiles, tcost, r, c;
	char nametile;
	//map<char, int> tiles;
	//map<char, int>::iterator it;

	vector<vector<int>> board;
	vector<int> col;
	char input;
	int value;

	int c1, c2, e1, e2;

	while(cin>>ntiles){
		
		map<char, int> tiles;
	    map<char, int>::iterator it;
		
		board.clear();
		col.clear();

		//reading in tile names and costs
		for(int i = 0; i < ntiles; i++){
			cin>>nametile>>tcost;
			tiles.insert(make_pair(nametile, tcost));
		}
		
		//reading in rows and columns
		
		cin>>r>>c;

		//reading in board

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cin>>input;
				it = tiles.find(input);
				value = it->second;
				col.push_back(value);
			}

			board.push_back(col);
			col.clear();

		}
		
		//reading in start(or current) and end points
		cin>>c1>>c2>>e1>>e2;

		//testing output
		
/*		cout<<"Testing the input: "<<endl;
		cout<<ntiles<<endl;
		for(map<char, int>::iterator i = tiles.begin(); i != tiles.end(); i++){
			cout<<i->first<<" "<<i->second<<endl;
		}
		cout<<r<<" "<<c<<endl;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}

		cout<<c1<<" "<<c2<<endl;
		cout<<e1<<" "<<e2<<endl;*/

	}

	return 0;
}


