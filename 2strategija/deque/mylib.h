#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <time.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <omp.h>
#include<random>
#include<locale.h>
#include <clocale>
#include<deque>
#include <execution>
#include<list>
#include<Windows.h>
using std::wcout;
using std::setlocale;
using std::partition;
using std::exit;
using std::list;
using std::deque;
using std::move;
using std::cout;
using std::cin;
using std::ios;
using std::endl;
using std::setlocale;
using std::back_inserter;
using std::left;
using std::right;
using std::setw;
using std::copy;
using std::setprecision;
using std::string;
using std::flush;
using std::sort;
using std::vector;
using std::getline;
using std::fixed;
using std::stringstream;
using std::runtime_error;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::istringstream;
using std::move;
struct studentukas{
    string vardas, pavarde; 
    deque<int> pazymiukai; //struktura objektams saugoti
    int egzas;
};
class RandInt{
    public:
    RandInt(int low,int high): mt{rd()},dist{low,high}{}
    int operator()(){return dist(mt);}
    private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> dist;
};
