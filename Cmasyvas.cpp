#include "mylib.h"
string ats; 
int X=1;

struct studentukas
{
    string vardas= " ", pavarde= " "; 
    int *pazymiukai=nullptr; 
    int egzas=0;
    int paz_sk=0;
};

void pildyk(studentukas &temp)
{
    cout<<"Iveskite varda ir pavarde: ";
    cin>>temp.vardas>>temp.pavarde;

     while((ats!="r")&&( ats!="a"))
    {
        cout<<"Rankinis ivedimas ar atsitiktiniai skaiciai?(r/a)";
        cin>>ats;  
       
    }
    if(ats=="r")
    {
    cout<<"Iveskite pazymius(0-10)(iveskite simboli arba raide sustabdyti): ";
    int in=0, d=1, paz=0;//indeksas,dydis, pazymis
    int *pazymiuMasyvas=new int[d];
    
    while(cin>>paz)
    {
        if(d==1)
        {
            while(true)
            {
                if((paz>=0)&&(paz<=10))
                {
                pazymiuMasyvas[in]=paz;
                d++;
                int* naujasPazMasyvas= new int[d];
                copy(pazymiuMasyvas,pazymiuMasyvas+1,naujasPazMasyvas);
                delete[]pazymiuMasyvas;
                pazymiuMasyvas=naujasPazMasyvas;
                naujasPazMasyvas=NULL;
                break;
                }
                else
                { 
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Iveskite skaiciu nuo 0 iki 10"<<endl; 
                cin>>paz;
                }
            }
        }
        else
        {
            while(true)
            {
                if(paz>=0 && paz<=10)
                {
                    d++;
                    in++;
                    pazymiuMasyvas[in]=paz;
                    int* naujasPazMasyvas= new int[d];
                    copy(pazymiuMasyvas,pazymiuMasyvas+(d-1),naujasPazMasyvas);
                    delete[]pazymiuMasyvas;
                    pazymiuMasyvas=naujasPazMasyvas;
                    naujasPazMasyvas=NULL;
                    break; 
                }
                else
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    cout<<"Iveskite skaiciu nuo 0 iki 10"<<endl; 
                    cin>>paz;
                }
            }
        }
        
    }
    temp.pazymiukai=pazymiuMasyvas;
    temp.paz_sk=d-1;
    
    pazymiuMasyvas=NULL;
    
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    cout<<"Iveskite egzamino pazymi: ";
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
    cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    else if (ats=="a")
       { 
        srand(time(NULL));
        
        cout<<"Kiek pazymiu noretumete gauti?";
        cin>>temp.paz_sk; 
        while(cin.fail() ||temp.paz_sk<1)
        {
            cout<<"Neteisinga ivestis, reikia teigiamo skaiciaus: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin>>temp.paz_sk;
        }
        temp.pazymiukai=new int[temp.paz_sk];  
        cout<<"Nd pazymiai: ";
        for(int i=0;i<temp.paz_sk;i++)
        {
        int n= (rand()%10)+1;
        temp.pazymiukai[i]=n; 
        cout<<n<<" ";
         }
        cout<<endl;
        cout<<"Atsitiktinis egzamino pazymys: ";
        int m=(rand()%10)+1;
        cout<<m<<endl;
        temp.egzas=m;
    }
 
}
float vidurkis(studentukas &temp)
{
  float sum=0;
  float avg=0;
  if(temp.paz_sk>0)
  {
    for(int i=0;i<temp.paz_sk;i++)
    {
        sum+=temp.pazymiukai[i];
    }
    avg=(((float)sum)/(temp.paz_sk)); 
    return avg;
  }
    else{
        avg=0;
        return avg; 
    }
   
}

float mediana(studentukas &temp){
    float mediana=0;
    sort(temp.pazymiukai,temp.pazymiukai+temp.paz_sk);
    if(temp.paz_sk>0)
    {
      if(temp.paz_sk%2==0)
    {
        mediana=((float)(temp.pazymiukai[temp.paz_sk/2-1]+temp.pazymiukai[temp.paz_sk/2])/2.0);
        return mediana;
    }
    else{
        mediana=((float)temp.pazymiukai[temp.paz_sk/2]);
        return mediana;
    }  
    }
    else
    {
        mediana=0;
        return mediana;   
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
    studentukas *studentuMasyvas;
    int in=0;

    studentuMasyvas=new studentukas[X]; 
do { 
    pildyk(studentuMasyvas[in]);
    X++;
    in++;
    studentukas *temp= new studentukas[X];

    copy(studentuMasyvas, studentuMasyvas+(X-1), temp);
    delete [] studentuMasyvas;
    studentuMasyvas=temp;
    temp=NULL;
    cout<<"Ar norite pildyti informacija apir kita studenta?(t/n)"; 
    cin>>ats;
    while((ats!="t")&&(ats!="n"))
    {
        cout<<"t-prideti dar studenta, n-baigti ivedima"<<endl;
        cin>>ats;
    }
  
}while(ats=="t");
X--;


for(int i=0; i<X;i++) spausdinimas(studentuMasyvas[i]);

}
