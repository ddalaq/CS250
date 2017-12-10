#ifndef _SORTING
#define _SORTING

/**
    Sets the value of a to the original value of b,
    and sets the value of b to the original value of a.

    @param <T&> a   The reference to an element of an array
    @param <T&> b   The reference to another element of an array
    @return <void>  No return - values are changed via pass-by-reference parameters
*/
template <typename T>
void Swap( T& a, T& b )
{
	T s;
	s = a;
	a = b;
	b = s;
}

/**
    Implementation of Selection Sort.
    See for reference: https://en.wikipedia.org/wiki/Selection_sort#Implementation

    @param <T[]> a  An array to sort
    @param <int> n  The size of the array a[]
    @return <void>  No return - array is passed-by-reference and modified directly
*/
template <typename T>
void SelectionSort( T a[], int n )
{
	int i, j;

	for (j = 0; j < n - 1; j++)
	{
		int iMin = j;
		for (i = j + 1; i < n; i++) {
			if (a[i] < a[iMin]) {
				iMin = i;
			}
		}

		if (iMin != j)
		{
			swap(a[j], a[iMin]);
		}
	}

	// Source:  https://en.wikipedia.org/wiki/Selection_sort#Implementation
}

/**
    Display each element of the array, from 0 to n-1

    @param <T[]> a  An array to sort
    @param <int> n  The size of the array a[]
    @return <void>  No return
*/
template <typename T>
void DisplayArray( const T a[], int n )
{
	for (int i = 0; i < n; i++)
	{
		cout << "'" << a[i] << "'" << " ";
	}
	cout << endl;
}

#endif
