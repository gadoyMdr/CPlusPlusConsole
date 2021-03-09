#include "Item.h"
#include <string>

using namespace std;

Item::Item() : itemName("itemName"), weight(0){}
Item::Item(string itemName) : itemName(itemName), weight(0){}
Item::Item(string itemName, float itemWeight) : itemName(itemName), weight(itemWeight){}
Item::~Item(){}

string Item::GetItemName() { return itemName; }
void Item::SetItemName(string _itemName) { itemName = _itemName; }

float Item::GetItemWeight() { return weight; }
void Item::SetItemWeight(float _weight) { weight = _weight; }
