#include "GameObject.h"
#include <string>
#include <vector>
#include <iostream>

#include "Utils.h"
#include "MeleeWeapon.h"
#include "Credit.h"
#include "Health.h"
#include "Attack.h"
#include "Move.h"

using namespace std;

GameObject::GameObject() : name("gameobject"), tag(Tag::Other){}

GameObject::GameObject(string _name, Tag _tag) : name(_name), tag(_tag){}

void GameObject::AddComponent(Component* c) {
    components.push_back(c);
    c->SetParentGO(this);
}

Vector2 GameObject::GetPosition() { return position; }

void GameObject::SetPosition(Vector2 pos) { position = pos; }

GameObject* GameObject::MoneyBag() {
    GameObject* moneyBag = new GameObject("Money bag", Tag::Money);
    moneyBag->AddComponent(new Credit(Utils::RandomRange(10, 80)));

    return moneyBag;
}