#include <iostream>
#include <limits>  // Give you limits like numeric limit and it is helping us out in vlaidation function
#include <sstream> // Give functions like string
#include <cctype> // Used for character classification
#include <fstream> //Load files
#include <set> // help us out in sorting in built function
using namespace std;
class queuenode
{
public:
    int studentid;
    string name;
    float grade;
    string course;
    queuenode* next;

    queuenode()
    {
        studentid = 0;
        name = "";
        grade = 0;
        next = nullptr;
        course = "";
    }
};

class ListNode {
public:
    int studentID;
    string name;
    int age;
    float grade;
    int position;
    ListNode* next;
    char attendence;
    string course;

    ListNode()
        {
            studentID = 0;
            name = "";
            age = 0;
            grade = 0;
            next = nullptr;
            position = 0;
            attendence = '\0';
            course = " NULL ";
        }
};



class stackk
{
public:
    ListNode* top;

    stackk()
    {
        top == nullptr;
    }

      void pushdata(int SI, string Name, int agee, float gradee, int p)
    {
        ListNode* newnode = new ListNode();
        newnode->studentID = SI;
        newnode->name = Name;
        newnode->age = agee;
        newnode->grade = gradee;
        newnode->position = p;
        if(top == nullptr)
        {

            newnode->next=nullptr;
            top = newnode;
            return;
        }
        newnode->next = top;
        top = newnode;
    }


     ListNode* popdata()
    {
        if(top == nullptr)
        {
            cout<<"Nothing to Redo "<<endl;
            return nullptr;
        }
        ListNode* temp = top;
        top = top->next;
        temp->next = nullptr;
        return temp;
    }
    void displayst()
    {
        ListNode* current = top;
        cout << "****Stack elements: ****\n";
        int position = 0;
        while (current != nullptr)
        {
           cout<< "----Showing data for Student at Index "<<position + 1 <<endl;
           cout<< "********** STUDENT ID = "<<current->studentID<<" **********" <<endl;
            cout<< "********** STUDENT NAME = "<<current->name<<" **********" <<endl;
            cout<< "********** STUDENT AGE = "<<current->age<<" **********" <<endl;
            cout<< "********** STUDENT GRADE = "<<current->grade<<" ********** \n" <<endl;
            current = current->next;
            position++;
        }

    }
};


class linklist
{
public:
    ListNode * head;
    stackk s1;
    linklist()
    {
        head = nullptr;
    }


    void insertdataathead(int SI, string Name, int agee, float gradee)
            {
                ListNode* newnode = new ListNode();
                newnode->studentID = SI;
                newnode->name = Name;
                newnode->age = agee;
                newnode->grade = gradee;
                newnode->next = nullptr;
                if(head == nullptr)
                {
                head = newnode;
                cout<<"*******---INSERTION SUCCESSFULL AT HEAD---*******"<<endl;
                return;
                }
                else
                {
                newnode->next = head;
                head = newnode;

                cout<<"*******---INSERTION SUCCESSFULL AT HEAD---*******"<<endl;
                return;
                }
            }


            void insetattail(int SI, string Name, int agee, float gradee)
            {
                ListNode* currnode = head;
                ListNode* newnode = new ListNode();
                newnode->studentID = SI;
                newnode->name = Name;
                newnode->age = agee;
                newnode->grade = gradee;
                newnode->next = nullptr;
                if(currnode == nullptr)
                {
                    head = newnode;
                    cout<<"*******---INSERTION SUCCESSFULL AT Tail---*******"<<endl;
                    return;
                }

                while(currnode->next != nullptr)
                {
                   currnode = currnode->next;
                }

               currnode->next = newnode;
               cout<<"*******---INSERTION SUCCESSFULL AT Tail---*******"<<endl;
            }

