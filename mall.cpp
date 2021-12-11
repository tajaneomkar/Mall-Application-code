#include<iostream>
using namespace std;
class Product
{
	int prodid;
	string prodname;
	int qty;
	float rate,amt;
	
	public:
		Product()
		{
			qty=1;
			amt=0;
		}
		friend void operator>>(istream &cin,Product &p)
		{
			cout<<"\nEnter a Prodid";
			cin>>p.prodid;
			cout<<"\nEnter a Prod Name";
			cin>>p.prodname;
			cout<<"\nEnter a Rate";
			cin>>p.rate;
			cout<<"\nEnter a Qty";
			cin>>p.qty;
			p.cal();
		}
		void cal()
		{
			amt=rate*qty;
		}
		static void headshow()
		{
						cout<<"\nProd Id\tProd Name\tRate \tQty\tAmount";

		}
		void show()

		{
			cout<<endl<<prodid<<"\t"<<prodname<<"\t\t"<<rate<<"\t"<<qty<<"\t"<<amt;
		}
		friend class Customer;
};
class Customer
{
	int billno;
	static int cnt;
	string name;
	int noi;
	Product p[10];
	float totalbill;
	public:
		Customer()
		{
			billno=cnt;
			cnt++;
			noi=0;
			totalbill=0;	
		}
		void input()
		{
			char ans;
			cout<<"\nEnter a Name of Customer";
			cin>>name;
			do
			{
			
			cout<<"\nEnter PRoduct Details";
			cin>>p[noi];
			noi++;
			cout<<"Have a More Items???";
			cin>>ans;		
			}
		while(ans=='y');
		}
		void calbill()
		{
			for(int i=0;i<noi;i++)
				totalbill=totalbill+p[i].amt;
		}
		void show()
		{
			cout<<"\n-------------------------------------------";
			cout<<"\nBill No   : "<<billno;
			cout<<"\nCust Name : "<<name;
			Product::headshow();
			for(int i=0;i<noi;i++)
				p[i].show();
			cout<<"\nTotal Bill : "<<totalbill;
			cout<<"\n-------------------------------------------";
			
			
		}
		int gettotalbill()
		{
			return totalbill;
		}

};
int Customer::cnt=1;
main()
{
	Customer c[10];
	int cnt=0,i,opt,bno;
	float totalincome=0;
	do{
	
	cout<<"\nMENU\n1.Generate A Bill\n2.View Bill by Bill No\n3.View all Customers\n4.Exit";
	cin>>opt;
	switch(opt)
	{
	case 1:    c[cnt].input();
	  		   c[cnt].calbill();
			   cnt++;
				break;
	case 3:		totalincome=0;
				for(int i=0;i<cnt;i++)
	   			{
				   c[i].show();
				   totalincome=totalincome+c[i].gettotalbill();
				}
				cout<<"Today's Income is "<<totalincome;
				break;
	case 2:		cout<<"\nEnter a Bill No ";
				cin>>bno;
				if(bno<=cnt)
				{
					c[bno-1].show();
				}
				else
				cout<<"\nBill No not exist";
				break;
	case 4:		cout<<"\nExited.. Thank you";
				break;
				
	}
	}
	while(opt!=4);	

	}
