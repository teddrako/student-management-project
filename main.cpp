#include "declare.h"

int main() {

  string option = "0";

  compiledata();

  cout<<"Welcome to the Student Management System by Ted Drako"<<endl<<"Refer to the \" Readme.txt \" for a thourough guide and feature report"<<endl<<endl;

  while (operationsin(option) == true) {
    cout<<"Available Operations: "<<endl<<"1 - Student Login "<<endl<<"2 - Educator Login "<<endl<<"3 - Director Login"<<endl<<"4 - Admin Login"<<endl<<"5 - Exit "<<endl<<"Enter option --> ";
    cin>>option;
    cout<<endl;
  }

}

bool operationsin(string n) {

  int student, educator, director, snum;
  string passw, adminpw = "admin";
  static bool firstt = true;

  if (n == "0" && firstt == true) {

    firstt = false;
    return true;

  } else if (n == "1") {

    cout<<"Enter your Student Number: ";
    cin>>snum;

    if (cin.fail()) {

      cin.clear(); 
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<endl<<"Invalid data type entered"<<endl<<endl;
      return true;

    }

    cout<<"Enter your Password: ";
    cin>>passw;

    student = studentlogin(snum, passw);

    if (student == -1) {
      
      cout<<endl<<"Invalid student login"<<endl<<endl;
      return true;

    } else if (student == -2) {
      return true;
    } else {

      studentprofile(student);
      cout<<endl<<"Successfully logged out"<<endl<<endl;
      return true;

    }

  } else if (n == "2") {
    
    cout<<"Enter your Educator Number: ";
    cin>>snum;

    if (cin.fail()) {

      cin.clear(); 
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<endl<<"Invalid data type entered"<<endl<<endl;
      return true;

    }

    cout<<"Enter your Password: ";
    cin>>passw;

    educator = educatorlogin(snum, passw);

    if (educator == -1) {

      cout<<endl<<"Invalid educator login"<<endl<<endl;
      return true;

    } else {

      educatorprofile(educator);
      cout<<endl<<"Successfully logged out"<<endl<<endl;
      return true;

    }

  } else if (n == "3") {
    
    cout<<"Enter your Director Number: ";
    cin>>snum;

    if (cin.fail()) {

      cin.clear(); 
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<endl<<"Invalid data type entered"<<endl<<endl;
      return true;

    }

    cout<<"Enter your Password: ";
    cin>>passw;

    director = directorlogin(snum, passw);

    if (director == -1) {
      
      cout<<endl<<"Invalid director login"<<endl<<endl;
      return true;

    } else {

      directorprofile(director);
      cout<<endl<<"Successfully logged out"<<endl<<endl;
      return true;

    }

  } else if (n == "4") {

    cout<<"Enter admin password: ";
    cin>>passw;

    if (passw == adminpw) {

      adminprofile();
      cout<<endl<<"Successfully logged out"<<endl<<endl;
      return true;

    } else {

      cout<<endl<<"Invalid password"<<endl<<"Security breach detected - Shutting Down System"<<endl;
      return false;

    }
    
  } else if (n == "5") {

    cout<<"Closing system"<<endl;
    return false;

  } else {

    cout<<"Invalid Option"<<endl<<endl;
    return true;

  }
}

int studentlogin(int num, string pw) {
  
  for (sl = slist.begin(); sl != slist.end(); sl++) {
    if ( num == sl->first && pw == sl->second.password ) {

      if (to_string(num) == pw) {

        cout<<endl<<"Welcome to the institution "<<sl->second.name<<", as this is your first time logging in you will need to set your password"<<endl<<endl<<"Please enter your new password: ";
        cin>>sl->second.password;

        while (sl->second.password == to_string(num)) {
          cout<<endl<<"Password must not be same as student number"<<endl<<"Enter new password: ";
          cin>>sl->second.password;
        }

        cout<<endl<<"Your new password has been set please login again to view your options"<<endl<<endl;

        return -2;

      } else {
        return num;
      }
    }
  }
  return -1;
}

