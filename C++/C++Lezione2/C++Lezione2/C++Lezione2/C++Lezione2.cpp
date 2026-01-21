
#include <iostream>
#include <memory>


struct Posizione
{
public:
    int x;
    int y;
    void Debug() {
        std::cout << "Posizione X: " << x;
        std::cout << "\nPosizione Y: " << y;
    }
};
struct Salute {
public:
    int vita;
    void Debug() {
        std::cout << "\nSalute: " << vita;
    }
};

struct Attacco
{
public:
    int danno;
    void Debug() {
        std::cout << "\nAttacco: " << danno;
    }
};


class Entità
{
public:
    std::string nome;
    Entità() = default;
    Entità(bool posizione = false, bool salute = false, bool attacco = false) {
        if (posizione)
            this->posizione = std::make_unique<Posizione>();
        if (salute)
            this->salute = std::make_unique<Salute>();
        if (attacco)
            this->attacco = std::make_unique<Attacco>();

    }
    ~Entità() = default;

    std::unique_ptr<Entità> entità;
    std::unique_ptr<Posizione> posizione;
    std::unique_ptr<Salute> salute;
    std::unique_ptr<Attacco> attacco;

    void Debug() {
        if (posizione) posizione->Debug();
        if (salute) salute->Debug();
        if (attacco) attacco->Debug();
    }
};



int main()
{
    
	auto muro = std::make_unique<Entità>(true, false, false);
    muro->posizione->x = 10;
    muro->posizione->y = 5;
    auto torretta = std::make_unique<Entità>(true, true, false);
    torretta->posizione->x = 15;
    torretta->posizione->y = 15;
    torretta->salute->vita = 10;
    auto drone = std::make_unique<Entità>(true, true, true);
    drone->posizione->x = 15;
    drone->posizione->y = 40;
    drone->salute->vita = 120;
    drone->attacco->danno = 25;

    std::cout << "Muro\n";
    muro->Debug();
    std::cout << std::endl;
	std::cout << "Torretta\n";
    torretta->Debug();
    std::cout << std::endl;
	std::cout << "Drone\n";
	drone->Debug();
	return 0;

}
