#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
	#define population_size 100
	#define generations 75

vector <int> pop[population_size];

struct knap_sack
{
	int index;
	int weight;
	int benefit;
};

vector <knap_sack> v;
//Fitness is calculated and later on pushed into this vector where weight and benefit is given
//Index is used in this vector to tell whether it is valid or not
vector <knap_sack> Ans;

bool valid(vector <int> pop[], int x,long knap_sack_capacity);

int max(int a, int b) { return (a > b)? a : b; }

void Create_Initial_Population()
{
	for(int j=0;j<population_size;j++)
		for(int i=0;i<v.size();i++)
		{
			int no = rand()%2;
			pop[j].push_back(no);
		}	
}

int first()
{
	int small_first = -1;
	int it_return;
	for(auto it=Ans.begin();it!=Ans.end();it++)
	{
		if(small_first < it->benefit)
		{
			small_first = it->benefit;
			it_return = it->index;
		}
	}
	return it_return;
}

void fitness()
{
	for(int i=0;i<population_size;i++)
	{
		static int l = 0;
		auto k = v.begin();		int total_weight = 0;		int total_benefit = 0;
		for(auto it=pop[i].begin();it!=pop[i].end();it++)
		{
			if(*it==1)
			{
				total_weight = total_weight + k->weight;		total_benefit = total_benefit + k->benefit;
			}
			k++;
		}
		Ans.push_back({l,total_weight,total_benefit});
		///fit_value.push_back(total_benefit);
	l++;
	}
}

void print_fitness()
{
	int i=0;
	auto it_1 = Ans.begin() + first();
	cout << "      Index         Weights	 Benefits " << "\n\n";
	for(auto it=Ans.begin();it!=Ans.end();it++)
	{
		if(i%15 == 0)
			sleep(1);
		cout << setw(10) << it->index << setw(15) << it->weight << setw(15) << it->benefit  << endl;
		i++;
	}
}

