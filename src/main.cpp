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
#include <map>

using namespace std;
int **MAXIMUM_PLANAR_SUBSET(std::map<int, int>, int);
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
    int i, j;
    map<int, int> chord;
    while (fin >> i >> j)
    {
        chord[i] = j;
        chord[j] = i;
    }
    ////////////get the table///////////////////////////
    int **table = MAXIMUM_PLANAR_SUBSET(chord, size / 2);
    /////////////print out the size/////////////////////
    fout << table[0][size - 1] << endl;
    /////////////print out the chord////////////////////
    for (int i = 0; i < size - 1; i++)
    {
        if (table[i][size - 1] - table[i + 1][size - 1] > 0)
            fout << i << " " << chord[i] << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
///////////////construct the table///////////////////////////
int **MAXIMUM_PLANAR_SUBSET(map<int, int> chord, int n)
{
    int size = 2 * n;
    int **M = new int *[size];
    for (int i = 0; i < (size); i++)
        M[i] = new int[size];

    for (int i = 0; i < size; i++)
    {
        M[i][i] = 0;
    }
    for (int l = 1; l < size; l++)
    {
        for (int i = 0; i < size - l; i++)
        {
            int j = i + l;
            int k = chord[j];
            if (!(k >= i && k <= j))
                M[i][j] = M[i][j - 1];
            else if (k == i)
                M[i][j] = M[i + 1][j - 1] + 1;
            else
            {
                if (M[i][j - 1] >= M[i][k - 1] + 1 + M[k + 1][j - 1])
                {
                    M[i][j] = M[i][j - 1];
                }
                else
                {
                    M[i][j] = M[i][k - 1] + 1 + M[k + 1][j - 1];
                }
            }
        }
    }
    return M;
}
