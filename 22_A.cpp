#include <iostream>

using namespace std;

class Solution
{
    struct node
    {
        char val;
        node *next;
    };
    node *head = NULL;
    node *tail = NULL;

public:
    void pushCharacter(char x)
    {
        node *newnode;
        newnode=new node;
        newnode->val = x;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

public:
    char popCharacter()
    {
        char x;
        if (head == NULL)
        {
            return -1;
        }
             else if(head==tail)
    {
        int x=head->val;
        head=NULL;
        tail=NULL;
        return x;
    } 
        else
        {
            x = head->val;
           // node *temp = head;
            head = head->next;
            //delete temp;
             return x;
        }
       
    }
    node *head1 = NULL;
    node *tail1 = NULL;

public:
void enqueueCharacter(char x)
{
    node *newnode1 = new node;
    newnode1->val = x;
    newnode1->next = NULL;

    if (tail1)
    {
        tail1->next = newnode1;
        tail1 = newnode1; 
    }
    else
    {
        head1 = newnode1; 
        tail1 = newnode1; 
    }
}


public:
    char dequeueCharacter()
    {
        char x;
        if (head1 == NULL)
        {
            return -1;
        }
     else if(head1==tail1)
    {
        int x=head1->val;
        head1=NULL;
        tail1=NULL;
        return x;
    } 
        else
        {
            x = head1->val;
            head1 = head1->next;
            return x;
        }
        
    }
};
    int main()
    {
        // read the string s.
        string s;
        getline(cin, s);
        // create the Solution class object p.
        Solution obj;
        // push/enqueue all the characters of string s to stack.
        for (int i = 0; i < s.length(); i++)
        {
            obj.pushCharacter(s[i]);
            obj.enqueueCharacter(s[i]);
        }

        bool isPalindrome = true;

        // pop the top character from stack.
        // dequeue the first character from queue.
        // compare both the characters.
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (obj.popCharacter() != obj.dequeueCharacter())
            {
                isPalindrome = false;
                break;
            }
        }
        // finally print whether string s is palindrome or not.
        if (isPalindrome)
        {
            cout << "The word, " << s << ", is a palindrome.";
        }
        else
        {
            cout << "The word, " << s << ", is not a palindrome.";
        }

        return 0;
    }