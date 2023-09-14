 <-- Student Management System -->
          -- Ted Drako -- 

{ To Do Features }
  --> add sub Educator title (1) Educator (2) director
  --> Educator roles: assign marks, fail students, 
  --> director roles: accept student requests, fire teachers, assign teachers new courses, expell students
  --> director numbers begin with 900, 6 digits
  --> fail students subject becomes spare
  --> fire teachers, remove their subject and 

<1> Student Login
  --> Login as a student with number and passsword find them at the bottom of main in the compiledata function
    <1.1> Student info
      --> Display all info of logged in student
      --> Password can be revealed with first character
    <1.2> View schedule
      --> Display the schedule of logged in student
      --> Prompted to request a course change with Y and N
      <1.2.Notes>
        --> Enter a period between 1 and 4 inclusive
        --> Enter a subject the student isn't already taking and one that aligns with available subjects listed in <6>
        --> Only one student request may be prompted at a time per student, once accepted or denied by a Educator member another one may be requested
    <1.3> View marks
      --> Displays marks assigned to students for each subject
      --> Original values set to "-1" displayed as mark not recorded, until mark is assigned by Educator see <2.2> for mark assingment
    <1.4> Logout
      --> Logout of student profile and go back to general operations

<2> Educator Login
  --> Login as a student with number and passsword found at the bottom of main in compiledata function
  <2.1> Educator info
    --> Display all info of logged in Educator
    --> Password can be revealed with first character
  <2.2> View class List
    --> Displays students currently taking the course taught by logged in Educator members
    --> Prompts Educator to assign marks towards students
    <2.2.Notes>
      --> Marks entered must be an integer between 1 and 100 inclusive
      --> Marks assigned to students may not be accessed through student profiles in section <1.3>
  <2.3> Student requests
    --> Displays all requests made by students
    --> User is prompted to either accept or deny requests made by students
    <2.3.Notes>
      --> Once a request is accepted the students schedule is switched accordingly with respect to period and new subject, student may access and view this information upon subsequent login
      --> If denied, request is removed from the hashmap and no changes are made in students schedule
  <2.4> Logout
    --> Logout of Educator profile and go back to general operations

<3> Admin Login
  --> View and edit the sessions student and Educator list, export all data into external file
  --> Login with password "admin"
    <3.Notes>
      --> Incorrect password input will shut down the session

    <3.1> Student list
      --> Displays all current student data, prompts user to add or delete students 
      --> "Add" prompts user with according values of a student profile - name, year, student number, password, and courses
      --> "Delete" prompts user to delete a student profile by Name
        <3.1.Notes>
          --> To add student follow guidelines mentioned in <5.Notes>
          --> Deleting students name prompt is case sensitive
    
    <3.2> Educator list
      --> Displays all current Educator data, prompts user to add or delete Educator members 
      --> "Add" prompts user with according values of a facukty profile - name, course, Educator number and password
      --> "Delete" prompts user to delete a Educator profile by Name
        <3.2.Notes>
          --> To add Educator follow guidelines mentioned in <6.Notes>
          --> Deleting Educator name prompt is case sensitive

<4> Exit
  --> Shuts down the program

<6> Course list
  --> Course name values stored in variable subjects[], course count stored in variable subjectcount, user may edit these values respectively - count and number of values in array must match

 - Version list -

[1.0.0 - 12/29/21] 
  - All basic features fully implemented 

[1.0.1 - 12/30/21]
  - Exported file now outputs marks next to courses, outputs "marks not recorded" if Educator has not assigned them yet

[1.0.2 - 12/31/21]
  - Prompts user to input only courses that are listed when adding a student and teacher
  - Courses already taught by Educator may not be repeated
  - Student and Educator numbers are unique, previously assigned numbers may not be added to new profiles
  - Program now handles incorrect data type without crashing
  - Added Readme.txt for accessibility

[1.0.3 - 1/3/22]
  - When adding students through admin student numbers now must begin with 300 and be 6 digits long
  - When adding Educator through admin Educator numbers now must begin with 600 and be 6 digits long
  - When adding students through admin shceulde requires unique courses to new student entries
  - Educator now referred to as Educators
  - Passwords assigned to new entries default to student/Educator numbers
  - Password changable by user when logging for first time on new student/Educator entry
  - Added director options shell