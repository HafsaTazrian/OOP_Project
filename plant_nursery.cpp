#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<stdlib.h>
using namespace std;
class RegisterUser{
protected:
    string user;
private:
    string pass;
public:
    RegisterUser()
    {
        cout<<"Enter Username: \n";
        cin>>user;
        cout<<"\nEnter Password: \n";
        cin>>pass;
        ofstream reg("userdata.txt", ios::app);
        reg<<user<<' '<<pass<<endl;
        cout<<"Registration is successful\n";
    }
    
    void GetUser()
    {
        cout<<"User Name is: "<<user;
    }

};
class LoginUser{
protected:
    string user;
    string u;
private:
    string pass;
    string p;
public:
    LoginUser()
    {
        int exist, c;
        cout<<"Enter Username: \n";
        cin>>user;
        cout<<"Enter Password: \n";
        cin>>pass;
        ifstream input("userdata.txt");

        while (input>>u>>p)
        {
            if (u == user && p == pass)
            {
                exist = 1;
            }
        }
        input.close();
        if (exist == 1)
        {
            cout<<"Hey "<<user<<"\nYou have successfully logged in\n";
        }
        else
        {
            cout<<"Sorry, user name or password incorrect"<<endl;
            cout<<"Press 1 to TRY AGAIN\n";
            cout<<"Press 2 for USER REGISTRATION"<<endl;
            //cout<<"Press 3 for Forgot Password"<<endl;
            cin>>c;
            if (c == 1)
            {
                LoginUser l1;
            }
            else if (c== 2)
            {
                RegisterUser l2;
            }
            /*else if (c == 3)
            {
                forgot();
            }*/
            else
            {
                cout<<"Choice is not valid\n";
            }
        }


    }
    /*void forgot()
    {
        int ex= 0;
        string searchuser, su, sp;
        cout<<"Enter username:"<<endl;
        cin>>searchuser;
        ifstream searchu("userdata.txt");
        while (searchu>>su>>sp)
        {
            if (su == searchuser)
            {
                ex = 1;
                break;
            }
            searchu.close();
            if (ex==1)
            {
                cout<<"Your account is found\n";
                cout<<" "
            }
        }

    }*/

};

class AdminLogin{
protected:
    string admin;
    string a;
private:
    string pass;
    string p;
public:
    AdminLogin()
    {
        int exist, c;
        cout<<"Enter Admin ID: \n";
        cin>>admin;
        cout<<"Enter Password: \n";
        cin>>pass;
        ifstream input("admindata.txt");

        while (input>>a>>p)
        {
            if (a==admin && p == pass)
            {
                exist = 1;
            }
        }
        input.close();
        if (exist == 1)
        {
            cout<<"Hey admin, "<<admin<<"\nYou have successfully logged in\n";
        }
        else
        {
            cout<<"Hey, you are not the ADMIN!!!!"<<endl;
            cout<<"Press 1 to TRY AGAIN\n";
            cout<<"Press 2 for USER REGISTRATION"<<endl;
            cin>>c;
            if (c == 1)
            {
                AdminLogin l1;
            }
            else if (c== 2)
            {
                RegisterUser l2;
                return;
            }
            else
            {
                cout<<"Choice is not valid\n";

            }
        }
    }
};

class Products
{
    private:
        choice;
    protected:
       int quantity, price;
    public:
        Products()
        {
            system("cls");
            cout<<"Here's PLANTS, SEEDS and FERTILIZERS"<<endl;
            cout<<"Press 1 to see PLants chart\n";
            cout<<"Press 2 to see SEEDS chart\n";
            cout<<"Press 3 to see Fertilizers chart\n";
            if (choice == 1)
            {
                Plants p;
            }
            if (choice == 2)
            {
                Seeds s;
            }
            if (choice == 3)
            {
                Fertilizers f;
            }
        }
};
class Plants: virtual public Products
{
    private:

    public:
    Plants()
    {
        system ("cls");
        cout<<"\t\t\t\t\t\tWelcome to the Plants Section!! "<<endl;
        cout<<"\t\t\t\tWe have TREES, HERBS, SHRUBS and MEDICINAL PLANTS FOR YOU"<<endl;
        cout<<"Press 1 for seeing TREES"<<endl;
        cout<<"Press 2 for seeing SHRUBS"<<endl;
        cout<<"Press 3 for seeing HERBS"<<endl;
        cout<<"Press 4 for seeing MEDICINAL PLANTS"<<endl;
    }
    
};
int main()
{
    cout<<"**************************************** PLANT ABODE *****************************************"<<endl;
    cout<<"Choose what you want:"<<endl;
    cout<<"Press 1 for USER LOGIN"<<endl;
    cout<<"Press 2 for USER REGISTRATION"<<endl;
    cout<<"Press 3 for ADMIN LOGIN"<<endl;
    cout<<"Press 4 for SEEING PLANTS"<<endl;

    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            LoginUser l;
            cout<<"Press 4 for Seeing Product"<<endl;
            int choice1;
            cin>>choice1;
            if (choice1 == 4)
            {
                Products p;
            }
            else
            {
                cout<<"Going back to Home Page"<<endl;
                main();
            }
        }
        case 2:
        {
            RegisterUser r;
            cout<<"Press 1 for User Login"<<endl;
            int choice2;
            cin>>choice2;
            if (choice2 == 1)
            {
                LoginUser l2;
            }
            else
            {
                cout<<"Going back to Home Page"<<endl;
                main();
            }

            cout<<"Press 4 for Seeing Product"<<endl;
            int choice1;
            cin>>choice1;
            if (choice1 == 4)
            {
                Products p;
            }
            else
            {
                cout<<"Going back to Home Page"<<endl;
                main();
            }
            

        }
        case 3:
        {
            AdminLogin a;
            cout<<"Press 4 for Seeing Product"<<endl;
            int choice1;
            cin>>choice1;
            if (choice1 == 4)
            {
                Products p;
            }
            else
            {
                cout<<"Going back to Home Page"<<endl;
                main();
            }
        }
        case 4:
        {
            Products p;
        }
    }



}