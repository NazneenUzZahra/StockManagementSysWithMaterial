 #include <iostream>
 #include <string.h>
 #include<stdlib.h>
 #include<fstream>
 using namespace std;

 class Brand{//composition
 	string name,image,action;
 	public:
 		Brand(string n,string i,string a)
 		{
 			name=n;image=i;action=a;
		 }
		 string n()
         {
            return(name);
         }
         string i()
         {
            return(image);
         }
         string a() 
         {
            return(action);
         }
     };
class type{//aggregation
	string tname;
	public:
		type(string tn):tname(tn){}
		void displaytype()
		{
			cout<<"Item Type: "<<tname<<endl;
		}
};
class itemno{//one way association
	int num;
	public:
		itemno(int n):num(n){}
		void displayitemno()
		{
			cout<<"Item No: "<<num<<endl;
		 } 
};
 class stock{
 	protected:
 	Brand o;
 	itemno *ob;
 	type *o1;
 	string b;
 	string code;
 	int no;
 	string ans[100];
 	string Ans[100];
 	public:
 		stock(Brand b):o(b){}
		void Branddisplay()//composition in class stock
		{
			cout<<"The Brand name: "<<o.n()<<endl;
			cout<<"The Brand image: "<<o.i()<<endl;
			cout<<"The Brand action: "<<o.a()<<endl;
		}
		void typedisplay(type *t)//agregation in class stock
		{
		   o1=new type("food");
		   o1->displaytype();
		}
		void itemnodisplay(itemno *in)//association in class stock
		{
			ob=in;
			ob->displayitemno();
		}
void displaylist() {
	ifstream a("Entities.txt");
	char ch;
	while(!a.eof())
	{
		a.get(ch);
		cout<<ch;
	}
	a.close();
	system("PAUSE");
}
void displayitem() {
    ifstream a("DJUA.txt");
	char ch;
	while(!a.eof())
	{
		a.get(ch);
		cout<<ch;
	}
	a.close();
	system("PAUSE");
}

};
class head{
	protected:
	int i;
 	string s;
 	
 	public:
 		
 		
 		string sno[100], name[100], barcode[100], sellingprice[100], buyingprice[100];
     	
 		int StoreProduct()
 		{
	     	string li, lb, lbn, lsp, lbp;
	     	int c=0;
 			ifstream fi("items.txt"), fb("brands.txt"), fbn("barcode nos.txt"), fsp("selling price.txt"), fbp("buying price.txt");
			while(getline(fi, li) && getline(fb, lb) && getline(fbn, lbn) && getline(fsp, lsp) && getline(fbp, lbp))
			{
				sno[c] = li; name[c] = lb; barcode[c] = lbn; sellingprice[c] = lsp; buyingprice[c] = lbp;
				
				if(c==0)
				cout<<sno[c]<<"\t"<<name[c]<<"\t"<<barcode[c]<<"\t"<<sellingprice[c]<<"\t"<<buyingprice[c]<<endl<<endl;
				
				else
				cout<<sno[c]<<"\t\t"<<name[c]<<"\t\t"<<barcode[c]<<"\t\t"<<sellingprice[c]<<"\t\t"<<buyingprice[c]<<endl;
				
				c++;
			}
			
			fi.close();fb.close();fbn.close();fsp.close();fbp.close();
			return c;
		}
		
		void additem()//class head
		{
			ofstream f;
			int n;
			cout<<endl<<"Enter the no of products to be added: ";
			cin>>n;
		
	        for(int c=0;c<n;c++)
	        {
	        f.open("items.txt",ios_base::app);
			cout<<endl<<c+1<<".Enter the item no: ";
			cin>>i;
			f<<"\n"<<i;
			f.close();
			
	        f.open("brands.txt",ios_base::app);
			cout<<endl<<c+1<<".Enter the item brand name: ";
			cin>>s;
			f<<"\n"<<s;
			f.close();
			
			f.open("barcode nos.txt",ios_base::app);
			cout<<endl<<c+1<<".Enter the item barcode no: ";
			cin>>i;
			f<<"\n"<<i;
			f.close();
			
			f.open("selling price.txt",ios_base::app);
			cout<<endl<<c+1<<".Enter the selling price of item : ";
			cin>>i;
			f<<"\n"<<i;
			f.close();
			
			f.open("buying price.txt",ios_base::app);
			cout<<endl<<c+1<<".Enter the buying price of item : ";
			cin>>i;
			f<<"\n"<<i;
			f.close();
			
	        }
	        cout<<endl<<"Items info  has been added to the stock files successfully.";
	        system("PAUSE");
	    }
	    
