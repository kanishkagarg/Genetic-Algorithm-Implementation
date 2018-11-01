
#include <bits/stdc++.h>
#include <algorithm>
#include <unistd.h>

using namespace std;

struct str
{
	int index;
	string name;
	double x;
	double y;
};

vector <str> v;
vector <int> population[100];
vector <double> fin;


void start()
{	
	cout << "\n\n\n\n\n\n\t\t\t\033[0;31mALGORITHM AND PROBLEM SOLVING PROJECT\033[0m\n" ;
	cout << "\n\t\tTravelling Salesman Problem by Genetic Algorithm\n " ;
	cout << "\n\n\n\t\tHarsh Vishnoi		16803030" ;
	cout << "\n\t\tNaima Farooqi		16803005" ;
	cout << "\n\t\tKanishka Garg		16803012" ;
	cout << "\n\n\n\n" ;
	cout << "\t********************************************************\n" ;
}

void Create_InitialPopulation(int n1)
{	
	int l=v.size();
	vector <int> pop;
	
	for(int i=1;i<l;i++)
		pop.push_back(i);
	int t=n1;
	while(t)
	{	
		random_shuffle(pop.begin(),pop.end());
		for(auto it=pop.begin();it!=pop.end();it++)
			population[t-1].push_back(*it); 

		
		t--;
	}
}

void fitness(vector <int> population[100],int n)
{
	int t=n;		double fitness_score ;
	while(t)
	{
		auto it = population[t-1].begin();
		fitness_score = 0.0;		double pre_x = v[*it-1].x;				double pre_y = v[*it-1].y;

		for(auto it=population[t-1].begin()+1;it!=population[t-1].end();it++)
		{
			double cur_x = v[*it-1].x;			double cur_y = v[*it-1].y;
			fitness_score = fitness_score + sqrt(pow((cur_y)-(pre_y),2) + pow((cur_x)-(pre_x),2));
			pre_x = cur_x;			pre_y = cur_y;
		}

		fin.push_back((1/fitness_score)*10000);// Fitness = (1/fitness_score8)*10000

		t--;
		
	}
}

vector <int> mutate(vector <int> a)
{	
	int a_slice;
	a_slice= rand() % (a.size()-2);
	swap(a[a_slice],a[a_slice+1]);
	cout<<"\n\tAfer mutation the Offspring becomes: \n\t";
	
	for(auto it=a.begin();it!=a.end();it++)
	{
		cout<<*it<<"-> ";
	}
	cout<<endl;

	return a;
}

vector <double> crossover(vector <int> population[100],vector <double> fin,int n)
{	
	vector <int> a;
	vector <int> b;
	sleep(2);
	
	auto index_1=max_element(fin.begin(),fin.end()) - fin.begin();
	cout << "\tParent 1 Index: "<< index_1 <<" with fitness score: " << fin[index_1] << "\n\t";
	for(auto it=population[n-1-index_1].begin();it!=population[n-1-index_1].end();it++)
	{
		a.push_back(*it);
		cout<< *it <<"-> ";
		
	}

	cout << endl;
	double temp=fin[index_1];
	fin[index_1]=0.0;
	n--;
	auto index_2=max_element(fin.begin(),fin.end()) - fin.begin();
	cout << "\tParent 2 Index: "<< index_2 <<" with fitness score: " << fin[index_2] << "\n\t";

	for(auto it=population[n-1-index_2].begin();it!=population[n-1-index_2].end();it++)
	{
		b.push_back(*it);
		cout<<*it<<"-> ";
		
	}
	cout << endl;
	fin[index_1]=temp;
	vector <int> child;
	int a_slice=0,b_slice=0;
	a_slice= rand() % (a.size()-1);
	b_slice=rand() % (a.size()-1) + a_slice;
	
	for(int i=a_slice;i<b_slice;i++)
		
	{
		child.push_back(a[i]);
		
	}
	
	for(auto it=b.begin();it!=b.end();it++)
	{
		if(!(find(child.begin(),child.end(),*it)!=child.end()))
			child.push_back(*it);
		
	}
	vector <int> child1;
	for(auto it=b.begin();it!=b.end();it++)
	{
		if(*it>0 && *it<100)
			child1.push_back(*it);
		
	}
	child=child1;
	cout << "\n\tTheir Offspring :\n\t" ;
	for(auto it= child.begin();it!=child.end();it++)
	{
		cout << *it << "-> ";
	}
	cout<<endl;
	auto index_11=min_element(fin.begin(),fin.end()) - fin.begin();
	cout<< "\n\n\tNow element with lowest fitness function will be removed i.e: " << index_11 << " which was with fitness score "<< fin[index_11]<<endl;
	
	population[n-index_11].clear();

	for(auto it= child.begin();it!=child.end();it++)
	{
		population[n-index_11].push_back(*it);
	}

	population[n-index_11]=mutate(population[n-index_11]);

	auto it = population[n-index_11].begin();
		double fitness_score = 0.0;		double pre_x = v[*it-1].x;				double pre_y = v[*it-1].y;
		for(auto it=population[n-index_11].begin()+1;it!=population[n-index_11].end();it++)
		{
			double cur_x = v[*it-1].x;			double cur_y = v[*it-1].y;
			
			fitness_score = fitness_score + sqrt(pow((cur_y)-(pre_y),2) + pow((cur_x)-(pre_x),2));
			pre_x = cur_x;			pre_y = cur_y;
		}
		double f=(1/fitness_score)*10000;
		cout<< "\tand replaced with new fitness score "<< f<<endl;
	


	fin.at(index_11)=f;
	return fin;
}

