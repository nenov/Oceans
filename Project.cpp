//#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>


using namespace std;
struct Ocean
{
       int number;
       string name;
       string area;
       string depth;
};

void print(Ocean x[])
{
     for(int s=0;s<1000;s++){if(x[s].name!=""){cout<<"Number "<<s+1<<" is Ocean or sea named "<< x[s].name <<" with area: "<<x[s].area<<" with max depth : "<<x[s].depth<<"km"<<endl;
     cout<<"\n_______________________________________________________________________________ \n";}}
}
void search(string n,Ocean x[])
{
     for(int s=0;s<1000;s++)if(x[s].name==n)cout<<"Record found: "<<"Number "<<s+1<<" is Ocean or sea named "<< x[s].name <<" with area: "<<x[s].area<<" with max depth : "<<x[s].depth<<"km"<<endl;
}
void add(Ocean x[])
{
     for(int s=0;s<1000;s++)if(x[s].name=="")
     { cout<<"Enter new values, first name, then area and depth \n";
             cin.ignore();
             getline(cin,x[s].name);
             cin>>x[s].area;
             cin>>x[s].depth;
       s=1000;
     }
             
}
void del(string n, Ocean x[])
{
     int s=0;
       for( s=0;s<1000;s++)if(x[s].name==n)
       {
         for(s;s<999;s++){
                            x[s].name=x[s+1].name;
                            x[s].area=x[s+1].area;
                            x[s].depth=x[s+1].depth;
                            }                      
       }
 }
void edit(string n,Ocean x[])
{
     for(int s=0;s<1000;s++)if(x[s].name==n)
             {
             cout<<"Ocean or sea named "<< x[s].name <<" with area: "<<x[s].area<<" with max depth : "<<x[s].depth<<"km"<<endl;
             cout<<"Enter new values, first name, then area and depth \n";
             cin.ignore();
             getline(cin,x[s].name);
             cin>>x[s].area;
             cin>>x[s].depth;
             }
     
}
int main()
{
     Ocean a[1000];
     for(int i=0;i<1000;i++)a[i].number=i+1;
     string line;
     int k=0;
     ifstream myfile ("Oceans.txt");
     if (myfile.is_open()){
                           while (getline( myfile, line ))
                                           {
                                           
                                           istringstream liness( line );
                                            getline( liness, a[k].name,';');
                                            getline( liness, a[k].area,';');
                                            getline( liness, a[k].depth,';');
                                            k++;
                                            }
                            myfile.close();
                            }
     else cout << "Unable to open file"; 

    cout<<"L";
	Sleep(500);
	cout<<"O";
	Sleep(500);
	cout<<"A";
	Sleep(500);
	cout<<"D";
	Sleep(500);
	cout<<"I"; 
	Sleep(500);
	cout<<"N";
	Sleep(500);
	cout<<"G \n";
	Sleep(500);
    
    cout<<"Sample data has already been entered \n\n";
    
    string choice="1";
    string second="0";
    string third="";
    
    while(choice!="0")
    {
                    cout<<"Enter 1 for output \n";
                    cout<<"      2 for input \n";
                    cout<<"      0 for exit \n";
                    cin>>choice;
                    if(choice=="1"){ cout<<" 1 for all data \n 2 for individual search \n";
                                   cin>>second;
                                   if(second=="1")print(a);
                                   if(second=="2"){cout<<"Enter name of the record you are searching for \n";
                                                              cin.ignore();
                                                              getline(cin,third);
                                                              search(third,a);
                                                }
                                 }
                    if(choice=="2"){cout<<" 1 for a new record \n 2 for deleting a record \n 3 for modifying a record \n";
                                  cin>>second;
                                  if(second=="1")add(a);
                                  if(second=="2"){cout<<"Enter the name of the record that you want to delete \n";
                                                 cin.ignore();
                                                 getline(cin,third);
                                                 del(third,a);
                                                 }
                                  if(second=="3"){cout<<"Enter name of the record you are searching for \n";
                                                              cin.ignore();
                                                              getline(cin,third);
                                                              edit(third,a);
}                                                             }
}

     ofstream file("Oceans.txt");                                                        
     for(int f=0;f<1000;f++){
             if(a[f].name!=""){
                file<<a[f].name;
                file<<";";
                file<<a[f].area;
                file<<";";
                file<<a[f].depth;
                file<<endl;}
			}
     file.close();
    system("pause");
    return 0;
}

