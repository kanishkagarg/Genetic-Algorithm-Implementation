ALGORITHM AND PROBLEM SOLVING LAB 
PROJECT REPORT
APPLICATIONS OF GENETIC ALGORITHM


Introduction
This project is based on GENETIC ALGORITHMS and their applications.Genetic Algorithms (GAs) are adaptive heuristic search algorithm based on the evolutionary ideas of natural selection and genetics. As such they represent an intelligent exploitation of a random search used to solve optimization problems. Although randomised, GAs are by no means random, instead they exploit historical information to direct the search into the region of better performance within the search space. The basic techniques of the GAs are designed to simulate processes in natural systems necessary for evolution, especially those follow the principles first laid down by Charles Darwin of "survival of the fittest.". Since in nature, competition among individuals for scanty resources results in the fittest individuals dominating over the weaker ones.

The Two Applications of GA
CARGO SHIP LOADING:
Cargo ship load is a real problem when you have huge amount of cargo to be loaded to a ship with a specific load capacity.Solution to this problem is to take maximum worth of load to be shipped with minimal weight i.e minimum weight and maximum capacity.Either a cargo is loaded or not loaded.It can’t be loaded partially.
TRAVELLING SALESMAN PROBLEM:
The Travelling Salesman Problem or the TSP is a representative of a large class of problems known as combinatorial optimization problems. In the ordinary form of the TSP, a map of cities is given to the salesman and he has to visit all the cities only once to complete a tour such that the length of the tour is the shortest among all possible tours for this map.
Applications of the Project
CARGO SHIP LOADING:
It can be used in real life where certain amount of cargo are to be shipped having certain worth.
TRAVELLING SALESMAN PROBLEM:
Arranging school bus routes to pick up the children in a school district.
A classic example is the scheduling of a machine to drill holes in a circuit board or other object.   In this case the holes to be drilled are the cities, and the cost of travel is the time it takes to move the drill head from one hole to the next.  The technology for drilling varies from one industry to another, but whenever the travel time of the drilling device is a significant portion of the overall  manufacturing process then the TSP can play a role in reducing costs. 
Routing of trucks for parcel post pickup.
Delivery of meals to homebound people
Scheduling of stacker cranes in warehouses.
Algorithms used in the project :
CARGO SHIP LOADING & TRAVELLING SALESMAN PROBLEM :
Genetic algorithm is used in this project.
		1. Initialization of population
		2. Fitness
		3. Crossover
		4. Mutation			
Results and Screenshots of the output
CARGO SHIP LOADING:
In result we get a menu driven program which first asks the capacity of the cargo ship and then displays the menu
Pressing 1 creates our initial population. 1 represent the the weight being present in the bag and 0 denotes it’s absence.

Now, printing it’s fitness table. Here the total benefit associated with each bag denote it’s fitness.

Pressing 2 applies the crossover and mutation operator on the already created population.



Pressing 3 gives us our final result where 1 shows the weights to be included from our input and also prints our total weight and total benefit.



TRAVELLING SALESMAN PROBLEM:
In result we get a menu driven program which has a menu like this 


Pressing 1 creates our initial population. And outputs the population as the Index number of the city along with it’s fitness and a serial number.

Pressing 2 works the crossover and mutation operators on our initial population giving us the 2 selected parents and the offspring as output. It then calculates the fitness of the offspring and replaces it with the lowest fitness person of our initial population.

Pressing 3 gives us our calculated output i.e. the best fitness path along with the distance.

Comparison with other techniques
Genetic Algorithm is a good alternative to other algorithms to solve NP problems.Well, huge dataset may take few year or may be infinite amount of time to be solved and GA do it within few minutes.


References
CARGO SHIP LOADING:
The Coding Train (Youtube Channel)
www.tutorialspoint.com
www.geeksforgeeks.org
TRAVELLING SALESMAN PROBLEM:
www.tutorialspoint.com
www.geeksforgeeks.org
https://pdfs.semanticscholar.org/c31b/fd16935da83e419d631245272d7838262308.pdf
http://www.ppgia.pucpr.br/~alceu/mestrado/aula3/IJBB-41.pdf

Division of work among group members
Everyone was equally interested, determined and has contributed to the project.