    bool insetatposition(int position,int SI, string Name, int agee, float gradee)
            {


                 if (position <= 0) {
                    cout << "Invalid position. Please enter a position greater than 0." << endl;
                    return false;
                    }

                    if(position == 1)
                {
                    insertdataathead(SI,Name,agee,gradee);
                    return true;
                }

                ListNode* prevnode = nullptr;
                ListNode* currnode = head;

                int currposition = 0;
                while(currnode != nullptr && currposition < position)
                {
                    prevnode = currnode;
                    currnode = currnode->next;
                    currposition++;
                }
                if(currposition != position)
                {
                    cout<<"No such position Please Enter a Valid Position"<<endl;
                    return false;
                }
                ListNode* newnode = new ListNode();
                newnode->studentID = SI;
                newnode->name = Name;
                newnode->age = agee;
                newnode->grade = gradee;
                prevnode->next = newnode;
                newnode->next = currnode;
                cout<<"*******---INSERTION SUCCESSFULL AT "<<position<<" ---*******"<<endl;
                return true;
            }


            bool deleteathead()
            {

                if(head == nullptr)
                {
                    cout<<"List is Empty cannot Delete"<<endl;
                    return false;
                }

                ListNode*temp = head;

                head = head->next;
                int sid = temp->studentID;
                string nname = temp->name;
                int age =temp->age;
                float f = temp->grade;
                int p = 1;
                s1.pushdata(sid,nname,age,f,p);

                delete temp;
                cout<<"***********-------- Deletion Successfull at head --------***********"<<endl;
                return true;
            }

             bool deleteattail()
            {

                if (head == nullptr)
                {
                    cout<<"List is Empty"<<endl;
                    return false;
                }
                else if(head->next == nullptr)
                {
                    int sid = head->next->studentID;
                    string nname = head->next->name;
                    int age =head->next->age;
                    float f = head->next->grade;
                    s1.pushdata(sid,nname,age,f,1);

                    delete head;
                    head = nullptr;
                    cout<<"***********-------- Deletion Successfull at tail --------***********"<<endl;
                    return true;
                }

                ListNode* temporary = head;

                while(temporary->next->next != nullptr)
                {
                    temporary = temporary->next;
                }

                    int sid = temporary->next->studentID;
                    string nname = temporary->next->name;
                    int age =temporary->next->age;
                    float f = temporary->next->grade;

                    s1.pushdata(sid,nname,age,f,100);
                delete temporary->next;

                temporary->next = nullptr;
                cout<<"***********-------- Deletion Successfull at tail --------***********"<<endl;
                return true;
            }

    bool deleteAtPosition(int position) {
            if (head == nullptr) {
                cout << "List is empty" << endl;
                return false;
            }
            ListNode* temporary = head;

            if(position == 1)
            {
                head = head->next;
                    int sid = temporary->studentID;
                    string nname = temporary->name;
                    int age =temporary->age;
                    float f = temporary->grade;
                    int p = position;
                    s1.pushdata(sid,nname,age,f,p);
                delete temporary;
                return true;
            }
            int count = 1;
            while(count < position-1 && temporary!= nullptr)
            {
                temporary = temporary->next;
                count++;
            }
            if(temporary == nullptr || temporary->next == nullptr)
            {
                cout<<"Position out of range "<<endl;
                return false;
            }
            ListNode* nextnode = temporary->next->next;
            int sid = temporary->next->studentID;
            string nname = temporary->next->name;
            int age =temporary->next->age;
            float f = temporary->next->grade;
            int p = position;
            s1.pushdata(sid,nname,age,f,p);
            delete temporary->next;
            temporary->next = nextnode;

            return true;
            }


            void undo()
            {
                ListNode* node = s1.popdata();
                 if(node == nullptr)
                {
                return;
                }
                int sid = node->studentID;
                string n = node->name;
                int age = node->age;
                float grad = node->grade;
                int pos = node->position;

                    if(pos == 1)
                    {
                        insertdataathead(sid,n,age,grad);
                    }

                    else if(pos == 100)
                    {
                        insetattail(sid,n,age,grad);
                    }

                    else
                    {
                        insetatposition(pos,sid,n,age,grad);
                    }
                    delete node;
                }


        ListNode* searchlistN(string name)
            {
                ListNode* temp = head;
                int position;
                while(temp != nullptr)
                {
                    if(temp->name == name)
                    {
                        cout<<" Value Found at Position "<< position <<endl;
                        return temp;
                    }
                    temp = temp->next;
                    position++;
                }
                cout<<"No Such data Found with Such Name"<<endl;
                return nullptr;
            }

