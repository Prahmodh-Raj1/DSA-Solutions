/*Q.The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

*/

int countStudents(vector<int>& students, vector<int>& sandwiches) {

	   int num=0;
	   int count=0;
    
       while(count<students.size()){
         if(students[0]== sandwiches[0]){
            sandwiches.erase(sandwiches.begin()+0);
            students.erase(students.begin()+0);
            count=0;
         }
         else{
            int x=students[0];
            students.erase(students.begin()+0);
            students.push_back(x);
            count++;
         }
       }
       return students.size();
}

