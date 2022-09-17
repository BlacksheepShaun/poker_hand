#include <iostream>
using namespace std;

const int NUM_CARD= 5;
int count[10] = {0};

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
        count[hand[i]]++;
    }

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
            if(count[i] == 2)
            {
                c++;
            }
        }

    if(c == 1)
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
        if(count[i] == 2)
        {
            c++;
        }
    }

    if(c== 2)
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
            if(count[i] == 3)
            {
                c++;
            }
        }

    if(c == 1)
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
            if(count[i] == 4)
            {
                c++;
            }
        }

    if(c == 1)
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