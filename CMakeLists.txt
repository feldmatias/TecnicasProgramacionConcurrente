cmake_minimum_required(VERSION 3.14)
project(primavera_concurrente)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(primavera_concurrente main.cpp src/utils/file/File.cpp src/utils/file/File.h src/utils/file/ReadOnlyFile.cpp src/utils/file/ReadOnlyFile.h src/utils/file/WriteOnlyFile.cpp src/utils/file/WriteOnlyFile.h src/utils/csv/CsvLine.cpp src/utils/csv/CsvLine.h src/flower/Flower.cpp src/flower/Flower.h src/flower/FlowerType.cpp src/flower/FlowerType.h src/actors/Producer.cpp src/actors/Producer.h src/actors/DistributionCenter.cpp src/actors/DistributionCenter.h src/actors/PointOfSale.cpp src/actors/PointOfSale.h src/config/ActorsCreator.cpp src/config/ActorsCreator.h config/ConfigFiles.h src/actors/Actor.cpp src/actors/Actor.h src/actors/ActorInfo.cpp src/actors/ActorInfo.h src/concurrency/SharedMemory.h src/comunication/ExitComunicator.cpp src/comunication/ExitComunicator.h src/concurrency/Runnable.h src/concurrency/Process.cpp src/concurrency/Process.h src/concurrency/Fifo.cpp src/concurrency/Fifo.h src/flower/FlowersBox.cpp src/flower/FlowersBox.h src/flower/FlowerStock.cpp src/flower/FlowerStock.h src/comunication/FlowerProtocol.cpp src/comunication/FlowerProtocol.h)