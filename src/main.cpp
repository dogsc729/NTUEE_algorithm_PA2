// **************************************************************************
//  File       [main.cpp]
//  Author     [Shu-Yu Lin]
//  Synopsis   [The main program of 2020 fall Algorithm PA2]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <new>
#include <ctime>
#include "../lib/tm_usage.h"

using namespace std;

void help_message()
{
    cout << "usage: ./mps <input file name> <output file name>" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        help_message();
        return 0;
    }
    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;
    //////////// read the input file /////////////

    char buffer[200];
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2], ios::out);
    fin.getline(buffer, 200);
    fin.getline(buffer, 200);
    int junk, num;
    vector<int> data;
    while (fin >> junk >> num)
        data.push_back(num); // data[0] will be the first data.
                             // data[1] will be the second data and so on.

    //////////// the sorting part ////////////////
    cout << "fuck" << endl;
    return 0;
}
