#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <regex>
using namespace  std;

string join(vector<string> list){
    string str = "";
    for (int i = 0; i < list.size(); i++){
        str += list[i];
        }
    return str;
}
string joinints(int code[]){
    string str = "";
    for (int i = 0; i < 4; i++){
        str += to_string(code[i]);
        }
    return str;
}
string generateCode(){
    string finalCode = "";
    int code[] = {1, 2, 3, 4, 5, 6, 7, 8};
    random_shuffle(code, code + 8);
    return joinints(code);
    }
vector<int> correctAndIncorrect(string code,string userAttempt){
    vector<int> result;
    int correct = 0;
    int correctInincorrectPos = 0;
    for (int i = 0; i < code.size(); i++){
        if (userAttempt[i] == code[i]){
            correct++;}
        else if(code.find(userAttempt[i]) != string::npos){
            correctInincorrectPos++;
            }   
    }
    result.push_back(correct);
    result.push_back(correctInincorrectPos);
    return result;
}


string getInput(){
    bool goOn= true;
    string guess;
    while (goOn){
        cout << "Enter a 4 digit code: ";
        cin >> guess;
        
        if (!regex_match(guess,regex("[1-8]{4}"))){
            cout<< "Enter exactly 4 digits of numbers 1-8"<<"\n";
            }
        else{
            goOn = false;
        }
    }
    return guess;
    }
void printResults(vector<int> results){
    cout << "NUmber of correct digits in correct places "<< results[0]<<"\n";
    cout << "Number of correct digits in incorrect places "<< results[1]<<"\n";
}

int main(){
    string code = generateCode();
    cout << "A super secret 4 digit code has been generated you have 10 tries to try and guess it, goodluck.\n";
    // cout << code<<"\n";
    int turns = 10;
    while (turns>0){
        turns --;
        string userinput = getInput();
        vector<int> result = correctAndIncorrect(code,userinput);
        printResults(result);
        if (result[0]==4){
            cout << "Congratilations you broke the code"<<"\n";
            cout << "The Code was "<< code<<"\n";
            break;
        }
        else{
            
            if (turns == 0){
                cout <<"Ran out of chances.\n"
                cout << "The Code was "<< code<<"\n";
            }
            else{
                cout << "Turns left "<< turns<<"\n";
            }
        }
    }
    

}