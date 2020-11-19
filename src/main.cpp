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
void MAXIMUM_PLANAR_SUBSET(int, int);
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

    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2], ios::out);
    int size;
    fin >> size;
    cout << size << endl;
    int i, j;
    map<int, int> data;
    while (fin >> i >> j)
    {
        data[i] = j;
        data[j] = i;
        cout << data[i] << endl;
        cout << data[j] << endl;
    }
    return 0;
}

void MAXIMUM_PLANAR_SUBSET(int c, int n)
{
    int **M = new int*[2*n]
    for(int i=0;i<(2*n);i++)
    M[i] = new int[2*n]
    for (int i = 0; i < (2*n - 1); i++)
    {
        M[i][i] = 0;
    }
    for (int l = 0; l < (2*n - 1); l++)
    {
        for (int i = 0; i < (2*n - l); i++)
        {
            int j = i + l;
            if (chord kj is in c && !(k >= i && k <= j))
                M[i][j] = M[i][j - 1];
            else if ()
        }
    }
    return;
}