int educatorlogin(int num, string pw) {
  
  for (el = elist.begin(); el != elist.end(); el++) {
    if ( num == el->first && pw == el->second.password ) {

      if (to_string(num) == pw) {

        cout<<endl<<"Welcome to the institution "<<el->second.name<<", as this is your first time logging in you will need to set your password"<<endl<<endl<<"Please enter your new password: ";
        cin>>el->second.password;

        while (el->second.password == to_string(num)) {
          cout<<endl<<"Password must not be same as student number"<<endl<<"Enter new password: ";
          cin>>el->second.password;
        }

        cout<<endl<<"Your new password has been set please login again to view your options"<<endl<<endl;

        return -2;

      } else {
        return num;
      }
    }
  }
  return -1;
}

int directorlogin(int num, string pw) {
  
  for (dl = dlist.begin(); dl != dlist.end(); dl++) {
    if ( num == dl->first && pw == dl->second.password ) {

      if (to_string(num) == pw) {

        cout<<endl<<"Welcome to the institution "<<dl->second.name<<", as this is your first time logging in you will need to set your password"<<endl<<endl<<"Please enter your new password: ";
        cin>>dl->second.password;

        while (dl->second.password == to_string(num)) {
          cout<<endl<<"Password must not be same as student number"<<endl<<"Enter new password: ";
          cin>>dl->second.password;
        }

        cout<<endl<<"Your new password has been set please login again to view your options"<<endl<<endl;
        return -2;

      } else {
        return num;
      }
    }
  }
  return -1;
}

void studentprofile(int student) {

  string inp = "0";

  cout<<endl<<"Welcome "<<slist.at(student).name<<endl;

  while (inp != "4") {
    cout<<endl<<"Available Operations: "<<endl<<"1 - Student Info "<<endl<<"2 - View Schedule "<<endl<<"3 - View Marks "<<endl<<"4 - Logout "<<endl<<"Enter option --> ";
    cin>>inp;
    studentchoice(inp, student);
  }

}

void educatorprofile(int educator) {

  string inp = "0";

  cout<<endl<<"Welcome "<<elist.at(educator).name<<endl;

  while (inp != "4") {
    cout<<endl<<"Available Operations: "<<endl<<"1 - Educator Info "<<endl<<"2 - View Class List "<<endl<<"3 - Student Requests "<<endl<<"4 - Logout "<<endl<<"Enter option --> ";
    cin>>inp;
    educatorchoice(inp, educator);
  }

}

void directorprofile(int director) {

  string inp = "0";

  cout<<endl<<"Welcome "<<dlist.at(director).name<<endl;

  while (inp != "4") {
    cout<<endl<<"Available Operations: "<<endl<<"1 - Educator Info "<<endl<<"2 - View Class List "<<endl<<"3 - Student Requests "<<endl<<"4 - Logout "<<endl<<"Enter option --> ";
    cin>>inp;
    directorchoice(inp, director);
  }

}

void adminprofile() {

  string inp = "0";

  cout<<endl<<"Welcome administrator"<<endl;

  while (inp != "4") {
    cout<<endl<<"Available Operations: "<<endl<<"1 - Student List "<<endl<<"2 - Educator List "<<endl<<"3 - Export Data "<<endl<<"4 - Logout "<<endl<<"Enter option --> ";
    cin>>inp;
    adminchoice(inp);
  }

}

