#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

struct Item
{
public:
	Item();
	Item(std::string& mName, std::string& mDesc, std::string& mMaterial, int mWeight, int mValue);

	std::string mName;
	std::string mDesc;
	std::string mMaterial;
	int mWeight;
	int mValue;
};

#endif //ITEM_H