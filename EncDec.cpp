#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class IncDec
{
private:
    string word = "";
    int length = 0;

public:
    IncDec(){}
    IncDec(string w){word = w;}

    string getWord(){return word;}
    void setWord(string w){word = w;}

    void CalLength(){length = word.size()-1;}

    void Incrypt()
    {
    stringstream ss;
    CalLength();

    int RandNb = rand()%9+1;

    ss << RandNb;
    for(int i=0; i<=length; i++)
    {
        ss << hex << (int)word.at(i)+5;
        RandNb = rand()%9+1;
        ss << RandNb;
    }
    word = ss.str();
    cout << ss.str();
    }


    void Decrypt()
    {
    CalLength();
    stringstream ss;

    for(int i = 1; i <= length; i+=2)
    {
        if(i%3 == 0){i -= 1;}
        else{
        int FInt = 0;
        int valA = word.at(i) - '0';
        int valB;

        switch(word.at(i+1))
        {case 'a': valB = 10;
            break;
         case 'b': valB = 11;
            break;
         case 'c': valB = 12;
            break;
         case 'd': valB = 13;
            break;
         case 'e': valB = 14;
            break;
         case 'f': valB = 15;
            break;
         default:
            valB = word.at(i+1) - '0';
        }
        FInt = valA * 16 + valB -5 ;
        cout << char(FInt);}
    }

    }

    ~IncDec(){}
};

int main()
{
bool loop = true;
srand((unsigned)time(0));
string c;
int choice = 0;

while(loop){
    cout << "\nDo you want to Encrypt[1] or Decrypt[2] ?: ";
    cin >> choice;
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    if(choice == 1)
    {
        cout << "\nWhat do you want to encrypt: ";
        getline(cin, c);
        IncDec x(c);
        cout << "Your encryption is: ";
        x.Incrypt();
        cout << "\n";
    }

    if(choice == 2)
    {
        cout << "\nWhat do you want to decrypt: ";
        getline(cin, c);
        IncDec x(c);
        cout << "Your Decryption is: ";
        x.Decrypt();
        cout << "\n";
    }

}

}
