#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>

using namespace std;

class CQueue{
    //consider a circular queue
    char cqueue[15];
    int head = 0;
    int tail = 0;

public:
    int qsize = 0;
    int Oflag = 0; //flag to indicate if we are now overwriting the queue
    //List of class members
    /*
    enqueue(char item)
    dequeue()
    first()
    isEmpty()
    csize()
    toString()
    */
    //all class members/functions have been tested and function
    void enqueue(char item){//tested
    //add item to tail of queue
    //does allow data to be overwritten,
    //so be careful with number of enqueues done
    cqueue[tail] = item;
    tail = (tail+1)%15; //Where 15 is the length of cqueue
    //cout<<"Enqueued --> "<<cqueue[tail-1]<< endl;
    //cout<<"New tail index: "<<tail<<endl;
    if(qsize<15){//where 15 is length of queue
        qsize = qsize+1;
    }
    else if(qsize == 15){//if queue is full, but enqueue is used to overwrite
            //need to adjust head and tail as queue is filled
            head = tail;
    }
    }
    char dequeue(void){//tested
    //remove item from head of queue if queue isn't empty
        if(qsize>0){
            //cannot dequeue if queue is empty (head==tail)
            char output = cqueue[head];
            head = head+1;
            if(head>14){
                //if head has gone negative, set to largest queue index
                head = 0;//15-1
            }
            //cout<<"Dequeued --> "<<output<<endl;
            //cout<<"New head index: "<<head<<endl;
            qsize = qsize-1;
            return(output);
        }//if
        /*
        else{
            cout<<"Queue is empty. There is nothing to dequeue."<<endl;
        }
        */
    }
    char first(void){//tested
    //Peek at head of queue
    if(qsize>0){
        //if queue is not empty, otherwise data bay be garbage
        char output = cqueue[head];
        //cout<<"First out of Queue will be: "<<output<<endl;
        return(output);//return the value just in case we want to use it
    }
    else{
        cout<<"Queue is empty."<<endl;
    }
    }
    void isEmpty(void){//tested
    //Check if queue is empty
    if(qsize==0){
        cout<<"Queue is empty. Enqueue something."<<endl;
    }
    else{
        cout<<"Queue is not empty."<<endl;
    }
    }
    int cSize(void){//tested
    //Return the # of elements in queue
    //cout<<"Size of queue is: "<<qsize<<endl;
    return(qsize);//return in case value can be used for something
    }
    string toString(void){//tested
    //return string representation of queue
    //but I'm actually just going to print what contents
    //since I can't see a use for a long string of all of the contents
    string s;
    //cout<<"String Representation of circular queue:"<<endl;
    int tempHead = head;

    //cout<<"Head --> ";
    for(int i=0;i<qsize;i++){
            //cout<<"Current Head Index: " <<tempHead<<endl;
        //cout<<" "<<cqueue[tempHead];
        s = s+cqueue[tempHead];
        tempHead = (tempHead+1)%15;

    }
    //cout<<s<<endl;
    //cout<<" <-- Tail"<<endl;
    return(s);


    }//void to string

    void clearQueue(void){
    //remove all elements from queue
        while(qsize>0){
            dequeue();
        }
        //cout<<"Current Head Index: "<<head<<endl;
        //cout<<"Current Tail Index: "<<tail<<endl;
    }

};//class







class CStack{
    //can I initialize variables here? Hope so.
    char cstack[10];
    int stackSz = 10;
public:
    int myTop = -1;
    //List of class members
    /*
    push(char item)
    pop()
    isEmpty()
    top()
    display()
    */
    //all class member functions are tested/functional

    void push(char item){//tested
    //push item to top of stack if stack isn't full
        if(myTop < (stackSz)){
            myTop = myTop + 1;
            cstack[myTop] = item;
            //cout<<"Pushed to stack --> "<< cstack[myTop]<<endl;
        }//if
        else{
            cout<<"Stack is full"<<endl;
        }//else
    }

    char pop(void){ //tested
    //Remove item from stack and output it if stack isn't empty
    //need to have a variable ready to save the returned value to
        if(myTop > -1){
            char output;
            output = cstack[myTop];
            myTop = myTop - 1;
           // cout<<"Pop: "<<output<<endl;
            return(output);
        }//if
        else{
                return(0);
            cout<<"The stack is empty."<<endl;
        }//else
    }

