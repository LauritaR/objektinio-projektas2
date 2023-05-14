#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "fun.h"

TEST_CASE("File generation works correctly", "[fileGen]") {

    string filename = "test.txt";
  
    fileGen(filename);

    ifstream fin(filename);
    REQUIRE(fin.is_open());
    fin.close();

    ifstream fin2(filename);
    string line;
    getline(fin2, line);
    stringstream ss(line);
    string word;
    ss >> word;
    REQUIRE(word == "Vardas");
    ss >> word;
    REQUIRE(word == "Pavardė");
    for (int i = 1; i <= 5; i++) {
        ss >> word;
        REQUIRE(word == ("ND" + std::to_string(i)));
    }
    ss >> word;
    REQUIRE(word == "Egz.");

    for (int i = 1; i <= 10; i++) {
        getline(fin2, line);
        stringstream ss2(line);
        string name, surname;
        ss2 >> name >> surname;
        REQUIRE(name.length() <= 15);
        REQUIRE(surname.length() <= 15);
        for (int j = 1; j <= 5; j++) {
            int grade;
            ss2 >> grade;
            REQUIRE(grade >= 1);
            REQUIRE(grade <= 10);
        }
        int egz;
        ss2 >> egz;
        REQUIRE(egz >= 1);
        REQUIRE(egz <= 10);
    }
    fin2.close();

    remove(filename.c_str());
}




TEST_CASE("Testing rasymas function") {
    std::vector<studentukas> stud;
    stud.emplace_back("Jonas", "Jonaitis", std::vector<int>{10, 9, 8, 7, 10},5); // add sample student
    std::ostringstream oss; // create output string stream
    rasymas("test.txt", stud); // call rasymas function with test data
    std::ifstream in("test.txt"); // open test file
    oss << in.rdbuf(); // read contents of file into output string stream
    std::string output = oss.str(); // get string from output string stream
    std::string expected = "Vardas              Pavardė            Galutinis(vid)      \n"
                           "---------------------------------------------------------------------------\n"
                           "Jonas               Jonaitis            6.52\n"; // define expected output
    REQUIRE(output == expected); // compare actual and expected output
}