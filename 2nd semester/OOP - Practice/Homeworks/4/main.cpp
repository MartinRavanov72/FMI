#include <iostream> 
#include <string>
#include "Shop.h"
#include "User.h"
#include "Menu.h"
#include "Cart.h"
#include "Sale.h"
#include "Product.h"
#include "Phone.h"
#include "PC.h"
#include "Laptop.h"

using namespace std;


int main(){
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);*/
	Shop shop;
	shop.setName("IT Shop");

	Menu menu("We are a new company, created for YOU", "Our email: it_shop@gmail.com", "Ivaka, Stefan, Qsen");

	User pecata(1, 12313, "popskaPesen", "Pecata", "I'm Pesho, but you can call me Pecata.");
	User stoyan(2, 9738.91, "tainaMaina", "Stoyan", "Hey, I am Stoyan :)");
	User stefan(3, 12.3, "tainoObichamAzis123,", "Stefan", "Hello, I sell all kinds of CDs!");

	shop.setMenu(&menu);
	shop.addUser(&pecata);
	shop.addUser(&stoyan);
	shop.addUser(&stefan);

	Product cd(4, 5, "Azis CD", "Mujete sushto plachat", "This album of Azis from 1999 is my favourite album ever made!");
	Phone iphone(6, 1000, "iPhone 10", "brand new iPhone 10", "More info here...", "Apple", 13, true);
	Phone xiaomi(7, 600, "Xiaomi mi a9", "brand new Xiaomi mi a9", "More info here", "Xiaomi", 10, true);
	PC alienware(8, 3500, "Alienware 7130i", "brand new Alienware 7130i", "More info here...", "Alienware", 2020, false);
	PC asus(9, 1700, "Asus a900p", "brand new Asus a900p", "More info here...", "Asus", 2017, true);
	Laptop laptop(10, 739.99, "HP", "used HP Contra 60", "More info here...", "HP", 2014, 2.1);


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
	alienware.printFullInfo();

	alienware.setPrice(3311.33);
	cout << "Now: " << endl;
	alienware.printFullInfo();

	iphone.printShortInfo();
	iphone.printFullInfo();
	stoyan.addLike(&iphone);
	iphone.setPrice(1699.99);
	iphone.printShortInfo();
	iphone.printFullInfo();

	cout << endl << "Let the shopping start..." << endl;
	
	stoyan.addProductToCart(&iphone, pecata);

	pecata.addProductForSale(&iphone);
	pecata.addProductForSale(&xiaomi);
	stefan.addProductForSale(&cd);
	stefan.addProductForSale(&laptop);
	pecata.addProductForSale(&alienware);

	stoyan.addProductToCart(&iphone, pecata);
	stoyan.addProductToCart(&alienware, pecata);
	stoyan.addProductToCart(&cd, stefan);
	stoyan.addProductToCart(&laptop, stefan);

	stoyan.buyProductsFromCart(pecata);
	stoyan.buyProductsFromCart(stefan);

	cout << "Now " << stoyan.getName() << " has " << stoyan.getMoney() << "$, " << pecata.getName() << " has " << pecata.getMoney() << "$ and " << stefan.getName() << " has " << stefan.getMoney() << "$." << endl << endl;

	int length = stoyan.getProductsBought().size();
	cout << stoyan.getName() << " has bought all these items: " << endl;
	if(length == 0){
		cout << "No items." << endl;
	} else{
		for(int i = 0; i < length; i++){
			stoyan.getProductsBought()[i]->printShortInfo();
		}
	}

	cout << endl;

	cout << pecata.getName() << " has all these items for sale: " << endl;
	length = pecata.getProductsForSale().size();
	if(length == 0){
		cout << "No items." << endl;
	} else{
		for(int i = 0; i < length; i++){
			pecata.getProductsForSale()[i]->printShortInfo();
		}
	}

	cout << endl;

	cout << stoyan.getName() << " has all these items in his cart: " << endl;
	length = stoyan.getCart().getProducts().size();
	if(length == 0){
		cout << "No items." << endl;
	} else{
		for(int i = 0; i < length; i++){
			stoyan.getCart().getProducts()[i]->printShortInfo();
		}
	}

	system("pause");
	return 0;
}
