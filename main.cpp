#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<ctype.h>
#include<time.h>
#include<string.h>

using namespace std;
COORD coord={0,0};//sets coordinates to 0,0
COORD res_max,cursor_size;


void delay(unsigned int milli)
{
    clock_t goal=milli+clock();
    while(goal>clock());
}
void gotoxy(int x,int y)
{
    coord.X=x;coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);//Sets the cursors position for the following
}
void LOADER_WAITING()
{
    system("cls");
    int loader;
    gotoxy(50,12);
    printf("LOADING...");
    gotoxy(50,14);
    for(loader=1;loader<20;loader++)
    {
        if(loader<=5)
            delay(100);
        else if(loader<=10)
            delay(50);
        else if(loader==15)
             delay(4000);
        else
            delay(200);

        printf("%c",219);
    }gotoxy(20,5);

}

class items
{
private:
    long itemsId;
    string itemsName;
    int Quantity;
    float Price;
    static long NextitemsId;

public:
    items(){}
    items(string itemsName,int Quantity,float Price);
    long getitemsId(){return itemsId;}
    string getitemsName(){return itemsName;}
    int getQuantity(){return Quantity;}
    float getPrice(){return Price;}
void Additems(int Quantity);
 void Issueitems(int Quantity);
  static void setLastitemsId(long itemsId);
   static long getLastitemsId();
    friend ofstream & operator<<(ofstream &ofs,items &pro);
     friend ifstream & operator>>(ifstream &ifs,items &pro);
      friend ostream & operator<<(ostream &os,items &pro);

};
long items::NextitemsId=0;
class bussiness
{
private:
    map<long,items> itemss;
public:
    bussiness();
    items AddNewitems(string itemsName,int Quantity,float Price);
    items itemsEnquiry(long itemsId);
    items Additems(long itemsId,int Quantity);
    items Issueitems(long itemsId,int Quantity);
    void Removeitems(long itemsId);
    void ShowAllitemss();
    ~bussiness();
};
bussiness sal;
items pro;
void MAIN_MENU()
{
    system("cls");


int choice;
string itemsName;
int Quant;
char enter;

long itemsId;
float Price;
gotoxy(40,7);
cout<<"******Sales Management System ******"<<endl;

    gotoxy(38,9);
    cout<<"Select one option below ";
    gotoxy(38,10);
    cout<<"1. Add New items";
    gotoxy(38,12);
    cout<<"2. item Enquiry";
    gotoxy(38,14);
    cout<<"3. Add items";
    gotoxy(38,16);
    cout<<"4. Issue items";
    gotoxy(38,18);
    cout<<"5. Remove items";
    gotoxy(38,20);
    cout<<"6. Show All items details";
    gotoxy(38,22);
    cout<<"7. Quit";
    gotoxy(38,24);
    cout<<"Enter your choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        system("cls");
        gotoxy(40,7);
        cout<<"Enter the items Name: ";
        cin>>itemsName;
        gotoxy(40,9);
        cout<<"Enter Quantity: ";
        cin>>Quant;
        gotoxy(40,11);
        cout<<"Enter PRICE: ";

        cin>>Price;
        pro=sal.AddNewitems(itemsName,Quant,Price);
        gotoxy(40,13);
        cout<<endl<<"Congratulation items  is successfully Added"<<endl;
        gotoxy(40,15);
        cout<<"Press ENTER to return to Main Menu";
        getch();
        MAIN_MENU();

       // cout<<pro;
    case 2:

        system("cls");
        gotoxy(40,7);
        cout<<"Enter items Id: ";
        cin>>itemsId;
        pro=sal.itemsEnquiry(itemsId);
        cout<<"\t\tYour items Details:"<<endl<<endl;
        cout<<pro;
           gotoxy(40,20);
        cout<<"Press ENTER to return to Main Menu";
        getch();
        MAIN_MENU();


    case 3:
        system("cls");
        gotoxy(40,7);
        cout<<"Enter items Id: ";
        cin>>itemsId;
        gotoxy(40,9);
        cout<<"Enter Quantity: ";
        cin>>Quant;
        pro=sal.Additems(itemsId,Quant);
        gotoxy(40,13);
        cout<<"item is Added!!!!";
           gotoxy(40,17);
        cout<<"Press ENTER to return to Main Menu";
        getch();
         MAIN_MENU();

       // cout<<pro;
    case 4:
        system("cls");
        gotoxy(40,7);
        cout<<"Enter itemsId: ";
        cin>>itemsId;
        gotoxy(40,9);
        cout<<"Enter Quantity: ";
        cin>>Quant;
        pro=sal.Issueitems(itemsId,Quant);
           gotoxy(40,15);
        cout<<"Press ENTER to return to Main Menu";
        getch();
         MAIN_MENU();

        //cout<<pro;
    case 5:
        system("cls");
        gotoxy(40,7);
        cout<<"Enter the itemsId:";
        cin>>itemsId;
        sal.Removeitems(itemsId);
        gotoxy(40,11);
        cout<<"item is Removed!!!";
           gotoxy(40,15);
        cout<<"Press ENTER to return to Main Menu";
        getch();
         MAIN_MENU();

        //cout<<pro;

    case 6:
        system("cls");
        sal.ShowAllitemss();
        cout<<"Press ENTER to return to Main Menu";
        getch();
        MAIN_MENU();

    case 7:system("cls");
         gotoxy(40,8);
         printf("Developed By:");
         gotoxy(40,10);
         printf("PAVAN YADAV A");
         gotoxy(40,12);
         printf("USN:4NI18EC415\tMobile:8095530319\temail:pavanyadava2@gmail.com\t");
         gotoxy(40,14);
         printf("Exiting...");
         delay(1000);
         exit(0);

    default:
        cout<<"\nEnter the correct choice";
        exit(0);

}
}
int main()
{
   LOADER_WAITING();
   MAIN_MENU();

return 0;


}
items::items(string itemsName,int Quant,float Price)
{
    NextitemsId++;
    itemsId=NextitemsId;
    this->itemsName=itemsName;
    Quantity=Quant;
    this->Price=Price;

}
void items::Additems(int another)
{
    Quantity+=another;
}
void items::Issueitems(int Quant)
{
    if((Quantity-Quant)<0)
       cout<<"\n\n\t\t\t\tSorry items is outOfStock"<<endl;
    else{
       Quantity-=Quant;
       cout<<"items Issued"<<endl;
    }


}
void items::setLastitemsId(long itemsId)
{
    NextitemsId=itemsId;
}
long items::getLastitemsId()
{
    return NextitemsId;
}
ofstream & operator<<(ofstream &ofs,items &pro)
{
    ofs<<pro.itemsId<<endl;
    ofs<<pro.itemsName<<endl;
    ofs<<pro.Quantity<<endl;
    ofs<<pro.Price<<endl;

    return ofs;
}
ifstream & operator>>(ifstream &ifs,items &pro)
{
    ifs>>pro.itemsId;
    ifs>>pro.itemsName;
    ifs>>pro.Quantity;
    ifs>>pro.Price;

    return ifs;
}
ostream & operator<<(ostream &os,items &pro)
{
    os<<"\t\titems Name:"<<pro.getitemsName()<<endl;
    os<<"\t\tQuantity:"<<pro.getQuantity()<<endl;
    os<<"\t\titemsId:"<<pro.getitemsId()<<endl;
    os<<"\t\tPrice:"<<pro.getPrice()<<endl;

    return os;
}

