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
void MAXIMUM_PLANAR_SUBSET(map<int, int>, int);
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
    map<int, int> chord;
    while (fin >> i >> j)
    {
        chord[i] = j;
        chord[j] = i;
    }
    MAXIMUM_PLANAR_SUBSET(chord, size / 2);
    return 0;
}

void MAXIMUM_PLANAR_SUBSET(map<int, int> chord, int n)
{
    int **M = new int *[2 * n];
    for (int i = 0; i < (2 * n); i++)
        M[i] = new int[2 * n];

    for (int i = 0; i < 2 * n; i++)
    {
        M[i][i] = 0;
    }
    for (int l = 1; l < 2 * n; l++)
    {
        for (int i = 0; i < 2 * n - l; i++)
        {
            int j = i + l;
            if (!(chord[j] >= i && chord[j] <= j))
                M[i][j] = M[i][j - 1];
            else if (chord[j] == i)
                M[i][j] = M[i + 1][j - 1] + 1;
            else
            {
                if (M[i][j - 1] >= M[i][chord[j] - 1] + 1 + M[chord[j] + 1][j - 1])
                {
                    M[i][j] = M[i][j - 1];
                }
                else
                {
                    M[i][j] = M[i][chord[j] - 1] + 1 + M[chord[j] + 1][j - 1];
                }
            }
        }
    }
    for (int i = 0; i < 2 * n; i++)
    {
        cout << chord[i] << endl;
    }
    for (int i = 0; i < 2 * n; i++)
    {
        cout << endl;
        for (int j = 0; j < 2 * n; j++)
            cout << M[i][j];
    }
    return;
}