void studentchoice(string choice, int student) {

  string schedin, subjchng = "";
  int periodchng = 0;
  bool subjexist, subjtaken = false;

  if (choice == "1") {

    cout<<endl<<"Name: "<<slist.at(student).name<<endl<<"Year: "<<slist.at(student).year<<endl<<"Student number: "<<student<<endl<<"Password: ";

    for (int i = 0; i < (slist.at(student).password).size(); i++) {
      cout<<"*";
    }

    // CHANGE PASSWORD CODE


  } else if (choice == "2") {

    cout<<endl;

    for (int i = 0; i < 4; i++) {
      cout<<"Period "<<i+1<<": "<<slist.at(student).schedule[i]<<endl;
    }
    
    if (schedreq.find(student) == schedreq.end()) {
      
      cout<<endl<<"Enter Y to request a change and N not to request --> ";
      cin>>schedin;

      if (schedin == "y" || schedin == "Y") {

        cout<<endl<<"Which period would you like to change: ";
        cin>>periodchng;

        if (cin.fail()) {
          cin.clear(); 
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          periodchng = -1;
        }

        cout<<"What subject would you like instead: ";
        cin>>subjchng;

        for (sj = subjects.begin(); sj != subjects.end(); sj++) {
          if (subjchng == *sj) {
            subjexist = true;
            break;
          } else {
            subjexist = false;
          }
        }

        for (int i = 0; i < 4; i++) {
          if (slist.at(student).schedule[i] == subjchng) {
            subjtaken = true;
          }
        }

        if (subjexist == true && periodchng > 0 && periodchng < 5 && subjtaken == false) {

          schedreq.insert({student, {slist.at(student).name, periodchng, subjchng, slist.at(student).schedule[periodchng-1]}});

          cout<<endl<<"Request sent to educator, check schedule again later to see if request was approved"<<endl;
        } else {

          if (subjtaken == true) {
            cout<<endl<<"You've already taken "<<subjchng<<endl;
          }

          if (periodchng < 0 || periodchng > 5) {
            cout<<endl<<"Periods can only be numbers entered from 1-4"<<endl;
          }

          if (subjexist == false) {
            cout<<endl<<"This subject does not exist"<<endl;
          }
          
        }

      } else if (schedin == "n" || schedin == "N") {

        cout<<endl<<"No changes made"<<endl;

      } else {

        cout<<endl<<"Invalid choice "<<endl;

      }
    } else {

      cout<<endl<<"Cannot request another change until current one is approved or denied"<<endl;
      
    }

  } else if (choice == "3") {

    cout<<endl;

    for (int i = 0; i < 4; i++) {

      cout<<slist.at(student).schedule[i]<<" - ";

      if (slist.at(student).marks[i] < 0 || slist.at(student).marks[i] > 100) {

        cout<<"mark not recorded"<<endl;

      } else {

        cout<<slist.at(student).marks[i]<<endl;

      }
    }
  } else if (choice == "4") {
    
  } else {

    cout<<endl<<"Invalid operation"<<endl;

  }
}

void educatorchoice(string choice, int educator) {

  string passin, markin, yrnad = "", reqin;
  vector<decltype(schedreq)::key_type> del;
  vector <int> takingclass;
  int mark;

  if (choice == "1") {

    cout<<endl<<"Name: "<<elist.at(educator).name<<endl<<"Course: "<<elist.at(educator).course<<endl<<"Educator number: "<<educator<<endl<<"Password: ";

    for (int i = 0; i < (elist.at(educator).password).size(); i++) {
      cout<<"*";
    }

    //PASSWORD CHANGE

  } else if (choice == "2") {
    
    cout<<endl<<"Students taking your class"<<endl;

    for (sl = slist.begin(); sl != slist.end(); sl++) {

      for (int j = 0; j < 4; j++) {

        if (sl->second.schedule[j] == elist.at(educator).course) {

          cout<<" -> "<<sl->second.name<<endl;
          takingclass.push_back(sl->first);

        }

      }

    }

    if (takingclass.empty() != true) {

      cout<<endl<<"Enter Y to update the students marks and N to cancel -> ";
      cin>>markin;

      if (markin == "Y" || markin == "y") {

        for (auto tc = takingclass.begin(); tc != takingclass.end(); tc++) {

          cout<<endl<<"Update mark for "<<slist.at(*tc).name<<" -> ";
          cin>>mark;

          if (cin.fail() || mark > 100 || mark < 0) {

            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<endl<<"Please provide a mark between 0-100 inclusive"<<endl;
            mark = -1;
            
          }

          for (int j = 0; j < 4; j++) {

            if (slist.at(*tc).schedule[j] == elist.at(educator).course) {

              slist.at(*tc).marks[j] = mark;

            }

          }

        }

        cout<<endl<<"Marks updated accordingly for all students"<<endl;

      } else if (markin == "N" || markin == "n") {

        cout<<endl<<"No updates made"<<endl;

      } else {

        cout<<endl<<"Invalid choice "<<endl;

      }
    } else {

      cout<<"No one took your class"<<endl;

    }

  } else if (choice == "3") {

    cout<<endl<<"Student requests"<<endl;

    for (auto x = schedreq.begin(); x != schedreq.end(); x++) {

      cout<<x->second.name<<" - period "<<x->second.period<<" change from "<<x->second.csub<<" to "<<x->second.sub<<endl;

    }

    if (schedreq.empty() != true) {

      cout<<endl<<"Enter Y to process requests and N to continue -> ";
      cin>>yrnad;

      if (yrnad == "Y" || yrnad == "y") {

        for (sr = schedreq.begin(); sr != schedreq.end(); sr++) {
            
          cout<<endl<<sr->second.name<<" - "<<"Enter A to approve D to deny -> ";
          cin>>reqin;

          if (reqin == "A" || reqin == "a") {

            slist.at(sr->first).marks[(sr->second.period)-1] = -1;

            slist.at(sr->first).schedule[(sr->second.period)-1] = sr->second.sub;

            cout<<endl<<"Request for "<<sr->second.name<<" approved"<<endl<<"Period "<<sr->second.period<<" changed from "<<sr->second.csub<<" to "<<sr->second.sub<<endl;

            del.emplace_back(sr->first);

          } else if (reqin == "D" || reqin == "d") {

            cout<<endl<<"Request for "<<sr->second.name<<" denied"<<endl;

            del.emplace_back(sr->first);

          } else {

            cout<<endl<<"Invalid option"<<endl;

          }

        }

        for (auto&& key : del) {
          schedreq.erase(key);
        }
        
      } else if (yrnad == "N" || yrnad == "n") {

        cout<<endl<<"Requests were not processed"<<endl;

      } else {

        cout<<endl<<"Invalid option"<<endl;

      }
    } else {

      cout<<"No requests found"<<endl;
      
    }

  } else if (choice == "4") {
    
  } else {

    cout<<endl<<"Invalid operation"<<endl;

  }

}

