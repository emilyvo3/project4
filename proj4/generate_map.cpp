
#include<iostream>
#include<fstream>
#include<iomanip>
#include<random>
#include<time.h>

using namespace std;

int GetRandom(int min, int max);

int main(){
     //seeding random number generator
	srand(time(0));


    ifstream fin;
    ofstream fout;
    int numbers, randnum = 0, start = 0, end = 0;
    string filename, ofilename;
	
	vector<char> tiles = {'f', 'g', 'G', 'h', 'm', 'r'};
	vector<int> cost = {3, 1, 2, 4, 7, 5};

    filename = "num.txt";
    fin.open(filename);
    if(!fin.is_open()){
        cout<<"Could not open file. Ceck permissions or filename.\n";
        return 1;
    }


    /*Create an output file to place newly formatte data */
	
	//10, 20, 50, 100, 200, 500, 1000
    while(fin>>numbers){
        //open output file

		switch(numbers){
			case 10:
                ofilename = "10.txt";
                break;
			case 20:
                ofilename = "20.txt";
                break;	
            case 50:
                ofilename = "50.txt";
                break;
            case 100:
                ofilename = "100.txt";
                break;
            case 200:
                ofilename = "200.txt";
                break;
            case 500:
                ofilename = "500.txt";
                break;
            case 1000:
                ofilename = "1000.txt";
                break;
        }

        fout.open(ofilename);

		for(int i = 0; i < (int) tiles.size(); i++){
			fout<<tiles[i]<< " " << cost[i]<<endl;
		}	

		fout<<numbers<<" "<<numbers<<endl;

        for(int i = 0; i < numbers; i++){
            for(int j = 0; j < numbers - 1; j++){
				randnum = GetRandom(0, (int) tiles.size() - 1);
		        fout<<tiles[randnum]<<" ";
			}	

			randnum = GetRandom(0, (int) tiles.size() - 1);
            fout<<tiles[randnum]<<endl;


        }

		start = GetRandom(0, (numbers * numbers) - 1);
		end = GetRandom(0, (numbers * numbers) - 1);
		fout<<start/numbers<<" "<<start%numbers<<endl;
		fout<<end/numbers<<" "<<end%numbers<<endl;


        //close output file
        fout.close();

    }
     //close statements
    fin.close();
    
	return 0;
}

int GetRandom(int min, int max){
    //Initialize random to 0 so that it gets a new value everytime we call it
    int random = 0;

    //Assign a random number from 0 to 51, which are the beginning and ending index of the array 'cards'

    random = min + rand() % (max - min + 1);
    return random;
}

