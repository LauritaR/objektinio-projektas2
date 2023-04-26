#include "mylib.h"

class studentukas{

    private:
    string vardas, pavarde; 
    vector<int> pazymiukai; //struktura objektams saugoti
    int egzas;
    float galutinisVID()const//vidurkio skaiciavimo kodas
        {
            float sum=0,avg=0;
            if(pazymiukai.size()>0)
            {
                for(auto const& paz: pazymiukai)
            {
             sum+=paz;
            }
            avg=((float)sum)/(pazymiukai.size());   
        } 
            return ((0.4*avg)+(0.6*egzas));
        }

    float galutinisMed()const//medianos skaiciavimas  
    {   
        float mediana=0;
        vector<int> sorted_paz(pazymiukai);

        sort(sorted_paz.begin(),sorted_paz.end());
    
        if(sorted_paz.size()%2==0)
            {
            mediana=((float)(sorted_paz[(sorted_paz.size()/2.0)-1]+sorted_paz[sorted_paz.size()/2.0])/2.0);
            }
            else 
            {
            mediana=((float)sorted_paz[sorted_paz.size()/2.0]);
            } 
        return ((0.4*mediana)+(0.6*egzas));
    }   
    public:

    studentukas():vardas(""),pavarde(""),egzas(0){}
    //getters
    inline string getVardas() const{return vardas;}
    inline string getPavarde() const{return pavarde;}
    inline vector<int> getPazymiai() const{return pazymiukai;}
    inline int getEgzas() const{return egzas;}  
    inline float getGalutinisVID() const{return galutinisVID();}
    inline float getGalutinisMED() const{return galutinisMed();} 
    bool tuscias(){ return pazymiukai.empty();} 
    //setters
    void setVardas(string v) { vardas = v; }
    void setPavarde(string p) { pavarde = p; }
    void setPazymiukai(int pz){ pazymiukai.push_back(pz);};
    void setEgzas(int e) { egzas = e; }
    void lasivinamaVieta(){pazymiukai.clear();}
 
    ~studentukas()
    {
        pazymiukai.clear();
    }
};

void pildyk(studentukas &temp);
void spausdinimas(studentukas &temp);
void skaitymas(string read_studentukas, vector<studentukas>& stud); 
void fileGen(string& filename);
void rasymas(string write_studentukas, vector<studentukas>& stud);
string randName();
string randSur();
void skirstymas(string filename);
