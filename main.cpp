
#include <iostream>
 
#include "DataProvider.hpp"
#include "Graphic.hpp"

using namespace std;

void addEdgeToGraph(Graphic& graphic, unsigned long vertex_1, unsigned long vertex_2){
	graphic.addEdge(vertex_1, vertex_2);	
}


int main(int argc, char* argv[]){
	///////////////////// 1. open csv file containing the table /////////////////////////////////
	if(argc < 2) {
		cerr<<"ERROR: please input csv file name"<<endl;
		return -1;
	}

	const char* fileName = argv[1];
	DataProvider* dataProvider = new FileDataProvider(fileName);

	///////////////////// 2. read each line from csv file, and create a graph data structure ////
	unsigned long data[2];
	Graphic graphic; 

	do{
		int result = dataProvider->getData(data, 2);
		if(result == -1) break;
		else if(result != 0) continue;

		addEdgeToGraph(graphic, data[0], data[1]);

	}while(true);

	
	///////////////////// 3. calculate the required vertex which has the maximum acquaintances ////
	graphic.getMaxAcquaintances();
	graphic.printMaxAcquaintances();
	cout<<endl;

	///////////////////// 4. clear environment and quit //////////////////////////////////////////
	delete dataProvider;
	return 0;
}