            bool searchlistI(int id)
            {
                ListNode* temp = head;
                int position;
                while(temp != nullptr)
                {
                    if(temp->studentID == id)
                    {
                        string n = temp->name;
                        cout<<" Value Found at Position "<< position << " And Name of Student is * "<< n <<" "<<endl;
                        return true;
                    }
                    temp = temp->next;
                    position++;
                }
                cout<<"No Such data Found with Such ID"<<endl;
                return false ;
            }

                void diplaystack()
                {
                    s1.displayst();
                    return;
                }



void saveDataToFile(string filename) {

    ofstream file(filename);

    if (!file) {
        cout << "Error creating file: " << filename << endl;
        return;
    }
    ListNode* current = head;
    while (current != nullptr) {
        file << "Student ID: " << current->studentID << endl;
        file << "Name: " << current->name << endl;
        file << "Age: " << current->age << endl;
        file << "Grade: " << current->grade << endl;
        file << endl;

        current = current->next;
    }

    file.close();

    cout << "Data saved to file: " << filename << endl;
}


ListNode* headd()
{
    ListNode* temp = head;
    if(temp == nullptr)
    {
        cout<< "!!!!!!!!!!!!!!!! Nothing in List !!!!!!!!!!!!!!!!!!!!!"<<endl;
        return nullptr;
    }
    else
    {
        return temp;
    }
}




   void sortDataByLast3DigitsOfStudentID() {
        if (head == nullptr || head->next == nullptr) {
            cout << "No data or only one element present in the list. Sorting not required." << endl;
            return;
        }

        ListNode* currnode = head;
        ListNode* prevnode = nullptr;
        ListNode* tempnode = nullptr;
        bool isSorted = false;

        while (!isSorted) {
            isSorted = true;
            currnode = head;
            prevnode = nullptr;

            while (currnode->next != nullptr) {
                int currID = currnode->studentID % 1000;  // Extract last 3 digits of current student ID
                int nextID = currnode->next->studentID % 1000;  // Extract last 3 digits of next student ID

                if (currID > nextID) {
                    isSorted = false;

                    if (prevnode == nullptr) {
                        // Swapping head and next node
                        tempnode = currnode->next;
                        currnode->next = currnode->next->next;
                        tempnode->next = currnode;
                        head = tempnode;
                        prevnode = head;
                    } else {
                        // Swapping currnode and next node
                        tempnode = currnode->next;
                        currnode->next = currnode->next->next;
                        tempnode->next = currnode;
                        prevnode->next = tempnode;
                        prevnode = prevnode->next;
                    }
                } else {
                    prevnode = currnode;
                    currnode = currnode->next;
                }
            }
        }

        cout << "Data sorted by last 3 digits of student ID." << endl;
    }

    void sortDataByName() {
        if (head == nullptr || head->next == nullptr) {
            cout << "No data or only one element present in the list. Sorting not required." << endl;
            return;
        }

        ListNode* currnode = head;
        ListNode* prevnode = nullptr;
        ListNode* tempnode = nullptr;
        bool isSorted = false;

        while (!isSorted) {
            isSorted = true;
            currnode = head;
            prevnode = nullptr;

            while (currnode->next != nullptr) {
                if (currnode->name > currnode->next->name) {
                    isSorted = false;

                    if (prevnode == nullptr) {
                        // Swapping head and next node
                        tempnode = currnode->next;
                        currnode->next = currnode->next->next;
                        tempnode->next = currnode;
                        head = tempnode;
                        prevnode = head;
                    } else {
                        // Swapping currnode and next node
                        tempnode = currnode->next;
                        currnode->next = currnode->next->next;
                        tempnode->next = currnode;
                        prevnode->next = tempnode;
                        prevnode = prevnode->next;
                    }
                } else {
                    prevnode = currnode;
                    currnode = currnode->next;
                }
            }
        }

        cout << "Data sorted by name." << endl;
    }


