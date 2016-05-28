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

edge::edge(){//default
	vert1 = 0;
	vert2 = 0;
}

edge::edge(int a, int b): vert1(a), vert2 (b){//autoassign values
	
}

vector <vertex> vertexInput (){
	int vertex;
}

//Main will take in input of edges and vertices and see if the graph is planar
int main(){

	edge* someEdge;
	
	vector<vertex> vertices;//all these v words confusing me
	vector <edge *> edges;
	
	vertices = vertexInput();
	
	
	
}

