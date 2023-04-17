#include "mylib.h"

void pildyk(studentukas &temp);
float galutinisVID(studentukas &temp);
float galutinisMed(studentukas &temp);
void spausdinimas(studentukas &temp);
void skaitymas(string read_studentukas, deque<studentukas>& stud); 
void fileGen(string& filename);
void rasymas(string write_studentukas, deque<studentukas>& stud);
string randName();
string randSur();
void skirstymas(string filename);
