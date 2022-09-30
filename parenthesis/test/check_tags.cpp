#include "adts/node.hpp"
#include "adts/stack.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>

using namespace eda;

bool validateParenthesis(const std::string &input, int* pos){
	bool error = false;
	int i = 0;
	Stack stack;
	while (!error && i < input.length()){
		if (input[i] == '<') {
			std::string tag = "<";
			while (input[i] != '>' && i < input.length())
			{	
				i++;
				
				
				tag += input[i];
				
			}
			;
			if (tag[1] == '/')
				{
					tag.erase(1,1); //borra el / del tag
					if (!stack.isEmpty() && tag.compare(stack.top()->getData())== 0 )
					{
						stack.pop();
					}
					else{
						*pos = i;
						return error;
					}
					
				}
			else{
					stack.push(new Node(tag));
				}
			std::cout<<tag<<std::endl;
		}
		i = i + 1;
	}
	if (!stack.isEmpty()){
		error = true;
	}
	*pos = i;
	return !error;
}


int main(int nargs, char** vargs){
	
	if (vargs[1])
	{
		auto stream = std::ostringstream{};
		std::ifstream html(vargs[1]);
		stream << html.rdbuf();
		std::string input = stream.str();
		int pos=0;
		bool status = validateParenthesis(input, &pos);
		if (status){
			std::cout<< " Expresión Correcta " << std::endl;
		}
		else{
			std::cout<< " Expresión Inválida" << std::endl;
			std::cout<< "Pos error:  " << pos - 1	<< std::endl;
		}
	}
	else{
		std::cout<<"Por favor ingresar un archivo html"<<std::endl;
	}
	return 0;
}
