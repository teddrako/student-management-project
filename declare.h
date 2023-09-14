#include <iostream>
#include <cstring>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void compiledata();

bool operationsin(string n);

int studentlogin(int num, string pw);
int educatorlogin(int num, string pw);
int directorlogin(int num, string pw);

void studentprofile(int student);
void educatorprofile(int educator);
void directorprofile(int director);
void adminprofile();

void studentchoice(string choice, int student);
void educatorchoice(string choice, int educator);
void directorchoice(string choice, int director);
void adminchoice(string choice);

void memedit(string type);

struct student {
  string name;
  int year;
  string password;
  string schedule[4];
  int marks[4] = {-1, -1, -1, -1};
};

struct educator {
  string name;
  string course;
  string password;
};

struct director {
  string name;
  string password;
};

struct sched {
  string name;
  int period;
  string sub;
  string csub;
};

unordered_map<int, sched> schedreq;
unordered_map<int, sched>::iterator sr;

unordered_map <int, student> slist;
unordered_map <int, student>::iterator sl;

unordered_map <int, educator> elist;
unordered_map <int, educator>::iterator el;

unordered_map <int, director> dlist;
unordered_map <int, director>::iterator dl;

vector <string> subjects = {"french", "english", "geography", "history", "math", "biology", "physics", "chemistry", "business", "spare"};
vector <string>::iterator sj;
