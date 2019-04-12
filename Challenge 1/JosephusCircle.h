#ifndef _Contestant_h_
#define _Contestant_h_

#include <string>

using namespace std;

struct Contestant {
	string name;
	Contestant* next;
	Contestant(string);
};

class JosephusCircle {
	private:
		Contestant* head;
		Contestant* tail;
		void add(string);
		bool josephusActivated;
	public:
		JosephusCircle();
		void josephus(int, string, int, int);
};
#endif