#pragma once
#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include "Nemico.h"

class Camera
{
	Camera();
	//~Camera() = default;


private:
	std::string id_;
	std::weak_ptr<Nemico> nemico_osservato_;

public:
	explicit Camera(std::string_view id) noexcept
		: id_(id) {
		
	}
	


	virtual ~Camera() noexcept {
		std::cout << "[CAM OFFLINE] " << id_ << " disattivata.\n";
	}

	Camera(const Camera&) = delete;
	Camera& operator=(const Camera&) = delete;
	Camera(Camera&&) = delete;
	Camera& operator=(Camera&&) = delete;



	void Osserva(std::shared_ptr<Nemico> nemico) & noexcept {
		nemico_osservato_ = nemico;
		std::cout << "[CAM] Camera " << id_ << " ora osserva " << nemico->getNome() << ".\n";
	}


	void VerificaStatoNemico() const& noexcept {
		if (auto nemico = nemico_osservato_.lock()) {
			std::cout << "[CAM] Camera " << id_ << " rileva nemico:\n " << nemico->getNome();
		}
		else {
			std::cout << "[CAM] Nemico " << id_ << " scomparso!.\n";
		}
	}

	void SmettiDiOsservare() & noexcept {
		if (auto nemico = nemico_osservato_.lock()) {
			std::cout << "[CAM] Camera " << id_ << " sta osservare " << nemico->getNome() << ".\n";
		}
		else {
			std::cout << "[CAM] Camera " << id_ << " ha smesso di osservando.\n";
		}
		nemico_osservato_.reset();
	}
};

