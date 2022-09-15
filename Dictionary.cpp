#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;

struct node
{
    string data;
    node * next;
}*start[52];


class linked_Dic
{
    private:
        node *head, *tail;
        char words[50];
    public:
        linked_Dic();//for Linked List Creation
        void create();
        void display();//Display Linked List
        void search1(string);
};

linked_Dic::linked_Dic()//Alphabet Linked list creation
{
    char alphabet='A';
    for(int i=0; i<51; i++)//Capital+Small Alphabets
    {
        start[i]=new struct node;
        start[i]->data=alphabet;
        start[i]->next=NULL;
        alphabet++;
        if(i==25)
        {
            alphabet='a';
        }
    }
}

void linked_Dic::create()
{
    int i=0;
    char input='y';
    struct node *ptr_data, *ptr_trav;
    while(input=='y' || input=='Y')
    {
        cout<<"Enter New String : ";
        ptr_data=new struct node;
        cin>>ptr_data->data;
        ptr_data->next=NULL;

        char file_name[6];
        file_name[0]=ptr_data->data[0];
        file_name[1]='.';
        file_name[2]='t';
        file_name[3]='x';
        file_name[4]='t';
        file_name[5]='\0';
        struct node *link=NULL;
        fstream file_object;
        file_object.open(file_name,ios::out | ios::app);
        file_object<<ptr_data->data<<endl;

        while(start[i]->data[0]!=ptr_data->data[0])
        {
            i++;
        }
        ptr_trav=start[i];
        while(ptr_trav->next!=NULL)
        {
            ptr_trav=ptr_trav->next;
        }
        ptr_trav->next=ptr_data;
        ptr_trav=ptr_data;
        cout<<"Would you like to enter more..? (Y=Yes || N=No):";
        cin>>input;
        i=0;
    }
}

void linked_Dic::search1(string arg1)
{
    string readString;
    char file_name[6];
    file_name[0]=arg1[0];
    file_name[1]='.';
    file_name[2]='t';
    file_name[3]='x';
    file_name[4]='t';
    file_name[5]='\0';
    fstream file_object;
    file_object.open(file_name,ios::in);
    if(file_object)
    {
        do
        {
            file_object>>readString;
            if(readString==arg1)
            {
                cout<<endl<<"Search Success-full - The searched word is present in the Dictionary";
                break;
            }
        }
        while(!file_object.eof());
        if(file_object.eof())
        {
            cout<<endl<<"No such word saved in the Dictionary...";
        }
    }
    else
    {
        cout<<endl<<"No such word saved in the Dictionary...";
    }
    getch();
}
void linked_Dic::display()//display the Linked List.
{
    int i=0;
    struct node *ptr_tra=NULL;

    while(i<51)
    {
        ptr_tra=start[i];
        if(ptr_tra==NULL)
        {
            cout<<"Nothing to Display";
        }
        else
        {
            do
            {
                cout<<" "<<ptr_tra->data;
            }
            while((ptr_tra->next!=NULL) && (cout<<" -> ") && (ptr_tra=ptr_tra->next));
        }
        cout<<endl;
        i++;
    }
}

int main()
{
    linked_Dic obj;
    string input_string, value, strInput;
    int choice;
    do
    {
        cout<<"**********Menu**********";
        cout<<"\n1.Enter a word";
        cout<<"\n2.Display Words";
        cout<<"\n3.Search Word";
        cout<<"\n4.Exit Screen";
        cout<<"\n______________________";
        cout<<"\n\nEnter Your Choice:";

        cin>>choice;

        switch(choice)
        {
            case 1:
                obj.create();
                getch();
                break;
            case 2:
                obj.display();
                getch();
                break;
            case 3:
                cout<<endl<<"Enter the word to be Searched: ";cin>>strInput;
                obj.search1(strInput);
                getch();
                break;
        }
        system("CLS");
    }while(choice!=4);
}


