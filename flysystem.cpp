
#include<stdlib.h>

#include<conio.h>

#include <stdlib.h>

#include<string>                 

#include<ctype.h>                   

#include<dos.h> 

#include<iostream>

#include<ctime>

#include<fstream>

#include<iomanip>

#include <vector>

#include<iterator>

#include<sstream>

#include <unistd.h>

#include<time.h>



using namespace std;
string natID ;
int n;
int quit = true ;
const char local[5][20]={"ISTANBUL","ANKARA","IZMIR","ANTALYA","KONYA"};	//local Destination
const char International[11][20]={"LONDON","BERLIN","DUBAI","RIYADH","BEIJING","PARIS","ISTANBUL","TOKYO","WASHINGTON","DELHI","MOSCOW" }; //International Destination

int enterFaceAdminstration(){

			cout<<"\t\t\t\t\t\t\t\t\t\t\t\t<1> BOOKING \n\t\t\t\t\t\t\t\t\t\t\t\t"
									  "<2> COMPLAINT \n\t\t\t\t\t\t\t\t\t\t\t\t"
									  "<3> ABOUT \n\t\t\t\t\t\t\t\t\t\t\t\t"
									  "<4> MANAGE \n\t\t\t\t\t\t\t\t\t\t\t\t"
									  "<5> Q U I T \n \n  Enter your choice:"<<endl;
									  cin>>n;
								


		return n; 
}



string getnatID(){
	
		cout<<"Pelese Enter Your NATIONAL ID :\n";
			cin>>natID;

		return natID;
					
	}	
int gotoSwitch(){
	
		cout<<"<1>Go to main menu?\n"; 
		cout<<"<2> Exit the program?\n";
		cin>>n;
		if (n ==1){
			//cout<<__FUNCTION__<<endl;   need some function here to call the main but i ll need to change all my code cuz irelized that is better to call function from the main itself!!!!
	
		}
		if(n==2){
			
			quit= false;
		}
		else{
			cout<<"You Have Entered Worrong !!";
			gotoSwitch();
		}
	
}	



class csvRow{
	
	public :
		
		string const& operator[](size_t index)const {
		
		return m_data[index];
		
		}
		
		size_t size()const {
		return m_data.size();
		
		}
		
		void readNextRow(istream& str){
			
			string line;
			getline(str, line);
			std::stringstream lineStream(line);
			string cell;
			
			m_data.clear();
			while(getline(lineStream, cell, ',')){
				
				m_data.push_back(cell);
				
			}
			if(!lineStream && cell.empty()){
				
				m_data.push_back("");
			}
			
		}
	private :
		
		vector<string>m_data; 	
};




istream& operator>>(istream& str, csvRow& data) {
	data.readNextRow(str);
	return str;
}




	
	
class booking{
	
	
	public :
		
	
	
	void flyCheeck(){
			
			cout<<"\t\t\t\t\t\t\t\t\t\t\t\t<1> INTERNATIONAL \n\t\t\t\t\t\t\t\t\t\t\t\t"	
									  "<2> LOCAL \n\t\t\t\t\t\t\t\t\t\t\t\t"
									  "<3> Q U I T \n \n  Enter your choice:"<<endl;
				cin>>flyType;

		if (flyType == "1" ){ 
			
				getInformationInternational();		
				setInformationInternational();
			     
			return;
		}
		if (flyType == "2" ){ 
		
				getInformationLocal();
				setInformationLocal();
			     
			return;
		}
		else {
			cout<<"HAVE A GOOD DAY "<<endl;
			enterFaceAdminstration();
			sleep(2);	
			system("CLS");
			return ;
			
		}
	}
	
		
		
	int getInformationInternational(){
		
		system("CLS");
		cout<<endl<<"These are the International destinations where we are flying: \n";
		for(int i=0;i<11;i++)
		{
			for(int j=0;j<20;j++)
			{
				cout<<International[i][j];
			}
			cout<<"\n";
		}

		{
			getnatID();
		}
		
		cout<<"Please Enter From Which Country Your Traviling\n";
			cin>>countryFrom;
		cout<<"Please Enter Which Country Your Traviling To\n";
			cin>>countryTo;	
		cout<<"Please Enter Your FIRS Name :\n";
			cin>>name;
		cout<<"Please Enter Your MOTHER Name :\n";
			cin>>motherName;
		cout<<"Please Enter Your FATHER Name :\n";
			cin>>fatherName;
		cout<<"Plese Enter Your FAMILY Name :\n";
			cin>>familyName;		
		cout<<"Please Enter Your Full ADDRESS :\n";
			cin>>address;
		cout<<"Please Enter Your PHONE NUMBER :\n";
			cin>>phoneNumber;
		cout<<"Please Enter Your Email ADDRESS :\n";
			cin>>email;
		cout<<"Enter date of departure(DD/MM/YYYY): ";
			cin>>datedep;	
		cout<<"Are You Looking For Pick Up <YES||NO> ?\n";
			cin>>pickUp;
			
																		
	}	
	
	
	
