#include <iostream>
#define SERIOUS 10
#define NONSERIOUS 5
#define GENERAL 1
const int MAX_SIZE = 100;
using namespace std;
class PriorityQueue
{
public:
string N[MAX_SIZE];
int P[MAX_SIZE];
int front, rear;
PriorityQueue()
{
front = -1;
rear = -1;
}
bool isFull() {
return rear == MAX_SIZE - 1;
}
bool isEmpty() {
return front == -1 || front > rear;
}
void enqueue(string name,int value) {
if (isFull()) {
cout << "Queue is full" << endl;
return;
}
if (isEmpty()) {
front++;
rear++;
N[rear]=name;
P[rear] = value;
}
else {
int i;
for (i = rear; i >= front; i--) { //i=1
if (value > P[i]) { //10 > 5
P[i+1] = P[i]; //p[2] 5
N[i+1] = N[i]; //N[2] abc2
} else {
break;
}
}
N[i+1] = name; // abc 10 abc3 10 abc2 5
P[i+1] = value;
rear++;//2
}
}
int dequeue() {
if (isEmpty()) {
cout << "Queue is empty" << endl;
return -1;
}
int value = front;
if (front == rear){
front = -1;
rear = -1;
}
else {
front++;
}
return value;
}
void display() {
if (isEmpty()) {
cout<<"\nQueue is empty" << endl;
return;
}
cout<<"\nQueue elements are : \n";
cout<<"\n\tName \t Priority";
cout<<"\n__________";
for (int i = front; i <= rear; i++)
{
cout<<"\n\t "<<N[i]<<" \t "<<P[i];
}
cout << endl;
}
};
int main() {
PriorityQueue PQ;
string data;
int ch = 0, p;
while(ch != 4){
cout<<"\n\n----- PRIORITY QUEUE -----\n\n";
cout<<"\t1. Insert data\n\t2. Display data\n\t3. Delete data\n\t4. Exit\n";
cout<<"\n__________\n";
cout<<"Enter your choice: ";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\nEnter patient name: ";
cin>>data;
cout<<"\nEnter priority of patient(1 - Serious, 2 - Non-serious, 3 - General checkup):";
std::cin>>p;
switch (p){
case 1:
PQ.enqueue(data, SERIOUS);//abc 10 //abc3 10
break;
case 2:
PQ.enqueue(data, NONSERIOUS);// abc2 5
break;
case 3:
PQ.enqueue(data, GENERAL);
break;
default:
cout<<"Enter valid priority value!\n";
break;
}
break;
case 2:
PQ.display();
break;
case 3:int x;
x=PQ.dequeue();
if(x!=-1)
cout<<"\nPatient "<<PQ.N[x]<<" having priority "<<PQ.P[x]<<" is dequeued..\n";
break;
case 4:
cout<<"\n\n*** Thank you ***\n";
break;
default:
cout<<"Enter valid option!\n";
break;
}
}
return 0;
}
