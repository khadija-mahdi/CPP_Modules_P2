
#include "PmergeMe.hpp"
/*-----------------------------------------------------------------------------*/
/*				        Orthodox Canonical Form :    						   */
/*-----------------------------------------------------------------------------*/

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &PmergeMe){
	*this = PmergeMe;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &PmergeMe){
	if (this != &PmergeMe)
	{
		this->listSorted = std::list<int>(listSorted.begin(), listSorted.end());
		this->vectorSorted = std::vector<int>(vectorSorted.begin(), vectorSorted.end());
		this->size = PmergeMe.size;
	}
	return *this;
}

PmergeMe::~PmergeMe(){
}
/*------------------------------------------------------------------------------------*/
void PmergeMe::setSize(int ac){
		size = ac;
}

void PmergeMe::isDigit(char **values){

	for (int i = 1; values && values[i] ; i++){
		for (int j = 0; values[i][j]; j++)
		{
			if (!std::isdigit(values[i][j]))
				throw std::runtime_error("Error");
		}
		vectorSorted.push_back(std::atoi(values[i]));
		listSorted.push_back(std::atoi(values[i]));		
	}
}
/*------------------------------------list functions ---------------------------------*/

void PmergeMe::mergeInsert(char **values)
{	
	try
	{
		clock_t start = clock();
		isDigit(values);
		std::cout << "Before:  ";
		for (std::list<int>::iterator it = listSorted.begin(); it != listSorted.end(); ++it) 
        	std::cout << *it << " ";
		merge_insert(vectorSorted);
		clock_t vectorend = clock();
		merge_insert(listSorted);
		clock_t listend = clock();
		double list_time = static_cast<double>(listend - start)  / 10000;
		double vector_time = static_cast<double>(vectorend - start) / 10000;
		std::cout << "\nAfter:   ";
		for (std::list<int>::iterator it = listSorted.begin(); it != listSorted.end(); ++it)
        	std::cout << *it << " ";
		std::cout << "\nTime to process a range of   " << size <<" elements with std::list  " << list_time - vector_time<< " us" << std::endl;
		std::cout << "Time to process a range of   " << size <<" elements with std::vector  " << vector_time<< " us" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}