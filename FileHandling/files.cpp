#include <bits/stdc++.h>
using namespace std;

int main() {

    ofstream fout;
    fout.open("../FileHandling/temp.txt");
    fout<<"hellooooooooochitarnshu"<<endl;
    fout<<"hellooooooooochitarnshu"<<endl;
    fout<<"hellooooooooochitarnshu"<<endl;
    fout.close();    

    ifstream fin;
    fin.open("../FileHandling/temp.txt");
    string line;

    while(getline(fin, line)){  //eks sath sab input mai lera hai or pritn akrra ra hai temp.text
        cout<<line<<endl;
    }
    

    fin.close();

    return 0;
}