#include <iostream>
#include <fstream>

using namespace std;

int get_n_rounds(string);

int main(void)
{
    int n_rounds, id_total = 0;

    ifstream file("input.txt");

    if (file.is_open()){
        string line;
        while (getline(file, line)){
            cout << "original: " << line << endl;
            n_rounds = get_n_rounds(line);
            cout << "rounds: " << n_rounds << endl;
        }
    }

    return 0;
}

int get_n_rounds(string line)
{
    int rounds = 0;
    int found_pos = line.find(';');

    while (found_pos != string::npos){
        rounds++;
        found_pos = line.find(';', found_pos+1);
    }

    return rounds+1;
}
