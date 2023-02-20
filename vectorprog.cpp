#include "mylib.h"
string ats;


struct studentukas{
    string vardas, pavarde; 
    vector<int> pazymiukai; 
    int egzas;
};

void pildyk(studentukas &temp)
{
    cout<<"iveskite varda ir pavarde: ";
    cin>>temp.vardas>>temp.pavarde;
    
    while((ats!="r")&&( ats!="a"))
    {
        cout<<"Rankinis ivedimas ar atsitiktiniai skaiciai?(r/a)";
        cin>>ats;  
    }

    if (ats=="r")
        {  
            int x=0;
            int paz_sk=0; 
            cout<<"iveskite pazymius(1-10): ";
        
        while(cin>>x)
        {
            if(x<=10 && x>=1)
            {
                temp.pazymiukai.push_back(x);
                paz_sk++;
                 
            }
            else{
                cout<<"iveskite skaiciu nuo 1 iki 10"<<endl;
            }
            
        } 
        cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//

        cout<<"iveskite egzamino pazymi(1-10): ";
        while(cin>>temp.egzas)
        {
            if((temp.egzas>=1)&&(temp.egzas<=10))
            {
            break;
            }
            else
            {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"iveskite skaiciu nuo 1 iki 10"<<endl; 
            }
      }
        }

    else if(ats=="a")
    {
        int size=0;
        srand(time(NULL));
        cout<<"kiek nd pazymiu norite tureti?";
        cin>>size;
        cout<<"Nd pazymiai: ";
         while(size>0)
        {
            int n=(rand()%10)+1;
            cout<<n<<" ";
            temp.pazymiukai.push_back(n);
            size--; 
        }
        cout<<endl;
        cout<<"atsitiktinis egzo pazymys: ";
        int m=(rand()%10)+1;
        cout<<m<<endl;
        temp.egzas=m;
    }
}
        
      
    
float vidurkis(studentukas &temp)
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

float mediana(studentukas &temp){
    
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

float galutinisVID(studentukas &temp)
{
    return ((0.4*vidurkis(temp))+(0.6*temp.egzas));
} 

float galutinisMed(studentukas &temp)
{
    return ((0.4*mediana(temp))+(0.6*temp.egzas)); 
}

void spausdinimas(studentukas &temp)
{
    cout<<"Galutinis su vidurkiu, mediana ar abu?(v/m/a)";
    cin>>ats;
    while(ats!="v"&& ats!="m"&& ats!="a")
   {
    cout<<"iveskite v arba m arba a: "<<endl;
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

    char kart; 
    int k=0;
    do{
        pildyk(laikinas);
        mas.push_back(laikinas);
        laikinas.pazymiukai.clear();
        cout<<"Ar norite ivesti informacija apie kitus studentus?(t/n)?";
        cin>>kart;
        while((ats!="t")&&(ats!="n"))
    {
        cout<<"t-prideti dar studenta, n-baigti ivedima"<<endl;
        cin>>ats;
    }
       
    }while(kart=='t');

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
