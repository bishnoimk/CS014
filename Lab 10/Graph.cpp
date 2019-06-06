//
// Graph.cpp
// Created by Panda on 6/2/19.

#include "Graph.h"

Graph::Graph(ifstream &ifs) {
	int nodes = 0, edges = 0, weight = 0;
	string title = "", neighborTitle = "";
	
	ifs >> nodes;
	ifs >> edges;
	
	ifs.ignore();
	
	for (int i = 0; i < nodes; i++) {
		Vertex newNode;
		string temp = "";
		getline(ifs, temp);
		newNode.label = temp;
		vertices.push_back(newNode);
	}
	
	while (ifs >> title) {
		int start = 0, neighborIndex = 0;
		ifs >> neighborTitle;
		ifs >> weight;
		for (unsigned int i = 0; i < vertices.size(); i++) {
			if (title == vertices.at(i).label) {
				start = i;
			}
			if (neighborTitle == vertices.at(i).label) {
				neighborIndex = i;
			}
		}
		vertices.at(start).neighbors.push_back(make_pair(neighborIndex, weight));
	}
}

Graph::~Graph() {
	vertices.clear();
}

void Graph::output_graph(const string &filename) {
	ofstream fout(filename);
	if (fout.is_open()) {
		fout << "digraph G {" << endl;
		for (unsigned int i = 0; i < vertices.size(); i++) {
			if (vertices.at(i).distance != INT_MAX) {
				fout << "	" << vertices.at(i).label << "[label= \"" << vertices.at(i).label << " " << vertices.at(i).distance << "\"];" << endl;
			}
			for (auto j = vertices.at(i).neighbors.begin(); j != vertices.at(i).neighbors.end(); j++) {
				if (vertices.at(i).distance != INT_MAX) {
					fout << "	" << vertices.at(i).label << " -> " << vertices.at(j->first).label << endl;
				}
			}
		}
		fout << "}";
		fout.close();
		string systemCommand = "dot -Tjpg input1.dot -o pic.jpg";
		system(systemCommand.c_str());
	}
	else {
		cerr << "Could not open " << filename << endl;
	}
}

void Graph::bfs() {
	vertices.at(0).distance = 0;
	queue<Vertex*> vertexQueue;
	vertexQueue.push(&vertices.at(0));
	
	while (!vertexQueue.empty()) {
		Vertex* frontVertex = vertexQueue.front();
		vertexQueue.pop();
		frontVertex->color = "GRAY";
		
		for (auto i = frontVertex->neighbors.begin(); i != frontVertex->neighbors.end(); i++) {
			if (vertices.at(i->first).color == "WHITE") {
				vertices.at(i->first).prev = frontVertex;
				vertices.at(i->first).distance = 0;
				vertices.at(i->first).color = "GRAY";
				vertices.at(i->first).distance += vertices.at(i->first).prev->distance + 1;
				vertexQueue.push(&vertices.at(i->first));
			}
		}
		
		frontVertex->color = "BLACK";
	}
}