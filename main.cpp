/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:40:24 by shamizi           #+#    #+#             */
/*   Updated: 2023/02/27 16:46:11 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include "iterator_traits.hpp"
#include "stack.hpp"
#include "reverse_iterator.hpp"
//#include "vector.hpp"

int main(void)
{
	// std::cout << "--------------check stack----------------\n";
	// std::vector<int> myvector (2,200);        // vector with 2 elements
	// ft::stack<int> first;                    // empty stack
	// ft::stack<int,std::vector<int> > third;  // empty stack using vector
	// ft::stack<int,std::vector<int> > fourth (myvector);

	// std::cout << "size of first: " << first.size() << '\n';
	// std::cout << "size of third: " << third.size() << '\n';
	// std::cout << "size of fourth: " << fourth.size() << '\n';
	// if (!fourth.empty())
	// 	std::cout << "pas de fourth empty \n";
	// else
	// 	std::cout << "empty return something\n";
	// if (!first.empty())
	// 	std::cout << "pas de first empty \n";
	// else
	// 	std::cout << "empty return something in first\n";
	// std::cout << "fourth.top() = " << fourth.top() << std::endl;
	// fourth.top() -= 2;
	// std::cout << " apres un -= 2 fourth.top() = " << fourth.top() << std::endl;

	// if (first.empty())
	// 	std::cout << "first est vide \n";
	// for (int i = 0; i < 5; i++)
	// 	first.push(i * 10);
	// if (!first.empty())
	// 	std::cout << "first a des element \n";
	// std::cout << "nb of element in first : " << first.size() << std::endl;
	// std::cout << "pop les element jusqua ce que first soit de nouveau vide";
	// while (!first.empty())
	// {
	// 	first.pop();
	// 	std::cout << "un element supprimer\n";
	// }

	std::cout << "---------------------test des reverse_iterator----------------\n";
	std::vector<int> myvec;
	for (int i = 0; i < 10; i++)
		myvec.push_back(i * 10);

	typedef std::vector<int>::iterator iterator_type;
	iterator_type from (myvec.begin());
	iterator_type until(myvec.end());

	ft::reverse_iterator<iterator_type> rev_until (from);
	ft::reverse_iterator<iterator_type> rev_from (until);

	while (rev_from != rev_until)
		std::cout << ' ' << *rev_from++;
	std::cout <<  "\n";
	std::cout << "test de base() :\n";
	ft::reverse_iterator<iterator_type> rev_end(myvec.begin());
	ft::reverse_iterator<iterator_type> rev_begin(myvec.end());

	for(iterator_type it = rev_end.base(); it != rev_begin.base(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';


	std::cout << "test operator* \n";
	iterator_type origin (myvec.begin());
	iterator_type finale(myvec.end());

	ft::reverse_iterator<iterator_type> rev_finale (origin);
	ft::reverse_iterator<iterator_type> rev_origin (finale);
	std::cout << "test de l'operateur [] en plus :" << std::endl; 
	std::cout << "vector qui existe : " << rev_origin[3] << std::endl;
	std::cout << "vector qui existe pas : " << rev_origin[12] << std::endl;
	while (rev_finale != rev_origin)
		std::cout << ' ' << *rev_origin++;
	std::cout << '\n';

	std::cout << "--------------test vector--------------\n";
	ft::vector<int> first;
	first.push_back(100);
	first.push_back(200);
	first.push_back(300);
	first.push_back(400);
	ft::vector<int> second;
	ft::vector<int> third(first.begin(), first.end());
	ft::vector<int> fourth(third);

	std::vector<int> test;
	std::cout << "fonction size 1: " << first.size() << std::endl;
	std::cout << "fonction size 2: " << second.size() << std::endl;
	std::cout << "fonction size 3: " << third.size() << std::endl;
	std::cout << "fonction size 4: " << fourth.size() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "fonction maxsize 1: " << first.max_size() << std::endl;
	std::cout << "fonction maxsize 2: " << second.max_size() << std::endl;
	std::cout << "fonction maxsize 3: " << third.max_size() << std::endl;
	std::cout << "fonction maxsize 4: " << fourth.max_size() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "fonction capacity 1: " << first.capacity() << std::endl;
	std::cout << "fonction capacity 2: " << second.capacity() << std::endl;
	std::cout << "fonction \"\"       3: " << third.capacity() << std::endl;
	std::cout << "fonction \"\"       4: " << fourth.capacity() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "fonction empty 1: " << first.empty() << std::endl;
	std::cout << "fonction \"\"       2: " << second.empty() << std::endl;
	std::cout << "fonction \"\"       3: " << third.empty() << std::endl;
	std::cout << "fonction \"\"       4: " << fourth.empty() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "fonction operator[] 1: " << first[2] << std::endl;
//	std::cout << "levrai: " << test[2] << std::endl;
//	std::cout << "fonction \"\"       2: " << second[2] << std::endl; segfault mais normal le vrai aussi
	std::cout << "fonction \"\"       3: " << third[2] << std::endl;
	std::cout << "fonction \"\"       4: " << fourth[2] << std::endl;
	std::cout << std::endl << std::endl;



	//si je pop back un element vide j'ai une boucle infini au moment du destructeur, apres j'ai la bonen valeur de size comme le vrai // donc a voir si c'est normal ou pas
	first.pop_back();
	//second.pop_back();
	third.pop_back();
	fourth.pop_back();
	//std::cout << "test pop back vide :" << test.size() << std::endl;
	//test.pop_back();
	//std::cout << "test pop back vide :" << test.size() << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "fonction size 1 apres un pop back: " << first.size() << std::endl;
	//std::cout << "fonction size 2: " << second.size() << std::endl;
	std::cout << "fonction size 3: " << third.size() << std::endl;
	std::cout << "fonction size 4: " << fourth.size() << std::endl;
	std::cout << std::endl << std::endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ft::vector<int>::iterator ite;
	ite = first.begin();
	first.insert(ite + 2, 999);
	std::cout << "vector contain after insert at pos +2 :";
	for(ite = first.begin(); ite < first.end(); ite++)
		std::cout << ' ' << *ite;
	std::cout << std::endl;
	ite = first.begin();
	first.insert(first.begin(), 901);
	std::cout << "vector contain after insert at pos begin(901) :";
	for(ite = first.begin(); ite < first.end(); ite++)
		std::cout << ' ' << *ite;
	std::cout << std::endl;
	ite = first.end();
	first.insert(ite , 1001);
	std::cout << "vector contain after insert at pos end(1001) :";
	for(ite = first.begin(); ite < first.end(); ite++)
		std::cout << ' ' << *ite;
	std::cout << std::endl;

	std::cout << std::endl << std::endl;



	return 0;
}