    void sortDataByAge() {
    if (head == nullptr || head->next == nullptr) {
        cout << "No data or only one element present in the list. Sorting not required." << endl;
        return;
    }

    ListNode* currnode = head;
    ListNode* prevnode = nullptr;
    ListNode* tempnode = nullptr;
    bool isSorted = false;

    while (!isSorted) {
        isSorted = true;
        currnode = head;
        prevnode = nullptr;

        while (currnode->next != nullptr) {
            if (currnode->age > currnode->next->age) {
                isSorted = false;

                if (prevnode == nullptr) {
                    // Swapping head and next node
                    tempnode = currnode->next;
                    currnode->next = currnode->next->next;
                    tempnode->next = currnode;
                    head = tempnode;
                    prevnode = head;
                } else {
                    // Swapping currnode and next node
                    tempnode = currnode->next;
                    currnode->next = currnode->next->next;
                    tempnode->next = currnode;
                    prevnode->next = tempnode;
                    prevnode = prevnode->next;
                }
            } else {
                prevnode = currnode;
                currnode = currnode->next;
            }
        }
    }

    cout << "Data sorted by age." << endl;
}

void sortDataByGrade() {
    if (head == nullptr || head->next == nullptr) {
        cout << "No data or only one element present in the list. Sorting not required." << endl;
        return;
    }

    ListNode* currnode = head;
    ListNode* prevnode = nullptr;
    ListNode* tempnode = nullptr;
    bool isSorted = false;

    while (!isSorted) {
        isSorted = true;
        currnode = head;
        prevnode = nullptr;

        while (currnode->next != nullptr) {
            if (currnode->grade > currnode->next->grade) {
                isSorted = false;

                if (prevnode == nullptr) {
                    // Swapping head and next node
                    tempnode = currnode->next;
                    currnode->next = currnode->next->next;
                    tempnode->next = currnode;
                    head = tempnode;
                    prevnode = head;
                } else {
                    // Swapping currnode and next node
                    tempnode = currnode->next;
                    currnode->next = currnode->next->next;
                    tempnode->next = currnode;
                    prevnode->next = tempnode;
                    prevnode = prevnode->next;
                }
            } else {
                prevnode = currnode;
                currnode = currnode->next;
            }
        }
    }

    cout << "Data sorted by grade." << endl;
}

  void display()
                {
                    ListNode* ptr = head;
                    cout<<"**** Link List Elements "<<endl;
                    int position = 0;
                    while (ptr != nullptr) {
                        cout<< "----Showing data for Student at Index "<<position + 1 <<endl;
                        cout<< "********** STUDENT ID = "<<ptr->studentID<<" **********" <<endl;
                        cout<< "********** STUDENT NAME = "<<ptr->name<<" **********" <<endl;
                        cout<< "********** STUDENT AGE = "<<ptr->age<<" **********" <<endl;
                        cout<< "********** STUDENT GRADE = "<<ptr->grade<<" ********** \n" <<endl;

                        ptr = ptr->next;
                        position ++;
                    }

                }


        void attendence()
                {
                    if(head == nullptr)
                    {
                        cout<<"No Students to mark Attendence of "<<endl;
                        return;
                    }
                    ListNode* nnode = head;

                    char a;

                        while(nnode!=nullptr)
                        {
                            cout<<"\n Enter Attendece of the student "<<nnode->name << " having ID  "<< nnode->studentID <<endl;
                              h:
                                cin>>a;
                                bool f = isValidChar(a);
                                if(f)
                                {
                                    if(a == 'p'||a == 'P')
                                    {
                                        nnode->attendence = 'P';
                                    }
                                    else if(a == 'a'||a == 'A')
                                    {
                                        nnode->attendence = 'A';
                                    }
                                    else
                                    {
                                        cout<<"Enter Valid Character a,A,p,P "<<endl;
                                        goto h;
                                    }
                            }
                            else
                            {
                                cout<<"Enter Valid Character"<<endl;
                                goto h;
                            }
                            nnode = nnode->next;
                        }
                    }




