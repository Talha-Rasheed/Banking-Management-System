#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <stdio.h>

using namespace std;

int function_to_create_account(int users_ids[5], string password[5],int sum);
int function_to_login(int users_ids[5],string password[5]);
void move(int x, int y);
void function_to_withdraw(int toStore[5],int usernumber);
void current_balance(int toStore[5],int usernumber);
int current_balance1(int toStore[5],int usernumber);
void function_to_deposit(int toStore[5],int usernumber);

int main()
{
    cout<<"\n\t\t\t-------------------------------------------";

    move(45, 2);
    Sleep(300);
    cout<<"A";
    Sleep(300);
    cout<<"T";
    Sleep(300);
    cout<<"M";
    Sleep(100);
    move(43, 3);
    Sleep(300);
    cout<<"M";
    Sleep(300);
    cout<<"A";
    Sleep(300);
    cout<<"C";
    Sleep(300);
    cout<<"H";
    Sleep(300);
    cout<<"I";
    Sleep(300);
    cout<<"N";
    Sleep(300);
    cout<<"E";
    Sleep(300);

    cout<<"\n\t\t\t-------------------------------------------"<<endl<<endl;
    int flag1;
    int flag2;
    int transactions[5]= {0};
    int toStore[5]= {0};
    int account_array[5]= {-1};
    string password_array[5];
    int total=0;
    int input;
    while(true)
    {
        cout<<"1. Create bank account"<<endl;
        cout<<"2. Login"<<endl;
        cout<<"3. Quit"<<endl<<endl;
        cout<<"Select an Option : ";
        cin>>input;
        cout<<endl;
        if(input==1)
        {
            cout<<"You are about to create your Bank Account\n\n";
            char loading1=176;
            cout<<"LOADING ";
            for(int i=0; i<=15; i++)
            {
                Sleep(100);
                cout<<loading1;
            }
            cout<<endl<<endl;
            flag1=function_to_create_account(account_array,password_array,total);
            if(total<5)
            {
                if(flag1==1)
                {
                    cout<<endl;
                    cout<<endl;
                    cout<<"Account is successfully created\n"<<endl;
                    total+=1;
                    Sleep(800);
                }
                else if(flag1==0)
                {
                    cout<<endl;
                    cout<<"ERROR!!!"<<endl;
                    Sleep(1000);
                }
            }
            else
            {
                cout<<endl;
                cout<<"Not more than 5 accounts"<<endl;
                Sleep(1000);
            }
        }

        if(input==2)
        {
            cout<<"You are about to LOGIN to your Bank Account\n\n";
            char loading2=176;
            cout<<"LOADING ";
            for(int i=0;i<=15;i++)
            {
                Sleep(100);
                cout<<loading2;
            }
            cout<<endl<<endl;
            flag2=function_to_login(account_array,password_array);
            if(flag2!=-1)
            {
                while(true)
                {
                    cout<<"\n\n1. Withdraw money"<<endl;
                    cout<<"2. Deposit money"<<endl;
                    cout<<"3. Check Current Balance"<<endl;
                    cout<<"4. Log Out"<<endl<<endl;
                    cout<<"Select an Option : ";
                    cin>>input;
                    cout<<endl;
                    if(input==1)
                    {
                        function_to_withdraw(toStore,flag2);
                        transactions[flag2]+=1;
                        Sleep(800);
                    }
                    if(input==2)
                    {
                        function_to_deposit(toStore,flag2);
                        transactions[flag2]+=1;
                        Sleep(200);
                    }
                    if(input==3)
                    {
                        current_balance(toStore,flag2);
                        Sleep(800);
                    }
                    if(input==4)
                    {
                        cout<<"You are about to LOG OUT your Bank Account\n\n";
                        char loading2=176;
                        cout<<"LOADING ";
                        for(int i=0;i<=15;i++)
                        {
                            Sleep(100);
                            cout<<loading2;
                        }
                        cout<<endl<<endl;
                        cout<<"LOGGED OUT!!!\n"<<endl;
                        Sleep(800);
                        break;
                    }
                }
            }
            else if(flag2==-1)
            {
                cout<<endl;
                cout<<"\nLogin Failed\n"<<endl;
                Sleep(1000);
            }
        }

        if(input==3)
        {
            cout<<"You've EXIT"<<endl;
            cout<<"\nHave a Nice Day -_-"<<endl<<endl;
            Sleep(1500);
            break;
        }
    }
    system("pause");
    return 0;
}

