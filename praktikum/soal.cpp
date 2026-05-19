#include <iostream>
using namespace std;

class RekeningBank
{
protected:
    double balance;
    double AdminFee;

public:
    virtual void potongAdmin() = 0;
    virtual void tampilkanInfo() = 0;
};

class RekeningSyariah : public RekeningBank
{
public:
    RekeningSyariah(double Balance)
    {
        balance = Balance;
        AdminFee = 0;
    }

    void potongAdmin()
    {
        cout << "Tidak ada biaya admin\n";
    }

    void tampilkanInfo()
    {
        cout << "Rekening Syariah\n";
        cout << "Saldo : " << balance << endl;
    }
};

class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(double Balance)
    {
        balance = Balance;
        AdminFee = 15000;
    }

    void potongAdmin()
    {
        balance -= AdminFee;
    }

    void tampilkanInfo()
    {
        cout << "Rekening Konvensional\n";
        cout << "Saldo : " << balance << endl;
    }
};

class PremiumAccount : public RekeningBank
{
public:
    PremiumAccount(double Balance)
    {
        balance = Balance;
    }

    void potongAdmin()
    {
        if (balance <= 10000000)
        {
            balance -= 50000;
            AdminFee = 50000;
        }
        else
        {
            AdminFee = 0;
        }
    }

    void tampilkanInfo()
    {
        cout << "Premium Account\n";
        cout << "Saldo : " << balance << endl;
    }
};

int main()
{
    RekeningBank* rekening[3];

    rekening[0] = new RekeningSyariah(5000000);
    rekening[1] = new RekeningKonvensional(5000000);
    rekening[2] = new PremiumAccount(12000000);

    for (int i = 0; i < 3; i++)
    {
        rekening[i]->potongAdmin();
        rekening[i]->tampilkanInfo();
        cout << endl;
    }

    return 0;
}