	    void deleteitem()
	    {
	     	ofstream fo;
	     	string l;
			int n, line;
			cout<<endl<<"Enter the no of products to be deleted: ";
			cin>>n;
			
	        for(int c=0;c<n;c++)
	        {
			cout<<endl<<c+1<<".Enter the item no you wish to be deleted: ";
			cin>>i;
			
			ifstream fi("items.txt");
			fo.open("t.txt",ios_base::app);
			line=0;
			while(getline(fi, l))
			{
				if(line != i)
				{
					fo<<l<<"\n";
				}
				
				line++;
				
			}
			fo.close(); fi.close();
			remove("items.txt");
			rename( "t.txt" , "items.txt");
			
			ifstream fb("brands.txt");
			fo.open("t.txt",ios_base::app);
			line=0;
			while(getline(fb, l))
			{
				if(line != i)
				{
					fo<<l<<"\n";
				}
				
				line++;
				
			}
			fo.close(); fb.close();
			remove("brands.txt");
			rename( "t.txt" , "brands.txt");
			
			ifstream fbn("barcode nos.txt");
			fo.open("t.txt",ios_base::app);
			line=0;
			while(getline(fbn, l))
			{
				if(line != i)
				{
					fo<<l<<"\n";
				}
				
				line++;
				
			}
			fo.close(); fbn.close();
			remove("barcode nos.txt");
			rename( "t.txt" , "barcode nos.txt");
	    	
	    	ifstream fsp("selling price.txt");
			fo.open("t.txt",ios_base::app);
			line=0;
			while(getline(fsp, l))
			{
				if(line != i)
				{
					fo<<l<<"\n";
				}
				
				line++;
				
			}
			fo.close(); fsp.close();
			remove("selling price.txt");
			rename( "t.txt" , "selling price.txt");
			
			ifstream fbp("buying price.txt");
			fo.open("t.txt",ios_base::app);
			line=0;
			while(getline(fbp, l))
			{
				if(line != i)
				{
					fo<<l<<"\n";
				}
				
				line++;
				
			}
			fo.close(); fbp.close();
			remove("buying price.txt");
			rename( "t.txt" , "buying price.txt");
		}
		
		cout<<endl<<"Items info  has been deleted from the stock files successfully.";
	    }
	    
		void update()
    	{
    	ofstream fo;
	    string l;
	    int n,in,line;
	    int c=0;
	    cout<<endl<<"1.Brand name"<<endl<<"2.Barcode no"<<endl<<"3.Selling price"<<endl<<"4.Buying price";
	    while(c!=-1)
	    {
	    cout<<endl<<"Enter the data option you wish to update: ";
	    cin>>n;
	    cout<<endl<<"Enter the item no to be updated: ";
	    cin>>i;
	    	
	    switch(n)
	    {
    	case 1:
    		{	
			cout<<endl<<"Enter the brand name: ";
			cin>>s;
			ifstream fb("brands.txt");
			fo.open("t.txt",ios_base::app);
			line=0;
			while(getline(fb, l))
			{
				if(line != i)
				{
					fo<<l<<"\n";
				}
				
				else
				    fo<<s<<"\n";
				    
				line++;
				
			}
			fo.close(); fb.close();
			remove("brands.txt");
			rename( "t.txt" , "brands.txt");
			}
    	break;
    	
    	case 2:
    		{
			cout<<endl<<"Enter the barcode no: ";
			cin>>s;
			ifstream fbn("barcode nos.txt");
			fo.open("t.txt",ios_base::app);
			line=0;
			while(getline(fbn, l))
			{
				if(line != i)
				{
					fo<<l<<"\n";
				}
				
				else
				    fo<<s<<"\n";
				    
				line++;
				
			}
			fo.close(); fbn.close();
			remove("barcode nos.txt");
			rename( "t.txt" , "barcode nos.txt");
		    }
    	break;
    	
    	case 3:
    		{
			cout<<endl<<"Enter the selling price: ";
			cin>>s;
			ifstream fsp("selling price.txt");
			fo.open("t.txt",ios_base::app);
			line=0;
			while(getline(fsp, l))
			{
				if(line != i)
				{
					fo<<l<<"\n";
				}
				
				else
				    fo<<s<<"\n";
				    
				line++;
				
			}
			fo.close(); fsp.close();
			remove("selling price.txt");
			rename( "t.txt" , "selling price.txt");
			}
		break;
    	
    	case 4:
    		{
			cout<<endl<<"Enter the buying price: ";
			cin>>s;
			ifstream fbp("buying price.txt");
			fo.open("t.txt",ios_base::app);
			line=0;
			while(getline(fbp, l))
			{
				if(line != i)
				{
					fo<<l<<"\n";
				}
				
				else
				    fo<<s<<"\n";
				    
				line++;
				
			}
			fo.close(); fbp.close();
			remove("buying price.txt");
			rename( "t.txt" , "buying price.txt");
    		}
		break;
    	
    	default:
    	cout<<endl<<"Default Option..................................:p";
	    }
	    	cout<<endl<<"Please enter the data option you wish to update(-1 to exit only): ";
	        cin>>c;
       }
       cout<<endl<<"Items info  has been updated to the stock files successfully.";
	        system("PAUSE");
    }
};
class rating
{
	int l,g;
	float max,min;
	
