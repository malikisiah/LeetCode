#include <bits/stdc++.h>

using namespace std;

int prefix(string &e);

int main()
{
    string e = "( / 6 2)";

    cout << e << endl;

    cout << prefix(e) << endl;

    cout << endl;


    string f = "( + 1 2 3 4)";
    cout << f << endl;
    cout << prefix(f) << endl;

     cout << endl;


    string h = "( + 1 ( * 2 3 )";
    cout << h << endl;
    cout << prefix(h) << endl;

    cout << endl;


     h = "( + 1 ( * 2 3 ) 5 )";
    cout << h << endl;
    cout << prefix(h) << endl;
}

int prefix(string &e)
{

    char ch = e[0];
    e = e.substr(1);

    if (e[0] == ' '){
        e=e.substr(1);
    }



    if (isdigit(ch)){

        /* if (e.) */


        return atoi(&ch);
    }

    if (ch == '+'){
        int op1 = prefix(e);

        vector <int> list;

        while (!e.empty() && e[0] != ')'){
            list.push_back(prefix(e));
        }
        int op2 = 0;
        for (auto x: list){
            op2+=x;
        }
        return op1 + op2;
    }

    if (ch == '-'){
        int op1 = prefix(e);

        vector <int> list;

        while (!e.empty() && e[0] != ')'){
            list.push_back(prefix(e));
        }
        int op2 = 0;
        for (auto x: list){
            op2+=x;
        }
        return op1 - op2;
    }

    if (ch == '*'){
        int op1 = prefix(e);

        vector <int> list;

        while (!e.empty() && e[0] != ')'){
            list.push_back(prefix(e));
        }
        int op2 = 1;
        for (auto x: list){
            op2*=x;
        }
        return op1 * op2;
    }

    if (ch == '/'){
        int op1 = prefix(e);

        vector <int> list;

        while (!e.empty() && e[0] != ')'){
            list.push_back(prefix(e));
        }
        int op2 = list[0];
        for (int x = 1; x<list.size(); x++){
            op2/=x;
        }
        return op1 / op2;
    }

    else{
        return prefix(e);
    }


}