#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
void split(vector<int> &v, vector<string> &o, string str, char delimiter)
{
    stringstream stri(str);
    bool o = false;
    while (stri.good())
    {
        string elem;
        getline(stri, elem, delimiter);
        if (!o)
            v.push_back(stoi(elem));
        else
            o.push_back(elem);
        o = !o;
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
        vector<vector<int>> trans(50);
        vector<vector<string>> out(50);
        int len = 0;
        while (getline(file, line))
        {
            split(trans[len], out[len], line, ' ');
            len++;
        }
        string input, op("");
        cin >> input;
        int pres = initial_st;
        for (int i = 0; i < input.length(); i++)
        {
            int state = input[i] - '0';
            int temp_pres = trans[pres][state];
            op += out[pres][state] == "-1" ? "" : out[pres][state];
            pres = temp_pres;
            if (pres == -1)
                break;
        }
        cout << op << endl;
    }
    else
    {
        cout << "Can't open File" << endl;
    }
}