void result(vector <int> population[100],vector <double> fin,int n)
{	
	double distance=0.0;
	sleep(2);
	auto index_1=max_element(fin.begin(),fin.end()) - fin.begin();
	cout << "\n\n\t\t\t\033[0;31mRESULT:\033[0m\n" ;
	cout << "\n\tBest path is at the Index: "<< index_1 <<" with fitness score: " << fin[index_1] << endl;
	cout << "\n\tTHE PATH IS \n\t";
	for(auto it=population[n-1-index_1].begin();it!=population[n-1-index_1].end();it++)
	{
		cout<< *it <<"-> ";	
	}
	cout<<"\n\n\t  \033[0;31mREPRESENTING IN TERMS OF CITIES:\033[0m \n\n\t";
	for(auto it=population[n-1-index_1].begin();it!=population[n-1-index_1].end();it++)
	{
		cout<< v[*it-1].name <<"-> ";	
	}

	cout<<"\n\n\n"<<endl;
	distance=10000/fin[index_1];
	cout << "\n\tThe distance of this path is "<<distance<< " units\n\n";
}

int main()
{
	ifstream ip;
	ip.open("data.csv");
	if(!ip.is_open())
		cout << "ERROR" << endl;
	else
	{
		while(ip.good())
		{
			string index1;		getline(ip,index1,',');		stringstream ss(index1); int index=0; ss>>index;
			string name;		getline(ip,name,',');
			string locx1;		getline(ip,locx1,',');		stringstream ss1(locx1);  double locx=0.0; ss1>>locx;
			string locy1;		getline(ip,locy1);			stringstream ss2(locy1);  double locy =0.0; ss2>>locy;			
			v.push_back({index,name,locx,locy});
		}
	}

	//start();
	
	sleep(2);

	cout << "\n\t\033[0;31mNOW CREATING OUR INITIAL POPULATION\033[0m\n\n\n" ;
	Create_InitialPopulation(100);
	
	fitness(population,100);

	for(int i=99;i>=0;i--)
	{
		cout << "\t" ;
		for(auto it=population[i].begin();it!=population[i].end();it++)
		{
			cout << " "<< *it << " -> " ;
		}
		cout << setw(20) << fin.at(99-i) << setw(20) << 99-i << endl;
	}
				
	int l=v.size()-1;
	cout<<"\n\t\033[0;31mNOW AFTER APPLYING CROSSOVER AND MUTATION OPERATORS :\033[0m \n\n";
	for(int i=0;i<l-1;i++)
	{
		fin=crossover(population,fin,100);
		cout << "\n\n\t----------------------------" << endl;
	}
		
	result(population,fin,100);

	return 0;
}

//sleep(0.2);