                   void displayattendance() {
                        ListNode* currentNode = head;

                        if (currentNode == nullptr) {
                                cout << "!!!!!___ Nothing in the list ___!!!!!" << endl;
                                return;
                            }

                        bool attendanceMarked = false;

                    while (currentNode != nullptr) {
                            if (currentNode->attendence != '\0') {
                                attendanceMarked = true;
                            break;
                        }
                        currentNode = currentNode->next;
                        }

                if (!attendanceMarked) {
                            cout << "!!!!!___ Attendance is not marked ___!!!!!" << endl;
                            return;
                    }

                currentNode = head;

                while (currentNode != nullptr) {
                        cout << currentNode->name << " was " << currentNode->attendence << endl;
                            currentNode = currentNode->next;
                    }
}


    bool isValidChar(char input) {
    // Check if the input is an uppercase or lowercase letter
            if ((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z')) {
                return true;
            }

    // Check if the input is a whitespace character
                if (std::isspace(input)) {
                return true;
            }

    // If the input is not valid, return false
            return false;
            }



void saveDataToFileattendence(string filename)
{
    ofstream file(filename);

    if (!file)
    {
        cout << "Error creating file: " << filename << endl;
        return;
    }

    ListNode* current = head;
    if (current->attendence == '\0')
    {
        cout << "Attendance hasn't been marked." << endl;
        return;
    }

    cout << "\nEnter Today's Date: ";
    int i = validateIntegerInput();
    cout << "Enter Month: ";
    int j = validateIntegerInput();
    cout << "Enter Year: ";
    int k = validateIntegerInput();
    file << "Date / Month / Year: " << i << "/" << j << "/" << k << endl;

    while (current != nullptr)
    {
        file << "Student ID: " << current->studentID << "\nName: " << current->name << "\nAttendance: " << current->attendence << "\n\n";
        current = current->next;
    }

    file.close();

    cout << "\nAttendance data saved to file: " << filename << endl;
}

            int validateIntegerInput() {
    int input;
    string inputString;
    while (true) {
        getline(cin, inputString);

        // Check if the input string is empty
        if (!inputString.empty()) {
            // Convert the string to an integer
            istringstream iss(inputString);
            if (iss >> input) {
                // Integer input successful
                break;
            }
        }

        cout << "\n !-!-!-!-!-!-!Invalid input. Please enter a non-empty integer.!-!-!-!-!-!-!\n";
    }
    return input;
}

        bool updatecourse( ListNode* n, string name, string course)
        {

            ListNode* node = n;

            while(node!=nullptr)
            {
                if(node->name == name)
                {
                    node->course = course;
                    return true;
                }
                node = node->next;
            }
            return false;
        }

        void displaycourses()
        {
            ListNode* node = head;
            if(head == nullptr)
            {
                cout<<"!-!-!-!-!-! Nothing in list to display !-!-!-!-!-!"<<endl;
                return;
            }

            int position = 0;

            while(node!=nullptr)
            {
                cout<< " Student at Position " << position+1 << " Having id "<< node->studentID << " and name "<<node->name<< "Is registered for "<<node->course <<endl;
                cout<<endl;
                node=node->next;
                position ++;
            }
        }
};


class queuee : public linklist{
public:
    queuenode* frontt;
    queuenode* rear;
    int numitems;
    queuee()
    {
        frontt = nullptr;
        rear = nullptr;
        numitems = 0;
    }

