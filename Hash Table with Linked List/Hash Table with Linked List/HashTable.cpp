#include "HashTable.h"

HashTable::HashTable()
{
	for(int i = 0; i < hashTableSize; i++)
	{
		hashTable[i] = new Person;
		hashTable[i]->forename = "empty";
		hashTable[i]->surname = "";
		hashTable[i]->age = 0;
		hashTable[i]->height = 0;
		hashTable[i]->profession = "empty";
		hashTable[i]->sex = true;
		hashTable[i]->nextPerson = nullptr;	
	}
}

int HashTable::HashingAlgo(std::string key)
{
	long int hash = 0;
	long int index = 0;
	long int a = 0; //random int
	long int b = 1; //random int
	long int p = 23581; //large prime number
	for(long int i = 0; i < key.size(); i++)
	{
		a = rand() % p;
		b = rand() % p;
		hash += (int)key[i]; //each iteration add up the ascii value of the strings char
	//	std::cout << "The char " << key[i] << " has an ascii value of " << hash << std::endl;
	}
	
	//index += (hash % hashTableSize) * hashValue;//hash algo
	index = ((a * hash + b) % p) % hashTableSize;
	//std::cout << index << " ";
	return index;
}

void HashTable::AddItem(std::string forename, std::string surname, int age, int height, std::string profession, bool sex)
{
	long int bucket = HashingAlgo(forename);

	if(hashTable[bucket]->forename == "empty")
	{
		hashTable[bucket]->forename = forename;
		hashTable[bucket]->surname = surname;
		hashTable[bucket]->age = age;
		hashTable[bucket]->height = height;
		hashTable[bucket]->profession = profession;
		hashTable[bucket]->sex = sex;
	}
	else
	{
		Person* personPtr = hashTable[bucket];
		Person* newPerson = new Person;
		newPerson->forename = forename;
		newPerson->surname = surname;
		newPerson->age = age;
		newPerson->height = height;
		newPerson->profession = profession;
		newPerson->sex = sex;
		newPerson->nextPerson = nullptr;

		while(personPtr->nextPerson != nullptr)
		{
			personPtr = personPtr->nextPerson;
		}
		personPtr->nextPerson = newPerson;
	}
}
int HashTable::AmountOfItemsInABucket(long int index)
{
	long int count = 0;
	if(hashTable[index]->forename == "empty")
	{
		return count;
		//no item present
	}
	else
	{
		count++;
		Person* personPtr = hashTable[index];
		while(personPtr->nextPerson != nullptr)
		{
			//move pointer down the list
			count++;
			personPtr = personPtr->nextPerson;
		}
	}
	return count;
}

void HashTable::PrintHashTable()
{
	long int numElements;

	for(long int i=0; i < hashTableSize; i++)
	{
		numElements = AmountOfItemsInABucket(i);
		std::cout << "-------------------------" << "\tIndex = " << i + 1 << "\t-------------------------" << std::endl;
		if (hashTable[i]->sex == true && hashTable[i]->forename != "empty")
		{
			std::cout << "Ms. " << hashTable[i]->forename << " " << hashTable[i]->surname << std::endl;
		}
		else if (hashTable[i]->sex == false && hashTable[i]->forename != "empty")
		{
			std::cout << "Mr. " << hashTable[i]->forename << " " << hashTable[i]->surname << std::endl;
		}
		else {
			std::cout << hashTable[i]->forename << std::endl;
		}
		std::cout << hashTable[i]->age << " years old" << std::endl;
		if(hashTable[i]->sex == true)
		{
			std::cout << "Female" << std::endl;
		}else if (hashTable[i]->sex == false)
		{
			std::cout << "Male" << std::endl;
		}
		std::cout << hashTable[i]->height << "cm" << std::endl;
		std::cout << hashTable[i]->profession << std::endl;
		std::cout << "How many people are there stored at this element? " << numElements << std::endl;
	}
}

void HashTable::PrintItemsInABucket(long int index)
{
	Person* personPtr = hashTable[index];

	if(personPtr->forename == "empty")
	{
		std::cout << "Bucket " << index + 1 << " is empty\n";
	}
	else
	{
		std::cout << "Bucket " << index + 1 << " contains these items\n";

		while(personPtr != nullptr)
		{
			std::cout << "-------------------------" << std::endl;
			if (personPtr->sex == true && personPtr->forename != "empty")
			{
				std::cout << "Ms. " << personPtr->forename << " " << personPtr->surname << std::endl;
			}
			else if (personPtr->sex == false && personPtr->forename != "empty")
			{
				std::cout << "Mr. " << personPtr->forename << " " << personPtr->surname << std::endl;
			}
			std::cout << personPtr->age << " years old" << std::endl;
			if (personPtr->sex == true)
			{
				std::cout << "Female" << std::endl;
			}
			else if (personPtr->sex == false)
			{
				std::cout << "Male" << std::endl;
			}
			std::cout << personPtr->height << "cm" << std::endl;
			std::cout << personPtr->profession << std::endl;
			personPtr = personPtr->nextPerson;
		}
	}
}