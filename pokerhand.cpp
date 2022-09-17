//CS110B
//Poker hand program
//Module 4
//Shun Lae Thawtar Khaing

#include <iostream>
using namespace std;

const int NUM_CARD= 5;
int count[10] = {0};    // start with the count of number(0-9)- "0"

//prototypes
bool containsPair();
bool containsTwoPair();
bool containsThreeOfaKind();
bool containsStraight(int hand[]);
bool containsFourOfaKind();
bool containsFullHouse();

int main()
{
    int hand[NUM_CARD];

    cout << "Enter 5 cards without face cards. Between 2-9." << endl;

    for(int i = 0; i < NUM_CARD; i++)
    {
        cout << "Card " << i + 1 << ": ";
        cin >> hand[i];
    }

    for(int i = 0; i<NUM_CARD; i++)
    {
        //count the number of hand[i]
        count[hand[i]]++;       // get the hand[] value and count[cin >> hand[i]] <--your input number(2-9)
                            // and increment by 1 whenever it found same value(count[cin >> hand[i]])
    }        

    //couts
    if(containsPair() && containsThreeOfaKind()==false)
    {
        cout << "Pair." << endl;
    }
    else if(containsTwoPair())
    {
        cout << "Two Pairs." << endl;
    }
    else if(containsThreeOfaKind() && containsPair() == false)
    {
        cout << "Three of a kind." << endl;
    }
    else if(containsFourOfaKind())
    {
        cout << "Four of a kind." << endl;
    }
    else if(containsStraight(hand))
    {
        cout << "Straight." << endl;
    }
    else if(containsFullHouse())
    {
        cout << "Full House." << endl;
    }
    else cout << "High Card!" << endl;

}

bool containsPair()
{
        int c = 0;
    
        for(int i = 0; i<10; i++)
        {
            if(count[i] == 2) //2 same number
            {
                c++;
            }
        }

    if(c == 1) //1- 1 pair
    {
        return true;
    }

    return false;
}

bool containsTwoPair()
{
    int c = 0;
    
    for(int i = 0; i<10; i++)
    {
        if(count[i] == 2)   //2 same number
        {
            c++;
        }
    }

    if(c== 2)   //1- 2 pair
    {
        return true;
    }

    return false;
}

bool containsThreeOfaKind()
{
        int c = 0;
    
        for(int i = 0; i<10; i++)
        {
            if(count[i] == 3)   //3 same number
            {
                c++;
            }
        }

    if(c == 1) //1- 1(3pair)
    {
        return true;
    }

    return false;
}

bool containsFourOfaKind()
{
        int c = 0;
    
        for(int i = 0; i<10; i++)
        {
            if(count[i] == 4)   //4 same numbers
            {
                c++;
            }
        }

    if(c == 1)  //1- 1(4 pair)
    {
        return true;
    }

    return false;
}


bool containsStraight(int hand[])
{
    int min = hand[0];
	for(int i = 1; i < NUM_CARD; i++)
	{
		if(hand[i] < min)
		{
			min = hand[i];
		}
	}

	int next = min + 1;
	int i = 0;
	while(i < NUM_CARD)
	{
		if(hand[i] == next)
		{
			next++;
			i=0;
		}
		else
		{
			i++;
		}
	}

	if(next == (min+5))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool containsFullHouse()
{
    int c = 0;
    int b = 0;
    
    for(int i = 0; i<10; i++)
    {
        if(count[i] == 2)
        {
            c++;
        }
        if(count[i] == 3)
        {
            b++;
        }
    }

    if(c == 1 && b == 1)
    {
        return true;
    }

    return false;

}



/*SAMPLE OUTPUT
[skhaing3@hills ~]$ ./a.out
Enter 5 cards without face cards. Between 2-9.
Card 1: 1
Card 2: 1
Card 3: 2
Card 4: 2
Card 5: 2
Full House.
[skhaing3@hills ~]$ ./a.out
Enter 5 cards without face cards. Between 2-9.
Card 1: 6
Card 2: 6
Card 3: 6
Card 4: 6
Card 5: 3
Four of a kind.
*/