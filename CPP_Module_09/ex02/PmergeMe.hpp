#pragma "one"

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include<sys/time.h>

template <typename T>

void  insertSort(T &MContainer) {
	typename T::iterator it;
	typename T::iterator new_end;
    for (it = MContainer.begin(); it != MContainer.end(); ++it) {
        int currentValue = *it;
        new_end = it;
        while (new_end != MContainer.begin() && currentValue < *(std::prev(new_end))) {
            *new_end = *(std::prev(new_end));
            --new_end;
        }
        *new_end = currentValue;
    }
}

template <typename T>

void  merge(T &MContainer,T& leftcontainer, T& rightcontainer) {
    typename T::iterator leftcontainerIt = leftcontainer.begin();
    typename T::iterator rightcontainerIt = rightcontainer.begin();

    while (leftcontainerIt != leftcontainer.end() && rightcontainerIt != rightcontainer.end()) {
        if (*leftcontainerIt < *rightcontainerIt) {
            MContainer.push_back(*leftcontainerIt);
            ++leftcontainerIt;
        } else {
            MContainer.push_back(*rightcontainerIt);
            ++rightcontainerIt;
        }
    }
    for (; leftcontainerIt != leftcontainer.end(); ++leftcontainerIt)
        MContainer.push_back(*leftcontainerIt);

    for (; rightcontainerIt != rightcontainer.end(); ++rightcontainerIt)
        MContainer.push_back(*rightcontainerIt);
}

template <typename T>

void  merge_insert(T &MContainer) {
	T leftcontainer, rightcontainer;
	typename T::iterator leftcontainerIt = leftcontainer.begin();
    typename T::iterator rightcontainerIt = rightcontainer.begin();
    if (MContainer.size() <= 1) {
        throw std::runtime_error("Error");
    }
    else if (MContainer.size() <= 16)
        insertSort(MContainer);
	else
	{
		int middle = MContainer.size() / 2;
		leftcontainer.clear();
		rightcontainer.clear();

		typename T::iterator leftcontainerIt = MContainer.begin();
		for (int i = 0; i < middle; ++i, ++leftcontainerIt) {
			leftcontainer.push_back(*leftcontainerIt);
		}
		for (; leftcontainerIt != MContainer.end(); ++leftcontainerIt) {
			rightcontainer.push_back(*leftcontainerIt);
		}
		merge_insert(leftcontainer);
		merge_insert(rightcontainer);
		MContainer.clear();
		merge(MContainer, leftcontainer, rightcontainer);
	}
}

class PmergeMe{
    std::list<int> listSorted;
    std::vector<int> vectorSorted;
	int size;
public:
clock_t start_time;
/*-----------------------------------------------------------------------------*/
/*				     Orthodox Canonical Form :    							   */
/*-----------------------------------------------------------------------------*/

	PmergeMe(); // ---> default constructor
	PmergeMe(const PmergeMe &PmergeMe); // ---> copy constructor 
	PmergeMe &operator=(const PmergeMe &PmergeMe); //--> Copy assignment operator 
	~PmergeMe();// destructor

/*-------------------------------------------------------------------------------*/
	void mergeInsert(char **container);
	void setSize(int ac);
	void isDigit(char **values);
};

