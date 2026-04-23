#include <bits/stdc++.h>
 using namespace std;

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


///////////////////////////SINGLE INHERITANCE???????????????????????
// #include <bits/stdc++.h>
// using namespace std;

// class Human{
//     public:
//     string name; // agar ye private hai toh outside the class accesable nhi hai. same for protected 
//     int age;
 
//     public:
//     Human(string name, int age){  //sabse pehele paarent ka constructor chlta hai
//         this->name = name;
//         this->age = age; 
//     }

//     public:
//     void work(){
//         cout<<"I am a human";
//     }

//     ~Human(){
//         cout<<"DESTRCUTOR"<<endl;
//     }
// };

// class Student: public Human{

// int roll_no;
// int fees;

// public:
// Student(string name, int age, int roll_no, int fees):Human(name,age){
//     this->roll_no = roll_no;
//     this->fees = fees;
// }

// public:
// void insert(string n, int a){
// name = n;
// age = a;
// }

// void display(){
//     cout<<name<<" "<<age<<" "<<" "<<roll_no<<" "<<fees<<endl;
// }

// ~Student(){
//     cout<<"STUDENT DESTRUCTOR"<<endl;
// }
// };


// class Teacher: public Human{

// };


// int main() {
//     Student s("chitanshi", 3, 3, 4);
//     s.display();
    
//     return 0;
// }

//////////////////MULTILEVEL INHERITANCE//////////////////////////////////

// #include <bits/stdc++.h>
// using namespace std;

// class Person{
//     protected:
//     string name;

//     public:

//     void introduce(){
//         cout<<"hello my name is:"<<name<<endl;
//     }
// };

// class Employee : public Person{
// protected:
// int salary;

// public:
// void monthysalary(){
//     cout<<"My montly salary is :"<<salary<<endl;
// }
// };


// class Manager : public Employee{
//  public:
//  string department;
 
//  Manager(string department, int salary, string name){
//    this->department = department;
//    this->salary = salary;
//    this->name = name;
//  }

//  void work(){
//     cout<<"I am leading"<<department<<salary<<endl;
//  }
// };

// int main() {
//     Manager m("cs", 3, "hello");
//     m.work();
//     m.monthysalary();
//     return 0;
// }

///////////////////////////////MULTIPLE INHERITANCE?????????????????????????

//  #include <bits/stdc++.h>
//  using namespace std;

//  class Engineer{
//     public:
//     string specilization;

//     void work(){
//         cout<<"i have a speclisation"<<specilization<<endl;
//     }
//  };
//  class Youtuber{
//     public:
//     int subscribers;

//     void contentcreation(){
//         cout<<"I HAVE a subscriber base:"<<subscribers<<endl;
//     }
//  };

//  class codeTeacher: public Engineer , public Youtuber{
//  public:
//  string name;

//  codeTeacher(string name, string specilization, int subscribers){
//    this->name = name;
//    this->specilization =  specilization;
//    this->subscribers = subscribers;
//  }

//  public:
//  void showcase(){
//     cout<<"my name is"<<name<<endl;
//     work();
//     contentcreation();
//  }
//  };

//  class Teacher(){

//  };
//  int main() {
//     codeTeacher c("chitranshi", "CSE", 234);
//     c.showcase();
//      return 0;
//  }
/////////////////////////HERIAARICHIACL///////////////////////
// class Human{
//     public:
//     string name; // agar ye private hai toh outside the class accesable nhi hai. same for protected 
//     int age;
 
// Human(){

// }

//     public:
//     Human(string name, int age){  //sabse pehele paarent ka constructor chlta hai
//         this->name = name;
//         this->age = age; 
//     }

//     public:
//     void work(){
//         cout<<"I am a human";
//     }

//     // ~Human(){
//     //     cout<<"DESTRCUTOR"<<endl;
//     // }
// };

// class Student: public Human{

// int roll_no;
// int fees;

// public:
// Student(string name, int age, int roll_no, int fees):Human(name,age){
//     this->roll_no = roll_no;
//     this->fees = fees;
// }
// };
// class Teacher: public Human{

//     int salary;

//      public:
//     Teacher(string name, int age, int salary){
//       this->name = name;
//       this->age = age;
//       this->salary = salary;
//     }

//     };

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     Teacher t("chitatnshi", 20, 2344000);
//     t.work();
//     return 0;
// }


/////////////////////////hybrib Inheritance///////////////////////

// #include <bits/stdc++.h>
// using namespace std;

// ///student
// //boy
// //girl
// //male
// //female

// class Student{

//     public:
//     void print(){
//         cout<<"I am student";
//     }
// };

// class Male{
//     public:
//     void Maleprint(){
//         cout<<"I am a Male";
//     }
// };

// class FeMale{
//     public:
//     void Femaleprint(){
//         cout<<"I am a FeMale";
//     }
// };


// class Boy : public Student, public Male{
//     public:
//     void Boyprint(){
//      cout<<"I am a boy";
//     }
// };
// class Girl : public Student, public FeMale{
//     public:
//     void Girlprint(){
//      cout<<"I am a Femlae";
//     }
// };




// int main() {

//     Girl g;
//     g.print();
//     g.Femaleprint();
//     return 0;
// }


///////////////////////////////////idk Inheritance///////////////////////////////////

//  class Engineer{
//     public:
//     string specilization;

//     void work(){
//         cout<<"i have a speclisation"<<specilization<<endl;
//     }
//  };
//  class Youtuber{
//     public:
//     int subscribers;

//     void contentcreation(){
//         cout<<"I HAVE a subscriber base:"<<subscribers<<endl;
//     }
//  };

//  class codeTeacher: public Engineer , public Youtuber{
//  public:
//  string name;

//  codeTeacher(string name, string specilization, int subscribers){
//    this->name = name;
//    this->specilization =  specilization;
//    this->subscribers = subscribers;
//  }

//  public:
//  void showcase(){
//     cout<<"my name is"<<name<<endl;
//     work();
//     contentcreation();
//  }
//  };

//  class Teacher(){

//  };
//  int main() {
//     codeTeacher c("chitranshi", "CSE", 234);
//     c.showcase();
//      return 0;
//  }
////////////////////////////Multipath inheritance///////////////////
 #include <bits/stdc++.h>
 using namespace std;

//engineer or youtuebr ek humna h or codeteacher ek engineer bhi hai or ek youtuber bhi hai

class Human{
    public:
    string name;


    void display(){
        cout<<"my name is:"<<name<<endl;
    
    }

};


 class Engineer: public virtual Human{
    public:
    string specilization;

    void work(){
        cout<<"i have a speclisation"<<specilization<<endl;
    }
 };
 class Youtuber : public virtual Human{ ///ye batati h ki human ka name ek hi hai jo dono yotutberr, or engineeer mai hai
    public:
    int subscribers;

    void contentcreation(){
        cout<<"I HAVE a subscriber base:"<<subscribers<<endl;
    }
 };

 class codeTeacher: public Engineer , public Youtuber{
 public:
 int salary;

 codeTeacher(){
    
 }
 public:
 codeTeacher(string name, string specilization, int subscribers, int salary){
   this->name = name;
   this->specilization =  specilization;
   this->subscribers = subscribers;
   this->salary = salary;
 }

 public:
 void showcase(){
    cout<<"my name is"<<name<<endl;
    work();
    contentcreation();
 }
 };


 int main() {
    codeTeacher c("chitarnshi", "cse", 33, 4444);
    c.display(); //ye dodo hai
     return 0;
 }
