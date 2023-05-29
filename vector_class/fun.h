#include "mylib.h"

class zmogus{
    protected:
        string vardas, pavarde;
    public:
        zmogus(){}
        zmogus(string vardas, string pavarde): vardas(vardas), pavarde(pavarde){}
        virtual ~zmogus(){};
        virtual void setVardas(string v) =0;
        virtual void setPavarde(string p) =0;
        inline string getVardas() const{return vardas;}
        inline string getPavarde() const{return pavarde;} 
};

class studentukas:public zmogus{
    private:
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

    studentukas():zmogus{},egzas(0){}//default constructor
    studentukas(string vardas1, string pavarde1,vector<int> paz1, int egz1):zmogus{vardas1,pavarde1}, pazymiukai(std::move(paz1)), egzas(egz1){}
    //copy constructor
    studentukas(const studentukas& kitas): zmogus{kitas.vardas,kitas.pavarde}, pazymiukai(kitas.pazymiukai),egzas(kitas.egzas){}
    //copy assignment
    studentukas& operator=(const studentukas& kitas)
         {
        if (&kitas == this)
        return *this;

        vardas=kitas.vardas;
        pavarde=kitas.pavarde;
        pazymiukai=kitas.pazymiukai;
        egzas=kitas.egzas;
        return *this;
    }

    //move constructor
    studentukas(studentukas&& kitas): zmogus{std::move(kitas.vardas),std::move(kitas.pavarde)}, pazymiukai(std::move(kitas.pazymiukai)), egzas(kitas.egzas)
    {   kitas.vardas.clear();
        kitas.pavarde.clear();
        kitas.pazymiukai.clear();
        kitas.egzas=0;} 

    //move assigment 
    studentukas& operator=(const studentukas&& kitas)
        {
        if (&kitas == this)
        return *this;
        
        vardas = kitas.vardas;
        pavarde = kitas.pavarde;
        pazymiukai = kitas.pazymiukai;
        egzas = kitas.egzas;
        kitas.vardas.clear();
        kitas.pavarde.clear();
        kitas.pazymiukai.clear();
        kitas.egzas=0;
        return *this;
    }

    friend std::istream& operator>>(std::istream& in, studentukas& stud);
    friend std::ostream& operator<<(std::ostream & out,const studentukas& stud);
    //getters
    inline string getVardas() const{return vardas;}
    inline string getPavarde() const{return pavarde;}
       
    inline vector<int> getPazymiai() const{return pazymiukai;}
    inline int getEgzas() const{return egzas;}  
    inline float getGalutinisVID() const{return galutinisVID();}
    inline float getGalutinisMED() const{return galutinisMed();} 
    bool tuscias(){ return pazymiukai.empty();} 
    //setters
    void setVardas(string v) { vardas = v;}
    void setPavarde(string p) { pavarde = p;}
    void setPazymiukai(int pz){ pazymiukai.push_back(pz);};
    void setEgzas(int e) { egzas = e; }
    void laisvinamaVieta(){pazymiukai.clear();}
 
    ~studentukas()//destructor
    {
       vardas.clear();
       pavarde.clear();
       pazymiukai.clear();
       egzas=0;
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

