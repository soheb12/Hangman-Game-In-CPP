#include<iostream>
#include<ctype.h>
#define f(a,n) for(int i=a;i<n;i++)

using namespace std;

class hangman
{
    string word;
    int filled[100];
    int lives;

    public:

    hangman(string w)
    {
        word = w;
        lives = 2;

        f(0,100)
        filled[i] = 0;
    }

    void display()
    {
        int len = word.length();
        for(int i=0;i<len;i++)
        {
            if(filled[i] == 1)
            cout<<word[i];
            else
            cout<<"__";
            cout<<" ";
        }
        cout<<endl;
    }

    void set(int pos)
    {
        filled[pos] = 1;
    }

    void lostlives()
    {
        lives--;
        if(lives<0)
        {
            lost();
        }
        else if(lives == 0)
        {
            lost0();
        }
        else if(lives == 1)
        {
            lost1();
        }
    }

    int getlives()
    {
        return lives;
    }

    int wordfound()
    {
        f(0,word.length())
        {
            if(filled[i] == 0)
            return 0;
        }

        return 1;
    }


    void lost1()
    {
        cout<<"\t\t\t\t       |      \n";
        cout<<"\t\t\t\t       |      \n";
        cout<<"\t\t\t\t       |      \n";
        cout<<"\t\t\t\t       |      \n";
        cout<<"\t\t\t\t       |      \n";
        cout<<"\t\t\t\t       |      \n";
        cout<<"\t\t\t\t       |      \n";
        cout<<"\t\t\t\t|------|------|\n";

            cout<<endl<<endl;
    }

    void lost0()
    {
        cout<<"\t\t\t\t|------|------------|------------|\n";
        cout<<"\t\t\t\t       |                         \n";
        cout<<"\t\t\t\t       |                         \n";
        cout<<"\t\t\t\t       |                         \n";
        cout<<"\t\t\t\t       |                         \n";
        cout<<"\t\t\t\t       |                         \n";
        cout<<"\t\t\t\t       |                         \n";
        cout<<"\t\t\t\t|------|------|                   \n";

            cout<<endl<<endl;
    }

    void lost()
    {
        cout<<"\t\t\t\t|------|------------|------------|\n";
        cout<<"\t\t\t\t       |                         |\n";
        cout<<"\t\t\t\t       |                       /--\\\n";
        cout<<"\t\t\t\t       |                       \\__/\n";
        cout<<"\t\t\t\t       |                       /||\\\n";
        cout<<"\t\t\t\t       |                      / || \\\n";
        cout<<"\t\t\t\t       |                       /||\\\n";
        cout<<"\t\t\t\t|------|------|               / || \\\n";

            cout<<endl<<endl;
    }

    void won()
    {

            cout<<endl<<endl;

        cout<<"       ******WON******  "<<endl;
        cout<<"  You Live To Die Another Day  "<<endl;

            cout<<endl<<endl;
    }

    void loss()
    {

            cout<<endl<<endl;

        cout<<"       ******LOST******  "<<endl;
        cout<<"        You Are Hanged       "<<endl;

            cout<<endl<<endl;
    }






};

int main()
{

    string strArray[100] = {"VIRAT" , "SACHIN" , "DHONI" , "YUVRAJ" , "ASHWIN" , "RAINA" , "DHAWAN" , "ROHIT" , "BHUVENESHWAR",
                       "BUMRAH" , "HARDIK" , "MANISH" , "JADEJA" , "KULDEEP"};

    srand(time(NULL));

    int arraylen = 14;

    cout<<arraylen<<endl;
    int ind = rand()%arraylen;

    string str = strArray[ind];

    hangman h(str);
    int len = str.length();
    int mid = len/2;
    h.set(0);
    h.set(len-1);
    h.set(mid);
    h.display();

    while(1)
    {
        if(h.wordfound())
        {
            h.won();
            break;
        }
 

        if(h.getlives() < 0)
        {
            h.loss();
            break;
        }

        cout<<"Guess a Letter"<<endl<<endl;
        char ch;
        cin>>ch;

        ch = toupper(ch);
        
        int flag=0;
        for(int i=0;i<len;i++)
        {
            if(ch == str[i])
            {
                h.set(i);
                flag=1;
            }
        }
        if(flag==1)
        h.display();
        else
        h.lostlives();
    }
    

}
