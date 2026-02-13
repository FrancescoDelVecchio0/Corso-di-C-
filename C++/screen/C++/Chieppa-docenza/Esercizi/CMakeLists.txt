cmake_minimum_required(VERSION 3.24)
project(Esercizi)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Esercizi
        composizione.cpp
        frequenza_parole.cpp
        lambda_1.cpp
        lambda_2.cpp
        lambda_3_opzionale.cpp
        polimorfismo.cpp
        raii_1.cpp
        raii_2.cpp
        rubrica.cpp
        smart_pointer_1.cpp
        smart_pointer_2.cpp
        algoritmi_1.cpp
        algoritmi_2.cpp
        utility_1.cpp
        utility_2.cpp
        utility_3.cpp
        utility_4.cpp
        temp.cpp
)
