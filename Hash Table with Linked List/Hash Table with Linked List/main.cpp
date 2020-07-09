#include <iostream>
#include <string>
#include "HashTable.h"

int main()
{
	HashTable table;
	/*int key = hashTable.HashingAlgo("Tom");

	std::cout << "Index in hash table: " << key << std::endl;*/
	
	table.AddItem("Tom", "Hudson", 22, 178, "Programmer", false);
	table.AddItem("Will", "Hain", 25, 182, "Programmer", false);
	table.AddItem("Brandon", "Yaw", 20, 187, "Business Analyst", false);
	table.AddItem("Lois", "Turnbull", 23, 168, "Archaeologist", true);
	table.AddItem("Stephen", "Johnson", 29, 180, "Programmer", false);
	table.AddItem("Cath", "Tryfona", 33, 167, "Head of Comp. Science", true);
	table.AddItem("Paul", "Angel", 38, 183, "Head of Comp. Science", false);
	table.AddItem("Ariana", "Grande", 27, 155, "Professional Singer", true);
	table.AddItem("Nathan", "Drake", 30, 188, "Professional Thrill Seeker", false);
	table.AddItem("Elena", "Fisher", 29, 168, "Journalist", true);
	table.AddItem("Victor", "Sullivan", 50, 185, "Pilot", false);


	table.PrintHashTable();
	table.PrintItemsInABucket(1);
	return 0;
}