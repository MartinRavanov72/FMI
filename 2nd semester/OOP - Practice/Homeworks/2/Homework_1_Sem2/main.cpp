#include <iostream> 
#include "User.h"
#include "Menu.h"
#include "Cart.h"
#include "Sale.h"
#include "Product.h"

using namespace std;


int main(){
	Menu menu("We are a new company, created for YOU", "Our email: firmata_nai_dobra@gmail.com", "Ivaka, Stefan, Qsen");

	User pecata(1, 12313, "popskaPesen", "Pecata", "I'm Pesho, but you can call me Pecata.");
	User stoyan(2, 4444, "tainaMaina", "Stoyan", "Hey, I am Stoyan :)");
	User stefan(3, 12.3, "tainoObichamAzis123,", "Stefan", "Hello, I sell all kinds of CDs!");

	Product meat(1, 11, "Meat", "Ludogorets", "Chicken........");
	Product shoes(2, 100, "Shoes", "Nikes", "Awesome Nike shoe. original from 2018");
	Product chips(3, 3, "Chips", "Chio", "This chips is made from........");
	Product cd1(4, 5, "Azis CD", "Mujete sushto plachat", "This album of Azis from 1999 is my favourite album ever made!");
	Product cd2(5, 10, "Lili Ivanova CD", "Vechnost", "Minavaaaa, golemiq korab minaaaava...");

	cout << "Here is some info about us: " << endl;
	cout << menu.getAboutUs() << endl << endl;

	menu.setAboutUs("We have 3 years of experience! :)");
	cout << "Here is some new info about us: " << endl;
	cout << menu.getAboutUs() << endl << endl;

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

	int length = stoyan.getProductsBoughtNumber();
	cout << stoyan.getName() << " has bought all these items: " << endl;
	for(int i = 0; i < length; i++){
		cout << stoyan.getProductsBought()[i].getName() << endl;
	}

	cout << endl;

	cout << pecata.getName() << " has all these items for sale: " << endl;
	length = pecata.getProductsForSaleNumber();
	if(length == 0){
		cout << "No items." << endl;
	} else{
		for(int i = 0; i < length; i++){
			cout << pecata.getProductsForSale()[i].getName() << endl;
		}
	}

	cout << endl;

	cout << stoyan.getName() << " has all these items in his cart: " << endl;
	length = stoyan.getCart().getProductsNumber();
	if(length == 0){
		cout << "No items." << endl;
	} else{
		for(int i = 0; i < length; i++){
			cout << stoyan.getCart().getProducts()[i].getName() << endl;
		}
	}

	system("pause");
	return 0;
}
