#include<bits/stdc++.h>
using namespace std;
map<string,string>m;
int nodeid=1;
struct node
{
    string ownername;
    string address;
    string mobile_no;
    int nodenumber;
    int nodeid;
    int referncenodeid;
    int childnodeid;
    int *referencechildnodeid;
    node* next;
    node* bottom;
    string encrypted_key;
}*head=NULL;
node * ptr=new node();
node* getnode()
{

node* s=new node();
 s->next=NULL;
 s->bottom=NULL;
 return s;

}
node* insertnode()
{
    if(head==NULL)
    {
    	node* s=getnode();
	    string ownername;
	    string address;
	    string mobile_no;
	    int nodeid;
	    int referncenodeid;
	    cout<<"\nEnter your full name\n"<<endl;
	    cin>>s->ownername;
	    cout<<"\nEnter address(without spaces)\n"<<endl;
	    cin>>address;
	    s->address=address;
	    cout<<"\nEnter mobile no.\n"<<endl;
	    cin>>s->mobile_no;
	    
	    s->encrypted_key=ownername.substr(0,2)+"XXXXXX";
	    s->nodeid=nodeid;
	    s->referencechildnodeid=&nodeid;
	    s->next=NULL;
	    s->bottom=NULL;
	    head=s;
	    ptr=head;
	    cout<<"\nNode inserted successfully\n\n";
	    return s;

	}
	else
	{
		node* s=getnode();
	    string ownername;
	    string address;
	    string mobile_no;
	    int nodeid;
	    int referncenodeid;
	    cout<<"\nEnter your full name\n"<<endl;
	    cin>>s->ownername;
	    cout<<"\nEnter address(without spaces)\n"<<endl;
	    cin>>address;
	    s->address=address;
	    cout<<"\nEnter mobile no.\n"<<endl;
	    cin>>s->mobile_no;
	    s->encrypted_key=ownername.substr(0,4)+"XXXXXX";
	    s->nodeid=nodeid;
	    s->referencechildnodeid=&nodeid;
	    s->next=NULL;
	    s->bottom=NULL;
	    ptr->bottom=s;
	    
	    cout<<"\nNode inserted successfully\n\n";
	    return s;

	}

}

void signup()
{
    string s,p;

    cout<<"Enter username"<<endl;
    cin>>s;
    if(m.find(s)!=m.end())
    {
        cout<<"This username has already been taken.Please enter another"<<endl;
    }
    else
    {
        cout<<"Enter password"<<endl;
        cin>>p;
        m.insert(make_pair(s,p));
        cout<<"Your account has been successfully created\n"<<endl;

    }
}
void login()
{
    cout<<"Verification Fuctionality"<<endl;
    string s,p;
    cout<<"Enter username"<<endl;
    cin>>s;
    cout<<"Enter password"<<endl;
    cin>>p;
    if(m[s]!=p)
      cout<<"Invalid username/password\n\n";
    else
    {
        cout<<"\n\nHi "<<s<<"\n\n"<<"You are successfully logged in\n"<<endl;
        cout<<"Press the following serial no. corresponding to the functionality to use it\n\n";
        int i=0;

        do
        {
            cout<<"1.) Add the node at the beginning"<<endl;
            cout<<"2.) Add more nodes to this set"<<endl;
            cout<<"3.) Add a node to a different node multi set"<<endl;
            cout<<"4.) Access root node data"<<endl;
            cout<<"5.) Modify root node data"<<endl;
            cout<<"6.) To see the longest chain length in your node set"<<endl;
            cout<<"7.) To logout of your account"<<endl;
            cout<<"Choice: ";
			cin>>i;
            if(i==1)
            {
            	nodeid++;
            	ptr=head;
            	node * temp=insertnode();
			}
			else if(i==2)
			{
				nodeid++;
				ptr=head;
				while(ptr->bottom)
				{
					ptr=ptr->next;
				}
				node *temp=insertnode();
			}
			else if(i==3)
			{
				nodeid++;
				ptr=head;
				while(ptr->next)
				{
					ptr=ptr->next;
				}
				node *temp=insertnode();
				
			}
			else if(i==4)
			{
				string s1,p1;
			    cout<<"Enter username"<<endl;
			    cin>>s1;
			    cout<<"Enter password"<<endl;
			    cin>>p1;	
			    if(s==s1)
			    {
			    	ptr=head;
			    	cout<<ptr->encrypted_key<<"  is the encrypted key"<<endl;
			    	cout<<ptr->ownername<<"  is your full name"<<endl;
			    	cout<<ptr->mobile_no<<"  is your phone no."<<endl;
			    	cout<<ptr->address<<"  is the address"<<endl;
			    	
				}
				else
				{
					cout<<"Access Denied You Have Entered wrong Username/Password";
				}
			}
			else if(i==5)
			{
			    cout<<"Enter Credentials for verification"<<endl;
				string s1,p1;
			    cout<<"Enter username"<<endl;
			    cin>>s1;
			    cout<<"Enter password"<<endl;
			    cin>>p1;
			    if(s==s1)
			    {
			    	cout<<"User Verified .You can now change root node data "<<endl;
			    	string ownername;
				    string address;
				    string mobile_no;
				    cout<<"\nEnter your full name\n"<<endl;
				    cin>>head->ownername;
				    cout<<"\nEnter address(without spaces)\n"<<endl;
				    cin>>address;
				    head->address=address;
				    cout<<"\nEnter mobile no.\n"<<endl;
				    cin>>head->mobile_no;
			    }
				else
				{
					cout<<"Access Denied You Have Entered wrong Username/Password";
				}
			    
			}
			else if(i==6)
			{
				int count=0;
				ptr=head;
				while(ptr)
				{
					ptr=ptr->bottom;
					count++;
				}
				cout<<"Longest Length: "<<count<<endl;
			}
			else if(i==7)
			{
				exit(0);					
			}
			else
			{
				cout<<"Wrong Choice";
			}
			
			// printimg list
			cout<<endl;
			cout<<"This is what List Looks Like"<<endl;
			ptr=head;
			while(ptr)
			{
				cout<<ptr->nodeid<<"->";
				ptr=ptr->next;
			}
			ptr=head;
			ptr=ptr->bottom;
			cout<<endl;
			while(ptr)
			{
				cout<<"|"<<endl;;
				cout<<ptr->nodeid<<endl;
				ptr=ptr->bottom;
			}
			cout<<endl;
			cout<<endl;
        }while(i!=5);
        cout<<"You are successfully logged out\n\n"<<endl;
    }
}

int main()
{
int i=0;

do
{
    cout<<"Press the corresponding serial number to use the functionality:"<<endl;
    cout<<"1.) To signup"<<endl;
    cout<<"2.) To Login(other functionalities after verifying you as a valid user)"<<endl;
    cout<<"3.) To see the longest chain of main node"<<endl;
    cout<<"4.) To Exit"<<endl;
    cout<<"Choice: ";
	cin>>i;
	switch(i)
	{
	    case 1:signup();
	    break;
	    case 2:login();
	    break;
	    case 3:exit(0);
	    break;
	    default:break;
	}
}while(i!=4);
return 0;
}


