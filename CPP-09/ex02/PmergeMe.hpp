/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:49:12 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/03/03 12:53:19 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <stdexcept>
# include <limits>
# include <cstdlib>
# include <algorithm>
# include <ctime>

class PmergeMe{
	private:
		//Constructors
		PmergeMe();
		PmergeMe(const PmergeMe &other);

		//Operator overloads
		PmergeMe &operator=(const PmergeMe &other);

		std::list<int> _mergeList;
		std::deque<int> _mergeDeque;
		double _listTime;
		double _dequeTime;
	
	public:
		//Exception classes
		class DuplicatesException : public std::exception{
			const char *what() const throw();
		};

		class NegativeInputException : public std::exception{
			const char *what() const throw();
		};

		class NonDigitInputException : public std::exception{
			const char *what() const throw();
		};

		class OutOfBoundsIntException : public std::exception{
			const char *what() const throw();
		};

		class BadSortException : public std::exception{
			const char *what() const throw();
		};
		
		//Constructor and destructor
		PmergeMe(int argc, char **argv);
		~PmergeMe();

		//Data builders
		void buildList(int argc, char **argv);
		void buildDeque(int argc, char **argv);

		//Class methods
		void parseInput(int argc, char **argv);
		void mergeInsertSortList(std::list<int> &data);
		void mergeInsertSortDeque(std::deque<int> &data);

		void sortList(std::list<int> &data);
		void sortDeque(std::deque<int> &data);
		void mergeList(std::list<int> &left, std::list<int> &right, std::list<int> &merged);
		void mergeDeque(std::deque<int> &left, std::deque<int> &right, std::deque<int> &merged);

		void insertList(std::list<int> &main, std::list<int> &secondary);
		void insertDeque(std::deque<int> &main, std::deque<int> &secondary);
		
		void printResults(int argc, char **argv) const;
};

#endif