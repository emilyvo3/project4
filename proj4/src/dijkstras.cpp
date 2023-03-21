// dijsktras.cpp

// Main Execution

#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(int argc, char *argv[]) {
	
	int ntiles, tcost, r, c;
	char nametile;
	map<char, int> tiles;
	map<char, int>::iterator it;

	vector<vector<int>> board;
	vector<int> col;
	char input;
	int value;

	while(cin>>ntiles){

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
		}

	}

	return 0;
}

