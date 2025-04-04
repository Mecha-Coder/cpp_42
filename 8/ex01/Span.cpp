/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:08:08 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/28 21:15:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

const char *Span::StorageFullException::what() const throw()
{return "Can't add anymore numbers\n";}


const char *Span::FailToComputeException::what() const throw()
{return "Fail to compute span. Not enough numbers\n";}

//=============================================================================
// Constructor & Destructor
//=============================================================================

Span::Span(){}

Span::Span (long int n) : N(static_cast<unsigned int>(n))
{
    if (n < 5) throw std::invalid_argument("The minimum limit need to be atleast 5\n");
}

Span::Span (const Span &obj) : N(obj.N)
{
   arr.insert(obj.arr.begin(), obj.arr.end());
}

//=============================================================================
// Overload function
//=============================================================================

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        this->N = obj.N;
        this->arr.clear();
        this->arr.insert(obj.arr.begin(), obj.arr.end());
    }
    return *this;
}

//=============================================================================
// Other Methods
//=============================================================================

int Span::shortestSpan()
{
    if (arr.size() < 2) throw FailToComputeException();
    
    int num = *arr.rbegin();
    int prev = *arr.begin();
    int newNum;

    for(std::set<int>::iterator i = ++arr.begin() ; i != arr.end(); i++)
    {
        newNum = *i - prev;
        if (num > newNum) 
            num = newNum;
        prev = *i;
    }
    return (num);
}

int Span::longestSpan()
{
    if (arr.size() < 2) throw FailToComputeException();
    
    return (*arr.rbegin() - *arr.begin()); 
}

unsigned int Span::getMaxSize()
{return N;}


void Span::showNumbers()
{
    for (std::set<int>::iterator i = arr.begin(); i != arr.end(); i++)
        std::cout << *i << ", ";
    std::cout << "\n";
}   

void Span::addNumber(int x)
{
    if (arr.size() == N)
        throw StorageFullException();
    arr.insert(x);
}