#include "mylib.h"

string randName()
{
    SetConsoleOutputCP(CP_UTF8);
    RandInt rnd(0,4);
    string names[5]= {"Perkunija", "Gojus", "Elektra", "Dziugimantas", "Lyja"};
    return names[rnd()];
}
string randSur()
{
    RandInt rnd(0,4);
    string surn[5]= {"Romero", "Garcia", "Moro", "Petersas", "Lehmann"};
    return surn[rnd()];
}

void pildyk(studentukas &temp)//funkcija pildyti studentuko duomenis
{
    SetConsoleOutputCP(CP_UTF8);
    string ats="";

    while((ats!="r")&&( ats!="a"))//uzklausa kokiu budu vartotojas nori irasyti pazymius, jeigu atsako nei a nei r-prasoma is naujo
    {
        cout<<"Rankinis įvedimas ar atsitiktiniai skaičiai?(r/a)";
        cin>>ats;  
    }

    if (ats=="r")//kai ivedama raide r
        {  
        cout<<"Įveskite vardą ir pavardę: ";//vartotojas iveda savo varda pavarde
        cin>>temp.vardas>>temp.pavarde;
        int x=0;//x pazymiui
        cout<<"Įveskite pažymius(0-10): ";
        while(cin>>x)//kol skaiciai irasomi
        {
            if(x<=10 && x>=0){
            temp.pazymiukai.push_back(x);//jeigu x maz/lygus nei 10 ir did/lygus 0 tai issaugoma 
            }
            else{
            cout<<"Įveskite skaičių nuo 0 iki 10"<<endl;//jeigu ne tai prasoma ivesti skaiciu vel
            } 
        } 
        cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        cout<<"Įveskite egzamino pažymį(0-10): ";
        while(true)
        {
            try//exception handling 1
            {
               cin>>temp.egzas;
               if(cin.fail()||(temp.egzas<0)||(temp.egzas>10))
               {
                throw"Įveskite skaičių nuo 0 iki 10";
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
        cout<<"Kiek namų darbų pažymių norite turėti?";
        while(true)
       {
        try//exception handling 1
        {  
            cin>>size;
            if(cin.fail() ||size<1)//jeigu  netinkamas simbolis vykdomas sis kodas
            {
            throw "Neteisinga įvestis, reikia teigiamo skaičiaus: ";
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
        cout<<"Namų darbų pažymiai: ";
        RandInt rnd(1,10);
        while(size>0)
        {
            int n=rnd();
            cout<<n<<" ";
            temp.pazymiukai.push_back(n);
            size--; 
        }
        cout<<endl;
        cout<<"Atsitiktinis egzamino pažymys: ";
        int m=rnd();
        cout<<m<<endl;
        temp.egzas=m;
    }  
}


float galutinisVID(studentukas &temp)//vidurkio skaiciavimo kodas
{
  float sum=0,avg=0;
    if(temp.pazymiukai.size()>0)
        {
            for(auto const& paz: temp.pazymiukai)
            {
             sum+=paz;
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

void spausdinimas(studentukas &temp)//duomenu spausdinimui 
{ 
    SetConsoleOutputCP(CP_UTF8);
try//exception handling 2
{
    cout<<setw(30)<<left<<temp.vardas<<setw(30)<<left<<temp.pavarde; 
    if(temp.pazymiukai.empty())
    {  
     throw runtime_error("--------------Trūksta namų darbų pažymių---------------");
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
    
    SetConsoleOutputCP(CP_UTF8);
    auto start = std::chrono::high_resolution_clock::now();
    
    studentukas laik;
    stringstream buff;
    ifstream open_f;
    string header;
    
    open_f.open(read_studentukas);

    if (!open_f)
    {
        cerr << "Nepavyko nuskaityti failo: " << read_studentukas << endl;
        while (!open_f)
        {
            cout << "Įrašykite dar kartą: ";
            cin >> read_studentukas;
            open_f.open(read_studentukas);
        }
    }
    else
    {
        {
            buff<<open_f.rdbuf();
            open_f.close();

            getline(buff, header);
            int cnt = count(header.begin(), header.end(), 'N'); 
            while (buff)
            {
                for(int i=0;i<cnt;i++)
                {
                    laik.pazymiukai.clear();
                    buff >> laik.vardas;
                    buff >> laik.pavarde;
                    int paz;
                    for (int j = 0; j < cnt; j++)
                    {
                        buff >> paz;
                        laik.pazymiukai.push_back(paz);
                    }  
                   
                    buff >>laik.egzas ;
                    stud.push_back(laik);
                }
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    cout <<"Duomenų nuskaitymas iš failo užtruko: " << difference.count() << " s\n";
    string ats;
    start = std::chrono::high_resolution_clock::now();
    sort(stud.begin(),stud.end(),[](studentukas& a,studentukas& b){
        return galutinisVID(a)<galutinisVID(b);
    });
    end = std::chrono::high_resolution_clock::now();
    difference = end - start;
    cout << "Rūšiavimas užtruko:  " << difference.count() << " s\n";
}

void rasymas(string write_studentukas, vector<studentukas>& stud) {
     SetConsoleOutputCP(CP_UTF8);
    ofstream out(write_studentukas);
    out<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavardė"<<setw(20)<<left<<"Galutinis(vid)"<<endl;
    out<<setw(20)<<"---------------------------------------------------------------------------"<<endl; 
   
    char eilute[60];
    for (auto& laik : stud) {
        sprintf(eilute, "%-20s%-20s%-.2f\n", laik.vardas.c_str(), laik.pavarde.c_str(), galutinisVID(laik));
        out<<eilute;
    }

    out.close();
}


void fileGen(string& filename)
{   SetConsoleOutputCP(CP_UTF8);
    RandInt rnd(1,10);
    int size,filesize; 
    cout<<"Kiek įrašų? ";
    cin>>filesize;
    cout<<"Kiek pažymių? ";
    cin>>size;

    auto start = std::chrono::high_resolution_clock::now();
    ofstream fin(filename);

    fin<<left<<setw(15)<<"Vardas"<<setw(15)<<right<<"Pavardė";
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
            int r=rnd();
            output<<right<<setw(8)<<r; 
        }
        int m=rnd();
        output<<right<<setw(7)<< m<<endl;
        fin<<output.str();
    }
    fin.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    cout <<filesize<< "Įrašų generavimas užtruko: " << difference.count() << " s\n";
}

void skirstymas(string filename)
{
    SetConsoleOutputCP(CP_UTF8);
    vector<studentukas> stud;
    skaitymas(filename,stud);

    auto start = std::chrono::high_resolution_clock::now();

    auto vargseliai_iter= partition(stud.begin(),stud.end(), 
    []( studentukas& s){return galutinisVID(s)<5.0;});
    vector<studentukas> vargseliai(stud.begin(),vargseliai_iter);
    stud.erase(stud.begin(),vargseliai_iter);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    cout << "Studentų skirstymas užtruko: " << difference.count() << " s\n";  

    start = std::chrono::high_resolution_clock::now();
  
    rasymas ("vargseliai.txt",vargseliai);
    rasymas ("saunuoliai.txt",stud);
    
    end = std::chrono::high_resolution_clock::now();
    difference = end - start;
    cout <<"Įrašų rašymas užtruko: " << difference.count() << " s\n";
}

