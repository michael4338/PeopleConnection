#include <iostream>
#include <algorithm>
#include "Graphic.hpp"

Graphic::Graphic(){
}

static bool sort_function(vertex_value_pair pair_1, vertex_value_pair pair_2) {
	return (pair_1.acquaints > pair_2.acquaints);
}

void Graphic::addEdge(unsigned long vertex_1, unsigned long vertex_2){
	addEdgeVertex(vertex_1, vertex_2);
	addEdgeVertex(vertex_2, vertex_1);
}

void Graphic::getMaxAcquaintances(){

	//loop all the vertexs
	for(GraphicHash::const_iterator it = m_graphicHash.begin(); it != m_graphicHash.end(); ++it){

		vertex_value_pair curPair;
		unsigned long curVertex = it->first;
		curPair.vertex = curVertex;
		curPair.acquaints = 0;

		//all the friends(edges) for current vertex
		EdgeSet edgeSet = it->second;
		for(EdgeSet::const_iterator it_friend = edgeSet.begin(); it_friend != edgeSet.end(); ++it_friend){
			unsigned long curFriend = *it_friend;

			//friends' friends
			EdgeSet friendSet = getEdgeSet(curFriend);
			for(EdgeSet::const_iterator it_friend_friend = friendSet.begin(); it_friend_friend != friendSet.end(); ++it_friend_friend){	
				unsigned long friend_friend = *it_friend_friend;

				EdgeSet::const_iterator it_contains = edgeSet.find(friend_friend);
				if((it_contains == edgeSet.end()) && (friend_friend != curVertex)){
					//cout<<"curVertex : "<<curVertex<<" ++"<<endl;
					curPair.acquaints ++;
				}
			}
		}

		m_vertexList.push_back(curPair);
	}	
	
	return ;
}

void Graphic::printMaxAcquaintances(){
	sort(m_vertexList.begin(), m_vertexList.end(), sort_function);	
	cout<<"Total Subscribers: "<<m_vertexList.size()<<endl;

	unsigned long maxAcquaints = 0; 
	vector<vertex_value_pair>::const_iterator it = m_vertexList.begin();
	while(it != m_vertexList.end()){
		unsigned long curAcquaints = (unsigned long)((vertex_value_pair*)it->acquaints);
		if(curAcquaints < maxAcquaints) break;
		else maxAcquaints = curAcquaints;

		cout<<"Subscriber "<<dec<<(unsigned long)((vertex_value_pair*)it->vertex);
		cout<<" : Acquaintances Number: "<<dec<<curAcquaints<<endl;
		it++;
	}
}

EdgeSet Graphic::getEdgeSet(unsigned long vertex){
	EdgeSet empty;
	GraphicHash::const_iterator it = m_graphicHash.find(vertex);
	if(it == m_graphicHash.end()) return empty;
	return it->second;
}

void Graphic::addEdgeVertex(unsigned long vertex_1, unsigned long vertex_2){
	GraphicHash::const_iterator it = m_graphicHash.find(vertex_1);
	if(it != m_graphicHash.end()){
		EdgeSet* edgeSet = const_cast<EdgeSet* >(&(it->second));
                edgeSet->insert(vertex_2);
        }else{
                EdgeSet edgeSet;
                edgeSet.insert(vertex_2);
                m_graphicHash.insert(GraphicHash::value_type(vertex_1, edgeSet));
        }
}

