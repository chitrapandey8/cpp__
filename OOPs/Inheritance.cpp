#include <bits/stdc++.h>
using namespace std;

//Private members of base class are NEVER directly accessible in derived class

class Animal{
    public:
    string name;
    string sound;

    Animal(string name, string sound){
        this->name = name;
        this->sound =  sound;
    }
    
    void Eating(){
        cout<<name<<" "<<"is Eating"<<endl;
    }

    void makesound(){
        cout<<"this animal does"<<" "<<sound<<endl;
    }
};

class Dog : public Animal{
    public: //constructor of dog calling parent constructor;
    Dog(string name, string sound) : Animal(name, sound){

    }

   
};


int main() {
    Dog  d("Dog","bow- bow");
    d.makesound();
    d.Eating();

    return 0;
}