    void isEmpty(void){//tested
    //Check if stack is empty
    int output = myTop+1;
        if(myTop <= -1){
            cout<<"The stack is empty."<<endl;
        }//if
        else{
            cout<<"Stack contains "<<output<<" values."<<endl;
        }//else
    }

    char top(void){//tested
    //Read and return the value at the top of the stack
        if(myTop > -1){
                char output;
        output = cstack[myTop];
            //cout<<"Top of stack: "<<output<<endl;
            return(output);
        }//if
        else{
            //cout<<"Stack.Top is empty."<<endl;
            return(NULL);
        }//else
    }

    void display(void){//tested
    //Display all elements in the stack top

        cout<<"\t Stack"<<endl;
        cout<<"\t---------"<<endl;
        int j = myTop;
        for(int i = 0;i<=myTop;i++){
            //print stack from top to bottom
            cout<<"\t   "<<cstack[j]<<endl;
            j = j-1;
        }
    }//void display
};











class FStack{
    //can I initialize variables here? Hope so.
    float fstack[10];
    int stackSz = 10;
public:
    int myTop = -1;
    //List of class members
    /*
    push(char item)
    pop()
    isEmpty()
    top()
    display()
    */
    //all class member functions are tested/functional

    void push(float item){//tested
    //push item to top of stack if stack isn't full
        if(myTop < (stackSz)){
            myTop = myTop + 1;
            fstack[myTop] = item;
            //cout<<"Pushed to stack --> "<< cstack[myTop]<<endl;
        }//if
        else{
            cout<<"Stack is full"<<endl;
        }//else
    }

    float pop(void){ //tested
    //Remove item from stack and output it if stack isn't empty
    //need to have a variable ready to save the returned value to
        if(myTop > -1){
            float output;
            output = fstack[myTop];
            myTop = myTop - 1;
           // cout<<"Pop: "<<output<<endl;
            return(output);
        }//if
        else{
                return(0);
            cout<<"The stack is empty."<<endl;
        }//else
    }

    void isEmpty(void){//tested
    //Check if stack is empty
    int output = myTop+1;
        if(myTop <= -1){
            cout<<"The stack is empty."<<endl;
        }//if
        else{
            cout<<"Stack contains "<<output<<" values."<<endl;
        }//else
    }

    float top(void){//tested
    //Read and return the value at the top of the stack
        if(myTop > -1){
                float output;
        output = fstack[myTop];
            //cout<<"Top of stack: "<<output<<endl;
            return(output);
        }//if
        else{
            //cout<<"Stack.Top is empty."<<endl;
            return(NULL);
        }//else
    }

    void display(void){//tested
    //Display all elements in the stack top

        cout<<"\t Stack"<<endl;
        cout<<"\t---------"<<endl;
        int j = myTop;
        for(int i = 0;i<=myTop;i++){
            //print stack from top to bottom
            cout<<"\t   "<<fstack[j]<<endl;
            j = j-1;
        }
    }//void display
};

int priority(char character){
    //function to output the priority of a character
    int priorityOut;
    if(character == '(' || character == ')'){
                        priorityOut = 0;
                    }
                    else if(character == '+' || character == '-'){
                        priorityOut = 1;
                    }
                    else if(character == '*' || character == '/'){
                        priorityOut = 2;
                    }
                    else if(character == '^'){
                        priorityOut = 3;
                    }
                    else{
                        priorityOut = NULL;
                    }
                    return(priorityOut);//To be saved to a variable
}

float EVALUATE_POSTFIX(CQueue myQueue){
        //Function will have to take in the queue after postfix is done
        //will pass through a variable to save the calculation result to. Also returns that value to be saved to a variable
        string s;
        int i,n,qs;
        char currentChar,Vchar;
        float V1,V2,V,product;
        FStack fstack;
        qs = myQueue.qsize;


        for(i=0;i<=qs;i++){
                    currentChar = myQueue.dequeue();

                    if(int(currentChar)>=48 && int(currentChar)<= 57){
                        //if the character is and ASCII number 0-9
                        //push to stack

                        fstack.push(float(currentChar)-48);
                    }//if ALPHA NUMERIC
                    else if(currentChar == '+'||currentChar == '-'|| currentChar == '*'|| currentChar == '/'|| currentChar == '^'){
                        //if operator, pop two from stack and perform operation
                        //V1 operator V2 = V

                        V2 = fstack.pop();
                        V1 = fstack.pop();
                        if(currentChar =='+'){
                                V = V1 + V2;
                        }
                        else if(currentChar=='-'){
                            V = V1 - V2;
                        }
                        else if(currentChar == '/'){
                            V = V1/V2;
                        }
                        else if(currentChar == '*'){
                            V = V1*V2;
                        }
                        else if(currentChar == '^'){
                            V = pow(V1,V2); //double check this comes out correctly
                        }
                        //push V to stack
                        fstack.push(V);
                    }//else if OPERATOR

        }//for
        //return floating result to variable
        product = fstack.pop();
        return(product); //must be saved to a variable
    }



