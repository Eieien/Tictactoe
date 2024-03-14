#include<iostream>
#include<string>

using namespace std;

void display(string table[3][3]);
void Win(bool turn, string table[3][3]);
int main(){

    bool turn1 = true, added = false;
    int placed = 0 ;
    string ta[3][3]={{" "," "," "},{" "," "," "},{" "," "," "}};
    string answer = "XXX|OOO";
    int row, column;
    for(int i = 0; i < 8; i++){

        if(answer.find(ta[0][0] + ta[0][1] + ta[0][2]) != string::npos){
            Win(turn1, ta);
            break;
        }else if(answer.find(ta[1][0] + ta[1][1] + ta[1][2]) != string::npos){
            Win(turn1, ta);
            break;
        }else if(answer.find(ta[2][0] + ta[2][1] + ta[2][2]) != string::npos){
            Win(turn1, ta);
            break;
        }else if(answer.find(ta[0][0] + ta[1][0] + ta[2][0]) != string::npos){
            Win(turn1, ta);
            break;
        }else if(answer.find(ta[0][1] + ta[1][1] + ta[2][1]) != string::npos){
            Win(turn1, ta);
            break;
        }else if(answer.find(ta[0][2] + ta[1][2] + ta[2][2]) != string::npos){
            Win(turn1, ta);
            break;
        }else if(answer.find(ta[0][0] + ta[1][1] + ta[2][2]) != string::npos){
            Win(turn1, ta);
            break;
        }else if(answer.find(ta[0][2] + ta[1][1] + ta[2][0]) != string::npos){
            Win(turn1, ta);
            break;
        }else{
            display(ta);
            while(1){
                cout << "\nrow: ";
                cin >> row;
                cout << "\ncolumn: ";
                cin >> column;

                if(ta[row][column] == " "){
                    break;
                }else{
                    cout << "That box is occupied, pick another box" << endl;
                }

            }
            if(turn1){
                ta[row][column] = "O";
                turn1 = false;
            }else{
                ta[row][column] = "X";
                turn1 = true;
            }
            

        }
        
    }
    int ans;
    cout << "Match draw" << endl;
    display(ta);
    cout << "Would you like to play again? (1 for yes, 2 for no) " << endl;
    cout << "> ";
    cin >> ans;
    if(ans == 1){
        cout << "Rematch commencing..." << endl;
        main();
    }else{
        cout << "Ending game" << endl;
        exit(0);
    }
    return 0;
}

void Win(bool turn, string table[3][3]){
    if (turn == true){
        cout << "Player 2 wins" << endl;
    }else{
        cout << "Player 1 wins" << endl;
    }
    display(table);
    int choice;
    cout << "Would you like to rematch?  (1 for yes, 2 for no)" << endl;
    cout << "> ";
    cin >> choice;
    if(choice == 1){
        cout << "Rematch commencing..." << endl;
        main();
    }else{
        cout << "Ending program" << endl;
        exit(0);
    }
}

void display(string table[3][3]){
    //201 203 187 188 185 204 205 206 186
    cout << "    0   1   2" << endl;
    cout << "  -------------"<< endl;
    cout << "0 | " << table[0][0] << " | " << table[0][1] << " | " << table[0][2] << " | " << endl;
    cout << "  -------------"<< endl;
    cout << "1 | " << table[1][0] << " | " << table[1][1] << " | " << table[1][2] << " | " << endl;
    cout << "  -------------"<< endl;
    cout << "2 | " << table[2][0] << " | " << table[2][1] << " | " << table[2][2] << " | " << endl;
    cout << "  -------------"<< endl;
}
