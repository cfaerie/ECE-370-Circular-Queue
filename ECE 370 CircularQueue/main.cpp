#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;



class FStack
{
    float fstack[10];
    int stackSz = 10;

public:
    int myTop = -1;

    void push(float item){
    //push item to top of stack if stack isn't full
        if(myTop < (stackSz))
        {
            myTop = myTop + 1;
            fstack[myTop] = item;
        }
        else
        {
            cout<<"Stack is full"<<endl;
        }
    }

    float pop(void)
    {
    //Remove item from stack and output it if stack isn't empty
    //need to have a variable ready to save the returned value to
        if(myTop > -1)
        {
            float output;
            output = fstack[myTop];
            myTop = myTop - 1;

            return(output);
        }
        else
        {
            cout<<"The stack is empty."<<endl;
            return(0);
        }
    }

    void isEmpty(void)
    {
    //Check if stack is empty
    int output = myTop+1;
        if(myTop <= -1)
        {
            cout<<"The stack is empty."<<endl;
        }//if
        else
        {
            cout<<"Stack contains "<<output<<" values."<<endl;
        }//else
    }

    float top(void)
    {
    //Read and return the value at the top of the stack
        if(myTop > -1)
        {
            float output;
            output = fstack[myTop];

            return(output);
        }
        else
        {
            return(NULL);
        }
    }

    void display(void)
    {
    //Display all elements in the stack top

        cout<<"\t Stack"<<endl;
        cout<<"\t---------"<<endl;
        int j = myTop;
        for(int i = 0;i<=myTop;i++)
        {
            //print stack from top to bottom
            cout<<"\t   "<<fstack[j]<<endl;
            j = j-1;
        }
    }
};


int str2int(string s)
{
    int result;
    //Convert String to float
    istringstream convert(s);
    if(!(convert >> result))
    {
        return(0);
    }
    return(result);

}

int Spriority(string character)
{
    //function to output the priority of a character
    int priorityOut;
    if(character == "(" || character == ")")
    {
        priorityOut = 0;
    }
    else if(character == "+" || character == "-")
    {
        priorityOut = 1;
    }
    else if(character == "*" || character == "/")
    {
        priorityOut = 2;
    }
    else if(character == "^")
    {
        priorityOut = 3;
    }
    else
    {
        priorityOut = NULL;
    }
    return(priorityOut);//To be saved to a variable
}


class CSQueue //String Queue
{
    //consider a circular queue
    string cqueue[15];
    int head = 0;
    int tail = 0;

public:
    int qsize = 0;
    int Oflag = 0; //flag to indicate if we are now overwriting the queue

    void enqueue(string item)
    {
        //add item to tail of queue. Allows data to be overwritten, so careful with number of enqueues done
        cqueue[tail] = item;
        tail = (tail+1)%15; //Where 15 is the length of cqueue

        if(qsize<15)
        {//where 15 is length of queue
            qsize = qsize+1;
        }
        else if(qsize == 15)
        {//if queue is full, but enqueue is used to overwrite
                //need to adjust head and tail as queue is filled
                head = tail;
        }
        //cout<<"Enqueue current queue Size: "<<qsize<<endl;
    }
    string dequeue(void)
    {
    //remove item from head of queue if queue isn't empty
        if(qsize>0)
        {
            //cannot dequeue if queue is empty (head==tail)
            string output = cqueue[head];
            head = head+1;
            if(head>14)
            {
                //if head has gone negative, set to largest queue index
                head = 0;//15-1
            }
            qsize = qsize-1;
            //cout<<"Dequeue current queue Size: "<<qsize<<endl;
            return(output);
        }
    }
    string first(void)
    {
        //Peek at head of queue
        if(qsize>0)
        {
            //if queue is not empty, otherwise data bay be garbage
            string output = cqueue[head];
            //cout<<"First out of Queue will be: "<<output<<endl;
            return(output);//return the value just in case we want to use it
        }
        else
        {
            cout<<"Queue is empty."<<endl;
        }
    }
    void isEmpty(void)
    {
        //Check if queue is empty
        if(qsize==0)
        {
            cout<<"Queue is empty. Enqueue something."<<endl;
        }
        else
        {
            cout<<"Queue is not empty."<<endl;
        }
    }
    int cSize(void)
    {
    //Return the # of elements in queue
    return(qsize);//return in case value can be used for something
    }
    string toString(void)
    {
        //return string representation of queue
        string s;
        int tempHead = head;

        for(int i=0;i<qsize;i++)
        {
            //cout<<"Current Head Index: " <<tempHead<<endl;
            //cout<<" "<<cqueue[tempHead]<<endl;
            s = s+cqueue[tempHead];
            tempHead = (tempHead+1)%15;

        }
        //cout<<s<<endl;
        //cout<<" <-- Tail"<<endl;
        return(s);


    }
};

