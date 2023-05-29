#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "fun.h"

TEST_CASE("Failų generavimo testavimas", "[fileGen]") {

    string pavadinimas = "test_output.txt";
  
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
}


TEST_CASE("Rašymo į failą testavimas") {
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

TEST_CASE("Rule of Five - studentukas class") {
    // Test case 1: Copy constructor
    SECTION("Copy constructor") {
        studentukas obj1("Studentas", "Studentaitis", {5, 4, 10}, 10);
        studentukas obj2(obj1);

        std::cout << "Copy constructor:\n";
        std::cout << "obj1: " << obj1 << "\n";
        std::cout << "obj2: " << obj2 << "\n";

        REQUIRE(obj1.getVardas() == obj2.getVardas());
        REQUIRE(obj1.getPavarde() == obj2.getPavarde());
        REQUIRE(obj1.getPazymiai() == obj2.getPazymiai());
        REQUIRE(obj1.getEgzas() == obj2.getEgzas());
    }

    // Test case 2: Copy assignment operator
    SECTION("Copy assignment operator") {
        studentukas obj1("Studentas", "Studentaitis", {5, 4, 10}, 10);
        studentukas obj2;
        obj2 = obj1;

        std::cout << "Copy assignment operator:\n";
        std::cout << "obj1: " << obj1 << "\n";
        std::cout << "obj2: " << obj2 << "\n";

        REQUIRE(obj1.getVardas() == obj2.getVardas());
        REQUIRE(obj1.getPavarde() == obj2.getPavarde());
        REQUIRE(obj1.getPazymiai() == obj2.getPazymiai());
        REQUIRE(obj1.getEgzas() == obj2.getEgzas());
    }

    // Test case 3: Move constructor
    SECTION("Move constructor") {
        studentukas obj1("Studentas", "Studentaitis", {5, 4, 10}, 10);
        studentukas obj2(std::move(obj1));

        std::cout << "Move constructor:\n";
        std::cout << "obj1: " << obj1 << "\n";
        std::cout << "obj2: " << obj2 << "\n";

        REQUIRE(obj1.getVardas().empty());
        REQUIRE(obj1.getPavarde().empty());
        REQUIRE(obj1.getPazymiai().empty());
        REQUIRE(obj1.getEgzas() == 0);

        REQUIRE(obj2.getVardas() == "Studentas");
        REQUIRE(obj2.getPavarde() == "Studentaitis");
        REQUIRE(obj2.getPazymiai() == std::vector<int>({5, 4, 10}));
        REQUIRE(obj2.getEgzas() == 10);
    }

    // Test case 4: Move assignment operator
    SECTION("Move assignment operator") {
        studentukas obj1("Studentas", "Studentaitis", {5, 4, 10}, 10);
        studentukas obj2;
        obj2 = std::move(obj1);

        std::cout << "Move assignment operator:\n";
        std::cout << "obj1: " << obj1 << "\n";
        std::cout << "obj2: " << obj2 << "\n";

        REQUIRE(obj1.getVardas().empty());
        REQUIRE(obj1.getPavarde().empty());
        REQUIRE(obj1.getPazymiai().empty());
        REQUIRE(obj1.getEgzas() == 0);

        REQUIRE(obj2.getVardas() == "Studentas");
        REQUIRE(obj2.getPavarde() == "Studentaitis");
        REQUIRE(obj2.getPazymiai() == std::vector<int>({5, 4, 10}));
        REQUIRE(obj2.getEgzas() == 10);
    }
}

class TestClass : public zmogus {
public:
    using zmogus::zmogus; 

    void setVardas(string v) override {
        vardas = v;
    }

    void setPavarde(string p) override {
        pavarde = p;
    }
};

TEST_CASE("zmogus Abstract Class") {
    SECTION("Constructor and Getters") {
        TestClass obj("Studentas", "Studentaitis");
        cout<<"Vardas: "<<obj.getVardas()<<endl;
        cout<<"Pavardė: "<<obj.getPavarde()<<endl;

        REQUIRE(obj.getVardas() == "Studentas");
        REQUIRE(obj.getPavarde() == "Studentaitis");
    }

    SECTION("Setters") {
        TestClass obj;

        obj.setVardas("Studentas");
        obj.setPavarde("Studentaitis");
        cout<<"Vardas: "<<obj.getVardas()<<endl;
        cout<<"Pavardė: "<<obj.getPavarde()<<endl; 

        REQUIRE(obj.getVardas() == "Studentas");
        REQUIRE(obj.getPavarde() == "Studentaitis");
    }
}