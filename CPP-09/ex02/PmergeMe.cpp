/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:57:58 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/03/05 09:30:22 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//Constructor and destructor
PmergeMe::PmergeMe(int argc, char **argv){
	
	
	parseInput(argc, argv);


	clock_t listStart = clock();
	buildList(argc, argv);
	mergeInsertSortList(this->_mergeList);
	clock_t listEnd = clock();
	double listTime = (double)(listEnd - listStart) / CLOCKS_PER_SEC * 1000000;

	clock_t dequeStart = clock();
	buildDeque(argc, argv);
	mergeInsertSortDeque(this->_mergeDeque);
	clock_t dequeEnd = clock();
	double dequeTime = (double)(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000000;

	this->_listTime = listTime;
	this->_dequeTime = dequeTime;

	printResults(argc, argv);
}

PmergeMe::~PmergeMe(){}

//Data builders
void PmergeMe::buildList(int argc, char **argv){
	for (int i = 1; i < argc; i++){
		this->_mergeList.push_back(std::atoi(argv[i]));
	}
}

void PmergeMe::buildDeque(int argc, char **argv){
	for (int i = 1; i < argc; i++){
		this->_mergeDeque.push_back(std::atoi(argv[i]));
	}
}

//Class Methods
void PmergeMe::parseInput(int argc, char **argv){
	std::list<int> checked;

	for (int i = 1; i < argc; i++){
		std::string tmp = std::string(argv[i]);
		for (size_t j = 0; j < tmp.length(); j++){
			if (argv[i][j] == '-')
				throw (NegativeInputException());
			if (!std::isdigit(argv[i][j])){
				throw (NonDigitInputException());
			}
		}
		long conv = std::atol(tmp.c_str());
		if (conv > std::numeric_limits<int>::max() || conv < std::numeric_limits<int>::min())
			throw (OutOfBoundsIntException());
		if (std::find(checked.begin(), checked.end(), conv) != checked.end()) {
            throw DuplicatesException();
        }

        checked.push_back(conv);
	}
}

void PmergeMe::mergeInsertSortList(std::list<int> &data){
	std::list<int> mainList;
	std::list<int> secondaryList;

	//1. Build Main and Secondary list
	for (std::list<int>::iterator it = data.begin(); it != data.end(); ++it){
		std::list<int>::iterator next_it = it;
		++next_it;

		if (next_it != data.end()){
			if (*it < *next_it){
				mainList.push_back(*it);
				secondaryList.push_back(*next_it);
			}
			else{
				mainList.push_back(*next_it);
				secondaryList.push_back(*it);
			}
			std::advance(it, 1);
		}
		else{
			secondaryList.push_back(*it);
		}
	}

	sortList(mainList);
	insertList(mainList, secondaryList);
	this->_mergeList = mainList;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &data){
	std::deque<int> mainDeque;
	std::deque<int> secondaryDeque;

	for (std::deque<int>::iterator it = data.begin(); it != data.end(); ++it){
		std::deque<int>::iterator next_it = it;
		++next_it;

		if (next_it != data.end()){
			if (*it < *next_it){
				mainDeque.push_back(*it);
				secondaryDeque.push_back(*next_it);
			}
			else{
				mainDeque.push_back(*next_it);
				secondaryDeque.push_back(*it);
			}
			std::advance(it, 1);
		}
		else{
			secondaryDeque.push_back(*it);
		}
	}

	sortDeque(mainDeque);
	insertDeque(mainDeque, secondaryDeque);
	this->_mergeDeque = mainDeque;
}

void PmergeMe::sortList(std::list<int> &data){
	if (data.size() <= 1)
		return ;
	
	std::list<int> left;
	std::list<int> right;

	std::list<int>::iterator it = data.begin();
	for (size_t i = 0; i < data.size() / 2; i++)
		it++;
	for (std::list<int>::iterator ite = data.begin(); ite != it; ite++)
		left.push_back(*ite);
	for (std::list<int>::iterator ite = it; ite != data.end(); ite++)
		right.push_back(*ite);

	data.clear();

	sortList(left);
	sortList(right);

	mergeList(left, right, data);
}

void PmergeMe::mergeList(std::list<int> &left, std::list<int> &right, std::list<int> &merged){
	while (!left.empty() && !right.empty()){
		if (left.front() < right.front())
		{
			merged.push_back(left.front());
			left.pop_front();
		} else {
			merged.push_back(right.front());
			right.pop_front();
		}
	}

	while(!left.empty()){
		merged.push_back(left.front());
		left.pop_front();
	}

	while(!right.empty()){
		merged.push_back(right.front());
		right.pop_front();
	}
}

void PmergeMe::sortDeque(std::deque<int> &data){
	if (data.size() <= 1)
		return ;

	std::deque<int> left;
	std::deque<int> right;

	std::deque<int>::iterator it = data.begin();
	for (size_t i = 0; i < data.size() / 2; i++)
		it++;
	for (std::deque<int>::iterator ite = data.begin(); ite != it; ite++)
		left.push_back(*ite);
	for (std::deque<int>::iterator ite = it; ite != data.end(); ite++)
		right.push_back(*ite);

	data.clear();

	sortDeque(left);
	sortDeque(right);

	mergeDeque(left, right, data);
}

void PmergeMe::mergeDeque(std::deque<int> &left, std::deque<int> &right, std::deque<int> &merged){
	while (!left.empty() && !right.empty()){
		if (left.front() < right.front())
		{
			merged.push_back(left.front());
			left.pop_front();
		} else {
			merged.push_back(right.front());
			right.pop_front();
		}
	}

	while(!left.empty()){
		merged.push_back(left.front());
		left.pop_front();
	}

	while(!right.empty()){
		merged.push_back(right.front());
		right.pop_front();
	}
}

void PmergeMe::insertList(std::list<int> &mainList, std::list<int> &secondary){
	for (std::list<int>::iterator it = secondary.begin(); it != secondary.end(); it++){
		bool inserted = false;
		for (std::list<int>::iterator ite = mainList.begin(); ite != mainList.end(); ite++){
			if (*it < *ite){
				mainList.insert(ite, *it);
				inserted = true;
				break ;
			}
		}
		if (!inserted)
			mainList.push_back(*it);
	}
}

void PmergeMe::insertDeque(std::deque<int> &maindeque, std::deque<int> &secondary){
	for (std::deque<int>::iterator it = secondary.begin(); it != secondary.end(); it++){
		bool inserted = false;
		for (std::deque<int>::iterator ite = maindeque.begin(); ite != maindeque.end(); ite++){
			if (*it < *ite){
				maindeque.insert(ite, *it);
				inserted = true;
				break ;
			}
		}
		if (!inserted)
			maindeque.push_back(*it);
	}
}

void PmergeMe::printResults(int argc, char **argv) const{
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++){
			std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	if (this->_mergeList.size() != this->_mergeDeque.size())
		throw(BadSortException());
	
	std::list<int>::const_iterator listIt = this->_mergeList.begin();
	std::deque<int>::const_iterator dequeIt = this->_mergeDeque.begin();

	while (listIt != this->_mergeList.end() && dequeIt != this->_mergeDeque.end()){
		if (*listIt != *dequeIt)
			throw(BadSortException());
		++listIt;
		++dequeIt;
	}

	std::cout << "After: ";
	for (std::list<int>::const_iterator it = this->_mergeList.begin(); it != this->_mergeList.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::list: " << this->_listTime << " us" << std::endl;
	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::deque: " << this->_dequeTime << " us" << std::endl;
}

//Exception messages
const char *PmergeMe::DuplicatesException::what() const throw(){
	return ("Duplicate numbers detected in input");
}

const char *PmergeMe::NegativeInputException::what() const throw(){
	return ("Negative numbers detected in input");
}

const char *PmergeMe::NonDigitInputException::what() const throw(){
	return ("Non digit character detected in input");
}

const char *PmergeMe::OutOfBoundsIntException::what() const throw(){
	return ("int underflow/overflow detected in input");
}

const char *PmergeMe::BadSortException::what() const throw(){
	return ("Sorting error");
}
