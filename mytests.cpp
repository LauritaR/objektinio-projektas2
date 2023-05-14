#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "fun.h"

TEST_CASE("File generation works correctly", "[fileGen]") {

    string pavadinimas = "test.txt";
  
    fileGen(pavadinimas);

    ifstream fin(pavadinimas);
    REQUIRE(fin.is_open());
    fin.close();

    ifstream fin2(pavadinimas);
    string line;
    getline(fin2, line);
    stringstream ss(line);
    string w;
    ss >> w;
    REQUIRE(w == "Vardas");
    ss >> w;
    REQUIRE(w == "Pavardė");
    for (int i = 1; i <= 5; i++) {
        ss >> w;
        REQUIRE(w == ("ND" + std::to_string(i)));
    }
    ss >> w;
    REQUIRE(w == "Egz.");

    for (int i = 1; i <= 10; i++) {
        getline(fin2, line);
        stringstream ss2(line);
        string vardas, pavarde;
        ss2 >> vardas >> pavarde;
        REQUIRE(vardas.length() <= 15);
        REQUIRE(pavarde.length() <= 15);
        for (int j = 1; j <= 5; j++) {
            int paz;
            ss2 >> paz;
            REQUIRE(paz >= 1);
            REQUIRE(paz <= 10);
        }
        int egz;
        ss2 >> egz;
        REQUIRE(egz >= 1);
        REQUIRE(egz <= 10);
    }
    fin2.close();

    remove(pavadinimas.c_str());
}


TEST_CASE("Testing rasymas function") {
    std::vector<studentukas> stud;
    stud.emplace_back("Richard", "Feynman", std::vector<int>{10, 9, 8, 7, 10},5); 
    std::ostringstream oss;
    rasymas("test.txt", stud);
    std::ifstream in("test.txt"); 
    oss << in.rdbuf(); 
    std::string output = oss.str(); 
    std::string expected = "Vardas              Pavardė            Galutinis(vid)      \n"
                           "---------------------------------------------------------------------------\n"
                           "Richard             Feynman             6.52\n"; 
    REQUIRE(output == expected); 
}