#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
void split(vector<int> &v, vector<string> &o, string str, char delimiter)
{
    stringstream str_strm(str);
    bool output = false;
    while (str_strm.good())
    {
        string elem;
        getline(str_strm, elem, delimiter);
        if (!output)
            v.push_back(stoi(elem));
        else
            o.push_back(elem);
        output = !output;
    }
}
int main()
{
    fstream file;
    file.open("input.txt");
    if (file.is_open())
    {
        string line;
        getline(file, line);
        int initial_st = stoi(line);
        vector<vector<int>> transition(50);
        vector<vector<string>> output(50);
        int len = 0;
        while (getline(file, line))
        {
            split(transition[len], output[len], line, ' ');
            len++;
        }
        string input, op("");
        cin >> input;
        int present = initial_st;
        for (int i = 0; i < input.length(); i++)
        {
            int state = input[i] - '0';
            int temp_present = transition[present][state];
            op += output[present][state] == "-1" ? "" : output[present][state];
            present = temp_present;
            if (present == -1)
                break;
        }
        cout << op << endl;
    }
    else
    {
        cout << "Can't open File" << endl;
    }
}