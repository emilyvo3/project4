#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// we need multimap for our "frontier"
// and a list that stores the back links
// make a separate function which only does recurssion so that we dont mess up initialization of back-links
// so we have two functions: dij and path
// recurssive function that will return the shortest cost

void dij(vector<int> &board, vector<vector<int>> &edges, int &start, int &end, int &r)
{
    vector<int> backlink((r * r), -1);
    vector<int> costs((r * r), INT_MAX);
    multimap<int, int> frontier;
    multimap<int, int>::iterator it;
    frontier.insert(make_pair(0, start));

    int new_dist, cost, pos;

    while (!frontier.empty())
    {
        it = frontier.begin();
        // cout<<"Frontier: "<<frontier.begin()->first<<" "<<frontier.begin()->second<<" 'it': "<<it->first<<" "<<it->second<<endl;
        cost = it->first;
        pos = it->second;
        frontier.erase(it);

        for (int j = 0; j < (int)edges[pos].size(); j++)
        {
            // cout << edges[pos].size() << endl;
            int curr = edges[pos][j];
            if (curr >= 0 && curr < (int)board.size())
            {
                new_dist = cost + board[pos];
                if (new_dist < costs[curr] /*&& curr != end*/)
                {
                    costs[curr] = new_dist;
                    backlink[curr] = pos;
                    frontier.insert(make_pair(new_dist, curr)); // add the neighbor to the frontier
                }
            }
        }
    }

    cout << costs[end] << endl;

    vector<int> path_tiles;
    int current = end; // set the end tile as the current tile

    // traverse the game board backwards from the end to start tile
    while (current != start)
    {
        path_tiles.push_back(current); // add the current tile to the path
        current = backlink[current];   // move to the tile that led to the current tile in the shortest path
    }

    path_tiles.push_back(start);                   // add the start tile to the path
    reverse(path_tiles.begin(), path_tiles.end()); // reverse the path to obtain the correct order

    for (int i = 0; i < (int)path_tiles.size(); i++)
    {
		//cout << path_tiles.size() << endl;
        int row = path_tiles[i] / r;
        int col = path_tiles[i] % r;

        if (i == (int)path_tiles.size()-1) { 
            cout << col << " " << row << endl;
        }
        else{
            cout << row << " " << col << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    int ntiles, tcost, r, c;
    char nametile;
    vector<int> board;
    char input;
    int value, end;
    int start = 0;
    int c1, c2, e1, e2;

    while (cin >> ntiles)
    {

        map<char, int> tiles;
        map<char, int>::iterator it;
        end = 0;
        board.clear();

        // reading in tile names and costs
        for (int i = 0; i < ntiles; i++)
        {
            cin >> nametile >> tcost;
            tiles.insert(make_pair(nametile, tcost));
        }

        // reading in rows and columns
        cin >> r >> c;

        // reading in board
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> input;
                it = tiles.find(input);
                value = it->second;
                board.push_back(value);
            }
        }

        // reading in start(or current) and end points
        cin >> c1 >> c2 >> e1 >> e2;

        // testing output

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
                }*/

        // cout<<c1<<" "<<c2<<endl;
        // cout<<e1<<" "<<e2<<endl;
        start = (c2 * c) + c1;
        end = (e2 * c) + e1;

        //cout<<start<<" "<<end<<endl;
        int x, y;
        vector<vector<int>> edges;
        vector<int> index;

        edges.clear();
        index.clear();

        for (int i = 0; i < r * c; i++)
        {
            x = i / r;
            y = i % r;

            // checking for the 4 corners ONLY
            // will have 2 edges
            if ((y == 0 && x == 0) || (y == 0 && x == c - 1) || (y == r - 1 && x == 0) || (y == r - 1 && x == c - 1))
            {
                index.push_back(i + 1);
                index.push_back(i + c);
            }
            // check the elements adjacent to the corners
            // will have 3 edges
            else if ((y == 0) || (x == 0) || (y == r - 1) || (y == r - 1 && x == c - 1))
            {
                if (y == 0)
                {
                    index.push_back(i + 1);
                    index.push_back(i + c);
                    index.push_back(i - c);
                }
                else if (x == 0)
                {
                    index.push_back(i - 1);
                    index.push_back(i + 1);
                    index.push_back(i + c);
                }
                else if (y == r - 1)
                {
                    index.push_back(i - 1);
                    index.push_back(i - c);
                    index.push_back(i + c);
                }
                else if (x == c - 1)
                {
                    index.push_back(i - 1);
                    index.push_back(i + 1);
                    index.push_back(i - c);
                }
            }
            // check for remaining elements
            // will have 4 edges
            else
            {
                index.push_back(i + 1);
                index.push_back(i + c);
                index.push_back(i - 1);
                index.push_back(i - c);
            }
            edges.push_back(index);
            index.clear();
        }

        /*		for(int i = 0; i < (int) edges.size(); i++){
                    cout<<"Index "<<i<<" has these edges: ";
                    for(int j = 0; j < (int) edges[i].size(); j++){
                        cout<<edges[i][j]<<endl;
                    }
                    cout<<endl;
                }*/

        dij(board, edges, start, end, r);
    }
    return 0;
}


