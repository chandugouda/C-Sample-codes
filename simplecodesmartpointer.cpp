#include <iostream>
#include <memory>
using namespace std;

enum class PaymentType {
    CreditCard,
    UPI,
    NetBanking
};

class Payment {
public:
    virtual void pay(int amount) = 0;
    virtual ~Payment() = default;
};

class CreditCardPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "Credit Card payment: " << amount << endl;
    }
};

class UPIPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "UPI payment: " << amount << endl;
    }
};

class NetBankingPayment : public Payment {
public:
    void pay(int amount) override {
        cout << "NetBanking payment: " << amount << endl;
    }
};

class PaymentFactory {
public:
    unique_ptr<Payment> create(PaymentType type) {
        if (type == PaymentType::CreditCard)
            return make_unique<CreditCardPayment>();
        else if (type == PaymentType::UPI)
            return make_unique<UPIPayment>();
        else if (type == PaymentType::NetBanking)
            return make_unique<NetBankingPayment>();

        return nullptr;
    }
};

int main() {
    PaymentFactory factory;

    auto credit = factory.create(PaymentType::CreditCard);
    auto upi    = factory.create(PaymentType::UPI);
    auto net    = factory.create(PaymentType::NetBanking);

    credit->pay(100);
    upi->pay(200);
    net->pay(300);
}
