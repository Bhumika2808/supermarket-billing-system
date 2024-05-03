#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
};

void shopping:: menu()
{
	m:
	int choice;
	string email;
	string password; 
	
	cout<<"\n\t\t\t\t______________________________________\n";
	cout<<"\t\t\t\t                                      \n";
	cout<<"\t\t\t\t         supermarket main menu    \n";
	cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t______________________________________\n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t|   1)Administrator   |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t|   2)Buyer           |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t|   3)Exit            |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\n\t\t\t Please select!";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    		cout<<"\n\t\t\t............... Please Login............. \n\n";
    		cout<<"\t\t\t Enter Email:";
    		cin>>email;
    		cout<<"\t\t\t Password:";
    		cin>>password;
    		
    		if(email=="bhumika@gmail.com" && password=="bhumi")
    		{
    			administrator();
			}
			else
			{
				cout<<"\n\t\t\t==>Invalid email/password\n";
				break;
			}
		
		case 2: buyer();
		
		case 3:exit(0);
		
		default:
			{
				cout<<"Please select from the given options!"<<endl;
			}
			
	}
	goto m;
}

void shopping :: administrator()
{
    m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator Menu";
	cout<<"\n\t\t\t|_____1)Add the product_____|";
	cout<<"\n\t\t\t|                           |";
	cout<<"\n\t\t\t|_____2)Modify the product__|";
	cout<<"\n\t\t\t|                           |";
	cout<<"\n\t\t\t|_____3)Delete the product__|";
	cout<<"\n\t\t\t|                           |";
	cout<<"\n\t\t\t|_____4)Back to main  menu__|";
	
	cout<<"\n\n\t please enter your choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
	    default:
	    	cout<<"invalid choice!";
			 
	}
	goto m;
}

void shopping::buyer()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Buyer\n";
	cout<<"\n\t\t\t_____1)Buy  product\n";
	cout<<"\n\t\t\t_____2)Go Back\n";
	
	cout<<"\n\n\t please enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
		default:
			cout<<"Invalid choice";
	}
	goto m;
	
}    

void shopping :: add()
{
    m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Add new product....";
	cout<<"\n\n\t code of the product=";
	cin>>pcode;
	cout<<"\n\n\t Name of the product=";
	cin>>pname;
	cout<<"\n\n\t Price of the product=";
	cin>>price;
	cout<<"\n\n\t Discount on the product=";
	cin>>dis;
	data.open("database.txt",ios::in);
	
	if(!data) //if file not exist
	{
		data.open("database.txt",ios::app|ios::out);

	
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else //if file already exist
	{
		data>>c>>n>>p>>d;//read from file by (initializing index of file) already present deails
		while(!data.eof())
		{
			if(c==pcode) token++; //if duplicacy
			data>>c>>n>>p>>d; //iterating next row
		}
        data.close();
	

	if(token==1) 
	{
		cout<<"pcode alread exist";
		goto m;
	}
	else //not duplicate
	{
		data.open("database.txt",ios::app|ios::out);//open file in append and write mode
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
		
	}
  }
	cout<<"\n\n\n\t\t\t Record Inserted";	
} 

void shopping :: edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record";	
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data) cout<<"\n File doesn't exist!";
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t\t Product new code:";
				cin>>c;
				cout<<"\n\t\t\t Name of the product:";
				cin>>n;
				cout<<"\n\t\t\t Price:";
				cin>>p;
				cout<<"\n\t\t\t Discount:";
				cin>>d;
				data<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t\t Record edited";
				token++;
				break;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";//writing data on database 1 file
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
		}
	}

}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete Product";
	cout<<"\n\n\t Product code:";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File doesnt exist";
	
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted successfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}

void shopping :: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|_____________________________________________________\n";
	cout<<"ProNo\t\tName\t\tprice\t\tdiscount%\n";
	cout<<"\n\n|______________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<dis<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping::receipt()
{
	fstream data;
	
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t\t\t RECEIPT";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty database";
	}
	else
	{
		data.close();
		
		list();
    	cout<<"\n_______________________________________________\n";
		cout<<"\n please place the order \n";
		cout<<"\n_______________________________________________\n";
	                                              
		do
		{
		   m:
		   cout<<"\n\nEnter Product code:";
		   cin>>arrc[c];
		   cout<<"\n\nEnter the product quantity:";
		   cin>>arrq[c];
		   for(int i=0;i<c;i++)
		   {
			   	if(arrc[c]==arrc[i])
			   	{
			   		cout<<"\n\n duplicate product code.please try again!";
			   		goto m;
				}
		   }
		   
		   c++;
		   
		   cout<<"\n\n do you want to buy another product? if yes then press y else n :";
		   cin>>choice;
		   
		} while(choice=='y');
		
		
		cout<<"\n\n\t\t\t____________________RECEIPT______________________________\n";
		cout<<"\nProduct No\t Product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";
		
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis; 
			}
			
		}
		data.close();
	}
	cout<<"\n\n_______________________________________________";
	cout<<"\n Total Amount:"<<total;
}


int main()
{
	shopping s;
	s.menu();
}
