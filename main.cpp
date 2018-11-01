#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

void start()
{	
	cout << "\n\n\n\n\n\n\t\t\t\033[0;31mALGORITHM AND PROBLEM SOLVING PROJECT\033[0m\n" ;
	cout << "\n\t\tGenetic Algorithm\n " ;
	cout << "\n\n\n\t\tHarsh Vishnoi		16803030" ;
	cout << "\n\t\tNaima Farooqi		16803005" ;
	cout << "\n\t\tKanishka Garg		16803012" ;
	cout << "\n\n\n\n" ;
	cout << "\t********************************************************\n" ;
}

int main()
{
	start();
	sleep(2);
	int flag = 0;
	while(flag==0)
	{
		cout << "\n\n\n\tChoose between these two \n";
		cout << "\n\t1." << setw(25) << "Travelling Salesman Problem by Genetic Algorithm \n";
		cout << "\n\t2." << setw(25) << "Cargo Ship and Truck Load problem by Genetic Algorithm \n";
		cout << "\n\n\t Otherwise ,any other key to exit\t\t";
		int n;
		cin >> n;
		if(n==1)
				system("./tsp");
		else if(n==2)
				system("./cargo");
		else
			flag=1;
	}
	cout << "\n\n\t******************************************************\n\n\n\n";
	return 0;
}