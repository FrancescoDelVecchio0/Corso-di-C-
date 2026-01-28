#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include "Nemico.h"
#include "Camera.h"



void test() noexcept {
	std::cout << "\n" << std::string(70, '=') << "\n";
	std::cout << "ESERCIZIO: Osservatori di Nemico con weak_ptr\n";
	std::cout << std::string(70, '=') << "\n\n";


	std::cout << "--- STEP 1: Crea il nemico ---\n";
	auto nemico_live = std::make_shared<Nemico>("Nemico", 50);
	nemico_live->stampaInfo();

	std::cout << "--- STEP 2: Crea le telecamera ---\n";
	auto cam1 = std::make_unique<Camera>("CAM_1");
	auto cam2 = std::make_unique<Camera>("CAM_2");
	auto cam3 = std::make_unique<Camera>("CAM_3");

	std::cout << "--- STEP 3: Telecamere osservarno il nemico ---\n";

	cam1->Osserva(nemico_live);
	cam2->Osserva(nemico_live);
	cam3->Osserva(nemico_live);

	std::cout << "--- STEP 4: Verifica lo stato del nemico ---\n";

	cam1->VerificaStatoNemico();
	cam2->VerificaStatoNemico();
	cam3->VerificaStatoNemico();

	std::cout << "--- STEP 5: Nemico si muove ---\n";
	nemico_live->Muovi(5, 3);

	std::cout << "--- STEP 6: Nemico subisce danno ---\n";
	nemico_live->SubisciDanno(20);

	std::cout << "--- STEP 7: Verifica di nuovo ---\n";
	cam1->VerificaStatoNemico();

	std::cout << "--- STEP 8: Nemico muore ---\n";
	nemico_live.reset();


	std::cout << "--- STEP 9: Telecamere provano a vedere il nemico ---\n";

	cam1->VerificaStatoNemico();
	cam2->VerificaStatoNemico();
	cam3->VerificaStatoNemico();

	std::cout << "--- STEP 10: Telecamera smette di osservare ---\n";
	cam1->SmettiDiOsservare();

	std::cout << "\nTest completatp!\n";
}

int main()
{

	try {
		test();
		return 0;
	}
	catch (const std::exception& e) {
		std::cerr << "Errore: " << e.what() << "\n";
		return 1;
	}
	std::cout << "Hello World!\n";

}