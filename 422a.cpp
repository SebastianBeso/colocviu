#include <iostream>
#include <string>

class Card_calatorie
{
private:
    int id;
    char tip;

public:
    int valid;

public:
    Card_calatorie() {}
    Card_calatorie(int id, char tip) : id(id), tip(tip) {}
    virtual void validare_calatorie(int, int) = 0;
    virtual void incarcare(int) = 0;
    virtual void transfer(Card_calatorie *, int) = 0;
    virtual void afisare()
    {
        std::cout << this->id << " ";
    }
    char get_tip()
    {
        return tip;
    }
    int get_id()
    {
        return id;
    }
};

class Card_autobuz : public Card_calatorie
{
public:
    int sold;

public:
    Card_autobuz() {}

    Card_autobuz(int id, int sold, char t) : sold(sold), Card_calatorie(id, t) {}
    void afisare()
    {
        Card_calatorie::afisare();
        std::cout << Card_calatorie::get_tip() << " " << this->sold << " " << Card_calatorie::valid << "\n";
    }

    void validare_calatorie(int id, int mom)
    {
        if (this->get_id() == id)
        {
            if (this->sold > 3)
            {
                if (mom - Card_calatorie::valid <= 90)
                {
                }
                else
                {

                    Card_calatorie::valid = mom;
                    this->sold = this->sold - 3;
                }
            }
            else
            {
                std::cout << "Sold insuficient\n";
            }
        }
        else
            return;
    }
    void incarcare(int a)
    {
        this->sold = this->sold + a;
    }
    void transfer(Card_calatorie *card, int am)
    {
        Card_autobuz *autobuz = dynamic_cast<Card_autobuz *>(card);

        if (card->get_tip() != Card_calatorie::get_tip())
        {
            std::cout << "Transfer nereusit\n";
            return;
        }
        else
        {
            if (this->sold < am)
            {
                std::cout << "Transfer nereusit\n";
                return;
            }
            else
            {
                this->sold = this->sold - am;
                autobuz->sold = autobuz->sold + am;
            }
        }
    }
};

class Card_metrou : public Card_calatorie
{
public:
    int calatorii;

public:
    Card_metrou() {}
    Card_metrou(int id, int calatorii, char t) : calatorii(calatorii), Card_calatorie(id, t) {}
    void afisare()
    {
        Card_calatorie::afisare();
        std::cout << Card_calatorie::get_tip() << " " << this->calatorii << " " << Card_calatorie::valid << "\n";
    }
    void validare_calatorie(int id, int mom)
    {
        if (this->get_id() == id)
        {
            if (this->calatorii > 0)
            {
                if (mom - Card_calatorie::valid <= 90)
                {
                }
                else
                {

                    Card_calatorie::valid = mom;
                    this->calatorii = this->calatorii - 1;
                }
            }
            else
            {
                std::cout << "Numar calatorii insuficient\n";
            }
        }
    }
    void incarcare(int a)
    {
        this->calatorii = this->calatorii + a;
    }
    void transfer(Card_calatorie *card, int am)
    {
        Card_metrou *metrou = dynamic_cast<Card_metrou *>(card);

        if (card->get_tip() != Card_calatorie::get_tip())
        {
            std::cout << "Transfer nereusit\n";
            return;
        }
        else
        {
            if (this->calatorii < am)
            {
                std::cout << "Transfer nereusit\n";
                return;
            }
            else
            {
                this->calatorii = this->calatorii - am;
                metrou->calatorii = metrou->calatorii + am;
            }
        }
    }
};

int main()
{
    int n, c, id, am, id2;
    char t;
    std::cin >> n;
    Card_calatorie *carduri[10];
    for (int i = 0; i < n; i++)
    {
        std::cin >> t;
        std::cin >> id;
        std::cin >> c;
        if (t == 'a')
            carduri[i] = new Card_autobuz(id, c, t);
        else
            carduri[i] = new Card_metrou(id, c, t);
    }
    c = 1;
    while (c != 5)
    {
        std::cin >> c;
        if (c == 5)
            break;
        if (c == 1)
        {
            for (int i = 0; i < n; i++)
                carduri[i]->afisare();
        }
        if (c == 2)
        {
            std::cin >> id;
            std::cin >> am;
            for (int i = 0; i < n; i++)
                if (carduri[i]->get_id() == id)
                    carduri[i]->incarcare(am);
        }
        if (c == 3)
        {
            std::cin >> id;
            std::cin >> am;
            for (int i = 0; i < n; i++)
                carduri[i]->validare_calatorie(id, am);
        }
        if (c == 4)
        {
            std::cin >> id;
            std::cin >> id2;
            std::cin >> am;
            int i, j;
            for (i = 0; i < n; i++)
                if (carduri[i]->get_id() == id)
                    break;
            for (j = 0; j < n; j++)
                if (carduri[j]->get_id() == id2)
                    break;
            carduri[i]->transfer(carduri[j], am);
        }
    }
    return 0;
}
