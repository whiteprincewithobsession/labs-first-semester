#include <iostream>
#include <cmath>

int main(){
    long long firstElement, lastElement, step, numRoots = 0, templElement, element = 0, sum = 0;
    std::cout << "Enter firstElement, lastElement, step ";
    std::cin >> firstElement >> lastElement >> step;
    templElement = lastElement;
    element = firstElement;
    if(std::cin.fail()){
        std::cout << "ERROR";
    }
    else{
        if(firstElement > lastElement && step > 0){
            std::cout << "ERROR";
        }
        else if(firstElement < lastElement && step < 0){
            std::cout << "ERROR";
        }
        else if(firstElement > lastElement && step < 0){
            while(templElement <= firstElement){
            templElement -= step;
            numRoots++;
            }
            if((firstElement + step * (numRoots - 1)) == lastElement){

                for(int i = 0; i < numRoots; i++){
                    sum += pow(-2, i) * element;
                    element += step;
                }
                std::cout << sum << '\n';
            }
            else{
                std::cout << "No sequence";
            }
        }
        else if(firstElement < lastElement && step > 0){
            while(templElement >= firstElement){
            templElement -= step;
            numRoots++;
        } 
        if((firstElement + step * (numRoots - 1)) == lastElement){
            for(int i = 0; i < numRoots; i++){
                sum += pow(-2, i) * element;
                element += step;
            }
            std::cout << sum;
        }
        else{
            std::cout << "No sequence";
        }
        }
        else if(firstElement == lastElement && step != 0){
            std::cout << "ERROR";
        }
    }
}