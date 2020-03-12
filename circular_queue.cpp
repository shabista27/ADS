/*

Pizza parlor accepting maximum M orders.
Orders are served in first come first served basis.
Order once placed cannot be cancelled. 
Write C++ program to simulate the system using circular queue using array.

*/


//==============================================
// Name        : Pizza_parlor.cpp
// Author      : Shabista shaikh
// Version     : 1.
// Copyright   : Your copyright notice
// Description : ervedPizza parlor accepting maximum M orders. 
//==============================================

#include <iostream>
using namespace std;
#define size 5
class pizza
{
    int porder[size];
    int front,rear;
public:
    pizza()
    {
     front=rear=-1;
    }
    int qfull()
    {
     if((front==0)&&(rear==(size-1))||(front==(rear+1)%size))
         return 1;
     else
         return 0;
    }
    int qempty()
    {
        if(front==-1)
            return 1;
        else
            return 0;
    }
    void accept_order(int);
    void make_payment(int);
    void order_in_queue();
};
void pizza::accept_order(int item)
{
    if(qfull())
        cout<<"\nVery Sorry !!!! No more orders....\n";
    else
    {
        if(front==-1)
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%size;
        }
        porder[rear]=item;
    }
}

void pizza::make_payment(int n)
{
    int item;
    char ans;
    if(qempty())
        cout<<"\nSorry !!! order is not there...\n";
    else
    {
      cout<<"\nDeliverd orders as follows...\n";
      for(int i=0;i<n;i++)
      {
          item=porder[front];
          if(front==rear)
          {
               front=rear=-1;
          }
          else
          {
              front=(front+1)%size;
          }
          cout<<"\t"<<item;
      }
      cout<<"\nTotal amount to pay : "<<n*100;
      cout<<"\nThank you visit Again....\n";
    }
}

void pizza::order_in_queue()
{
    int temp;
    if(qempty())
    {
        cout<<"\nSorry !! There is no pending order...\n";
    }
    else
    {
        temp=front;
        cout<<"\nPending Order as follows..\n";
        while(temp!=rear)
        {
            cout<<"\t"<<porder[temp];
            temp=(temp+1)%size;
        }
        cout<<"\t"<<porder[temp];
    }
}
int main()
{
    pizza p1;
    int ch,k,n;
    do
    {
     cout<<"\n\t***** Welcome To Pizza Parlor *******\n";
     cout << "\n1.Accept order\n2.Make_payment\n3.Pending Orders\nEnter u r choice: ";
     cin>>ch;
     switch(ch)
     {
      case 1:cout<<"\nWhich Pizza do u like most....\n";
             cout<<"\n1.Veg Soya Pizza\n2.Veg butter Pizza\n3.Egg_Pizza";
             cout<<"\nPlease enter u r order: ";
             cin>>k;
             p1.accept_order(k);
             break;
      case 2:cout<<"\nHow many Pizza ?";
             cin>>n;
             p1.make_payment(n);
             break;
      case 3:cout<<"\n Following orders are in queue to deliver....as follows..\n";
             p1.order_in_queue();
             break;
     }
    }while(ch!=4);

    return 0;
}


/*

Output
 ***** Welcome To Pizza Parlor *******

1.Accept order
2.Make_payment
3.Pending Orders
Enter u r choice: 1

Which Pizza do u like most....

1.Veg Soya Pizza
2.Veg butter Pizza
3.Egg_Pizza
Please enter u r order: 2

    ***** Welcome To Pizza Parlor *******

1.Accept order
2.Make_payment
3.Pending Orders
Enter u r choice: 1

Which Pizza do u like most....

1.Veg Soya Pizza
2.Veg butter Pizza
3.Egg_Pizza
Please enter u r order: 3
 ***** Welcome To Pizza Parlor *******

1.Accept order
2.Make_payment
3.Pending Orders
Enter u r choice: 1

Which Pizza do u like most....

1.Veg Soya Pizza
2.Veg butter Pizza
3.Egg_Pizza
Please enter u r order: 2

    ***** Welcome To Pizza Parlor *******

1.Accept order
2.Make_payment
3.Pending Orders
Enter u r choice: 1

Which Pizza do u like most....

1.Veg Soya Pizza
2.Veg butter Pizza
3.Egg_Pizza
Please enter u r order: 3

    ***** Welcome To Pizza Parlor *******

1.Accept order
2.Make_payment
3.Pending Orders
Enter u r choice: 3

 Following orders are in queue to deliver....as follows..

Pending Order as follows..
    2    3    2    3
*/