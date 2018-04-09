#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

/**
- Complex(float re,im)
- Matrice( Complex **v)
- Matrice_oarecare (int lin, int col) : Matrice
- Matrice_patratica (int dim): Matrice
*/

class Complex
{
    float re,im;
 public:
    Complex();
    Complex(Complex&);
    Complex(float,float);
    ~Complex();
    Complex operator+ (const Complex&);
    Complex& operator= (const Complex&);
    Complex& operator() (float r, float i){re=r;im=i;}
        ///SET

        ///GET

        ///FRIEND
    friend ifstream& operator>> (ifstream&,Complex&);
    friend istream& operator>> (istream&,Complex&);
    friend ostream& operator<< (ostream&,Complex&);
        ///ALTELE
    float modul(){return (float)sqrt(re*re+im*im);}
};

Complex::Complex()
{
re=im=0;
}

Complex::Complex(float r, float i)
{
    re=r;
    im=i;
}

Complex::Complex(Complex& z)
{
    re=z.re;
    im=z.im;
}

Complex::~Complex()
{
re=im=0;
}

Complex Complex::operator+(const Complex& z)
{
    re+=z.re;
    im+=z.re;
return *this;

}

Complex& Complex::operator=(const Complex& z)
{
re=z.re;
im=z.im;
return *this;

}

ifstream& operator>> (ifstream& fin,Complex& z)
{
fin>>z.re>>z.im;
return fin;
}

istream& operator>> (istream& in,Complex& z)
{
cout<<"Re:";
in>>z.re;
cout<<"Im:";
in>>z.im;
return in;
}

ostream& operator<< (ostream& out, Complex& z)///FARA \n
{
if(z.re==z.im && z.im==0) cout<<"0";
else
{

    if(z.re) out<<z.re;

    if(z.re==1) out<<"+i";
    else
    {
    if(z.re==-1) out<<"-i";
    else
        {
            if(z.im>0)
                {if(z.re) out<<"+";
                out<<z.im<<"i";}
            else if(z.im<0)out<<z.im<<"i";
        }
    }
}
out<<" ";
return out;
}


class Matrice
{
protected:
    Complex **v;
public:
    Matrice();
    virtual ~Matrice()=0;

};

Matrice::Matrice(){v=NULL;}

Matrice::~Matrice()
{
    if(v!=NULL) delete[] v;
    v=NULL;
}

class Matrice_oarecare: Matrice
{
    int lin, col;
public:
    Matrice_oarecare();
    Matrice_oarecare(const Matrice_oarecare&);
    Matrice_oarecare(int l,int c);
    ~Matrice_oarecare();
    Matrice_oarecare operator+(Matrice_oarecare&);
        ///FRIEND
    friend ifstream& operator>> (ifstream&,Matrice_oarecare&);
    friend istream& operator>> (istream&,Matrice_oarecare&);
    friend ostream& operator<< (ostream&,const Matrice_oarecare&);
};

ifstream& operator>> (ifstream& fin,Matrice_oarecare& mat)
{
    fin>>mat.lin>>mat.col;
    mat.v=new Complex*[mat.lin];
    for(int i=0;i<mat.lin;i++) mat.v[i]=new Complex[mat.col];
    for(int i=0;i<mat.lin;i++)
        for(int j=0;j<mat.col;j++) fin>>mat.v[i][j];
    return fin;
}

istream& operator>> (istream& in,Matrice_oarecare& mat)
{
    cout<<"Introduceti numarul de LINII si COLOANE: ";
    in>>mat.lin>>mat.col;
    mat.v=new Complex*[mat.lin];
    cout<<"Introduceti cate "<<mat.col<<" ELEMENTE pentru fiecare dintre cele "<<mat.lin<<" LINII:\n";
    for(int i=0;i<mat.lin;i++) mat.v[i]=new Complex[mat.col];
    for(int i=0;i<mat.lin;i++)
        for(int j=0;j<mat.col;j++) in>>mat.v[i][j];
    return in;
}

ostream& operator<< (ostream& out,const Matrice_oarecare& mat)
{

    for(int i=0;i<mat.lin;i++)
    {
        for(int j=0;j<mat.col;j++) out<<mat.v[i][j];
        out<<"\n";
    }
return out;
}

Matrice_oarecare::Matrice_oarecare()
{
lin=col=0;
}

Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare& m)
{
lin=m.lin;
col=m.col;
v=new Complex*[lin];
for(int i=0;i<lin;i++) v[i]=new Complex[col];

for(int i=0;i<lin;i++)
    for(int j=0;j<col;j++) v[i][j]=m.v[i][j];
}

Matrice_oarecare::Matrice_oarecare(int l,int c)
{
    lin=l; col=c;
    v=new Complex*[lin];
    for(int i=0;i<lin;i++) v[i]=new Complex[col];
}

Matrice_oarecare::~Matrice_oarecare()
{
for(int i=0;i<lin;i++) delete[] v[i];
delete[] v;
lin=col=0;
v=NULL;
}

Matrice_oarecare Matrice_oarecare::operator+(Matrice_oarecare& z)
{
    Matrice_oarecare sum(max(lin,z.lin),max(col,z.col));
    int lc=min(lin,z.lin), cc=min(col,z.col);   ///LINIE / COLOANA COMUNE
    for(int i=0;i<lc;)
return sum;
}

class Matrice_patratica: protected Matrice
{
    int dim;
};
int main()
{
ifstream f ("date.in");

Matrice_oarecare mat;
f>>mat;
cout<<mat;

Matrice_oarecare mat1(mat);
cout<<"\n"<<mat1;
f.close();
return 0;
}
