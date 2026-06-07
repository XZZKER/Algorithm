#include <bits/stdc++.h>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	
	system("g++ -std=c++2a data.cpp -o data.exe");
	system("g++ -std=c++2a baoli.cpp -o baoli.exe");
	system("g++ -std=c++2a std.cpp -o std.exe");
	
	while (true) {
		system("data.exe > data.txt");
		system("baoli.exe < data.txt > baoli.txt");
		system("std.exe < data.txt > std.txt");
		
		if (system("fc std.txt baoli.txt")) {
			std::cout << "WA\n";
			system("type data.txt");
			system("type std.txt");
			system("type baoli.txt");
			break;
		}
		else
			std::cout << "AC\n";
	}
	
	return 0;
}