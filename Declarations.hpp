#ifndef DECLARATIONS_HPP
#define DECLARATIONS_HPP
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;

#undef max
inline int Exception(){
    int opt;
    try
    {
        cin >> opt;
        if (opt <= 0 || opt >= 5)
        {
            throw (opt);
        }
    }
    catch (int option)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid selection. Must be a number between 1-4.\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return opt;
}


#endif