		int getInformationLocal(){
			
		system("CLS");
		cout<<endl<<"These are the local destinations where we are flying: \n";
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<20;j++)
			{
				cout<<local[i][j];
			}
			cout<<"\n";
		}
		
			{
			getnatID();
			}
		
		cout<<"Please Enter From Which Country Your Traviling\n";
			cin>>countryFrom;
		cout<<"Please Enter Which Country Your Traviling To\n";
			cin>>countryTo;	
		cout<<"Please Enter Your FIRS Name :\n";
			cin>>name;
		cout<<"Please Enter Your MOTHER Name :\n";
			cin>>motherName;
		cout<<"Please Enter Your FATHER Name :\n";
			cin>>fatherName;
		cout<<"Plese Enter Your FAMILY Name :\n";
			cin>>familyName;		
		cout<<"Please Enter Your Full ADDRESS :\n";
			cin>>address;
		cout<<"Please Enter Your PHONE NUMBER :\n";
			cin>>phoneNumber;
		cout<<"Please Enter Your Email ADDRESS :\n";
			cin>>email;
		cout<<"Enter date of departure(DDMMYYYY):\n ";
			cin>>datedep;	
		cout<<"Are You Looking For Pick Up <YES||NO> ?\n";
			cin>>pickUp;

			
						
																		
	}	
	
	
	
	
	int setInformationInternational(){// for the inter national 
		
	ofstream Fout;
	time_t now;
	struct tm nowLocal;
	now = time (NULL);
	nowLocal = *localtime(&now);
	Fout.open("fly.csv", ios::app);
	srand( time(NULL) );
	int ticketNum = rand() % 10000;
	int timeFly = rand () % ((24-1)+1);
	Fout<<natID<<','<<name<<','<<fatherName<<','<<familyName<<','<<motherName<<','<<phoneNumber<<','<<address<<','<<nowLocal.tm_mday<<"/"<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_year+1900<<','<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<" "<<','<<email<<','<<datedep<<','<<"FROM"<<','<<countryFrom<<','
	 <<"TO"<<','<<countryTo<<','<<"TK-"<<ticketNum<<','<<timeFly<<" 00:AM"<<','<<"pick up situation:"<<','<<pickUp<<'\n';
	cout<<"L";
	usleep(33000);
	cout<<"O";
	usleep(33000);
	cout<<"D";
	usleep(33000);
	cout<<"I";
	usleep(33000);
	cout<<"N";
	usleep(33000);
	cout<<"G"<<endl;
	cout<<"Your Ticket Habe Been Saved Thank You For Using Turin Airline \n";
	gotoSwitch();
	

  	}
  	int setInformationLocal(){// for the local
		
	ofstream Fout;
	time_t now;
	struct tm nowLocal;
	now = time (NULL);
	nowLocal = *localtime(&now);
	Fout.open("fly.csv", ios::app);
	srand( time(NULL) );
	int ticketNum = rand() % 10000;
	int timeFly = rand () % ((24-1)+1);
	Fout<<natID<<','<<name<<','<<fatherName<<','<<familyName<<','<<motherName<<','<<phoneNumber<<','<<address<<','<<nowLocal.tm_mday<<"/"<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_year+1900<<','<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<" "<<','<<email<<','<<datedep<<','<<"FROM"<<','<<countryFrom<<','
	 <<"TO"<<','<<countryTo<<','<<"TK-"<<ticketNum<<','<<timeFly<<" 00:AM"<<','<<"pick up situation:"<<','<<pickUp<<'\n';
	cout<<"L";
	usleep(33000);
	cout<<"O";
	usleep(33000);
	cout<<"D";
	usleep(33000);
	cout<<"I";
	usleep(33000);
	cout<<"N";
	usleep(33000);
	cout<<"G"<<endl;
	cout<<"Your Ticket Habe Been Saved Thank You For Using Turin Airline \n";
	gotoSwitch();
	

  	}
  	
 	private : 
	string address;
	string motherName;
	string fatherName;
	string name;
	string nameCandidate;
	string date;
	string phoneNumber; 
	string familyName;	
	string email;
	string datedep;
	string flyType;
	string countryFrom;
	string countryTo;
	string pickUp;

};












