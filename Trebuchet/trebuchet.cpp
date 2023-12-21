#include <iostream>
#include <fstream>
#include <map>

using namespace std;

string spelt_to_int(string input)
{
    map<string, string> num_str_map;
    num_str_map["1"] = "one";
    num_str_map["2"] = "two";
    num_str_map["3"] = "three";
    num_str_map["4"] = "four";
    num_str_map["5"] = "five";
    num_str_map["6"] = "six";
    num_str_map["7"] = "seven";
    num_str_map["8"] = "eight";
    num_str_map["9"] = "nine";
    num_str_map["0"] = "zero";

    for (auto x : num_str_map){
        int found_pos = input.find(x.second);
        while (found_pos != string::npos){
            input.replace(found_pos+1, x.second.length()-2, x.first);
            found_pos = input.find(x.second, found_pos+1);
        }
    }
    return input;
}

string filter_val(string line)
{
    string str_ints, output;

    for (char c : line) {
        if (isdigit(c)) {
            str_ints += c;
        }
    }

    output.append(1, str_ints.front());
    output.append(1, str_ints.back());

    return output;
}

int main(void)
{
    ifstream file("input.txt");

    int total = 0;

    if (file.is_open()) {
        string line;
        while (getline(file, line)){
            cout << "original: " << line << endl;
            string filtered_val = spelt_to_int(line);
            cout << "converted line: " << filtered_val << endl;
            filtered_val = filter_val(filtered_val);
            cout << "filtered values: " << filtered_val << endl;
            total += stoi(filtered_val);
        }

    }

    cout << total;

    return 0;
}