void directorchoice(string choice, int director) {


  if (choice == "1") {


  } else if (choice == "2") {
    
    
  } else if (choice == "3") {

    
  } else if (choice == "4") {
    
  } else {
    cout<<endl<<"Invalid operation"<<endl;
  }
}

void adminchoice(string choice) {

  ofstream fout;
  string se_in, stdel, educatoredit = "", fcdel, exportname;
  int subjch, crsch;
  bool numberexist, courseexist, subjexist;

  if (choice == "1") {

    if (slist.empty() != true) {

      cout<<endl<<"List of all students"<<endl;

      for (sl = slist.begin(); sl != slist.end(); sl++) {

        cout<<endl<<"Name: "<<sl->second.name<<endl<<"Year: "<<sl->second.year<<endl<<"Student number: "<<sl->first<<endl<<"Password: "<<sl->second.password<<endl<<"Schedule"<<endl;

        for (int j = 0; j < 4; j++) {

          cout<<" -- Period "<<j+1<<": "<<sl->second.schedule[j]<<endl;

        }

      }

    } else {

      cout<<endl<<"There are no students in the list"<<endl;

    }

    memedit("s");
 
  } else if (choice == "2") {
    
    if (elist.empty() != true) {

      cout<<endl<<"List of all educators"<<endl;

      for (el = elist.begin(); el != elist.end(); el++) {

        cout<<endl<<"Name: "<<el->second.name<<endl<<"Course: "<<el->second.course<<endl<<"Educator number: "<<el->first<<endl<<"Password: "<<el->second.password<<endl;

      }

    } else {

      cout<<endl<<"There are no educators in the list"<<endl;

    }

    memedit("e");

  } else if (choice == "3") {

    cout<<endl<<"Enter file name to export data: ";
    cin>>exportname;

    if (exportname != "Readme.txt" && exportname != "main.cpp" && exportname != "declare.h") {

      fout.open(exportname);
      fout<<endl<<"-------< Student List >-------"<<endl;

      for (sl = slist.begin(); sl != slist.end(); sl++) {

        fout<<endl<<"Student Name: "<<sl->second.name<<endl<<"Student Year: "<<sl->second.year<<endl<<"Student Number: "<<sl->first<<endl<<"Student Password: "<<sl->second.password<<endl;

        for (int j = 0; j < 4; j++) {

          fout<<" - Period "<<j+1<<": "<<sl->second.schedule[j]<<" > ";

          if (sl->second.marks[j] >= 0 && sl->second.marks[j] <= 100) {

            fout<<sl->second.marks[j]<<endl;
            
          } else {

            fout<<"mark not recorded"<<endl;

          }
          
        }

      }

      fout<<endl<<endl<<"-------< Educator List >-------"<<endl<<endl;

      for (el = elist.begin(); el != elist.end(); el++) {

        fout<<"Educator Name: "<<el->second.name<<endl<<"Educator Course: "<<el->second.course<<endl<<"Educator Number: "<<el->first<<endl<<"Educator Password: "<<el->second.password<<endl<<endl;

      }

      fout<<endl<<"-------< Director List >-------"<<endl<<endl;

      for (dl = dlist.begin(); dl != dlist.end(); dl++) {

        fout<<"Director Name: "<<dl->second.name<<endl<<"Diretor Number: "<<dl->first<<endl<<"Director Password: "<<dl->second.password<<endl<<endl;

      }

      fout.close();

      cout<<endl<<"All contents successfully exported to "<<exportname<<endl;

    } else {

      cout<<endl<<"Files of such name already exist"<<endl;

    }

  } else if (choice == "4") {

  } else {

    cout<<endl<<"Invalid operation"<<endl;

  }
  
}

