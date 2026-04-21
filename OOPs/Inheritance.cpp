// #include <bits/stdc++.h>
// using namespace std;

// //Private members of base class are NEVER directly accessible in derived class

// class Animal{
//     public:
//     string name;
//     string sound;



//     Animal(string name, string sound){
//         this->name = name;
//         this->sound =  sound;
//     }
    
//     void Eating(){
//         cout<<name<<" "<<"is Eating"<<endl;
//     }

//     // void makesound()
//         cout<<"this animal does"<<" "<<sound<<endl;
//     }
// };

// class Dog : public Animal{
//     public: //constructor of dog calling parent constructor;
//     Dog(string name, string sound) : Animal(name, sound){
//     }   
// };

// int main() {
//     Dog  d("Dog","bow- bow");
//     d.makesound();
//     d.Eating();

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class Human{
    public:
    string name; // agar ye private hai toh outside the class accesable nhi hai. same for protected 
    int age;
};

class Student: public Human{

int roll_no;
int fees;

public:
void insert(string n, int a){
name = n;
age = a;
}

void display(){
    cout<<name<<" "<<age<<" "<<endl;
}
};


class Teacher: public Human{

};


int main() {
    Student s;
    s.insert("chitanshi",1);
    s.display();
    Teacher t;
    t.name;
    return 0;
}