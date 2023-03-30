#include "mylib.h"


struct studentukas{
    string vardas, pavarde; 
    vector<int> pazymiukai; //struktura objektams saugoti
    int egzas;
}; 

void pildyk(studentukas &temp);
float galutinisVID(studentukas &temp);
float galutinisMed(studentukas &temp);
bool sortPavarde(studentukas& a, studentukas& b);
bool sortVardas(studentukas&a, studentukas&b);
void spausdinimas(studentukas &temp);
void skaitymas(string read_studentukas, vector<studentukas>& stud); 
void fileGen(string& filename);
void rasymas(string write_studentukas, vector<studentukas>& stud);
string randName();
string randSur();

void skirstymas(string filename);

class RandInt{
    public:
    RandInt(int low,int high): mt{rd()},dist{low,high}{}
    int operator()(){return dist(mt);}
    private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> dist;
};