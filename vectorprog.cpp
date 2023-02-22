#include "mylib.h"

string ats;//kintamasis gauti input validation

struct studentukas{
    string vardas, pavarde; 
    vector<int> pazymiukai; //struktura objektams saugoti
    int egzas;
};

void pildyk(studentukas &temp)//funkcija pildyti studentuko duomenis
{
    cout<<"Iveskite varda ir pavarde: ";//vartotojas iveda savo varda pavarde
    cin>>temp.vardas>>temp.pavarde;
    
    while((ats!="r")&&( ats!="a"))//uzklausa kokiu budu vartotojas nori irasyti pazymius, jeigu atsako nei a nei r-prasoma is naujo
    {
        cout<<"Rankinis ivedimas ar atsitiktiniai skaiciai?(r/a)";
        cin>>ats;  
    }

    if (ats=="r")//kai ivedama raide r
        {  
        int x=0;//x pazymiui
        cout<<"Iveskite pazymius(0-10): ";
        
        while(cin>>x)//kol skaiciai irasomi
        {
            if(x<=10 && x>=0)
            {
                temp.pazymiukai.push_back(x);//jeigu x maz/lygus nei 10 ir did/lygus 1 tai issaugoma
                 
            }
            else{
                cout<<"Iveskite skaiciu nuo 0 iki 10"<<endl;//jeigu ne tai prasoma ivesti skaiciu vel
            }
            
        } 
        cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        cout<<"Iveskite egzamino pazymi(0-10): ";
        while(cin>>temp.egzas)
        {
            if((temp.egzas>=0)&&(temp.egzas<=10))
            {
            break;
            }
            else
            {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"Iveskite skaiciu nuo 0 iki 10"<<endl; 
            }
      }
        }

    else if(ats=="a")//jeigu vartotojas renkasi atsitiktini vykdomass sis kodas
    {
        int size=0;
        srand(time(NULL));
        cout<<"Kiek nd pazymiu norite tureti?";
        cin>>size;
        while(cin.fail() ||size<1)//jeigu irasomas 0 ar kitas netinkamas simbolis vykdomas sis kodas
        {
            cout<<"Neteisinga ivestis, reikia teigiamo skaiciaus: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin>>size;
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
        
      
    
float vidurkis(studentukas &temp)//vidurkio skaiciavimo kodas
{
  float sum=0;
  float avg=0;
  if(temp.pazymiukai.size()>0)
  {
     for(int i=0;i<temp.pazymiukai.size();i++)
    {
        sum+=temp.pazymiukai[i];
    }
    avg=(((float)sum)/(temp.pazymiukai.size())); 
    return avg;
  }
  else{
    avg=0;
    return 0;
  }
   
}

float mediana(studentukas &temp){//medianos skaiciavimas 
    
    float mediana=0;
    sort(temp.pazymiukai.begin(),temp.pazymiukai.end());
    if(temp.pazymiukai.empty())
    {
        mediana=0;
        return mediana;
    }
    else
    {
        if(temp.pazymiukai.size()%2==0)
        {
        mediana=((float)(temp.pazymiukai[(temp.pazymiukai.size()/2.0)-1]+temp.pazymiukai[temp.pazymiukai.size()/2.0])/2.0);
        return mediana;
        }
        else {
        mediana=((float)temp.pazymiukai[temp.pazymiukai.size()/2.0]);
        return mediana;
        }
    }

}

float galutinisVID(studentukas &temp)//galutinio su vidurkiu skaiciavimas
{
    return ((0.4*vidurkis(temp))+(0.6*temp.egzas));
} 

float galutinisMed(studentukas &temp)//galutinio su mediana skaiciavimas
{
    return ((0.4*mediana(temp))+(0.6*temp.egzas)); 
}

void spausdinimas(studentukas &temp)//duomenu spausdinimui vartotojas turi pasirinkti isvedimo forma 
{
    cout<<"Galutinis su vidurkiu, mediana ar abu?(v/m/a)";
    cin>>ats;
    while(ats!="v"&& ats!="m"&& ats!="a")
   {
    cout<<"Iveskite v arba m arba a: "<<endl;
    cin>>ats; 
   }
    
    if(ats=="v")
    {cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis(vid)"<<endl;
    cout<<setw(20)<<"---------------"<<setw(20)<<"---------------"<<setw(20)<<"---------------"<<endl;
    cout<<setw(20)<<left<<temp.vardas<<setw(20)<<left<<temp.pavarde; 
    cout<<setw(20)<<fixed<<setprecision(2)<<galutinisVID(temp)<<endl;
    }
    else if(ats=="m")
    {
        cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis(med)"<<endl;
        cout<<setw(20)<<"---------------"<<setw(20)<<"---------------"<<setw(20)<<"---------------"<<endl;
        cout<<setw(20)<<left<<temp.vardas<<setw(20)<<left<<temp.pavarde; 
        cout<<setw(20)<<fixed<<setprecision(2)<<galutinisMed(temp)<<endl;

    }
    else if(ats=="a")
    {
        cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis(vid)"<<setw(20)<<left<<"Galutinis(med)"<<endl;
        cout<<setw(20)<<"---------------"<<setw(20)<<"---------------"<<setw(20)<<"---------------"<<setw(20)<<"---------------"<<endl;
        cout<<setw(20)<<left<<temp.vardas<<setw(20)<<left<<temp.pavarde; 
        cout<<setw(20)<<fixed<<setprecision(2)<<galutinisVID(temp)<<setprecision(2)<<galutinisMed(temp)<<endl;
    
    }
    
}

int main()
{ 
    vector<studentukas> mas;
    studentukas laikinas;
    int k=0;
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
