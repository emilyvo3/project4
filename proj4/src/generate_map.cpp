//Emily Vo & Dhwani Patel
// Project 4: Path Finding
// CS 302
// 3/31/23
#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <time.h>

using namespace std;

int GetRandom(int min, int max);

int main()
{
    srand(time(0)); // seeding random number generator

    ofstream fout; // declare an output file stream object
    int numbers, randnum = 0, start = 0, end = 0;
    string ofilename; // declare a string variable to hold the output file name
    int ntiles = 6;
    vector<char> tiles = {'f', 'g', 'G', 'h', 'm', 'r'};
    vector<int> cost = {3, 1, 2, 4, 7, 5};

    cin >> numbers; // prompt the user to enter the board size or number of row/columns

    ofilename = "map.txt"; // set the output file name
    fout.open(ofilename); 

    fout << ntiles << endl;

    for (int i = 0; i < (int)tiles.size(); i++)
    {
        fout << tiles[i] << " " << cost[i] << endl; // write the tile type and its cost to the output file
    }

    fout << numbers << " " << numbers << endl; // write the number of rows/columns to the output file

    for (int i = 0; i < numbers; i++) 
    {
        for (int j = 0; j < numbers - 1; j++) 
        {
            randnum = GetRandom(0, (int)tiles.size() - 1); // get a random tile type
            fout << tiles[randnum] << " "; // write the tile type to the output file
        }
        randnum = GetRandom(0, (int)tiles.size() - 1); // get a random tile type for the last column
        fout << tiles[randnum] << endl; // write the tile type to the output file
    }

    start = 0; // set the starting point to the top-left corner
    end = (numbers * numbers) - 1; // set the ending point to the bottom-right corner
    fout << start / numbers << " " << start % numbers << endl; // write the starting point to the output file
    fout << end / numbers << " " << end % numbers << endl; // write the ending point to the output fil

    fout.close(); 
    return 0;
}

int GetRandom(int min, int max)
{
    // initialize random to 0 so that it gets a new value everytime we call it
    int random = 0;

    // assign a random number from 0 to 51, which are the beginning and ending index of the array 'cards'
    random = min + rand() % (max - min + 1);
    return random;
}

