#include <iostream>
#include <string>

using namespace std;

int iG;
char reflector[27] = {"YRUHQSLDPXNGOKMIEBFZCWVJAT"};
char rotors[][27] = {
    {"EKMFLGDQVZNTOWYHXUSPAIBRCJ"},
    {"AJDKSIRUXBLHWTMCQGZNPYFVOE"},
    {"BDFHJLCPRTXVZNYEIWGAKMUSQO"},
    {"ESOVPZJAYQUIRHXLNFTGKDCMWB"},
    {"VZBRGITYUPSDNHLXAWMJQOFECK"}
};
int notchPos[] = {16,4,21,9,25};
int currentPos[5], ringSetting[5];
char plugEffect[26];
char inversAlpha(int index, char inp){
    iG=0;
    while (rotors[index][iG]!=inp)iG++;
    return 65+iG;
  
}
int stepWiring(int index){
    return (currentPos[index] - ringSetting[index] + 26)%26;
}
char convert(int index, char inp){
    return 65 + (((rotors[index][((inp-65) + stepWiring(index))%26]-65) - stepWiring(index) + 26)%26);
}
char inversConvert(int index, char inp){
    return 65 + (((inversAlpha(index, 65+(((inp-65) + stepWiring(index))%26))-65) - stepWiring(index)+26)%26);
}
int main(){
    string firstLine, plugLine, textInp;
    int choosenRotor[3];
    int T, i;
    cin >> T;
    cin.ignore(1, '\n');
    while(T--){
        getline(cin, firstLine);
        getline(cin, plugLine);
        getline(cin, textInp);
        for(i=0; i<26; i++){
            plugEffect[i] = 65 + i;
        }
        for(i=0; i<3; i++){
            choosenRotor[i] = firstLine[i]-49;
            currentPos[choosenRotor[i]] =  firstLine[8+i]-65;
            ringSetting[choosenRotor[i]] = firstLine[4+i]-65;
        }
        i=1;
        while(plugLine[i-2]!='\0'){
            plugEffect[plugLine[i]-65] = plugLine[i-1];
            plugEffect[plugLine[i-1]-65] = plugLine[i];
            i+=3;
        }
        for(i=0; textInp[i]!='\0'; i++){
            if(textInp[i]!=' '){
                if(currentPos[choosenRotor[2]]==notchPos[choosenRotor[2]]){
                    (currentPos[choosenRotor[1]]+=1)%=26;
                } else if(currentPos[choosenRotor[1]]==notchPos[choosenRotor[1]]){
                    (currentPos[choosenRotor[1]]+=1)%=26;
                    (currentPos[choosenRotor[0]]+=1)%=26;
                }
                (currentPos[choosenRotor[2]]+=1)%=26;
                printf("%c", plugEffect[((inversConvert(choosenRotor[2], inversConvert(choosenRotor[1], inversConvert(choosenRotor[0], reflector[((convert(choosenRotor[0], convert(choosenRotor[1], convert(choosenRotor[2], plugEffect[(textInp[i]-65)]))))-65)]))))-65)]);
            } else{
                printf(" ");
            }
        }
        puts("");
    }
}
