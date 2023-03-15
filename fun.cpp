#include "mylib.h"

struct studentukas{
    string vardas, pavarde; 
    vector<int> pazymiukai; //struktura objektams saugoti
    int egzas;
};
string randName()
{
    int nameIn=rand()%5;
    string names[5]= {"Perkunija", "Gojus", "Elektra", "Dziugimantas", "Lyja"};
    return names[nameIn];
}
string randSur()
{
    int surIn=rand()%5;
    string surn[5]= {"Romero", "Garcia", "Moro", "Petersas", "Lehmann"};
    return surn[surIn];
}

void pildyk(studentukas &temp)//funkcija pildyti studentuko duomenis
{
    string ats;

    while((ats!="r")&&( ats!="a"))//uzklausa kokiu budu vartotojas nori irasyti pazymius, jeigu atsako nei a nei r-prasoma is naujo
    {
        cout<<"Rankinis ivedimas ar atsitiktiniai skaiciai?(r/a)";
        cin>>ats;  
    }

    if (ats=="r")//kai ivedama raide r
        {  
        cout<<"Iveskite varda ir pavarde: ";//vartotojas iveda savo varda pavarde
        cin>>temp.vardas>>temp.pavarde;
        int x=0;//x pazymiui
        cout<<"Iveskite pazymius(0-10): ";
        while(cin>>x)//kol skaiciai irasomi
        {
            if(x<=10 && x>=0){
            temp.pazymiukai.push_back(x);//jeigu x maz/lygus nei 10 ir did/lygus 0 tai issaugoma 
            }
            else{
            cout<<"Iveskite skaiciu nuo 0 iki 10"<<endl;//jeigu ne tai prasoma ivesti skaiciu vel
            } 
        } 
        cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        cout<<"Iveskite egzamino pazymi(0-10): ";
        while(true)
        {
            try//exception handling 1
            {
               cin>>temp.egzas;
               if(cin.fail()||(temp.egzas<0)||(temp.egzas>10))
               {
                throw"Iveskite skaiciu nuo 0 iki 10";
               }
               break;
            }
            catch(const char* emsg)
            {
                cout<<emsg<<endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
        }
        }
        else if(ats=="a")//jeigu vartotojas renkasi atsitiktini vykdomass sis kodas
        {
        srand(time(NULL));    
        int size=0;
        temp.vardas=randName();
        temp.pavarde=randSur(); 
        cout<<"Kiek nd pazymiu norite tureti?";
       while(true)
       {
        try//exception handling 1
        {  
            cin>>size;
            if(cin.fail() ||size<1)//jeigu  netinkamas simbolis vykdomas sis kodas
            {
            throw "Neteisinga ivestis, reikia teigiamo skaiciaus: ";
            }
            break;
           
        }
        catch(const char* msg)     
        {
            cout<<msg<<endl;
            cin.clear();
            cin.ignore(256,'\n');
        }
       }
        cout<<"Nd pazymiai: ";
        while(size>0)
        {
            int n=(rand()%10)+1;
            cout<<n<<" ";
            temp.pazymiukai.push_back(n);
            size--; 
        }
        cout<<endl;
        cout<<"Atsitiktinis egzamino pazymys: ";
        int m=(rand()%10)+1;
        cout<<m<<endl;
        temp.egzas=m;
    }  
}


float galutinisVID(studentukas &temp)//vidurkio skaiciavimo kodas
{
  float sum=0,avg=0;
    if(temp.pazymiukai.size()>0)
        {
            for(int i=0;i<temp.pazymiukai.size();i++)
            {
             sum+=temp.pazymiukai[i];
            }
            avg=((float)sum)/(temp.pazymiukai.size());   
        } 
    return ((0.4*avg)+(0.6*temp.egzas));
}

float galutinisMed(studentukas &temp)//medianos skaiciavimas  
{   
    float mediana=0;
    sort(temp.pazymiukai.begin(),temp.pazymiukai.end());
   
    if(temp.pazymiukai.size()%2==0)
        {
        mediana=((float)(temp.pazymiukai[(temp.pazymiukai.size()/2.0)-1]+temp.pazymiukai[temp.pazymiukai.size()/2.0])/2.0);
        }
        else 
        {
        mediana=((float)temp.pazymiukai[temp.pazymiukai.size()/2.0]);
        } 
    return ((0.4*mediana)+(0.6*temp.egzas));
}   
   
bool sortGal(studentukas& a, studentukas& b)
{
    return galutinisVID(a)<galutinisVID(b);
}
bool sortPavarde(studentukas& a, studentukas& b)
{
    return a.pavarde<b.pavarde;
}
bool sortVardas(studentukas&a, studentukas&b)
{
    return a.vardas<b.vardas;
}
void spausdinimas(studentukas &temp)//duomenu spausdinimui 
{
try//exception handling 2
{
    cout<<setw(30)<<left<<temp.vardas<<setw(30)<<left<<temp.pavarde; 
    if(temp.pazymiukai.empty())
    {  
     throw runtime_error("--------------Truksta nd pazymiu---------------");
    }
    else{
        cout<<setw(30)<<fixed<<setprecision(2)<<galutinisVID(temp)<<setw(30)<<fixed<<setprecision(2)<<galutinisMed(temp)<<endl;
    }
}catch(const runtime_error& e)
{
    cerr<<e.what()<<endl;
}
        
}

 void skaitymas(string read_studentukas,vector<studentukas>&stud)
{
    auto start = std::chrono::high_resolution_clock::now();
    studentukas laik;
    string line;
    bool first_line=true;
    stud.reserve(1000000);
    ifstream open_f(read_studentukas);
     if(!open_f.is_open())
    {
        cerr<<"Nepavyko nuskaityti failo: "<<read_studentukas<<endl;
        while(!open_f.is_open())
        {
            cout<<"Irasykite dar karta: ";
            cin>>read_studentukas;
            open_f.open(read_studentukas);
        }
    }
          while(getline(open_f,line))
          {
            if(first_line)
            {
                first_line=false;
                continue;
            }
            istringstream iss(line);
            iss>>laik.vardas>>laik.pavarde;
            int paz;
            while(iss>>paz)
            {
                laik.pazymiukai.push_back(paz);
            }
            laik.egzas=laik.pazymiukai.back();
            laik.pazymiukai.pop_back();
            stud.push_back(laik);
            laik.pazymiukai.clear();
            laik.egzas=0;
    }
    open_f.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    cout <<"duomenu nuskaitymas is failo uztruko: " << difference.count() << " s\n";
    string ats;
/*     while(ats!="v"&&ats!="p"&&ats!="g")
    {
        cout<<"Rusiuoti pagal varda,pavarde ar galutini(vid)?(v/p/g) ";
        cin>>ats;
    } 
    if(ats=="v")
    { 
        sort(stud.begin(),stud.end(),sortVardas);
    }
  
     else if(ats=="p")
    {
        sort(stud.begin(),stud.end(),sortPavarde);
    } 
    else{} */
        sort(stud.begin(),stud.end(),sortGal);
    
}
/* void rasymas(string write_studentukas, vector<studentukas>& stud)
{
    ofstream out(write_studentukas);
    cout<<"Apdorojami duomenys...\n";
    out<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis(vid)"<<endl;
    out<<setw(20)<<"---------------------------------------------------------------------------"<<endl; 
   
    for(auto& laik: stud)
    {
    out<<setw(20)<<left<<laik.vardas<<setw(20)<<left<<laik.pavarde;  
    out<<setw(20)<<left<<fixed<<setprecision(2)<<galutinisVID(laik)<<endl; 
    }
   
    for(auto& i: stud)
    {
        i.pazymiukai.clear();
        i.pazymiukai.shrink_to_fit();
    }
    stud.clear();
    stud.shrink_to_fit();
    out.close() ; 
} 
 */
void rasymas(string write_studentukas, vector<studentukas>& stud) {
    ofstream out(write_studentukas);
    cout << "Apdorojami duomenys...\n";
    out<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis(vid)"<<endl;
    out<<setw(20)<<"---------------------------------------------------------------------------"<<endl; 
   

    char eilute[60];
    for (auto& laik : stud) {
       /*  memset(buffer, 0, sizeof(buffer)); */
        sprintf(eilute, "%-20s%-20s%-.2f\n", laik.vardas.c_str(), laik.pavarde.c_str(), galutinisVID(laik));
        out<<eilute;
    }

    out.close();
}


void fileGen(string& filename)
{
    int size,filesize; 
    cout<<"Kiek irasu? ";
    cin>>filesize;
    cout<<"Kiek pazymiu? ";
    cin>>size;

    auto start = std::chrono::high_resolution_clock::now();
    ofstream fin(filename);

    fin<<left<<setw(15)<<"Vardas"<<setw(15)<<right<<"Pavarde";
    for(int i=1;i<=size;i++)
    {
        fin<<setw(7)<<"ND"<<i; 
    }        
    fin<<setw(7)<<"Egz."<<endl;
    srand(time(NULL));
    for(int i=1;i<=filesize;i++)
    {   stringstream output;
        string name=randName();
        string surname=randSur();

        output<<left<<setw(15)<<name<<setw(15)<<right<<surname;
        
        for(int j=1;j<=size;j++)
        {
            int r=(rand()%10)+1;
            output<<right<<setw(8)<<r; 
        }
        int m=(rand()%10)+1;
        output<<right<<setw(7)<< m<<endl;
        fin<<output.str();
    }
    fin.close();
    auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference = end - start;
        cout <<filesize<< " irasu generavimas uztruko: " << difference.count() << " s\n";
}

void skirstymas(string filename)
{
    auto start = std::chrono::high_resolution_clock::now();
    vector<studentukas> stud;
    skaitymas(filename,stud);
    
    vector<studentukas> vargseliai;
    vector<studentukas> saunuoliai;
    vargseliai.reserve(stud.size());
    saunuoliai.reserve(stud.size());
 
   for(auto& laik:stud)
    {
        if(galutinisVID(laik)<5.0)
        {
                vargseliai.push_back(laik);
        }
        else 
            {
               saunuoliai.push_back(laik); 
            }      
    }
     
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    cout << "Studentu skirstymas uztruko: " << difference.count() << " s\n";  

    start = std::chrono::high_resolution_clock::now();
    rasymas ("saunuoliai.txt",saunuoliai);
    rasymas ("vargseliai.txt",vargseliai);
    end = std::chrono::high_resolution_clock::now();
   difference = end - start;
   cout << "Rasymas uztruko: " << difference.count() << " s\n";  
  
}

