#include <iostream> 
#include "Shop.h"
#include "User.h"
#include "Menu.h"
#include "Cart.h"
#include "Sale.h"
#include "Product.h"
#include "Vector.h"
#include "String.h"
#include "Phone.h"
#include "PC.h"
#include "Laptop.h"

using namespace std;


int main(){
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
	Shop shop;
	shop.setName("IT Shop");

	Menu menu("We are a new company, created for YOU", "Our email: firmata_nai_dobra@gmail.com", "Ivaka, Stefan, Qsen");

	User pecata(1, 12313, "popskaPesen", "Pecata", "I'm Pesho, but you can call me Pecata.");
	User stoyan(2, 4444, "tainaMaina", "Stoyan", "Hey, I am Stoyan :)");
	User stefan(3, 12.3, "tainoObichamAzis123,", "Stefan", "Hello, I sell all kinds of CDs!");

	shop.setMenu(&menu);
	shop.addUser(&pecata);
	shop.addUser(&stoyan);
	shop.addUser(&stefan);

	Product meat(1, 11, "Meat", "Ludogorets", "Chicken........");
	Product shoes(2, 100, "Shoes", "Nikes", "Awesome Nike shoe. original from 2018");
	Product chips(3, 3, "Chips", "Chio", "This chips is made from........");
	Product cd1(4, 5, "Azis CD", "Mujete sushto plachat", "This album of Azis from 1999 is my favourite album ever made!");
	Product cd2(5, 10, "Lili Ivanova CD", "Vechnost", "Minavaaaa, golemiq korab minaaaava...");


	cout << "Here is some info about us: " << endl;
	cout << "Our shop is called " << shop.getName() << endl;
	cout << shop.getMenu()->getAboutUs() << endl << endl;

	menu.setAboutUs("We have 3 years of experience! :)");
	cout << "Here is some new info about us: " << endl;
	cout << shop.getMenu()->getAboutUs() << endl << endl;

	cout << "Here is some info about our users: " << endl;
	cout << pecata.getName() << " has " << pecata.getMoney() << "$" << endl;

	pecata.setMoney(1111.3);
	cout << "Now: " << endl;
	cout << pecata.getName() << " has " << pecata.getMoney() << "$" << endl;

	cout << pecata.getName() << " says: " << pecata.getDescription() << endl;
	cout << stoyan.getName() << " says: " << stoyan.getDescription() << endl << endl;

	cout << "Here is some info about our products: " << endl;
	meat.printFullInfo();

	meat.setPrice(12);
	cout << "Now: " << endl;
	meat.printFullInfo();

	chips.printShortInfo();
	chips.printFullInfo();
	stoyan.addLike(chips);
	chips.setPrice(4.1);
	chips.printShortInfo();
	chips.printFullInfo();

	cout << endl << "Let the shopping start..." << endl;
	
	stoyan.addProductToCart(meat, pecata);

	pecata.addProductForSale(meat);
	pecata.addProductForSale(shoes);
	stefan.addProductForSale(cd1);
	pecata.addProductForSale(cd2);

	stoyan.addProductToCart(meat, pecata);
	stoyan.addProductToCart(shoes, pecata);
	stoyan.addProductToCart(cd1, stefan);

	stoyan.buyProductsFromCart(pecata);
	stoyan.buyProductsFromCart(stefan);

	cout << "Now " << stoyan.getName() << " has " << stoyan.getMoney() << "$, " << pecata.getName() << " has " << pecata.getMoney() << "$ and " << stefan.getName() << " has " << stefan.getMoney() << "$." << endl << endl;

	int length = stoyan.getProductsBought().getSize();
	cout << stoyan.getName() << " has bought all these items: " << endl;
	for(int i = 0; i < length; i++){
		cout << stoyan.getProductsBought()[i].getName() << endl;
	}

	cout << endl;

	cout << pecata.getName() << " has all these items for sale: " << endl;
	length = pecata.getProductsForSale().getSize();
	if(length == 0){
		cout << "No items." << endl;
	} else{
		for(int i = 0; i < length; i++){
			cout << pecata.getProductsForSale()[i].getName() << endl;
		}
	}

	cout << endl;

	cout << stoyan.getName() << " has all these items in his cart: " << endl;
	length = stoyan.getCart().getProducts().getSize();
	if(length == 0){
		cout << "No items." << endl;
	} else{
		for(int i = 0; i < length; i++){
			cout << stoyan.getCart().getProducts()[i].getName() << endl;
		}
	}

	cout << endl << "You can see our large variety of products: " << endl;
	Phone phone(100, 1000, "iPhone 10", "brand new iPhone 10", "More info here...", "Apple", 13, true);
	PC pc(101, 3500, "Alienware 7130i", "brand new Alienware 7130i", "More info here...", "Alienware", 2020, false);
	Laptop laptop(102, 739.99, "HP", "used HP Contra 60", "More info here...", "HP", 2014, 2.1);

	phone.printFullInfo();
	cout << endl;
	pc.printFullInfo();
	cout << endl;
	laptop.printFullInfo();
	cout << endl;

	system("pause");
	return 0;
}
