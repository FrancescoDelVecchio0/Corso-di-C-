#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <string_view>

class Nemico
{
	Nemico();

	//~Nemico() = default;


private:
	std::string nome_;
	int hp_;
	int x_, y_;
public:
	explicit Nemico(std::string_view nome, int hp)
		noexcept
		: nome_(nome), hp_(hp), x_(0), y_(0) {
		std::cout << "[SPAWN] " << nome_;
	}

	virtual ~Nemico() noexcept
	{
		std::cout << "[DEATH] " << nome_ << " è stato eliminato.\n";
	}


	


	Nemico(const Nemico&) = delete;
	Nemico& operator=(const Nemico&) = delete;
	Nemico(Nemico&&) = delete;
	Nemico& operator=(Nemico&&) = delete;




	[[nodiscard]] int getHP() const& noexcept
	{
		return hp_;
	}
	[[nodiscard]] std::string_view getNome() const& noexcept
	{
		return nome_;
	}
	void stampaInfo() const& noexcept
	{
		std::cout << "[Nemico] Nome: " << nome_ << ", HP: " << hp_ << ", Posizione: (" << x_ << ", " << y_ << ")\n";
	}
	void Muovi(int dx, int dy)
	{
		x_ += dx;
		y_ += dy;
		std::cout << "[MOVE]" << nome_ << " si sposta a (" << x_ << ", " << y_ << ")\n";
	}

	void SubisciDanno(int danno) & noexcept {
		hp_ -= danno;
		if (hp_ < 0) hp_ = 0;
		std::cout << "[DAMAGE] " << nome_ << " subisce " << danno << " danni. HP rimasti: " << hp_ << "\n";
	}


}
;