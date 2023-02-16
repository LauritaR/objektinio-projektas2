#include "mylib.h"
char ats;
struct studentukas{
    string vardas, pavarde; 
    vector<int> pazymiukai; 
    int egzas;
};

void pildyk(studentukas &temp)
{
    cout<<"iveskite varda ir pavarde: ";
    cin>>temp.vardas>>temp.pavarde;
    
    cout<<"rankinis ivedimas ar atsitiktiniai skaiciai?(r/a)";
    cin>>ats;
    if (ats=='r'||ats=='R')
    {   
        cout<<"iveskite pazymius: ";
        int x;
        while(cin>>x)
        {
            temp.pazymiukai.push_back(x);
        } 
        cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//
        cout<<"iveskite egzamino pazymi: ";
        cin>>temp.egzas; 
    }
    else if(ats=='a'||ats=='A')
    {
        int size=0;
        srand(time(NULL));
        cout<<"kiek nd pazymiu norite tureti?(1-10)";
        cin>>size;
        cout<<"nd pazymiai: ";
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
    for(int i=0;i<temp.pazymiukai.size();i++)
    {
        sum+=temp.pazymiukai[i];
    }
    avg=(((float)sum)/(temp.pazymiukai.size())); 
    return avg;
}

float mediana(studentukas &temp){
    
    sort(temp.pazymiukai.begin(),temp.pazymiukai.end());
    if(temp.pazymiukai.size()%2==0)
    {
        return((float)(temp.pazymiukai[temp.pazymiukai.size()/2-1]+temp.pazymiukai[temp.pazymiukai.size()/2])/2);
    }
    else{
        return((float)temp.pazymiukai[temp.pazymiukai.size()/2]);
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
        cout<<"do you want to add infor about ther student(t/n)?";
        cin>>kart;
       
    }while(kart=='t'||kart=='T');

    for(auto &i: mas)
    {
        spausdinimas(i); 
    }
   for(auto &i: mas) i.pazymiukai.clear();
   mas.clear();



    
    

}
