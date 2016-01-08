/*
Author: nemasu@gmail.com
License: Public Domain

Simple BF interpreter.
No bounds checking.
*/

#include <stdint.h>
#include <iostream>
#include <fstream>

#define ARRAY_SIZE 30000

int main( int argv, char **argc ) {
	
	std::fstream file( argc[1] );
	if( !file.good() ) {
		std::cerr << "File error" << std::endl;
		std::cerr << "Usage: 'bf input-script'" << std::endl;
		return -1;
	}

	char array[ ARRAY_SIZE ] = {0};
	char *p = array;

	char c = 0;
	while( 1 ) {
		if( (c = file.peek()) == std::ios::traits_type::eof() ) {
			break;
		}
		
		switch( c ) {
			case '>':
				++p;
				break;
			case '<':
				--p;
				break;
			case '+':
				(*p)++;
				break;
			case '-':
				(*p)--;
				break;
			case '.':
				std::cout << *p;
				break;
			case ',':
				std::cin >> *p;
				if ( std::cin.eof() ) {
					return 0;
				}
				break;
			case '[':
				if( *p == 0 ) {
					uint64_t skip = 0;
					while(1) {
						file.seekg( 1, std::ios::cur );
						c = file.peek();
						if ( c == '[' ) {
							skip++;
						}
						else if( c == ']' ) {
							if( skip != 0 ) {
								skip--;
							} else {
								break;
							}
						} 
					}

				}
				break;
			case ']':
				if( *p != 0 ) {
					uint64_t skip = 0;
					while(1) {
						file.seekg( -1, std::ios::cur );
						c = file.peek();
						if ( c == ']' ) {
							skip++;
						}
						else if( c == '[' ) {
							if( skip != 0 ) {
								skip--;
							} else {
								break;
							}
						} 
					}
				}
				break;
			default:
				break;
		}
		
		file.seekg( 1, std::ios::cur );
	}
	return 0;
}
