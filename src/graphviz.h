#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#define mp make_pair
#define pb push_back
using namespace std;

string graphType = "digraph", graphName = "G";
struct edge {
	string u, v, label;
	edge(){}
	edge(string a, string b, string c): u(a), v(b), label(c) {}
};
vector<edge> e;

namespace graph {
	string property;
	void setDpi(int dpi) {
		property+=" dpi="+to_string(dpi);
	}
	void addStr(string str) {
		property+=" "+str;
	}
}
void clearEdge() {
	e.clear();
}

void clearGraphProperty() {
	graph::property="";
}

void fullClear() {
	clearEdge();
	clearGraphProperty();
}

// initial the graph's type and name
void init(string givenGraphType, string givenGraphName = "G") {
	graphType = givenGraphType;
	graphName = givenGraphName;
}

// add an edge
void addEdge(string u, string v, string label= "") {
	edge tmp(u,v,label);
	e.pb(tmp);
}

// make xxx become "xxx"
string addQuote(const string &t) {
	return "\""+t+"\"";
}


namespace outputMode {
	#define tab "  "
	ofstream file;
	
	void outputEdge() {
		for(edge t : e) {
			file<<tab<<t.u<<" -> "<<t.v;
			if(t.label != "") file<<'['<<t.label<<']'<<endl;
			else file<<endl;
		}
	}
	void outputGraphProperty() {
		if(!graph::property.empty()) 
			file<<tab<<"graph"<<'['<<graph::property<<']'<<endl;
	}
	void outputToDot(string fileName) {
		// if the file name doesn't have a filename extension, then add one
		if(fileName.find(".dot") == size_t(-1)) fileName += ".dot";
		file.open(fileName, ios::out);
		
		file<<graphType<<' '<<graphName<<' '<<'{'<<endl;
		outputGraphProperty();
		outputEdge();
		file<<'}'<<endl;
		
		//close the output file
		file.close();
	}	
}
using namespace outputMode;

void compileDot(string fileName, string outType="png", string outName="") {
	if(outName=="") outName=fileName;
	if(fileName.find(".dot") == size_t(-1)) fileName += ".dot";
	if(outName.find("." + outType) == size_t(-1)) outName += "." + outType;
	string cmd = "dot " + fileName + " -T " + outType+ " -o "+ outName;
	system(cmd.c_str());
}

// automatically generate xxx.dot and compile it
void autoOut(string fileName, string outType="png", string outName="") {
	if(outName=="") outName=fileName;
	if(fileName.find(".dot") == size_t(-1)) fileName += ".dot";
	if(outName.find("." + outType) == size_t(-1)) outName += "." + outType;
	outputToDot(fileName);
	compileDot(fileName, outType, outName);
}