	public:
		void ranking(head h)
		{
			int j = h.StoreProduct();
			
	        max=atof(h.buyingprice[1].c_str());
	        min=atof(h.buyingprice[j-1].c_str());
	        
	        for(int c=1;c<j;c++)
	        {
	        	if(max<atof(h.buyingprice[c].c_str()))
	        	{
	            	max=atof(h.buyingprice[c].c_str());
	            	l = c;
	            }
	        	if(min>atof(h.buyingprice[c].c_str()))
	        	{
	        		min=atof(h.buyingprice[c].c_str());
	        		g = c;
	        	}
			}
			
			cout<<endl<<"Highest rank : "<<endl<<" item -> "<<h.sno[g]<<"  Brand Name -> "<<h.name[g]<<"  Barcode no. -> "<<h.barcode[g]<<"  Selling Price -> "<<h.sellingprice[g]
			<<"  Buying Price -> "<<h.buyingprice[g]<<endl;
		    
			cout<<endl<<"Lowest rank : "<<endl<<" item -> "<<h.sno[l]<<"  Brand Name -> "<<h.name[l]<<"  Barcode no. -> "<<h.barcode[l]<<"  Selling Price -> "<<h.sellingprice[l]
			<<"  Buying Price -> "<<h.buyingprice[l]<<endl;
			
		}
};
 int main()
 {
 	system("Color 7C");
 	cout<<"********** NH STOCK MANAGEMENT SYSTEM **********"<<endl;
 	rating r;
 	int n;
 	Brand b("Amerco","Excellent","Mangement");
 	stock i(b);
 	i.Branddisplay();
 	itemno in(7);
 	{
 		stock a(b);
 		a.itemnodisplay(&in);
	 }
	type t("food");
	{
		stock c(b);
		c.typedisplay(&t);
    }
	int num;
	cout<<"\t\t=============MENU============="<<endl;
	cout<<"1.	Add item"<<endl<<"2. 	Update item"<<endl<<"3. 	Display Entities"<<endl<<"4. 	Display Stock Sales"<<endl<<"5. 	Highest And Lowest Rank Brand"<<endl<<"6. 	Delete items"<<endl;
	cout<<"Enter the option you wish to select: "<<endl;
	cin>>num;
	head h;
	int c=0;
	while(c!=-1)
	{
	switch(num)
	{
		case 1:
			cout<<endl;
    		h.additem();
    	break;
    	case 2:
    		cout<<endl;
    		h.update();
    	break;
    	case 3:
    		cout<<endl;
    		i.displaylist();
    	break;
    	case 4:
    		cout<<endl;
    		i.displayitem();
    	break;
    	case 5:
    		cout<<endl;
    		r.ranking(h);
    	break;
    	case 6:
    		cout<<endl;
            h.deleteitem();
    	break;
    	default:
    	cout<<endl<<"Default Option..................................:p";
	}
	cout<<endl<<"Please enter the option you wish to select (-1 to exit only): ";
	cin>>c;
	num = c;
    }
 	return 0;
 }

