#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>

using namespace std;

//class edge will be two ints and there is an edge between the two
class edge{
    public:
    int vert1;
    int vert2;
       
    edge();
    edge(int, int);
     ~edge();

};

//default cons
edge::edge(){
	vert1 = 0;
	vert2 = 0;
}

//constructor to assign start and end of an edge
edge::edge(int a, int b): vert1(a), vert2 (b){//autoassign values
	
}

//vertexInput takes in a vector for vertices and the number of vertices to count
void vertexInput (vector<int> &vertices, int number){
	int vertex;
	stringstream ss;
	
	
	for(int i = 1; i <= number; i++){
		vertices.push_back(i);
		cerr << "Adding to vector " <<i << endl;
	}
}

//edgeInput takes in the vector for edges and number of edges and will 
// create the edges and put them in the vector
void edgeInput (vector <edge *> edges, int &number){
	int edge;
	stringstream ss;
	
	
	cout << "Enter the start and end points of the edges: " << endl;
	for(int i = 0; i < number; i++){
		int start, end;
		string line;
		stringstream ss;
		cout << "Enter the start and end point: ";
		getline(cin, line);
		ss << line;
		ss >> start;
		ss >> end;
		
		cout << endl;
		
		edge* e = new edge(start,end);
		
		edges.push_back(e);
		cerr << "Adding edge with start " << e->vert1 << " and end " << e->vert2 << endl;
	}
}

//threeCycles will check the edges of the graph to see if there are any cycles of length 3 and return a bool
bool threeCycles (vector <edge *> edges, int number){
	//need to go through each edge, take the start point and its end point, 
	//search list for all occurrences of the end point in the start point position
	//look at that edge and see if its end point is equal to the original start point
	bool found = false;
	int counter = 0;
	
	while (!found && counter < number){
		int start, end;
		
		start = edges[counter]->vert1;
		end = edges[counter]->vert2;
		
		for(int i = 0; i < number; i++){
			if(end == edges[i]->vert1){
				if(edges[i]->vert2 == start){
					found = true;
					break;
				}
			}
		}
		
		counter ++;
	}
	
	return found;
}

bool k33 (vector <edge *> edges,vector <int> vertices, int vnumber, int enumber){
	//k33 cycles require at least 6 vertices with at least 3 edges
	//create a vector
	bool valid = true;
	int vertMoreThan3 = 0;
	for(int i = 0; i < vnumber; i++){
		if(vertices[i] >= 3){
			vertMoreThan3++;
		}
	}
	
	if(vertMoreThan3 >= 6){
		//still maybe planar, will have to find a 6cycle, and 3 cuts straight across 
		// aka 1 to 4, 2 to 5, and 3 to 6
		
		return false; // assume it for now
	}else{
		return true; // definitely not k33
	}
}

bool k5 (vector <edge *> edges,vector <int> vertices, int vnumber, int enumber){
	//k33 cycles require at least 5 vertices with at least 4 edges
	//create a vector
	bool valid = true;
	int vertMoreThan4 = 0;
	for(int i = 0; i < vnumber; i++){
		if(vertices[i] >= 4){
			vertMoreThan4++;
		}
	}
	
	if(vertMoreThan4 >= 5){
		//still maybe planar, will have to find a the k5 pentagon where all vertices are connected
		
		return false; // assuming its not planar for now
	}else{
		return true; // definitely not k33
	}
}



//Main will take in input of edges and vertices and see if the graph is planar
int main(){
	//var for # of edges and vertices
	int vnumber = 0;
	int enumber = 0;
    
	edge* someEdge;
	bool planar = true;
	bool testing = true;
	bool found3cycle = false;
	
	vector<int> vertices;//all these v words confusing me
	vector <edge *> edges;
	
	cout << "Enter Number of Vertices: " << endl;
	cin >> vnumber;
	cout << "Enter Number of Edges: " << endl;
	cin >> enumber;
	
	vertexInput(vertices, vnumber);
	edgeInput(edges, enumber);
	
	//we will replace the vertices vertex with number of edges in said graph
	// to do so we must go through every edge, every start point and end point and add one to the corresponding vertex
	
	for(int i = 0; i < vnumber; i ++){
		vertices[i] = 0;
	}
	
	for(int i = 0; i < enumber; i ++){
		vertices[(edges[i]->vert1)]++;
		vertices[(edges[i]->vert2)]++;
	}
	
	
	found3cycle = threeCycles(edges, enumber);
	
	
	
	
	//How to know if a graph is planar?
	//Euler's formula must be satisfied
	if(vnumber < 3){
		cout << "The Graph is Planar as it has fewer than 3 vertices" << endl;
	}else {
		while(planar && testing){
			if(found3cycle){
				if(enumber > 2*vnumber - 4){
					planar = false;
					break;
				}else{
					//function to check k3 3 
	
					//function to check k5
				}
			}else if(!found3cycle){
				if(enumber > 3*vnumber - 6){
					planar = false;
					break;
				}else{
					//function to check k3 3 
	
					//function to check k5
				}
			}
		
			testing = false;
		}
	}
	
	
	
}