class complain{
	
	
	
	public :
		
		void problem(){
		system("CLS");
		//FILE *fptr;
		time_t now;
		struct tm nowLocal;
		now = time (NULL);
		nowLocal = *localtime(&now);
		cout<<"what is you type of complaine?"<<endl;
		cout<<"<1>Airport Handling: "<<endl;
		cout<<"<2>Baggage Delivery: "<<endl;
		cout<<"<3>Booking and Ticketing: "<<endl;
		cout<<"<4>Other: "<<endl;
		cin>>n;
		switch (n){
			case 1:
				system("CLS");
				cout<<"<1>Airport Handling: "<<endl;
				cout<<"Enter your first name	:"<<endl;
				cin>>firstName;
				cout<<"Enter your last name	:"<<endl;
				cin>>lastName;
				cout<<"Enter your note here Without space	:"<<endl;
				
				cout<<"Press Enter when you are finish"<<endl;
				cin>>yourComplain;
				{
					if (cin.get() == '\n' ){
						ofstream Fout;
						Fout.open("Airport Handling.csv", ios::app);
						Fout<<natID<<','<<firstName<<','<<lastName<<','<<yourComplain<<','<<nowLocal.tm_mday<<"/"<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_year+1900<<','<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<" "<<'\n';
						cout<<"L";
						usleep(33000);
						cout<<"O";
						usleep(33000);
						cout<<"D";
						usleep(33000);
						cout<<"I";
						usleep(33000);
						cout<<"N";
						usleep(33000);
						cout<<"G"<<endl;
						cout<<"Your Complaine have been taken Thank you  \n";

	
					}
				}
				break;
			case 2:	
				system("CLS");
				cout<<"<2>Baggage Delivery:"<<endl;
				cout<<"Enter your first name	:"<<endl;
				cin>>firstName;
				cout<<"Enter your last name	:"<<endl;
				cin>>lastName;
				cout<<"Enter your note here	:"<<endl;
				cout<<"Press Enter when you are finish"<<endl;
				cin>>yourComplain;
				{
					if (cin.get() == '\n' ){
						//ofstream out("baggage.txt");
						ofstream Fout;
						Fout.open("Airport Handling.csv", ios::app);
						Fout<<natID<<','<<firstName<<','<<lastName<<','<<yourComplain<<','<<nowLocal.tm_mday<<"/"<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_year+1900<<','<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<" "<<'\n';
						cout<<"L";
						usleep(33000);
						cout<<"O";
						usleep(33000);
						cout<<"D";
						usleep(33000);
						cout<<"I";
						usleep(33000);
						cout<<"N";
						usleep(33000);
						cout<<"G"<<endl;
						cout<<"Your Complaine have been taken Thank you  \n";
					}
				}
				break;
			case 3:	
				system("CLS");
				cout<<"<3>Booking and Ticketing:  "<<endl;
				cout<<"Enter your first name	:"<<endl;
				cin>>firstName;
				cout<<"Enter your last name	:"<<endl;
				cin>>lastName;
				cout<<"Enter your note here	:"<<endl;
				cout<<"Press Enter when you are finish"<<endl;
				cin>>yourComplain;
				{
					if (cin.get() == '\n' ){
						//ofstream out("Booking and Ticketing.txt");
						ofstream Fout;
						Fout.open("Airport Handling.csv", ios::app);
						Fout<<natID<<','<<firstName<<','<<lastName<<','<<yourComplain<<','<<nowLocal.tm_mday<<"/"<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_year+1900<<','<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<" "<<'\n';
						cout<<"L";
						usleep(33000);
						cout<<"O";
						usleep(33000);
						cout<<"D";
						usleep(33000);
						cout<<"I";
						usleep(33000);
						cout<<"N";
						usleep(33000);
						cout<<"G"<<endl;
						cout<<"Your Complaine have been taken Thank you  \n";
					}
				}
				break;
			case 4:	
				system("CLS");
				cout<<"<4>Other: "<<endl;
				cout<<"Enter your first name	:"<<endl;
				cin>>firstName;
				cout<<"Enter your last name	:"<<endl;
				cin>>lastName;
				cout<<"Enter your note here	:"<<endl;
				cout<<"Press Enter when you are finish"<<endl;
				cin>>yourComplain;

				{
					if (cin.get() == '\n' ){
						//ofstream out("Other.txt");
						ofstream Fout;
						Fout.open("Airport Handling.csv", ios::app);
						Fout<<natID<<','<<firstName<<','<<lastName<<','<<yourComplain<<','<<nowLocal.tm_mday<<"/"<<nowLocal.tm_mon+1<<"/"<<nowLocal.tm_year+1900<<','<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<" "<<'\n';
						cout<<"L";
						usleep(33000);
						cout<<"O";
						usleep(33000);
						cout<<"D";
						usleep(33000);
						cout<<"I";
						usleep(33000);
						cout<<"N";
						usleep(33000);
						cout<<"G"<<endl;
						cout<<"Your Complaine have been taken Thank you  \n";
					}
				}
				break;
				
				default :{
					cout<<"You Entered Wrrong Choice Please Try Agin :"<<endl;
					problem();
				
					break;
					
				}
			
		}
		
		
	
	}
		
		
		
	
	