void INFIX_TO_POSTFIX(CQueue myQueue, CStack myStack, string FILE_NAME){
        //function only works for single character numbers 0-9 and operators +-*/^
        ifstream text(FILE_NAME.c_str());
        string s;
        int i,n,priority_top,priority_current;
        float postEval = 0.0, evalOut = 0.0;
        char currentChar, stackTop, toQ;

        while(getline(text,s)){
            cout<<"Infix: "<<s<<endl;

            //char by char, sort to stack or queue
            for(i=0;i<s.size();i++){
                    currentChar = s[i];
                    //cout<<"Current Character: "<<currentChar<<endl;



                    //If currentChar is a number
                if(int(currentChar)>=48 && int(currentChar)<= 57){
                        //48 is the ASCII of 0 and 57 is ASCII of 9. Converts the currentChar to int ascii code values in range 48-57
                        //add to queue
                        myQueue.enqueue(currentChar);
                        //myQueue.toString();

                }//if
                else if(currentChar == '('){
                    //push to stack
                    myStack.push(currentChar);
                }//if
                else if(currentChar == ')'){
                    //pop content from stack to queue until '(' is reached, then pop '(' but don't save it to queue
                    while(myStack.top() != '('){
                            myQueue.enqueue(myStack.pop());
                    }//while
                    if(myStack.top() == '('){
                        myStack.pop();//pop the ( to nothing
                    }
                    else{
                        cout<<"Error when checking for close parenthesis."<<endl;
                    }
                }//if

                else if(currentChar == '+'||currentChar == '-'|| currentChar == '*'|| currentChar == '/'|| currentChar == '^'){
                    /* While Priority of stack.top() >= priority of currentChar, pop stack to queue

                    Operator Priotities:
                    ( ) 0
                    +,- 1
                    *,/ 2
                    ^   3
                    */
                    stackTop = myStack.top();
                    priority_top = priority(stackTop);
                    //cout<<"StackTop: "<<stackTop<<endl;

                    //cout<<"Priority of Top: "<<priority_top<<endl;
                    //setting priority for whatever is at top of stack
                    priority_current = priority(currentChar);
                    //cout<<"Priority of Current: "<< priority_current<<endl;

                    while(priority_top >= priority_current && priority_top != NULL){
                            //myStack.display();
                        myQueue.enqueue(myStack.pop());
                        //myQueue.toString();
                        //recalculate priority of top
                        stackTop = myStack.top();
                    priority_top = priority(stackTop);
                    //cout<<"StackTop: "<<stackTop<<endl;
                    //cout<<"Priority of Top: "<<priority_top<<endl;

                    }
                    //push currentChar to stack
                    myStack.push(currentChar);
                }//if
                else{
                    cout<<"Error in text file"<<endl;
                }//else

            }//for
            //done cycling through the line, dump rest of stack to queue if there is anything
            int temp = myStack.myTop + 1;
            //cout<<"Temp: " <<temp<<endl;
            if(myStack.myTop > -1){
                for(i=0;i<temp;i++){

                    myQueue.enqueue(myStack.pop());
                    //cout<<"Top of Stack: " <<myStack.top()<<endl;

                }
            }//if
            else{
                cout<<"Stack index should be -1. \n It is: "<<myStack.myTop<<endl;
            }//else
            //now print what is in queue
            cout<<"Postfix: "<<myQueue.toString()<<endl;
            evalOut = EVALUATE_POSTFIX(myQueue);
            postEval = postEval + evalOut;
            //Queue should be empty after this
            //Print Evaluation
            cout<<"Evaluation: "<<s<<" = "<<evalOut<<endl;

            cout<<"\n\n\n";
        }//while
        //print postEval which has collected the sum of all lines
        cout<<"The sum of all evaluations is: "<<postEval<<endl;
}


int main()
{
    //Initialize stack and queue classes
    CQueue cq;
    CStack cs;
    string filename = "a2.txt";

    float res1,res2,res3;//store results of each line after calculation
    INFIX_TO_POSTFIX(cq,cs,filename);











    return 0;
}
