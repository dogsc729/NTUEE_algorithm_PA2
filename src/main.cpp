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
int **MAXIMUM_PLANAR_SUBSET(int *, int);
void CHORD_OF_MPS(int **, int *, int, int, map<int, int> &);
void help_message()
{
    cout << "usage: ./mps <input file name> <output file name>" << endl;
}
struct comp
{
    template <typename T>

    // Comparator function
    bool operator()(const T &l,
                    const T &r) const
    {
        if (l.first != r.first)
        {
            return l.first < r.first;
        }
        return l.second < r.second;
    }
};

// Function to sort the map according
// to value in a (key-value) pairs
void sort(map<int, int> &chordset,fstream& fout)
{

    // Declare set of pairs and insert
    // pairs according to the comparator
    // function comp()
    set<pair<int, int>, comp> S(chordset.begin(),
                                chordset.end());
    // Print the sorted value
    for (auto &it : S)
    {
        fout << it.first << ' '
             << it.second << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        help_message();
        return 0;
    }
    //////////// read the input file /////////////

    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2], ios::out);
    int size;
    fin >> size;
    int i, j;
    int *chord = new int[size];
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
    /*for (int i = 0; i < size - 1; i++)
    {
        if (table[i][size - 1] - table[i + 1][size - 1] > 0)
            fout << i << " " << chord[i] << endl;
    }*/
    map<int, int> chordset;
    CHORD_OF_MPS(table, chord, 0, size, chordset);
    sort(chordset,fout);
    fin.close();
    fout.close();
    return 0;
}
///////////////construct the table///////////////////////////
int **MAXIMUM_PLANAR_SUBSET(int *chord, int n)
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
void CHORD_OF_MPS(int **M, int *chord, int start, int end, map<int, int> &chordset)
{
    if (start == end)
        return;
    int i = start;
    int j = end - 1;
    while (j != i)
    {
        if (M[i][j] - M[i][j - 1] > 0)
        {
            CHORD_OF_MPS(M, chord, i, chord[j], chordset);
            CHORD_OF_MPS(M, chord, chord[j] + 1, j, chordset);
            //cout << chord[j] << " " << j << endl;
            chordset[chord[j]] = j;
            break;
        }
        else
            j--;
    }
    return;
}
// Comparison function for sorting the
// set by increasing order of its pair's
// second value
