/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <kethouve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:12:24 by kethouve          #+#    #+#             */
/*   Updated: 2024/12/05 13:27:35 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*Constructor*/
PmergeMe::PmergeMe(): _vtime(0.0), _dtime(0.0), _len(0) {}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	*this = cpy;
}

/*Overload operator*/
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_v = src._v;
		_d = src._d;
		_vtime = src._vtime;
		_dtime = src._dtime;
		_len = src._len;
	}
	return (*this);
}

/*Destructor*/
PmergeMe::~PmergeMe(){}

/*Public methods*/
void PmergeMe::fillContainer(int ac, char **av)
{
	_len = ac - 1;
	if (_len > 3000)
		throw TooMuchNumberException();
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (!isdigit(av[i][j]))
				throw BadArgumentException();
		}
		if (std::atoll(av[i]) > std::numeric_limits<int>::max())
			throw BadArgumentException();
		_v.push_back(std::atoi(av[i]));
		_d.push_back(std::atoi(av[i]));
	}
}

void PmergeMe::doubleNumber()
{
	for (std::vector<int>::iterator itv = _v.begin(); itv != _v.end(); itv++)
	{
		for (std::vector<int>::iterator itv2 = itv + 1; itv2 != _v.end(); itv2++)
		{
		if (*itv == *itv2)
			throw DoubleNumberException();
		}
	}
}

bool PmergeMe::isSorted()
{
	std::vector<int>::iterator itv = _v.begin();
	int last = *itv;
	for (itv = ++itv; itv != _v.end(); itv++)
	{
		if (*itv < last)
			return false;
		last = *itv;
	}
	std::deque<int>::iterator itd = _d.begin();
	last = *itd;
	for (itd = ++itd; itd != _d.end(); itd++)
	{
		if (*itd < last)
			return false;
		last = *itd;
	}
	return true;
}

void PmergeMe::printPmergeMe()
{
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printTime()
{
	std::cout << "Time to process a range of " << _len << " elements with std::vector: " << _vtime << "us" << std::endl;
	std::cout << "Time to process a range " << _len << " elements with std::deque: " << _dtime << "us" << std::endl;
}

void PmergeMe::sort_vector()
{
	std::clock_t start_vector = std::clock();
	std::vector<int> small, large;
	for(std::vector<int>::iterator it = _v.begin(); it < _v.end(); it += 2)
	{
		if (it + 1 < _v.end())
		{
			if (*it > *(it + 1))
			{
				std::swap(*it, *(it + 1));
			}
			small.push_back(*it);
			large.push_back(*(it + 1));
		}
		else
			large.push_back(*it);
	}
	std::sort(large.begin(), large.end());
	for(std::vector<int>::iterator it = small.begin(); it != small.end(); ++it)
	{
		std::vector<int>::iterator pos = std::lower_bound(large.begin(), large.end(), *it);
		large.insert(pos, *it);
	}
	_v = large;
	std::clock_t end_vector = std::clock();
	_vtime = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1e6;
    /*std::cout << "_v: ";
    for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;*/
}

void PmergeMe::sort_deque()
{
	std::clock_t start_deque = std::clock();
	std::deque<int> small, large;
	for(std::deque<int>::iterator it = _d.begin(); it < _d.end(); it += 2)
	{
		if (it + 1 < _d.end())
		{
			if (*it > *(it + 1))
			{
				std::swap(*it, *(it + 1));
			}
			small.push_back(*it);
			large.push_back(*(it + 1));
		}
		else
			large.push_back(*it);
	}
	std::sort(large.begin(), large.end());
	for(std::deque<int>::iterator it = small.begin(); it != small.end(); ++it)
	{
		std::deque<int>::iterator pos = std::lower_bound(large.begin(), large.end(), *it);
		large.insert(pos, *it);
	}
	_d = large;
	std::clock_t end_deque = std::clock();
	_dtime = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1e6;
    /*std::cout << "_d: ";
    for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;*/
}

/*Exception*/
const char *PmergeMe::BadArgumentException::what() const throw()
{
	return ("Invalid agument!");
}

const char *PmergeMe::DoubleNumberException::what() const throw()
{
	return ("Double number detected!");
}

const char *PmergeMe::TooMuchNumberException::what() const throw()
{
	return ("Too much number. Please enter less than 3000 number!");
}
