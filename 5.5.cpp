#include<iostream>
#include<vector>
#include<algorithm>



class Poligon{

   
public:
Poligon(){};
    virtual float aria()=0;
    virtual void afisare()=0;
   
};


class Triunghi:public Poligon{
    
    
    private:
    
        int h;
        int b;
    public:
       Triunghi(int h,int b):b(b),h(h){};
       float aria(){
           return(h*b/2);
       }
       void afisare()
       {
           std::cout<<h<<' '<<b<<std::endl;
       }
};

class Paralelogram:public Poligon
{ private:
    int l1;
    int l2;
    public:
    Paralelogram(int l1,int l2):l1(l1),l2(l2){};
    float aria(){
        return(l1*l2);
    }
        void afisare(){       std::cout<<l1<<' '<<l2<<std::endl;
       }
};
 
 bool comp(Poligon *a,Poligon  *b)
 {
     return(a->aria()<b->aria());
 }
int main()
{
    int n;
    float a,b;std::cin>>n;
    std::vector<Poligon*> x;
    for(int i=0;i<n;i++)
    {    std::cin>>a>>b;
        Poligon *X=new Triunghi(a,b);
        x.push_back(X);
       // x[0]->afisare();
        
    }
    for(int i=0;i<n;i++)
    {
        std::cin>>a>>b;
        Poligon *Y=new Paralelogram(a,b);
        x.push_back(Y);
    }
    
    sort(x.begin(),x.end(),comp);
    for(auto a:x)
    {
        a->afisare();
    }
    
    
    return 0;
}
