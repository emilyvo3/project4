//Emily Vo & Dhwani Patel
// Project 4: Path Finding
// CS 302
// 3/31/23
#include <iostream>
#include <climits> // for INT_MAX
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void dij(vector<int> &board, vector<vector<int>> &edges, int &start, int &end, int &r)
{
    vector<int> backlink((r * r), -1); // store the previous vertex in the shortest path
    vector<int> costs((r * r), INT_MAX); // store the shortest path costs 
    multimap<int, int> frontier; // store unvisited vertices, sorted by their cose
    multimap<int, int>::iterator it;
    frontier.insert(make_pair(0, start)); // insert the starting vertex with zeo cost into the frontier

    int new_dist, cost, pos;

    while (!frontier.empty())
    {
        // select vertex with the lowest cost from the frontier
        it = frontier.begin();
        cost = it->first;
        pos = it->second;
        
        frontier.erase(it); // remove selected vertex from the frontier

        for (int j = 0; j < (int)edges[pos].size(); j++)
        {
            int curr = edges[pos][j]; // neighbor vertex
            if (curr >= 0 && curr < (int)board.size()) // check if the negihbor is inside the board
            {
                // calculate the new distance through the selected vertex to the neighbor
                new_dist = cost + board[pos];

                if (new_dist < costs[curr])
                {
                    // update the shortest path cost and backlink for the neighbor
                    costs[curr] = new_dist;
                    backlink[curr] = pos;

                    frontier.insert(make_pair(new_dist, curr)); 
                }
            }
        }
    }

    cout << costs[end] << endl; // output the shortest/total path cost from start to end vertex

    // reconstruct the shortest path from backlinks
    vector<int> path_tiles;
    int current = end; 

    // traverse the game board backwards from the end to start tile
    while (current != start)
    {
        path_tiles.push_back(current); 
        current = backlink[current];   // move to the tile that led to the current tile in the shortest path
    }

    path_tiles.push_back(start);                   
    reverse(path_tiles.begin(), path_tiles.end()); // reverse the path to obtain the correct order

    /* output the tiles in the shortest path */
    for (int i = 0; i < (int)path_tiles.size(); i++)
    {
        int row = path_tiles[i] / r;
        int col = path_tiles[i] % r;

        cout << row << " " << col << endl;
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
    int c1, c2, e1, e2; // variables for inputting start and end points

    while (cin >> ntiles)
    {
        map<char, int> tiles;
        map<char, int>::iterator it;
        end = 0; // reset end point
        board.clear();

        /* reading in tile names and costs and store them in the map */
        for (int i = 0; i < ntiles; i++)
        {
            cin >> nametile >> tcost;
            tiles.insert(make_pair(nametile, tcost));
        }

        // reading in rows and columns
        cin >> r >> c;

        /* read in the game board and store the corresponding values in the board vector */
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

        /* read in the start and end points and calculate their positions on the board */
        cin >> c1 >> c2 >> e1 >> e2;
        start = (c1 * c) + c2;
        end = (e1 * c) + e2;

        int x, y;
        vector<vector<int>> edges;
        vector<int> index;

        edges.clear();
        index.clear();

        /* loop through each element on the board and add its corresponding edges to the edges vector */
        for (int i = 0; i < r * c; i++)
        {
            x = i / r;
            y = i % r;

            /* checking for the 4 corners ONLY; will have 2 edges */
            if ((y == 0 && x == 0) || (y == 0 && x == c - 1) || (y == r - 1 && x == 0) || (y == r - 1 && x == c - 1))
            {
                index.push_back(i + 1);
                index.push_back(i + c);
            }
            /* check the elements adjacent to the corners; will have 3 edges */
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
            /* check for remaining elements; will have 4 edges */
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
        dij(board, edges, start, end, r);
    }
    return 0;
}


