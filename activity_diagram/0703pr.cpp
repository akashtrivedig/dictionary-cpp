#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

struct node
{
    string data;
    node * next;
}*start[27];


class linked_Dic
{
    private:
        node *head, *tail;
        char words[50];
    public:
        linked_Dic();

        void create();

        void display();

        void Search();
};

linked_Dic::linked_Dic()
{
    char alphabet='A';
    for(int i=0; i<26; i++)
    {
        start[i]=new struct node;
        start[i]->data=alphabet;
        start[i]->next=NULL;
        alphabet++;
    }
    alphabet='a';
    for(int i=26; i<52; i++)
    {
        start[i]=new struct node;
        start[i]->data=alphabet;
        start[i]->next=NULL;
        alphabet++; alphabet='a';
    for(int i=26; i<52; i++)
    {
        start[i]=new struct node;
        start[i]->data=alphabet;
        start[i]->next=NULL;
        alphabet++;
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
        file_object<<ptr_data->data<<"\t";



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


void linked_Dic::display()
{
    int i=0;
    struct node *ptr_tra=NULL;

    while(i<52)
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
void linked_Dic::Search()
{
        char name;
        struct node *ptr_data;
        cout<<"enter word you want search:";
        cin>>name;

      ifstream input;
		size_t pos;
              string line;

		input.open(ptr_data->data);
		if(input.is_open())
		{
			while(getline(input,line))
			{
                pos = line.find(name);
                if(pos!=string::npos)
                {
                    cout <<"Found at"<<pos;
                    break;
                }
			}
		}
}
int main()
{
    linked_Dic obj;
    string input_string, value;
    int choice;
    do
    {
        cout<<"\n1.Enter a word";
        cout<<"\n2.Display Words";
        cout<<"\n3.search word";
        cout<<"\n4.Exit Screen";
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
                obj.Search();
                getch();
                break;
        }
    }while(choice!=3);
}


