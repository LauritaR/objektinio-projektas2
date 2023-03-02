#include "mylib.h"

struct studentukas{
    string vardas, pavarde; 
    vector<int> pazymiukai; //struktura objektams saugoti
    int egzas;
};

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
        int size=0,vardasIRpav=(rand()%5)+1;
        switch (vardasIRpav)
        {
        case 1:
            temp.vardas="Perkunija";temp.pavarde="Romero ";
            break;
        case 2: 
            temp.vardas="Gojus";temp.pavarde="Garcia ";
            break;
        case 3:
            temp.vardas="Elektra";temp.pavarde="Moro ";
            break;
        case 4:
            temp.vardas="Dziugimantas";temp.pavarde="Petersas ";
            break;
        case 5: 
            temp.vardas="Lyja";temp.pavarde="Lehmann ";
            break;
        default:
            break;
        }
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

void skaitymas(string read_studentukas, string write_studentukas)
{
    vector<studentukas> stud;
    studentukas laik;
    string line,ats;
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
    while(open_f)
    {
        
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
          
    }
    open_f.close();   
  while(ats!="v"&&ats!="p")
    {
        cout<<"Rusiuoti pagal varda ar pavarde?(v/p) ";
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
 
    ofstream out(write_studentukas);
    cout<<"Apdorojami duomenys...";
    out<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis(vid)"<<setw(20)<<left<<"Galutinis(med)"<<endl;
    out<<setw(20)<<"---------------------------------------------------------------------------"<<endl; 

    for(auto& laik: stud)
    {
    out<<setw(20)<<left<<laik.vardas<<setw(20)<<left<<laik.pavarde;  
    out<<setw(20)<<left<<fixed<<setprecision(2)<<galutinisVID(laik)<<setw(20)<<left<<fixed<<setprecision(2)<<galutinisMed(laik)<<endl; 
    }
    for(auto& i: stud)
    {
        i.pazymiukai.clear();
    }
    stud.clear();
    out.close() ;  
}

int main()
{ 
    
    vector<studentukas> mas;
    studentukas laikinas;
    string pavadinimas,ats;
    while(ats!="f"&&ats!="i")
    {
        cout<<"duomenu ivedimas ranka(i) ar nuskaitymas is failo(f)?(i/f)";
        cin>>ats; 
    }
    if(ats=="f")
    {
        cout<<"Irasykite failo pavadinima: ";
        cin>>pavadinimas;
        skaitymas(pavadinimas,"output.txt");  
        
        cout<<"\nStudentu duomenys sekmingai isvesti i faila 'output.txt'";
    }
    else if(ats=="i")
    {
       do{
        pildyk(laikinas);
        mas.push_back(laikinas);
        laikinas.pazymiukai.clear();
        
        while((ats!="t")&&(ats!="n"))
        {
        cout<<"Ar norite ivesti informacija apie kitus studentus?(t/n)?";
        cout<<"t-prideti dar studenta, n-baigti ivedima"<<endl;
        cin>>ats;
        }
    }while(ats=="t");

    cout<<setw(30)<<left<<"Vardas"<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Galutinis(vid)"<<setw(30)<<left<<"Galutinis(med)"<<endl;
    cout<<setw(20)<<"-----------------------------------------------------------------------------------------------------------"<<endl; 
    for(auto &i: mas)
    {
        spausdinimas(i); 
    }
   for(auto &i: mas) 
   {
      i.pazymiukai.clear();
   }
   mas.clear();   
}

return 0;
}
