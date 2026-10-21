#include <iostream>

using namespace std;

template <typename T>
T sqOf(T a){
    return a*a;
}

int main(){
cout << sqOf(2) << endl;
cout << sqOf(2.5) << endl;
}