void memedit(string type) {

  string sname, ename, inp;
  int syear, snum, ssub[4], ednum, ecourse;
  bool nexist = true, sbexist = true, cexist = true;

  if (type == "s") {

    cout<<endl<<"Enter A to add a student D to del a student or N to do neither - > ";
    cin>>inp;

    if (inp == "A" || inp == "a") {

      cout<<endl<<"Enter student name: ";
      cin>>sname;

      while (true) {

        cout<<"Enter student year: ";
        cin>>syear;

        if (cin.fail() || syear > 5 || syear < 1) {

          cin.clear(); 
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout<<endl<<"Please enter a number between 1-5"<<endl<<endl;

        } else {

          break;

        }
        
      }

      while (nexist == true) {

        cout<<"Enter student number: ";
        cin>>snum;

        if (snum < 300000 || snum > 300999 || cin.fail()) {

          cin.clear(); 
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout<<endl<<"Please enter a valid student number beggining with 300 and 6 digits long"<<endl<<endl;

        } else {

          for (sl = slist.begin(); sl != slist.end(); sl++) {

            if (snum == sl->first) {

              cout<<endl<<"That number has already been assigned"<<endl<<endl;
              nexist = true;
              break;

            } else {
              nexist = false;
            }

          }

        }

      }

      cout<<endl<<"Enter the number corresponding to the subject"<<endl<<endl;

      for (int i = 0; i < subjects.size(); i++) {

        cout<<" "<<i+1<<" - "<<subjects[i]<<endl;

      }
        
      cout<<endl;

      for (int i = 0; i < 4; i++) {
        
        sbexist = true;

        while (sbexist == true) {
          
          cout<<"Period "<<i+1<<": ";
          cin>>ssub[i];

          if (cin.fail() || ssub[i] < 1 || ssub[i] > subjects.size()) {

            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<endl<<"Please enter a number between 1-"<<subjects.size()<<endl<<endl;

          } else {

            for (int j = 0; j <= i; j++) {

              if (ssub[i] == ssub[j] && j != i) {

                cout<<endl<<"This student is already taking "<<subjects[ssub[i]-1]<<endl<<endl;
                sbexist = true;
                break;

              } else {

                sbexist = false;

              }

            }

          }

        }

      }

      slist.insert({snum, {sname, syear, to_string(snum), {subjects[ssub[0]-1], subjects[ssub[1]-1], subjects[ssub[2]-1], subjects[ssub[3]-1]}}});

    } else if (inp == "D" || inp == "d") {

      cout<<endl<<"Enter the number of the student you want to remove: ";
      cin>>snum;

      sl = slist.begin();

      if (cin.fail()) {

        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<endl<<"Please enter a valid student number"<<endl;

      } else {

        for (sl = slist.begin(); sl != slist.end(); sl++) {
          if (sl->first == snum) {

            cout<<endl<<"The profile of "<<sl->second.name<<" has successfully been deleted"<<endl;
            slist.erase(sl);
            break;

          } else if (sl->first != snum && next(sl) == slist.end()) {

            cout<<endl<<"The student you entered doesn't exist"<<endl;

          }

        }
        
      }
      
    } else if (inp == "N" || inp == "n") {
      
      cout<<endl<<"No changes made"<<endl;
    
    } else {
      
      cout<<endl<<"Invalid option"<<endl;

    }

  } else if (type == "e") {

    cout<<endl<<"Enter A to add a student D to del a student or N to do neither - > ";
    cin>>inp;

    if (inp == "A" || inp == "a") {

      cout<<endl<<"Enter educator name: ";
      cin>>ename;

      cout<<endl<<"Enter the number corresponding to the subject"<<endl<<endl;

      for (int i = 0; i < subjects.size(); i++) {

        cout<<" "<<i+1<<" - "<<subjects[i]<<endl;

      }
      
      cout<<endl;

      while (cexist == true) {

        cout<<"Enter educator course: ";
        cin>>ecourse;

        if (cin.fail()) {

          cin.clear(); 
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout<<endl<<"Please enter a number between 1-"<<subjects.size()<<endl<<endl;

        } else {

          for (el = elist.begin(); el != elist.end(); el++) {

            if (el->second.course == subjects[ecourse-1]) {

              cout<<endl<<"That course is already being taught"<<endl<<endl;
              cexist = true;
              break;

            } else {

              cexist = false;

            }

          }

        }          

      }

      while (nexist == true) {

        cout<<"Enter educator number: ";
        cin>>ednum;

        if (ednum < 600000 || ednum > 600999 || cin.fail()) {

          cin.clear(); 
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout<<endl<<"Please enter a valid educator number beggining with 600 and 6 digits long"<<endl<<endl;

        } else {

          for (el = elist.begin(); el != elist.end(); el++) {

            if (ednum == el->first) {

              cout<<endl<<"That number has already been assigned"<<endl<<endl;
              nexist = true;
              break;

            } else {

              nexist = false;

            }

          }

        }

      }

      cout<<endl<<"Enter the number corresponding to the subject"<<endl<<endl;

      for (int i = 0; i < subjects.size(); i++) {

        cout<<" "<<i+1<<" - "<<subjects[i]<<endl;

      }
        
      cout<<endl;

      elist.insert({ednum, {ename, subjects[ecourse-1], to_string(ednum)}});

    } else if (inp == "D" || inp == "d") {

      cout<<endl<<"Enter the number of the educator you want to remove: ";
      cin>>ednum;

      el = elist.begin();

      if (cin.fail()) {

        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<endl<<"Please enter a valid educator number"<<endl;

      } else {

        for (el = elist.begin(); el != elist.end(); el++) {
          if (el->first == ednum) {

            cout<<endl<<"The profile of "<<el->second.name<<" has successfully been deleted"<<endl;
            elist.erase(el);
            break;

          } else if (el->first != ednum && next(el) == elist.end()) {

            cout<<endl<<"The educator you entered doesn't exist"<<endl;

          }

        }
        
      }
      
    } else if (inp == "N" || inp == "n") {
      
      cout<<endl<<"No changes made"<<endl;
    
    } else {
      
      cout<<endl<<"Invalid option"<<endl;

    }

  }

}


void compiledata() {

  //STUDENTS

  slist.insert({300371, {"Sam", 2, "p12345", {"geograhy", "math", "english", "physics"}}});

  slist.insert({300162, {"Justin", 4, "mycatsandra", {"history", "geography", "chemistry", "math"}}});

  slist.insert({300887, {"Cecelia", 1, "password", {"chemistry", "business", "math", "spare"}}});

  slist.insert({300111, {"Gang", 5, "nonsense", {"math", "chemistry", "spare", "french"}}});

  slist.insert({300783, {"Julia", 2, "disco343", {"spare", "math", "geography", "history"}}});

  //EDUCATORS

  elist.insert({600724, {"Robinson", "math", "drphd"}});

  elist.insert({600335, {"Svenson", "biology", "allele23"}});

  elist.insert({600992, {"Bordeaux", "french", "enfrancais"}});

  //DIRECTORS

  dlist.insert({900001, {"Smith", "thedirector"}});
  
}