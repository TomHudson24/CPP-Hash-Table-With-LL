#pragma once
#include <string>
#include <iostream>
class HashTable
{
private:

	struct Person{
		std::string forename;
		std::string surname;
		int age;
		int height; //in cm
		std::string profession;
		bool sex; //true for female and false for male
		Person* nextPerson;
	};

	//static const int hashValue = 25 / 13;
	static const int hashTableSize = 10;
	Person* hashTable[hashTableSize];
public:
	HashTable();
	int HashingAlgo(std::string key);
	void AddItem(std::string forename, std::string surname, int age, int height, std::string profession, bool sex);
	int AmountOfItemsInABucket(long int index);
	void PrintHashTable();
	void PrintItemsInABucket(long int index);
};