void move(int x, int y)
{
    COORD c= { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int function_to_create_account(int users_ids[5],string password[5],int sum)
{
    int id;
    string password1;
    while(true)
    {
        cout<<"Enter ID : ";
        cin>>id;
        cout<<endl;
        if(!cin.fail())
        {
            break;
        }
        else
        {
            cout<<"User Id should be integer"<<endl<<endl;
            cin.clear();
            cin.ignore();
            Sleep(500);
        }
    }

    for(int i=0; i<5; i++)
    {
        if(users_ids[i]==id)
        {
            return 0;
        }
        else {}
    }

    char ch;
    cout<<"Enter 5 digit password : ";
    ch=_getch();
    int password_length=0;
    while(true)
    {
        if(password_length<5)
        {
            password1.push_back(ch);
            cout<<'*';
            ch=_getch();
            password_length=password_length+1;
        }
        else
        {
            break;
        }
    }
    users_ids[sum]=id;
    password[sum]=password1;
    return 1;
}

int function_to_login(int users_ids[5],string password[5])
{
    int id;
    string password1;
    while(true)
    {
        cout<<"Enter User ID to Login : ";
        cin>>id;
        cout<<endl;
        if(!cin.fail())
        {
            break;
        }
        else
        {
            cout<<"User Id must be integer"<<endl<<endl;
            cin.clear();
            cin.ignore();
            Sleep(500);
        }
    }

    char pass;
    cout<<"Enter your password to Login : ";
    pass=_getch();
    int password_length=0;
    while(true)
    {
        if(password_length<5)
        {
            password1.push_back(pass);
            cout<<'*';
            pass=_getch();
            password_length=password_length+1;
        }
        else
        {
            break;
        }
    }
    for(int i=0; i<5; i++)
    {
        if(users_ids[i]==id && password[i]==password1)
        {
            return i;
        }
    }
    return -1;
}

void function_to_withdraw(int toStore[5],int usernumber)
{
    int amounttowithdraw;
    if(toStore[usernumber]==0)
    {
        cout<<"No money to withdraw";
    }
    else
    {
        cout<<"You can withdraw amount that is at least divisible by 10\n";
        cout<<"\nEnter amount you want to withdraw : ";
        cin>>amounttowithdraw;
        cout<<endl;
        if(amounttowithdraw%10==0)
        {
            if(amounttowithdraw<=toStore[usernumber])
            {
                toStore[usernumber]-=amounttowithdraw;
                cout<<"Rs: "<<amounttowithdraw<<" Successfully WithDrawn";
                Sleep(1000);
            }
            else
            {
                cout<<"Not Enough Balance"<<endl;
                Sleep(500);
            }
        }
        else
        {
            cout<<"Enter Valid Amount\n";
        }
    }
}

void current_balance(int toStore[5],int usernumber)
{
    cout<<"Your Current Balance is Rs : "<<toStore[usernumber];
}

int current_balance1(int toStore[5],int usernumber)
{
    return toStore[usernumber];
}

void function_to_deposit(int toStore[5],int usernumber)
{
    int amount_deposit;
    while(true)
    {
        cout<<"Enter amount you want to Deposit : ";
        cin>>amount_deposit;
        cout<<endl;
        if(amount_deposit%10==0)
        {
            break;
        }
        else
        {
            cout<<"Amount Not Correct\n"<<endl;
            cout<<"You can deposit amount that is at least divisible by 10\n\n";
        }
    }
    toStore[usernumber]+=amount_deposit;
    cout<<"Rs: " <<amount_deposit<<" is successfully deposited";
    Sleep(800);
}