bussiness ::bussiness()
{
    items pro;
    ifstream infile;

    infile.open("itemss.data");
    if(!infile)
    {
        return;
    }
    while(!infile.eof())
    {
        infile>>pro;
        itemss.insert(pair<long,items>(pro.getitemsId(),pro));
    }
    items::setLastitemsId(pro.getitemsId());

    infile.close();
}
items bussiness::AddNewitems(string itemsName,int Quant,float balance)
{
    ofstream outfile;
    items pro(itemsName,Quant,balance);
    itemss.insert(pair<long,items>(pro.getitemsId(),pro));

    outfile.open("itemss.data",ios::trunc);
    map<long,items>::iterator itr;
    for(itr=itemss.begin();itr!=itemss.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();

    return pro;
}
items bussiness::itemsEnquiry(long itemsId)
{
    map<long,items>::iterator itr=itemss.find(itemsId);
    return itr->second;
}
items bussiness::Additems(long ProId,int Quant)
{
    map<long,items>::iterator itr=itemss.find(ProId);
    itr->second.Additems(Quant);

    return itr->second;
}
items bussiness::Issueitems(long ProId,int Quant)
{
map<long,items>::iterator itr=itemss.find(ProId);
    itr->second.Issueitems(Quant);

    return itr->second;

}
void bussiness::Removeitems(long PId)
{
    map<long,items>::iterator itr=itemss.find(PId);
    itemss.erase(PId);
}
void bussiness::ShowAllitemss()
{
    map<long,items>::iterator itr;
    for(itr=itemss.begin();itr!=itemss.end();itr++)
    {
        cout<<""<<itr->second<<endl;
    }
}
bussiness::~bussiness()
{
    ofstream outfile;
    outfile.open("itemss.data",ios::trunc);

    map<long,items>::iterator itr;
    for(itr=itemss.begin();itr!=itemss.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
}
