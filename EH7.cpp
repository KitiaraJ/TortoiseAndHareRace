/*
    Kitiara See
    HW 5
    EH7

Problem reads:
    Simulation of a race: You need to use pointers in this classic tortoise and 
    hare race. Both begin the race at square 1 of 70 squares. Each square           
    represents a possible position along the race track. 
    The finish is square 70. You win when you reach or pass square 70.
    (... and finishes details)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

//function to move the hair
int rabbit(int &i, int a)
{
    //initializer in the function
	int h = i;
	int *hare = nullptr;

    //following if statements define movement for hare
	if (a >= 8 && a <= 10)
	{
		hare = &h;
		a = *hare;
	}

	else if (a < 8 && a >= 6)
	{
		hare = &h;
		h = *hare + 9;

		if (h <= 70)
		{
			a = h;
		}
			
		else
		{
			a = 70;
		}
	}

	else if (a < 6 && a >= 5)
	{
		hare = &h;
		h = *hare - 1;

		if (h >= 0)
		{
			a = h;
		}
		
		else
		{
			a = 0;
		}
	}

	else if (a < 5 && a >= 2)
	{
		hare = &h;
		h = *hare + 1;
	
		if (h <= 70)
		{
			a = h;
		}
			
		else 
		{
			a = 70;
		}
	}

	else if (a < 2 && a >= 1)
	{
		hare = &h;
		h = *hare - 2;

		if (h >= 0)
		{
			a = h;
		}		
	
			else
		{
			a = 0;
		}
	}

	return a;
	
}


//function that defines tortoise movement
int turtle(int &j, int b)
{
    //initializers for tortoise function
	int t = j;
	int *tort = nullptr;
	
	if (b >= 5)
	{
		tort = &t;
		t = *tort + 3;
		
		if (t <= 70)
		{
			b = t;
		}
		else
		{
			b = 70;
		}
	}
	
	else if (b < 5 && b >= 3)
	{
		tort = &t;
		t = *tort - 6;

		if (t >= 0)
		{
			b = t;
		}
		else
		{
			b = 0;
		}
	}

	else if (b < 3 && b >= 0)
	{
		tort = &t;
		t = *tort + 1;

		if (t <= 70)
		{
			b = t;
		}
		else
		{
			b = 70;
		}
	}

	return b;
}

int main()
{
    //initializers for main
	unsigned seed = time(0);
	srand(seed);
	int time = rand() % 11;
	int t = 0;
	int h = 0;

	cout << "BANG!" << endl;
	cout << "AAAND THEY'RE OFF!!!" << endl;
	cout << endl;
	cout << endl;

    //keeps the program running the race
	while (t != 70 && h != 70)
	{
		time = rand() % 11;
		t = turtle(t, time);
		h = rabbit(h, time);

		//these if statements display the race
		if (t < h) 
		{
			for (int i = 1; i < t; i++)
			{
				cout << '=';
			}
			cout << 'T';
		

			for (int i = 1; i < (h - t); i++)
			{
				cout << '=';
			}
			cout << 'H';

			for (int i = 1; i < (70 - h); i++)
			{
				cout << '=';
			}
			cout << endl;
		}

		else if (h < t) 
		{
			for (int i = 1; i < h; i++)
			{
				cout << '=';
			}
			cout << 'H';
	
			for (int i = 1; i < (t - h); i++)
			{
				cout << '=';
			}
			cout << 'T';

			for (int i = 1; i < (70 - t); i++)
			{
				cout << '=';
			}
			cout << endl;
		}
    
		//for when they both land in the same square
		else 
		{
			for ( int i = 1; i < h; i++ )
			{
				cout << '=';
			}
			cout << 'B';

			for (int i = 1; i < (70 - h); i++)
			{
				cout << '=';
			}
			cout << endl << "OUCH !!!" << endl;
		}

	}
    
    //Win conditions to print the results
	if (t == 70)
	{
		cout << "Tortoise Wins!!" << endl;
	}

	else if (h == 70)
	{
		cout << "Hare Wins?" << endl;
	}

	else 
	{
		cout << "TIE!" << endl;
	}

	system("pause>nil");
	return 0;
}

/*
The output looks like this:

BANG!
AAAND THEY'RE OFF!!!


==T=====H============================================================
=====T===========H===================================================
========T========H===================================================
=========T========H==================================================
============T=====H==================================================
===============T===========H=========================================
=========T==================H========================================
==========T==================H=======================================
=============T========================H==============================
================T====================H===============================
==========T===========================H==============================
=============T=================================H=====================
================T==============================H=====================
===================T===========================H=====================
======================T=================================H============
=======================T=================================H===========
=================T========================================H==========
===========T===============================================H=========
==============T=====================================================H
=================T==================================================H
====================T===============================================H
=====================T============================================H==
========================T============================================H
Hare Wins?

*/