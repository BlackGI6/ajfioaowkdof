#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int nrDoc; // nr doctori
int nrP; // nr pacienti
struct medic
{
    int codMedic;
    char nume[30];
    char prenume[30];
    char specializare[30];
};
struct pacient
{
    int codPacient;
    char nume[30];
    char prenume[30];
    struct
    {
        int an,
            luna,
            zi;
    }dataNasterii;
    int codMedic;
};

void afisare_m(medic m[])
{
    ifstream f("medici.in");
    while (!f.eof())
    {
        f>>m[nrDoc].codMedic;
        f.get();
        f.getline(m[nrDoc].nume,100);
        f.getline(m[nrDoc].prenume,100);
        f.getline(m[nrDoc].specializare,100);
        nrDoc++;
    }
    nrDoc--;
    for (int i = 0 ; i < nrDoc ; ++i)
    {
        cout<<"Cod medic : "<<m[i].codMedic<<endl
            <<"Nume medic : "<<m[i].nume<<endl
            <<"Prenume medic : "<<m[i].prenume<<endl
            <<"Specializare : "<<m[i].specializare<<endl;
    }
    system("pause");
}
void afisare_p(pacient p[])
{
    ifstream f("pacienti.in");

    while (!f.eof())
    {
        f>>p[nrP].codPacient;
        f.get();
        f.getline(p[nrP].nume,100);
        f.getline(p[nrP].prenume,100);
        f>>p[nrP].dataNasterii.an>>p[nrP].dataNasterii.luna>>p[nrP].dataNasterii.zi;
        f>>p[nrP].codMedic;
        nrP++;
    }
    nrP--;
    for (int i = 0 ; i < nrP ; ++i)
    {
        cout<<"Cod pacient : "<<p[i].codPacient<<endl
            <<"Nume medic : "<<p[i].nume<<endl
            <<"Prenume medic : "<<p[i].prenume<<endl
            <<"Data nasterii : " << "\n| An : "<<p[i].dataNasterii.an<<endl
                                 << "| Luna : "<<p[i].dataNasterii.luna<<endl
                                 << "| Zi : "<<p[i].dataNasterii.zi<<endl
            <<"Cod medic : " <<p[i].codMedic<<endl;
    }
    system("pause");
}

void nr_p_d (medic m[],pacient p[])
{
    int n=0;
    for (int i = 0 ; i < nrDoc ; ++i )
    {
        for (int j = 0 ; j < nrP ; j++)
        {
            if (m[i].codMedic==p[j].codMedic)
                n++;
        }
        cout<<endl<<"Doc. " << m[i].nume<<' '<<m[i].prenume<< " are "<<n<<" pacienti !"<<endl<<endl;
        n=0;
    }
    system("pause");
}
void pd(medic m[],pacient p[])
{
    for (int i = 0 ; i < nrDoc ; ++i )
    {
        cout<<endl<<"Doc. " << m[i].nume<<' '<<m[i].prenume<< " are pacientii : "<<endl;
        for (int j = 0 ; j < nrP ; j++)
        {
            if (m[i].codMedic==p[j].codMedic)
                {
                    cout<<"------------------\n"
                        <<'|'<<p[j].nume<<endl
                        <<'|'<<p[j].prenume<<endl
                        <<"|cod pacient : "<<p[j].codPacient<<endl
                        <<"------------------\n";
                }
        }
    }
    system("pause");
}
int main()
{
    int optiuni;
    medic medici[30];
    pacient pacienti[30];
    do
    {
        system("cls");
        cout<<"__________________________\n"
            <<"1= Afisare medici\n2= Afisare pacienti\n3= Pacient - doctor\n4= Numar pacienti / doctor"<<endl
            <<"0= Iesire prog."<<endl
            <<"Alegeti o optiune:\n"; cin>> optiuni;
        switch (optiuni)
        {
            case 1 : afisare_m(medici);
                    break;
            case 2 : afisare_p(pacienti);
                    break;
            case 3 : pd(medici,pacienti);
                    break;
            case 4 : nr_p_d(medici,pacienti);
                    break;
        }
    }while(optiuni);
    return 0;
}
