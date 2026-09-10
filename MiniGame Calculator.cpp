#include <iostream>
#include <ctime>
using namespace std;

enum operations {  

    Add=0,
    Sub=1,
    Mult=2,
    Div=3

};

int quiz (){

    int quiz=rand()%4;
    return quiz;

}

int scoreBoard(int num){

    static int score=0;
    score+=num;
    
    return score;
}

void checkanswer (int Answer){
    int userAnswer;
    
    while (!(cin>>userAnswer)){  
        cout<<"\nError , only Numbers Are Allowed\nWrite Again Your Answer --> ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    if (userAnswer==Answer){
        cout<<"\nCorrect !!\n";
        scoreBoard(1);
    }
    else {
    cout<<"\nWrong , it's "<<Answer;
    cout<<'\n';
}
}

void add (){

    int a=rand()%1001;
    int b=rand()%1001;
    cout<<a<<" + "<<b<<" = ??\nYour Answer --> ";
    int c=a+b;
    checkanswer(c);

}

void sub (){

    int a=rand()%1001;
    int b=rand()%1001;
    cout<<a<<" - "<<b<<" = ??\nYour Answer --> ";
    int c=a-b;
    checkanswer(c);
    
}

void mult (){

    int a=rand()%51;
    int b=rand()%13;
    cout<<a<<" * "<<b<<" = ??\nYour Answer --> ";
    int c=a*b;
    checkanswer(c);

}

void div (){

    int a=rand()%501;
    int b=(rand()%(26)+1); 

    while (a%b!=0){

    a=rand()%501;
    b=(rand()%(26)+1);
    }

    cout<<a<<" / "<<b<<" = ??\nYour Answer --> ";
    int c=a/b;
    checkanswer(c);

}

void quizSelector(int ques){

    switch (ques){
        case Add: add(); break;
        case Sub: sub(); break;
        case Mult: mult(); break;
        case Div: div(); break;
    }

}

int main (){

    srand(time(0));
    bool dis=1;
    string name;
    cout<<"Hello , Enter Your Name --> ";
    getline(cin,name);  
    cout<<"=============================\n";

    do {

    int terms;
    cout<<"Hello In Mini Calculator Game "<<name<<"\nHow Many Rounds You Want To Play ?? ";
    cin>>terms;
    cout<<'\n';

    while (terms--){
    int ques=quiz();
    quizSelector(ques);
    }

    cout<<"Your Score Is "<<scoreBoard(0)<<"\nWanna Play Again ?? (0 , 1) --> ";
    cin>>dis;  

}  while (dis);

    cout<<"\nThanks For Playing, "<<name;
    cout<<"\nHave A nice Day !!\n";
    

    return 0;
}
