#include "mylib.h"
char ats; 
int paz_sk;
const int MAX_PAZ=10;

struct studentukas{
    string vardas= " ", pavarde= " "; 
    int *pazymiukai=nullptr; 
    int egzas=0;
};

void pildyk(studentukas &temp)
{
    cout<<"Iveskite varda ir pavarde: ";
    cin>>temp.vardas>>temp.pavarde;
    cout<<"rankiinis ivedimas ar atsitiktiniai skaiciai?(r/a)";
    cin>>ats;

    if(ats=='r'||ats=='R')
    {
    cout<<"Iveskite pazymius(iveskite neskaiciu, kad sustabdytumet): ";
    int paz=0;
    paz_sk=0;
    int *pazymiuMasyvas=new int[MAX_PAZ];
    while(cin>>paz && paz_sk<MAX_PAZ)
    {
        if(paz<=10 && paz>=0){
            pazymiuMasyvas[paz_sk]=paz;
            paz_sk++;
        }
       
        else{
            cout<<"please enter the number from 0 to 10: "; 
        }
    } 
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    temp.pazymiukai=new int[MAX_PAZ];

    copy(pazymiuMasyvas, pazymiuMasyvas+ paz_sk, temp.pazymiukai);//pradzia pabaiga ir kur prasideda irasymas 
    delete[] pazymiuMasyvas;  

    cout<<"iveskite egzamino pazymi: ";
    cin>>temp.egzas; 
    }
    else if (ats=='a'||ats=='A')
       {
             paz_sk=0;
    srand(time(NULL));
    cout<<"kiek pazymiu noretumet gauti?(1-10)";
    cin>>paz_sk; 
    temp.pazymiukai=new int[MAX_PAZ];  
    cout<<"Nd pazymiai: ";
    for(int i=0;i<paz_sk;i++)
    {
        int n= (rand()%10)+1;
        cout<<n<<" ";
        temp.pazymiukai[i]=n; 
    }
    cout<<endl;
      cout<<"Atsitiktinis egzamino pazymys: ";
        int m=(rand()%10)+1;
        cout<<m<<endl;
        temp.egzas=m;
    }
}
   

   
    /* int pazymiuMasyvas[paz_sk];//laikinas masyvas 
    cout<<"iveskite  pazymius: ";
    for(int &i: pazymiuMasyvas)//nuoroda i elementus 
    {
        cin>>i; 
    } 
    temp.pazymiukai=new int[paz_sk];  *///rezervuoja kiek duomenu patalpinti
    
    //alternative
    
    /*
    for(int j=0;j<paz_sk; j++) temp.pazymiukai[j]=pazymiuMasyvas[j]; 
    */
    
  

float vidurkis(studentukas &temp)
{
  float sum=0;
  float avg=0;
    for(int i=0;i<paz_sk;i++)
    {
        sum+=temp.pazymiukai[i];
    }
    avg=(((float)sum)/(paz_sk)); 
    return avg;
}

float mediana(studentukas &temp){
    
    sort(temp.pazymiukai,temp.pazymiukai+paz_sk);
    if(paz_sk%2==0)
    {
        return((float)(temp.pazymiukai[paz_sk/2-1]+temp.pazymiukai[paz_sk/2])/2);
    }
    else{
        return((float)temp.pazymiukai[paz_sk/2]);
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
    cout<<"Galutinis su vidurkiu ar mediana?(v/m)";
    cin>>ats;
    cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(20)<<left<<"Galutinis"<<endl;
    cout<<setw(20)<<"---------------"<<setw(20)<<"---------------"<<setw(20)<<"---------------"<<endl;
    
    cout<<setw(20)<<left<<temp.vardas<<setw(20)<<left<<temp.pavarde; 
   
    if(ats=='v'||ats=='V')
    {
        cout<<setw(20)<<setprecision(3)<<galutinisVID(temp)<<endl;
    }
    else if(ats=='m'||ats=='M')
    {
        cout<<setw(20)<<setprecision(3)<<galutinisMed(temp)<<endl;

    }

   
   /*  
    for(int i=0; i<paz_sk;i++)
    {
        cout<<setw(5)<<temp.pazymiukai[i]; 
    }

    cout<<setw(3)<<temp.egzas<<endl;

    delete [] temp.pazymiukai;//bus trinamas pagal pointeri*/
} 

int main()
{
    studentukas *studentuMasyvas;
    int nr=1;
  
    studentuMasyvas=new studentukas[nr]; 
//cia ciklas
do { 
    pildyk(studentuMasyvas[nr-1]);
    studentukas *temp= new studentukas[nr];

    copy(studentuMasyvas, studentuMasyvas+nr, temp);
    delete [] studentuMasyvas;

    studentuMasyvas=new studentukas[nr+1];
    
    copy(temp, temp+nr, studentuMasyvas);
    delete [] temp;
    nr++;//baigiasi // ir sukurti dinamine struktura pazymiu ivedimui 
    cout<<"Ar norite pildyti informacija apir kita studenta?"; 
    cin>>ats;
  
}while(ats=='t'||ats=='T');


for(int i=0; i<nr-1;i++) spausdinimas(studentuMasyvas[i]);

delete [] studentuMasyvas;
}
