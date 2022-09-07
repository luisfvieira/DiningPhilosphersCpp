# Dining Philosophers Cpp
In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them. 
The C++ is from [Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem) with some personal modifications, more philosphers 9, and a name variable for each of them.
## Running with Docker alpine
```
git clone git@github.com:luisfvieira/DiningPhilosphersCpp.git
docker build . -t dinning-philosophers:1.0.0
docker run -it dinning-philosophers:1.0.0
```
## Running
```
cd /src
g++ philosophers.cpp -lpthread -o philosophers -Wall
./philosophers
```