	private	:	
	string firstName;
	string lastName;
	string yourComplain;
	
	
	
	
};







class about
{
	public:
		void Aboutus()
		{
			cout<<"The height of skies was first touched by our airline in 1950. Since then,\nTURIN Fly is the world's leading airline with 500 biggest airplanes.\nWe are at the customers high service in cuisine, comfort and care.\nSo make a plan and fly high with TURIN Fly."<<endl<<endl;
			cout<<"Press any key to continue...";
		}
	
};


class manage
{
	

	public:				
		
		
		void find(){
			ifstream file("fly.csv");
			csvRow row ;
			getnatID();
			system("CLS");
		while(file >> row ){
				
		
			if (row[0]==natID){
				cout<<"YOUR FLIGHT INFORMATION"<<endl;
				cout<<"ID          :"<<row[0]<<endl;
				cout<<"Name        :"<<row[1]<<" "<<row[2]<<" "<<row[3]<<endl;
				cout<<"Mother name :"<<row[4]<<endl;
				cout<<"Phone Number:"<<row[5]<<endl;
				cout<<"Address	    :"<<row[6]<<endl;
				cout<<"Date buying :"<<row[7]<<endl;
				cout<<"Time buying :"<<row[8]<<endl;
				cout<<"Email       :"<<row[9]<<endl;
				cout<<"Fly date    :"<<row[10]<<endl;
				cout<<"Flying "<<row[11]<<" :"<<row[12]<<endl;
				cout<<row[13]<<"          :"<<row[14]<<endl;
				cout<<"Ticket NUM  :"<<row[15]<<endl;
				cout<<"Flight Time :"<<row[16]<<endl;
				cout<<""<<row[17]<<""<<row[18]<<""<<row[19]<<""<<row[20]<<endl;
			}

			
			/*	else {
				cout<<"Sorry ! Wrong Input !"<<endl;
				cout<<"Do you Want To Enter New Date OR go another ID User ?"; /////////////////////
				cin>>n;
	 			if(n=='1'||n=='2'){
	 					manage mag;
						mag.find();
	 					
		 		}
		 			else{
		 				
						quit = false;
						
								 			
		 			
		 			}
					
				}*/	
			
		}
				if (row[0]!=natID)
				{
		
					cout<<"Sorry ! Wrong Input !"<<endl;	
		
				}			
		}
				
};





int main (){
	
enterFaceAdminstration();
booking bookingfly;
about aboutreport;
complain tellus;
manage findfly;

	switch (n){
		
		case 1:
			
			bookingfly.flyCheeck();
			
				break ;
		
		case 2:
			
			tellus.problem();
			
				break;	
		case 3:
			
			aboutreport.Aboutus();
			
				break;
		case 4:
			findfly.find();
			
				break;
		case 5 :
			
			quit= false;
			
				break;
			
		default :{
		
					cout<<"You Entered Wrrong Choice Please Try Agin :"<<endl;
		
					main();
				
					break;
		}		
									
	}
	
	
	
}


	