void print_pop()
{
	for(int j=0;j<population_size;j++)
	{	
		cout << " Population -----------		" << j << "\t  " ;
		if(j%20 == 0)
			sleep(1);
		for(auto it=pop[j].begin();it!=pop[j].end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}	
	cout << endl;
}

void make_valid(vector <int> pop[],int x,long knap_sack_capacity)
{
	auto it_ans = Ans.begin() + x;		auto it_v = v.begin();		
	int small_weight = 999999;			int small_benefit = 999999;
	vector <int> :: iterator it,it_1;
	for(it=pop[x].begin();it!=pop[x].end();it++)
	{
		if(*it == 1)
		{
			if(it_v->weight <= small_weight && it_v->benefit < small_benefit)
			{
				small_benefit = it_v->benefit;
				small_weight = it_v->weight;
				it_1 = it;
			}		
		}
		it_v++;
	}
	*it_1=0;
	it_ans->weight = it_ans->weight - small_weight;
	it_ans->benefit = it_ans->benefit - small_benefit;
	//cout << it_ans->weight << "   " << it_ans->benefit << "  " << it_ans->index <<  endl;
	if(!valid(pop,x,knap_sack_capacity))
		make_valid(pop,x,knap_sack_capacity);
}

bool valid(vector <int> pop[], int x,long knap_sack_capacity)
{
	auto it = Ans.begin() + x;
	if(it->weight > knap_sack_capacity )
		return false;
	else
		return true;
}

int second()
{
	int small_sec = 0;
	auto it_1 =  Ans.begin() + first();
	int it_return;
	for(auto it=Ans.begin();it!=Ans.end();it++)
	{
		if(small_sec < it->benefit && it->benefit < it_1->benefit)
		{
			small_sec = it->benefit;
			it_return = it->index;
		}
	}
	return it_return;
}

int small()
{
	int smallest = 9999;
	int it_return;
	for(auto it=Ans.begin();it!=Ans.end();it++)
	{
		if(smallest > it->benefit)
		{
			smallest = it->benefit;
			it_return = it->index;
		}
	}
	return it_return;
}

bool comp(const pair<double,int> &a ,const pair<double,int> &b)
{
	return (a.first > b.first);
}

void knapsack_ans()
{
	cout <<  endl;
	double array[population_size] = {0};
	auto it = Ans.begin();
	vector <pair<double,int>> vec;
	for(int i=0;i<population_size;i++)
	{
		array[i] = (double)((double)it->benefit/(double)it->weight); 
		vec.push_back(make_pair(array[i],i));
		it++;
	}
	sort(vec.begin(),vec.end(),comp);
	//for(auto it_1=vec.begin();it_1!=vec.end();it_1++)
	//	cout << setw(10) << it_1->first << setw(20) << it_1->second << endl;
}

void start()
{	
	cout << "\n\n\n\n\n\n\t\t\t\033[0;31mALGORITHM AND PROBLEM SOLVING PROJECT\033[0m\n" ;
	cout << "\n\t\tCargo Ship Loading\n " ;
	cout << "\n\n\n\t\tHarsh Vishnoi		16803030" ;
	cout << "\n\t\tNaima Farooqi		16803005" ;
	cout << "\n\t\tKanishka Garg		16803012" ;
	cout << "\n\n\n\n" ;
	cout << "\t********************************************************\n" ;
}

void fitness_1()
{
	auto k = v.begin();		int total_weight = 0;		int total_benefit = 0;
	for(auto it=pop[small()].begin();it!=pop[small()].end();it++)
	{
		if(*it==1)
		{
			total_weight = total_weight + k->weight;		total_benefit = total_benefit + k->benefit;
		}
		k++;
	}
	auto it_ans = Ans.begin() + small();
	it_ans->index = small();	it_ans->weight = total_weight;		it_ans->benefit = total_benefit;
}

void crossover()
{
	pop[small()].erase(pop[small()].begin(),pop[small()].end());
	for(auto it_1 = pop[first()].begin();it_1!=pop[first()].begin()+4;it_1++)
		pop[small()].push_back(*it_1);
	for(auto it= pop[second()].begin()+4;it!=pop[second()].end();it++)
		pop[small()].push_back(*it);
}

void mutation()
{
	int x = rand()%v.size();
	auto it = pop[small()].begin() + x;
	if(*it==1)
		*it=0; 
	else
		*it=1;
}

int main()
{
	ifstream ip;
	ip.open("Cargo_data.csv");
	if(!ip.is_open())
		cout << "ERROR" << endl;
	else
	{
		while(ip.good())
		{
			string index1;		getline(ip,index1,',');		int index = stoi(index1);
			string wei;			getline(ip,wei,',');		int weight = stoi(wei);
			string ben;			getline(ip,ben);		int benefit = stoi(ben);			
			v.push_back({index,weight,benefit});
		}
	}
	sleep(1);

	cout << "\n\n  Enter the Capacity of Cargo ship \t\t";
	long knap_sack_capacity;
	cin >> knap_sack_capacity;
	//The function is used to create initial population where population size is intialised above;
	Create_Initial_Population(); 
	//Function is used just to print the population where population_size is initialised above;
	cout << "\n\t Initial populaiton is this --> \n\n";
	print_pop();
	//Function is used to calculate whether its valid or not.
	cout << "\n\t Initial fitness of population is as follows --> \n\n";
	fitness();
	//print_fitness();
	cout << "\n\n";
	for(int i=0;i<population_size;i++)
		if(!valid(pop,i,knap_sack_capacity))
			make_valid(pop,i,knap_sack_capacity);
	//Function used to print fitness values of all population
	print_fitness();
	
	int gen = generations;
	while(gen)
	{
		if(gen%15 ==0)
			sleep(1);	
		cout << "\n\t\tImproving Generation ------------	" << generations-gen+1 << endl;
		//cout << "\n\n";
		crossover();
		//cout << small() << " " << first() << " " << second() << endl;
		//print_pop();
		//cout << "\n\n";
		mutation();
		//print_pop();
		fitness_1();
		for(int i=0;i<population_size;i++)
		if(!valid(pop,i,knap_sack_capacity))
			make_valid(pop,i,knap_sack_capacity);
		//print_fitness();
		gen--;
	}
	for(int i=0;i<population_size;i++)
		if(!valid(pop,i,knap_sack_capacity))
			make_valid(pop,i,knap_sack_capacity);

	cout << "\n\t After " << generations << " generations, data seems to be as following \n\n"; 
	cout << "\n\n";
	cout << "\n\tFinal populaiton is this --> \n\n";
	print_pop();
	cout << "\n\t Final fitness of population is as follows --> \n\n";
	print_fitness();
	knapsack_ans();
	cout << "\n\n\t Best output is  -> ";
	for(auto it=pop[first()].begin();it!=pop[first()].end();it++)
		cout << *it << " ";
	cout << endl;
	auto it = Ans.begin() + first();
	cout << "\t\033[0;31m Index 		->\033[0m " << first() << endl;
	cout << "\t \033[0;31mWeight 	-> \033[0m" << it->weight << endl;
	cout << "\t\033[0;31m Benefit 	-> \033[0m" << it->benefit << endl;

	cout <<"\n\n\tCargo can contain atmost " << it->weight << " tons of weight having an optimal worth of " << it->benefit << " crores.\n\n";  
	return 0;
}