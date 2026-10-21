#include <iostream>
using namespace std;

class Memory;

class CPU
{
private:
    float cpuUtilization;
public:
    CPU(float cpu) {
        cpuUtilization = cpu;
    }
    friend void checkTask(CPU, Memory);
};

class Memory {
private:
    float memoryUtilization;
public:
    Memory(float memory) {
        memoryUtilization = memory;
    }
    friend void checkTask(CPU, Memory);
};

void checkTask(CPU c, Memory m) {
    if (c.cpuUtilization < m.memoryUtilization) {
        cout << "CPU-intensive task may be started." << endl;
    }
    else if (m.memoryUtilization < c.cpuUtilization) {
        cout << "Memory-intensive task may be started." << endl;
    }
    else {
        cout << "CPU and Memory utilization are equal." << endl;
    }
}

int main() {
    float cp, mem;
    cout << "Enter CPU utilization: ";
    cin >> cp;
    cout << "Enter Memory utilization: ";
    cin >> mem;

    CPU c(cp);
    Memory m(mem);

    checkTask(c, m); 
    return 0;
}


