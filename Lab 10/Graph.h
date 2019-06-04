//
// Graph.h
// Created by Panda on 6/2/19.

#ifndef _Graph_h_
#define _Graph_h_

#include "Vertex.h"

#include <iostream>
#include <list>
#include <utility>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

class Graph {
	private:
		vector<Vertex> vertices;
	public:
		Graph(ifstream &ifs);
		~Graph();
		void output_graph(const string &filename);
		void bfs();
};

#endif