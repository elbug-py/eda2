#include "adts/node.hpp"
#include "adts/stack.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>

using namespace eda;

bool validateParenthesis(const std::string &input, int* pos){
	std::ofstream log;
	log.open("output.log");
	bool error = false;
	int i = 0;
	int linea = 1;
	int posicion=0;
	Stack stack;
	while (!error && i < input.length()){
		if (input[i] == '\n')
		{
			linea++;
			posicion = 0;
		}
		
		if (input[i] == '<') {
			std::string tag = "<";
			while (input[i] != '>' && i < input.length())
			{	
				i++;
				posicion++;
				
				tag += input[i];
				
				
			}
			;
			if (tag[1] == '/')
				{	
					std::string tag_og = tag;
					tag.erase(1,1); //borra el / del tag
					if (!stack.isEmpty() && tag.compare(stack.top()->getData())== 0 )
					{
						stack.pop();
						log<<"tag "<<tag<<" ok"<<std::endl;
					}
					else{

						log<<"error en la linea "<<linea<<" posicion "<<posicion<<" el tag de cierre "<<tag_og<<" no corresponde al último tag abierto"<<std::endl;
						return error;
					}
					
				}
			else{	
					
					stack.push(new Node(tag));
				}
			
		}
		i = i + 1;
	}
	if (!stack.isEmpty()){
		
		error = true;
	}
	else{
		log<<"0 errores, archivo válido";
	}
	*pos = i;
	log.close();
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
		
	}
	else{
		std::cout<<"Por favor ingresar un archivo html"<<std::endl;
	}
	return 0;
}
