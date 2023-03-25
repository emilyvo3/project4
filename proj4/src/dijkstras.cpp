// dijsktras.cpp

// Main Execution

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

//we need multimap for our "frontier"
//and a list that stores the back links
//make a separate function which only does recurssion so that we dont mess up initialization of back-links
//so we have two functions: dij and path

//recurssive function that will return the shortest cost


// pseudocode for now
void dij(vector<int>& board, int &start, int &end, int &r){
	vector <int> backlink((r * r), -1); 
	vector <int> distances((r * r), -1);
	vector<bool> visited((r * r), false);
	multimap<int, int> frontier;
	multimap<int, int>::iterator it;


	
	distances[0] = 0;
	frontier.insert(make_pair(distances[0], start));
	visited[0] = true;

	while(!frontier.empty()){
		it = frontier.begin();

		int cost = it->first;
		int pos = it->second;

		frontier.erase(it);

		/*if(visited[..] != false){
		
		}*/
		if (visited[pos])
		{
			continue;
		}
		visited[pos] = true;
	

/*	frontier = []
	marked = {}
	frontier.push({0, v, v})

	while not frontier.empty():
		v = frontier.pop()

		if v.name in marked:
			continue

		maked[v.name] = v.prev
		for u in g.edges[v.name]:
			frontier.push((u.cost + v.cost, u.name, v.name))
		print result of computation*/
	}	
}

int main(int argc, char *argv[]) {
	
	int ntiles, tcost, r, c;
	char nametile;
	//map<char, int> tiles;
	//map<char, int>::iterator it;

	vector<int> board;
//	vector<int> col;
	char input;
	int value, end;
	int start = 0;

	int c1, c2, e1, e2;

	while(cin>>ntiles){
		
		map<char, int> tiles;
	    map<char, int>::iterator it;
		end = 0;

		board.clear();
//		col.clear();

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
				board.push_back(value);
			}

//			board.push_back(col);
//			col.clear();

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
		for(int i = 0; i < r * c; ){
			for(int j = 0; j < c; i++, j++){
				cout<<board[i]<<" ";
			}
			cout<<endl;
		}

		cout<<c1<<" "<<c2<<endl;
		cout<<e1<<" "<<e2<<endl;*/
		start = (c2 * c) + c1;
		end = (e2 * c) + e1;

//		cout<<start<<" "<<end<<endl;
		 int x,y;
		 vector<vector<int>> edges;
		 vector<int> index;


		for(int i = 0; i < r * c; i++){
			x = i / r;
			y = i % r;
			
			//checking for the 4 corners ONLY
			//will have 2 edges
			//if( (y == 0 && ((x % r) == 0)) || (y == (r - 1) && (((x ) % r) == 0))){
			if( (y == 0 && x == 0) || (y == 0 && x == c - 1) || (y == r - 1 && x == 0) || (y == r - 1 && x == c - 1)){
				index.push_back(board[i + 1]);
				index.push_back(board[i + c]);
			}

			//check the elements adjacent to the corners
			//will have 3 edges
			else if((y == 0 && x == 0) || (y == 0 && x == c - 1) || (y == r - 1 && x == 0) || (y == r - 1 && x == c - 1)){
				 /*index.push_back(board[i + 1]);
                 index.push_back(board[i + c]);
				 index.push_back(board[i - 1]);*/
				if (y == 0 && x == 0){
        		index.push_back(board[i + 1]);
        		index.push_back(board[i + c]);
    		}
    			else if (y == 0 && x == c - 1){
        		index.push_back(board[i - 1]);
        		index.push_back(board[i + c]);
    		}
    			else if (y == r - 1 && x == 0){
        		index.push_back(board[i + 1]);
       			index.push_back(board[i - c]);
    		}
    			else if (y == r - 1 && x == c - 1){
        		index.push_back(board[i - 1]);
        		index.push_back(board[i - c]);
    		}
		}

			//check for remaining elements
			//will have 4 edges
 			else{
				index.push_back(board[i + 1]);
                index.push_back(board[i + c]);
                index.push_back(board[i - 1]);
				index.push_back(board[i - c]);
			}
		}
		
		dij(board, start, end, r);



        

	}

	return 0;
}


