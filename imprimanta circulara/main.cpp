#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    int i = 0, posdor = 0, tmp = 0, actpos = 65, numar;
    string vin, Blu, Red;
    ifstream data ("data.txt");

    while (data >> vin){
        if (i == 0){
            numar = stoi(vin);
        } else if (i == 1){
            Blu = vin;
        } else if (i == 2){
            Red = vin;
        }
        i++;
    }
    if (numar == 1){
        for(int i = 0; i < Blu.length(); i++){
            posdor = int(Blu[i]);
            if(posdor > actpos){
                if (posdor - actpos > 12){
                    tmp = (90 - posdor) + (actpos - 65) + 1 + tmp;
                } else {
                    tmp = posdor - actpos + tmp;
                }
            } else {
                if (actpos - posdor > 12){
                    tmp = (90 - actpos) + (posdor - 65) + 1 + tmp;
                } else {
                    tmp = actpos - posdor + tmp;
                }
            }
            actpos = posdor;
            posdor = 0;
        }
        cout << tmp;
    }
    return 0;
}