class CSStack  //string stack
{
    string cstack[10];
    int stackSz = 10;

public:
    int myTop = -1;

    void push(string item)
    {
    //push item to top of stack if stack isn't full
        if(myTop < (stackSz))
        {
            myTop = myTop + 1;
            cstack[myTop] = item;

        }
        else
        {
            cout<<"Stack is full"<<endl;
        }
    }

    string pop(void)
    {
    //Remove item from stack and output it if stack isn't empty
    //need to have a variable ready to save the returned value to
        if(myTop > -1)
        {
            string output;
            output = cstack[myTop];
            myTop = myTop - 1;

            return(output);
        }
        else
        {
            cout<<"The stack is empty."<<endl;
            return(0);
        }//else
    }

    void isEmpty(void)
    {
    //Check if stack is empty
        int output = myTop+1;
        if(myTop <= -1)
        {
            cout<<"The stack is empty."<<endl;
        }
        else
        {
            cout<<"Stack contains "<<output<<" values."<<endl;
        }
    }

    string top(void)
    {
    //Read and return the value at the top of the stack
        string output;
        if(myTop > -1)
        {

            output = cstack[myTop];
            return(output);
        }
        else
        {
            output = "";
            return(output);
        }
    }

    void display(void)
    {
    //Display all elements in the stack top

        cout<<"\t Stack"<<endl;
        cout<<"\t---------"<<endl;
        int j = myTop;
        for(int i = 0;i<=myTop;i++)
        {
            //print stack from top to bottom
            cout<<"\t   "<<cstack[j]<<endl;
            j = j-1;
        }
    }
};

float EVAL_POSTFIX(CSQueue& myQueue)
{
        //Using & to pass by reference fixed my dequeue issue.
        //Function will have to take in the queue after postfix is done
        //will pass through a variable to save the calculation result to. Also returns that value to be saved to a variable
        string s;
        int i,n,qs;
        string currentChar,Vchar,nextChar;
        float V1,V2,V,product;
        FStack fstack;
        qs = myQueue.cSize();


        for(i=0;i<qs;i++)
        {
            //myQueue.toString();
            currentChar = myQueue.dequeue();
            //cout<<"Current Char Pulled from Queue: " << currentChar<<endl;

            if(str2int(currentChar) != 0 || currentChar == "0") //Might need to be reworked to handle 2+ digit nums
            {
                //if the character is and ASCII number 0-9
                //push to stack
                fstack.push(float(str2int(currentChar)));
            }//if ALPHA NUMERIC
                    else if(currentChar == "+"||currentChar == "-"|| currentChar == "*"|| currentChar == "/"|| currentChar == "^")
                    {
                        //if operator, pop two from stack and perform operation
                        //V1 operator V2 = V

                        V2 = fstack.pop();
                        V1 = fstack.pop();
                        if(currentChar =="+")
                        {
                                V = V1 + V2;
                        }
                        else if(currentChar=="-")
                        {
                            V = V1 - V2;
                        }
                        else if(currentChar == "/")
                        {
                            V = V1/V2;
                        }
                        else if(currentChar == "*")
                        {
                            V = V1*V2;
                        }
                        else if(currentChar == "^")
                        {
                            V = pow(V1,V2);
                        }
                        //push V to stack
                        fstack.push(V);
                        //fstack.display();
                    }

        }
        //return floating result to variable
        //cout<<"Number of items in queue, post Eval: "<<myQueue.cSize()<< endl;
        //cout<<"Is the queue empty? "<<endl;
        //myQueue.isEmpty();
        product = fstack.pop();
        //fstack.display();
        //myQueue.toString();
        return(product); //must be saved to a variable
    }

