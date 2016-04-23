// Sample solution to Frogger
// Author: Stein Norheim
// Algorithm: BFS

#include<iostream>
#include<vector>
#include<deque>
#include<cstring>

using namespace std;

class State {
public:
  int x;
  int y;
  int distance;
  
  State(int aX,int aY, int aDistance)
    : x(aX), y(aY), distance(aDistance) {};

  State forward() {return State(x,y+1,distance+1);}
  State backward() {return State(x,y-1,distance+1);}
  State left() {return State(x-1,y,distance+1);}
  State right() {return State(x+1,y,distance+1);}
  State still() {return State(x,y,distance+1);}
};

class Road : public vector<string> {
public:
  deque<State> q;
  bool visited[51][22][51];
  int width;
  int height;
  int maxTurns;
  bool carPresent(const State& s);

  bool tryState(const State& s);
  int getMinTurns();
  
  bool stateVisited(const State& s) { return visited[s.x][s.y][s.distance % width];}
  void markVisited(const State& s) { visited[s.x][s.y][s.distance % width] = true;}

  const string& lane(int y) { return (*this)[height+1-y]; }
  int startX() { return lane(0).find("F"); }
  int finishX() { return lane(height+1).find("G"); };
  
};

bool
Road :: carPresent(const State& s) {
  int offset = (s.y%2==1)?width-(s.distance % width):s.distance % width;
  return lane(s.y)[(s.x+offset)%width]=='X';
}

bool
Road :: tryState(const State& s) {
  if ((s.x>=0) && (s.x<width) && (s.y>=0)
      && (s.y<=height+1) && (s.distance<=maxTurns)
      && !stateVisited(s) && !carPresent(s)) {
    markVisited(s);
    q.push_back(s);
  }
}

int
Road :: getMinTurns() {
  memset(visited, 0, sizeof(visited));
  q.clear();

  int goalx = finishX();
  q.push_back(State(startX(),0,0));

  while (!q.empty()) {
    State s = q.front();
    q.pop_front();

    if ((s.x==goalx) && (s.y==height+1))
      return s.distance;
    
    tryState(s.left());
    tryState(s.right());
    tryState(s.forward());
    tryState(s.backward());
    tryState(s.still());
  }

  return -1;           
}

int main () {
  int nCases;
  string s;
  Road road;
  
  cin >> nCases;
  for (int i=0; i<nCases; i++) {
    road.clear();
    cin >> road.maxTurns >> road.height >> road.width;
    for (int j=0; j<road.height+2; j++) {
      cin >> s;
      road.push_back(s);
    }
    int minTurns = road.getMinTurns();
    if (minTurns>=0) {
      cout << "The minimum number of turns is " << minTurns << "." << endl;
    } else {
      cout << "The problem has no solution." << endl;
    }
  }
}
