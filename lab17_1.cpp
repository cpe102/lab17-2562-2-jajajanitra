//Write your code here
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<cctype>
using namespace std;

string upper(string s)
{
    for(int i =0;i<s.size();i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

int main()
{
    ifstream source;
    source.open("name_score.txt");
    vector<string> vname;
    vector<double> vscore;
    vector<string> vgrade;
    char cname[100];
    int s1,s2,s3,s,idx;
    string text0,text;
    while(getline(source,text))
    {
        sscanf(text.c_str(),"%[^:]: %d %d %d",cname,&s1,&s2,&s3);
        vname.push_back(cname);
        s = s1 + s2+ s3;
        vscore.push_back(s);
    }
    source.close();
    for(int i=0;i<= vscore.size();i++)
    {
        if(vscore[i]>=80){vgrade.push_back("A");}
        else{if(vscore[i]>=70 && vscore[i]<=79){vgrade.push_back("B");}
        else{if(vscore[i] >=60 && vscore[i]<=69){vgrade.push_back("C");}
        else{if(vscore[i]>=50 && vscore[i]<=59){vgrade.push_back("D");}
        else{vgrade.push_back("F");}}}}
    }

    while(true)
    {
        int find1 = 0;
        cout << "Please input your command :";
        getline(cin,text0);
        idx = text0.find_first_of(" ");
        string text1 = upper(text0.substr(0,idx));
        string text2 = upper(text0.substr(idx+1,text0.size()));
        if(text1 == "NAME"){
            for(int i =0;i < vgrade.size()-1;i++)
            {
                if(text2 == upper(vname[i]))
                {
                    find1 = 1;
                    cout << "-----------------------------------------\n";
                    cout << vname[i] << "'s grade = " << vgrade[i] << "\n";
                    cout << "-----------------------------------------\n";
                }
            }
            if(find1 != 1)
            {
                cout << "-----------------------------------------\n";
                cout << "Cannot found.\n";
                cout << "-----------------------------------------\n";
            }
        }
        else{if(text1 == "GRADE"){
            cout << "-----------------------------------------\n";
            for(int i =0;i < vgrade.size()-1;i++)
            {
                if(text2 == vgrade[i])
                {
                    cout << vname[i] << "\n";
                }
            }
            cout << "-----------------------------------------\n";continue;
        }
        else{if(text1 == "EXIT"){break;}
        else{if(text1 != "NAME" && text1 != "GRADE"){cout << "Invalid command\n";continue;}}}}

    }
}