void INFIX_2_POSTFIX(CSQueue myQueue, CSStack myStack, string FILE_NAME)
{
        //function only works for single character numbers 0-9 and operators +-*/^
        //Therefore numbers >=10 are not handled
        ifstream text(FILE_NAME.c_str());
        string s,num;
        int i,n,priority_top,priority_current,temp;
        //int Qtrack = 0;
        float postEval = 0.0, evalOut = 0.0;
        string currentChar, nextChar, stackTop, toQ;

        while(getline(text,s))
        {
            cout<<"Infix: "<<s<<endl;

            //char by char, sort to stack or queue
            for(i=0;i<s.size();i++)
            {
                    currentChar = s[i];
                    //cout<<"Current Character: "<<currentChar<<endl;



                    //If currentChar is a number
                if(str2int(currentChar)!=0 || currentChar == "0")
                {
                        //48 is the ASCII of 0 and 57 is ASCII of 9. Converts the currentChar to int ascii code values in range 48-57
                        //Loop to Check if nextChar is a number or symbol, without enqueueing
                        num = currentChar;
                        for(int j = i;j<s.size();j++)
                        {
                            //check next number and append until symbol is reached
                            nextChar = s[j+1];
                            if(str2int(nextChar)!= 0 || nextChar == "0")
                            {
                                num +=nextChar;
                                i++;
                                //cout <<"\nCurrent Num: "<<num<<endl;
                            }
                            else
                            {
                                break;
                            }
                        }
                        //add to queue
                        myQueue.enqueue(num);
                        //Qtrack += 1;
                        //myQueue.toString();
                }
                else if(currentChar == "(")
                {
                    //push to stack
                    myStack.push(currentChar);
                }
                else if(currentChar == ")")
                {
                    //pop content from stack to queue until '(' is reached, then pop '(' but don't save it to queue
                    while(myStack.top() != "(")
                    {
                            myQueue.enqueue(myStack.pop());
                            //Qtrack += 1;
                    }//while
                    if(myStack.top() == "(")
                    {
                        myStack.pop();//pop the ( to nothing
                    }
                    else
                    {
                        cout<<"Error when checking for close parenthesis."<<endl;
                    }
                }

                else if(currentChar == "+"||currentChar == "-"|| currentChar == "*"|| currentChar == "/"|| currentChar == "^")
                {
                    stackTop = myStack.top();
                    priority_top = Spriority(stackTop);

                    //setting priority for whatever is at top of stack
                    priority_current = Spriority(currentChar);

                    while(priority_top >= priority_current && priority_top != NULL)
                    {
                        myQueue.enqueue(myStack.pop());
                        //Qtrack += 1;
                        //recalculate priority of top
                        stackTop = myStack.top();
                        priority_top = Spriority(stackTop);

                    }
                    //push currentChar to stack
                    myStack.push(currentChar);
                    //myStack.display();
                }
                else
                {
                    cout<<"Error in text file"<<endl;
                }

            }
            //done cycling through the line, dump rest of stack to queue if there is anything
            int temp = myStack.myTop + 1;
            //cout<<"Temp: " <<temp<<endl;
            if(myStack.myTop > -1)
            {
                for(i=0;i<temp;i++)
                {
                    myQueue.enqueue(myStack.pop());
                    //Qtrack += 1;
                    //cout<<"Top of Stack: " <<myStack.top()<<endl;
                }
            }
            else{
                cout<<"Stack index should be -1. \n It is: "<<myStack.myTop<<endl;
            }
            //now print what is in queue
            //cout<<"Queue Size: "<<Qtrack<<endl;
            cout<<"Postfix: "<<myQueue.toString()<<endl; //This needs to be corrected. Only works properly if the function was longer than previous
            evalOut = EVAL_POSTFIX(myQueue);
            //Qtrack = 0;
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

    CSQueue csq;
    CSStack css;
    string filename = "a2.txt";
    //Run the function
    INFIX_2_POSTFIX(csq,css,filename);


    return 0;
}
