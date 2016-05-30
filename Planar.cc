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
		
		cout << "Start point of edge "<< i+1 << ": ";
		cin >> start;
		cout << endl << "End point of edge "<< i+1 << ": ";
		cin >> end;
		cout << endl;
		
		edge* e = new edge(start,end);
		
		edges.push_back(e);
		cerr << "Adding edge with start " << e->vert1 << " and end " << e->vert2 << endl;
	}
}

//Main will take in input of edges and vertices and see if the graph is planar
int main(){
	//var for # of edges and vertices
	int vnumber = 0;
	int enumber = 0;
	edge* someEdge;
	
	vector<int> vertices;//all these v words confusing me
	vector <edge *> edges;
	
	cout << "Enter Number of Vertices: " << endl;
	cin >> vnumber;
	cout << "Enter Number of Edges: " << endl;
	cin >> enumber;
	
	vertexInput(vertices, vnumber);
	edgeInput(edges, enumber);
	
	
}

