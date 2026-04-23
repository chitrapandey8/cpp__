#include <bits/stdc++.h>
using namespace std;

//types of polyphormism---compile time and runtime
//compile time --- functionoverloading , operator overloading
//runtime -- virtual function

///complile time error voh hota hai jo complie time mai aata hai mosltt syntactical errors.
//runtime error compile hone ke baad aata hai jaise outofbound, ya 0 se divide kar diya , esa kuch access karna jo present nhi hai.

//function overlaod mtlb fucntion ka name same h but uske parameter hai 

// class Area{
//     public:
//     int CalculateArea(int r){
//      return 3.14*r*r;
//     }

//     int CalculateArea(int l, int b){ // ye complile time pe decide hoga ki konsa call hoga parameter ske hisab se
//         return l*b;
//     }
// };

// int main() {
//     Area a;
//     cout<<a.CalculateArea(2);
//     return 0;
// }


////////////////operator overloading///////////////////
// #include <bits/stdc++.h>
// using namespace std;

// class Complex{
// int real;
// int img;

// Complex(){

// }

// public:
// Complex(int real, int img){
// this->real = real;
// this->img = img;
// }


// void display(){
//     cout<<real<<" "<<"+i"<<img<<endl;
// }

// Complex operator + (Complex &d){ //a ne call kiya d as a refrence pass hua hai 
// Complex ans; 
// ans.real = real + d.real; //withing the class same typr ke object ke private memeber ko acces kar sakte hai
// ans.img = img + d.img;
// return ans;
// }
// };

// int main() {
//     Complex c(3,4);
//     Complex d(4,6);
//     Complex Cans = c + d;
//     Cans.display();
//     return 0;
// }


//////////////////RUNTIME-virtualfuntion????????????????????????????
#include <bits/stdc++.h>
using namespace std;

//Aniaml *p jis object ka addresss store karke rakhega wahi function call karega

class Animal{
public:
// virtual void speak(){ //virtual h toh runtime pe decide hora hai
//         cout<<"huhuh";
//     }

    virtual void speak()= 0; //iska object nhi banega ye ek bstract class jaisa hai isko pure virtual function hai
};
class Dog : public Animal{

    public:
    void speak(){ // ye over ride hora hai
        cout<<"BARK";
    }

    
};
class Cat : public Animal{

    public:
    void speak(){
        cout<<"MOEW";
    }

    
};


int main() {
    // Animal *p; // ye p Animal class ko poin tkarra hai tohb voh sirf animal ke functions ko acces kar sakta hai sirf
    // p = new Dog();
    // p->speak();
    // return 0;

    // Dog d; //i can also do that why did i did? the upar one, because 
    // d.speak();

    Animal *p;
    vector<Animal*> animal;
    animal.push_back(new Dog());
    animal.push_back(new Cat());

    for(int i = 0; i<animal.size(); i++){
        p = animal[i];
        p->speak();

    }
}