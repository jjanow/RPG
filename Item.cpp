#include "Item.h"
#include <string>

Item::Item()
{
	std::string mName = "Item";
	std::string mDesc = "Description";
	std::string mMaterial = "Material";
	int mWeight = 0;
	int mValue = 0;
}

Item::Item(std::string& name, std::string& desc, std::string& material, int weight, int value)
{
	std::string mName = name;
	std::string mDesc = desc;
	std::string mMaterial = material;
	int mWeight = weight;
	int mValue = value;
}