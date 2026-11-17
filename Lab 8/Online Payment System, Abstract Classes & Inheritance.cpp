#include <iostream>

using namespace std;


class Payment{
	
public:

	virtual void calculateFee(double amount) = 0;
		
};

class BankTransfer : public Payment{
	
public:
	
	void calculateFee(double amount){
		cout << "Bank Transfer Fee: " << (amount * 0.02) << "\n";
	}
	
};

class DigitalWallet : public Payment{
	
public:
	
	void calculateFee(double amount){
		cout << "Digital Wallet Fee: " << (amount * 0.01) << "\n";
	}
	
};

int main(){
	
	BankTransfer b;
	b.calculateFee(10000);
	
	DigitalWallet d;
	d.calculateFee(10000);
	
	
	return 0;
}