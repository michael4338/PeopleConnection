#include <tr1/unordered_map>
#include <set>
#include <vector>

using namespace std;

//utility class for Graphic algorithm

typedef set<unsigned long> EdgeSet;
typedef tr1::unordered_map<unsigned long, EdgeSet > GraphicHash;

struct vertex_value_pair{
	unsigned long vertex;
	unsigned int acquaints;
};

class Graphic{
public:
	Graphic();
	~Graphic(){}

	void addEdge(unsigned long, unsigned long);
	void getMaxAcquaintances();
	void printMaxAcquaintances();

private:
	void addEdgeVertex(unsigned long, unsigned long);
	EdgeSet getEdgeSet(unsigned long);

private:
	GraphicHash m_graphicHash;	
	vector<vertex_value_pair> m_vertexList;
};
