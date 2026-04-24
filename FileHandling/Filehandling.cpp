///cin or cout ek object hai
    //first open the file
    //write in file
    // ofstream fout; ///ye object hai ofstream class ka
    // fout.open("../FileHandling/temp.txt");
    // fout<<"Hello india"<<endl;


    // fout.close();

    ///////////////reading from file
    //open the file
    // ifstream fin;
    // fin.open("../FileHandling/temp.txt");
    // //read from file
    // char c;
    // c = fin.get();
    // while(!fin.eof()){
    //     cout<<c;
    //     c = fin.get(); //for reading spacess.
    // }
    // fin.close();
    // return 0;

    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {


        vector<int> arr(5);
        for(int i = 0 ;i < 5; i++){
             cin>>arr[i];
        }

        //file oprn
        ofstream fout;
        fout.open("../FileHandling/array.txt");
        fout<<"origimal data:"<<endl;
        for(int i = 0; i<5; i++){
            fout<<arr[i]<<" ";
        }
        
        fout<<"soreted dtaa"<<endl;

        sort(arr.begin(), arr.end());
        for(int i = 0; i<5; i++){
            fout<<arr[i]<<" ";
        }

        return 0;
    }
