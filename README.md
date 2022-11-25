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

## Running with logs in Journald
1. Set "log-driver" the "journald" value in the daemon.json, located at /etc/docker in Linux and C:\ProgramData\docker\config\daemon.json in Windows. In case the file doesn't exist create one.
```
{
  "log-driver": "journald"
}
```
2. Restart docker service
```
sudo systemctl restart docker.service
```
3. Run docker run with log-driver flag
```
docker run --log-driver=journald --name=dinning-philosophers-1 dinning-philosophers:1.0.0
```
4. Enjoy the logs with journalctl
```
journalctl -b CONTAINER_NAME=dinning-philosophers-1 -f --all
```
for further reference check: [docs.docker](https://docs.docker.com/config/containers/logging/journald/).
