#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <random>
#include <ctime>

using namespace std;

int myrand(int min, int max) {
  static mt19937 rnd(time(nullptr));
  return uniform_int_distribution<>(min,max)(rnd);
}

void phil(string name, mutex& ma, mutex& mb, mutex& mo) {
  for (;;) {
    int duration = myrand(2000, 8000);
    {
      // Block { } limits scope of lock
      lock_guard<mutex> gmo(mo);
      cout<<name<<" thinks "<<duration<<"ms\n";
    }
    this_thread::sleep_for(chrono::milliseconds(duration));
    {
      lock_guard<mutex> gmo(mo);
      cout<<"\t\t"<<name <<" is hungry\n";
    }
    lock_guard<mutex> gma(ma);
    this_thread::sleep_for(chrono::milliseconds(myrand(2000, 8000)));
    lock_guard<mutex> gmb(mb);
    duration = myrand(2000, 8000);
    {
      lock_guard<mutex> gmo(mo);
      cout<<"\t\t\t\t"<<name<<" eats "<<duration<<"ms\n";
    }
    this_thread::sleep_for(chrono::milliseconds(duration));
  }
}

int main() {
  cout<<"dining Philosophers C++11 with Resource hierarchy\n";
  // resources/forks used by each thread/philosopher
  mutex m1, m2, m3, m4, m5, m6, m7, m8, m9;

  mutex mo;
  // Philosophers
  thread t1([&] {phil("Socrates", m1, m2, mo);});
  thread t2([&] {phil("Plato", m2, m3, mo);});
  thread t3([&] {phil("Aristotle", m3, m4, mo);});
  thread t4([&] {phil("Marcus Aurelius", m4, m5, mo);});
  thread t5([&] {phil("Seneca", m5, m6, mo);});  
  thread t6([&] {phil("Nietzsche", m6, m7, mo);});
  thread t7([&] {phil("Kierkegaard", m7, m8, mo);});
  thread t8([&] {phil("Wittgenstein", m8, m9, mo);});
  thread t9([&] {phil("Thoreau", m9, m1, mo);});
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  t7.join();
  t8.join();
  t9.join();

  return 0;
}