    void enqueue(int id, string name, float grade,string course)
    {
        queuenode* nnode = new queuenode();

        nnode->studentid = id;
        nnode->name = name;
        nnode->grade = grade;
        nnode->course = course;
        nnode->next = nullptr;
        if(isempty())
        {
            frontt = nnode;
            rear = nnode;
        }
        else
        {
            rear->next = nnode;
            rear = nnode;
        }
        return;
    }
    bool isempty()
    {
        if(frontt == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void dequeue()
    {
        if(isempty())
        {
            cout<<" !-!-!-!-!-!Nothing in Queue!-!-!-!-!-! "<<endl;
            return;
        }
        queuenode* temp = frontt;
        frontt = frontt->next;
        delete temp;
        return ;
    }

    void displayq()
{
    queuenode* current = frontt;

    if (isempty())
    {
        cout << "!-!-!-!-!-! Queue is empty !-!-!-!-!-!" << endl;
        return;
    }

    cout << "Queue Contents: " << endl;
    while (current != nullptr)
    {
        cout << "Student ID: " << current->studentid << endl;
        cout << "Name: " << current->name << endl;
        cout << "Grade: " << current->grade << endl;
        cout << "Course: " << current->course << endl;
        cout << endl;

        current = current->next;
    }
}


    void registerr(ListNode* n, string nn, string c)
        {
            int id = n->studentID;
            float f = n->grade;
            enqueue(id,nn,f,c);
            return;

        }

        void uploadcourse(ListNode* n)
        {
            queuenode* current = frontt;
            if(frontt == nullptr)
            {
                cout<<" !-!-!-!-!-!-!-! Cannot upload courses as no course request is there !-!-!-!-!-!-!-! "<<endl;
                return ;
            }
            while(current!=nullptr)
            {
                cout<<" Student Having id "<<current->studentid <<" and Name "<<current->name <<" having Grade"<<current->grade << " wants to register for "<<current->course<<endl;
                cout<<"\n Enter 1 to approve or 0 to decline \n"<<endl;
                int i;
                cin>>i;
                if(i == 1)
                {
                    bool f = updatecourse(n,current->name, current->course);
                    if(f)
                    {
                        cout<<" *-*-*-*-*-* Update successfull for student *-*-*-*-*-* "<<endl;
                    }
                    else
                    {
                        cout<<" !-!-!-!-!-! Update was not successfull !-!-!-!-!-!"<<endl;
                    }
                    dequeue();
                }
                else if(i == 0)
                {
                    dequeue();
                    cout<<" student Removed Successfully without course updating \n "<<endl;
                }
                current = current->next;
            }
            return;
        }
};


int validateIntegerInput() {
    int input;
    string inputString;
    while (true) {
        getline(cin, inputString);

        // Check if the input string is empty
        if (!inputString.empty()) {
            // Convert the string to an integer
            istringstream iss(inputString);
            if (iss >> input) {
                // Integer input successful
                break;
            }
        }

        cout << "!-!-!-!-!-!-!Invalid input. Please enter a non-empty integer.!-!-!-!-!-!-!\n";
    }
    return input;
}


string validateStringInput() {
    string input;
    while (true) {

        std::getline(cin,input);

        // Check if the string is empty or contains whitespace
        bool valid = true;
        for (char c : input) {
            if (!isalpha(c)) {
                valid = false;
                break;
            }
        }

        // Trim leading and trailing whitespace
        size_t start = input.find_first_not_of(" \t");
        size_t end = input.find_last_not_of(" \t");
        if (start != string::npos) {
            input = input.substr(start, end - start + 1);
        }

        if (valid && !input.empty()) {

            break;
        } else {
          cout << "!!!!!!!---Invalid input. Please enter a non-empty string with characters only.---!!!!!!!\n";
        }
    }
    return input;
}

float validateFloatInput() {
    float input;
string inputString;
    while (true) {
        getline(cin, inputString);

        // Use stringstream to convert the input string to float
        istringstream iss(inputString);
        if (iss >> input) {
            // Check if there are any remaining characters after conversion
            char remainingChar;
            if (!(iss >> remainingChar)) {
                // Float input successful
                break;
            }
        }

        cout << "!!!!!!!---Invalid input. Please enter a valid float value.---!!!!!!!\n";
    }
    return input;
}


int main()
{
     linklist hh;
         queuee q1;
aa:
    cout<<" \n *-*-*-*-*-*-*-*-*-*-*-*-*-* Welcome to Student Management System *-*-*-*-*-*-*-*-*-*-*-*-*-* \n"<<endl;

        cout<<"-------------------- Enter 1 to continue as Administrator --------------------"<<endl;
        cout<<"-------------------- Enter 2 to continue as Student --------------------"<<endl;
        int m = validateIntegerInput();

        if(m == 1)
        {
jj:
        cout<<"--------------------Please Enter Username (only in character) -------------------- \n"<<endl;
        string user = validateStringInput();
        cout<<"--------------------Please Enter Password (only in character) -------------------- \n"<<endl;
        string password = validateStringInput();
        string p = "admin";
        string u = "admin";
    if(user == u && password == p)
    {

    cout<<" \n *-*-*-*-*-*-*-*-*-*-*-* You Successfully Logged In *-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"\n ************____________Enter Numbers as illustrated____________************"<<endl;
b:
    cout<< "\n     - - - - - Enter 1 to Insert Data - - - - -     "<<endl;
    cout<< "\n     - - - - - Enter 2 to Display Data - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 3 to Delete Data - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 4 to Display Stack Data - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 5 to Undo - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 6 to To Search For Student - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 7 to To Save File - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 8 to To open File - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 9 to To sort Data - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 10 to To Mark Attendence - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 11 to To view Attendence - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 12 to To save Attendence - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 13 to To see who Register Course - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 14 to To approve Course - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 15 to To see courses registered - - - - -    "<<endl;
    cout<< "\n     - - - - - Enter 16 to To logout - - - - -    "<<endl;
    int j = validateIntegerInput();
    if(j == 1)
    {
                cout<<"\n       Enter Student id \n"<<endl;
                int Stuid = validateIntegerInput();
                cout<<"\n       Enter Student Name \n"<<endl;
                string Name = validateStringInput();
                cout<<"\n       Enter Age of Student \n"<<endl;
                int agee = validateIntegerInput();
                cout<<"\n       Enter Grade of Student \n"<<endl;
                float gradee = validateFloatInput();
                a:
                cout<< "\n          Enter 1 to Insert at End"<<endl;
                cout<< "\n          Enter 2 to Insert at Head"<<endl;
                cout<< "\n          Enter 3 to Insert at Position"<<endl;

        int i = validateIntegerInput();

                if(i == 1)
                    {
                        hh.insetattail(Stuid,Name,agee,gradee);
                        goto b;
                    }
                    else if(i == 2)
                    {
                        hh.insertdataathead(Stuid,Name,agee,gradee);
                        goto b;
                    }
                    else if(i == 3)
                    {
                        cout<<"\n           Enter the position on which you want to Enter"<<endl;
                        int k = validateIntegerInput();
                        bool l = hh.insetatposition(k,Stuid,Name,agee,gradee);
                        if(l==true)
                        {
                            goto b;
                        }
                        else
                        {
                            goto a;
                        }
                    }
                    else
                    {
                        cout<<"\n !!!!!-----Enter Valid Input between 1,2 and 3 -----!!!!!"<<endl;
                        goto a;
                    }
    }
    else if (j ==2)
    {
        hh.display();
        goto b;
    }
    else if(j == 3)
    {
                c:
                cout<< "\n      Enter 1 to Delete at End"<<endl;
                cout<< "\n      Enter 2 to Delete at Head"<<endl;
                cout<< "\n      Enter 3 to Delete at Position"<<endl;

                int l = validateIntegerInput();
                if(l == 1)
                {
                    bool h = hh.deleteattail();
                    if(h == true)
                    {
                        goto b;
                    }
                    else {
                        goto c;
                    }
                }
                else if (l == 2)
                {
                    bool h = hh.deleteathead();
                    if(h == true)
                    {
                        goto b;
                    }
                    else {
                        goto c;
                    }

                }
                else if(l ==3)
                {
                    cout<<"    *** Enter Position On which You want to Delete ***   "<<endl;
                    int u = validateIntegerInput();
                    bool val = hh.deleteAtPosition(u);
                    if(val == true)
                    {
                        goto b;
                    }
                    else
                    {
                        goto c;
                    }
                }
                else
                {
                    cout<<"!!!!! ---- Enter Valid Number In Between 1,2 and 3 ---- !!!!!"<<endl;
                    goto c;
                }
    }
    else if(j == 4)
    {
        hh.diplaystack();
        goto b;
    }
    else if(j == 5)
    {
        hh.undo();
        goto b;
    }
    else if(j ==6)
    {
        d:
        cout<<"***---____ Enter 1 to search By Name || Enter 2 to Search by Id ___---***"<<endl;
        int i = validateIntegerInput();
        if(i == 1)
        {
            cout<<"         Enter Name You Want to Search"<<endl;
            string s = validateStringInput();
            hh.searchlistN(s);
            goto b;
        }
        else if(i == 2)
        {
            cout<< "        Enter Id you Want to Search "<<endl;
            int i = validateIntegerInput();
            hh.searchlistI(i);
            goto b;
        }
        else
        {
            cout<< "!!!!! Enter Valid Input !!!!!"<<endl;
            goto d;
        }
    }
    else if(j == 7)
    {
        cout<<"\n       Enter Name of The File "<<endl;
        string n = validateStringInput();
        hh.saveDataToFile(n);
        goto b;
    }
    else if(j == 8)
    {
        //e:
        cout<< "\n !!!!!!!!!!!! This function is to be constructed !!!!!!!!!!!!! \n"<<endl;
//        cout<< "\n       Enter Name of File You want to open "<<endl;
//        string filename = validateStringInput();

         goto b;
    }
    else if(j == 9)
    {
        f:
        cout<< "\n **** Enter 1 to Sort by Name || Enter 2 to Sort by Id last 3 Digits || Enter 3 to Sort Data by age || Enter 4 to Sort Data by Grade || Enter 5 to go Back"<<endl;
        int l = validateIntegerInput();
        if(l == 1)
        {
            hh.sortDataByName();
            goto b;
        }
        else if(l == 2)
        {
            hh.sortDataByLast3DigitsOfStudentID();
            goto b;
        }
        else if(l ==3)
        {
            hh.sortDataByAge();
            goto b;
        }
        else if(l == 4)
        {
            hh.sortDataByGrade();
            goto b;
        }
        else if(l == 5)
        {
            goto b;
        }
        else
        {
            cout<< "!-!-!-!-!-! Please Enter a Valid Number !-!-!-!-!-!"<<endl;
            goto f;
        }
    }
    else if(j == 10)
    {
        hh.attendence();
        goto b;
    }
    else if(j == 11)
    {
        hh.displayattendance();
        goto b;
    }
    else if(j == 12)
    {
        cout<<"\n        *Enter Name of The File in which you want to save attendence* "<<endl;
        string n = validateStringInput();
        hh.saveDataToFileattendence(n);
        goto b;
    }

    else if(j == 13)
    {
        q1.displayq();
        goto b;
    }
    else if(j == 14)
    {
        ListNode* n = hh.headd();
        q1.uploadcourse(n);
        goto b;
    }
    else if(j == 15)
    {
        hh.displaycourses();
        goto b;
    }
    else if(j == 16)
    {
        goto aa;
    }
    else
    {
        cout<< "!-!-!-!-! Enter Valid Input !-!-!-!-!"<<endl;
        goto b;
    }
    }
    else
    {
        cout<< "!-!-!-!-!-!-! Either the password or UserName is wrong please Enter Again !-!-!-!-!-!-!"<<endl;
        goto jj;
    }
        }
        else if (m == 2)
        {
                cout<< "------------ Enter Your Id for Verification ------------"<<endl;
                int l = validateIntegerInput();
                bool m = hh.searchlistI(l);
                if(m)
                {
                     rr:
                        cout<<"\n -------------You Can Register Now ----------- \n"<<endl;
                        cout<< " ------------ Enter Your Name ------------\n "<<endl;
                        string n = validateStringInput();
                        ListNode* l = hh.searchlistN(n);
                        if(l == nullptr)
                        {
                            goto rr;
                        }
                        else
                        {
                            cout<< " ------------ Enter course ------------ \n"<<endl;
                            string c = validateStringInput();
                            q1.registerr(l,n,c);
                            cout<<"*************** LOGGING YOU OUT *************** "<<endl;
                            goto aa;
                        }
                }
                else
                {
                    goto aa;
                }
        }
        else
        {
            cout<< "!!!!!!!!!!!!!!!! Invalid Entery Insert Number in 1 || 2 !!!!!!!!!!!!!!!!!"<<endl;
            goto aa;
        }
    cout << "Hello world!" << endl;
    return 0;
};

// Resolve position regarding display
// Resolve memory leak in undo function
