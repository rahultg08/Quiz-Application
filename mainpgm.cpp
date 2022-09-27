#include <iostream>
#include <fstream>

using namespace std;

class quiz{
private:
    int marks;
    string name;

public:
    int checkMarks(){
        ifstream preAns;
        preAns.open("answers.txt");
        ifstream inpAns;
        inpAns.open("inputtedAns.txt");
        string convPreAns, convInpAns;

        int ctr = 0;

        while (getline(preAns, convPreAns) && getline(inpAns, convInpAns)){
            if (convPreAns[0] == convInpAns[0])
                ctr++;
        }

        preAns.close();
        inpAns.close();
        return ctr;
    }
    void mainQuiz()
    {
        cout << "Enter Your Name: ";
        cin >> name;
        system("cls");

        ifstream in;              // input file stream
        in.open("questions.txt"); // opening the questions
        ofstream ot;
        ot.open("inputtedAns.txt");

        string txt;
        int i = 0;
        char ans;

        while (getline(in, txt))
        {
            char ch = 'a';
            if (i % 2 == 0)
                cout << txt << "\n";
            else
            {
                for (int i = 0; i < txt.length(); i++)
                {
                    string a, b;
                    a += txt[i];
                    a += txt[i + 1];
                    b += ch;
                    b += '.';
                    if (a == b)
                    {
                        cout << "\n";
                        ch++;
                    }
                    cout << txt[i];
                }
                cout << "\n\n";
                cout << "Enter The Answer: ";
                cin >> ans;
                ot << ans << "\n";
                system("cls");
            }
            i++;
        }
        in.close();
        ot.close();
    }
    void displayScore()
    {
        while(getchar()!='\n');
        cout << "Name : " << name << endl;

        cout << "\n\n";
        // cout<<"Your Score is : "<<checkMarks()<<endl;
        ifstream ab, bc, cd;
        ab.open("questions.txt");
        bc.open("answers.txt");
        cd.open("inputtedAns.txt");
        string txt1, txt2, txt3, txt0;
        cout << "Question Wise Analysis:- \n\n";
        while (getline(ab, txt1) && getline(bc, txt2) && getline(cd, txt3) && getline(ab, txt0))
        {
            char ch = 'a';
            cout << txt1 << endl;
            for (int i = 0; i < txt0.length(); i++)
            {
                string a, b;
                a += txt0[i];
                a += txt0[i + 1];
                b += ch;
                b += '.';
                if (a == b)
                {
                    cout << "\n";
                    ch++;
                }
                cout << txt0[i];
            }
            cout << endl;
            cout << "Your Answer : " << txt3 << endl;
            cout << "Correct Answer : " << txt2 << endl;
            cout << "Marks Awarded : ";
            if (txt2[0] == txt3[0])
            {
                cout << " 1" << endl;
            }
            else
            {
                cout << " 0" << endl;
            }
            cout << "\n";
            cout << "Press Enter To Continue: ";
            cin.get();
            system("cls");
        }
        cout << "Your Final Score : " << checkMarks() << endl;
    }
};

int main()
{
    system("cls");
    cout << "Enter Number of People Attending Quiz: ";
    int n;
    cin >> n;
    system("cls");
    quiz ob[n];
    for (int i = 0; i < n; i++)
    {
        ob[i].mainQuiz();
        ob[i].displayScore();
    }

    return 0;
}