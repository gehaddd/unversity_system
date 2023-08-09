#include<bits/stdc++.h>
using namespace std;
class person
{
public:
    string person_name;
    int person_age;
    int person_id;
    virtual void role()=0;
};
class student:public person
{
public:
    float student_gba;
    void role()
    {
        cout<<"this is student class"<<"\n";
    }
};
class instructor:public person
{
public:
    string instructor_name;
    int instructor_age;
    void role()
    {
        cout<<"this is instructor class"<<"\n";
    }
};
class employee:public person
{
public:
    int employee_salary;
    void role()
    {
        cout<<"this is employee class"<<"\n";
    }
};
class manager:public person
{
    int salary;
    static manager*instance;
    manager()
    {
    };

public:
    static manager*getsalary()
    {
        if(instance==nullptr)
        {
            instance=new manager();
        }
        return instance;
    }
    void role()
    {
        cout<<"this is manager class"<<"\n";
    }
    void setsalary(int sa)
    {
        salary=sa;

    }
    int getsalar()
    {
        return salary;
    }

};

class course
{
public:
    string course_title;
    int course_id;
    void details()
    {
        cout<<"this is course details"<<"\n";
    }


};
class department
{
public:
    string deprt_titile;
    vector<course>cources;
    void details(course)
    {
        ifstream addd_course("courses.txt");
        if(!addd_course)
        {
            cout<<"error for reading"<<"\n";

        }
        string lines;
        cout<<"there are your courses"<<"\n";
        while(getline(addd_course,lines))
        {
            cout<<lines<<endl;
        }
    }
    void addcourse(course sd )
    {

        cout<<"please enter the course you want to add"<<"\n";
        getline(cin,sd.course_title);
        cources.push_back(sd);
        ofstream addd_course("courses.txt",ios::app);

        if(!addd_course)
        {
            cout<<"error for reading"<<"\n";

        }

        addd_course<<endl<<sd.course_title;
        addd_course.close();



    }
};
class faculty
{
public:
    string facul_title;
    vector<student>students;
    vector<instructor>instructors;
    vector<employee>employees;
    vector<department>departments;
    void details(student)
    {

        ifstream addd_students("students.txt");
        if(!addd_students)
        {
            cout<<"error for reading"<<"\n";

        }
        string lines;
        cout<<"there are your data"<<"\n";
        while(getline(addd_students,lines))
        {
            cout<<lines<<endl;
        }


    }
    void details(employee)
    {

        ifstream addd_employees("employees.txt");
        if(!addd_employees)
        {
            cout<<"error for reading"<<"\n";

        }
        string lines;
        cout<<"there are your data"<<"\n";
        while(getline(addd_employees,lines))
        {
            cout<<lines<<endl;
        }


    }
    void details(instructor)
    {

        ifstream addd_instructors("instructors.txt");
        if(!addd_instructors)
        {
            cout<<"error for reading"<<"\n";

        }
        string lines;
        cout<<"there are your data"<<"\n";
        while(getline(addd_instructors,lines))
        {
            cout<<lines<<endl;
        }


    }
    void details(department)
    {

        ifstream addd_departments("departments.txt");
        if(!addd_departments)
        {
            cout<<"error for reading"<<"\n";

        }
        string lines;
        cout<<"there are your data"<<"\n";
        while(getline(addd_departments,lines))
        {
            cout<<lines<<endl;
        }


    }

    void addstudent(student st)
    {
        cout<<"please enter the student you want to add"<<"\n";
        getline(cin,st.person_name);
        students.push_back(st);
        ofstream addd_students("students.txt",ios::app);

        if(!addd_students)
        {
            cout<<"error for reading"<<"\n";

        }

        addd_students<<endl<<st.person_name;
        addd_students.close();

    }
    void addinstructor(instructor in)
    {
        cout<<"please enter the instructor you want to add"<<"\n";
        getline(cin,in.instructor_name);
        instructors.push_back(in);
        ofstream addd_instructors("instructors.txt",ios::app);

        if(!addd_instructors)
        {
            cout<<"error for reading"<<"\n";

        }

        addd_instructors<<endl<<in.instructor_name;
        addd_instructors.close();

    }
    void addemployee(employee em)
    {
        cout<<"please enter the employee you want to add"<<"\n";
        getline(cin,em.person_name);
        employees.push_back(em);
        ofstream addd_employees("employees.txt",ios::app);

        if(!addd_employees)
        {
            cout<<"error for reading"<<"\n";

        }

        addd_employees<<endl<<em.person_name;
        addd_employees.close();

    }
    void adddepartment(department de)
    {
        cout<<"please enter the department you want to add"<<"\n";
        getline(cin,de.deprt_titile);
        departments.push_back(de);
        ofstream addd_departments("departments.txt",ios::app);

        if(!addd_departments)
        {
            cout<<"error for reading"<<"\n";

        }

        addd_departments<<endl<<de.deprt_titile;
        addd_departments.close();

    }
};
class university
{
public:
    string unive_title;
    vector<faculty>faculties;
    manager *man;
    void details(faculty)
    {
        ifstream addd_faculties("faculty.txt");
        if(!addd_faculties)
        {
            cout<<"error for reading"<<"\n";

        }
        string lines;
        cout<<"there are your data"<<"\n";
        while(getline(addd_faculties,lines))
        {
            cout<<lines<<endl;
        }
    }
    void addfaculties(faculty fa)
    {
        cout<<"please enter the faculty you want to add"<<"\n";
        getline(cin,fa.facul_title);
        faculties.push_back(fa);
        ofstream addd_faculties("faculty.txt",ios::app);
        if(!addd_faculties)
        {
            cout<<"error for reading"<<"\n";

        }

        addd_faculties<<endl<<fa.facul_title;
        addd_faculties.close();

    }

};
manager *manager::instance=nullptr;
int main ()

{
    string choice;
    cout<<"********************welcome to unversity system***************"<<"\n";
    cout<<"if you want to add faculty enter 1"<<"\n";
    cout<<"if you want to add course enter 2"<<"\n";
    cout<<"if you want to add student enter 3"<<"\n";
    cout<<"if you want to add employee enter 4"<<"\n";
    cout<<"if you want to add instructor enter 5"<<"\n";
    cout<<"if you want to add department enter 6"<<"\n";

    getline(cin,choice);
    university un;
    faculty fa;
    student st;
    employee em;
    instructor ins;
    course co;
    department de;

    if(choice=="1")
    {
        un.addfaculties(fa);
        un.details(fa);

    }

    else if(choice=="2")
    {
        de.addcourse(co);
        de.details(co);
    }
    else if(choice=="3")
    {
        fa.addstudent(st);
        fa.details(st);
    }
    else if(choice=="4")
    {

        fa.addemployee(em);
        fa.details(em);
    }
    else if(choice=="5")
    {
        fa.addinstructor(ins);
        fa.details(ins);
    }
    else if (choice=="6")
    {

        fa.adddepartment(de);
        fa.details(de);
    }
    else
    {

        cout<<"please enter a correct number from 1 to 6"<<"\n";


    }





}



