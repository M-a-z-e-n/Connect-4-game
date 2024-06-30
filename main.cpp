#include "iostream"
using namespace std;


int pos( char arr[7][7] , int col , bool ch ){
    int row;
    for (int i = 0; i < 7 ; ++i) {
        if( arr[i+1][col] != '.' ){
            row = i ;
            if( ch ){
                arr[i][col] = 'X';
            }else
                arr[i][col] = 'O';
            break;
        }
    }
    return row;
}

bool ch_row( char arr[7][7] , int row , char c ){
    int cnt = 0;
    for (int j = 0; j < 7; ++j) {
        if( arr[row][j] == c ) cnt++;
        else {
            if( cnt >= 4 ) return 1;
            else cnt = 0;
        }
    }
    return ( cnt >= 4 );
}

bool ch_col( char arr[7][7] , int col , char c ){
    int cnt = 0;
    for (int j = 0; j < 7; ++j) {
        if( arr[j][col] == c ) cnt++;
        else {
            if( cnt >= 4 ) return 1;
            else cnt = 0;
        }
    }
    return ( cnt >= 4 ) ;
}

void draw( char arr[7][7] ){
    cout << "1   2   3   4   5   6   7\n";
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            cout << arr[i][j] ;
            if( j != 6 ) cout << " | ";
        }
        cout << endl;
    }
}

void if_not_int(){
        cin.clear();
        cin.ignore(100, '\n');
}

int main() {

    char arr[7][7];

    string k ;

    do{
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            arr[i][j] = '.';
        }
    }
    bool win = 0;
    system("cls");
    cout << "Which player want to start ? \n";
    cout << "( X ) or ( O ) \n";
    string cc;
    cin >> cc;
    while ( cc.size() > 1 || (cc[0] != 'X' && cc[0] != 'O' && cc[0] != 'x' && cc[0] != 'o') ) {
        cout << "the character been entered isn't valid , please choose between ( X ) or ( O ) \n";
        cin >> cc;
    }

    bool ch;
    ch = (cc[0] == 'X' || cc[0] == 'x');

    bool player = 1;

    // show the grid for the player before any play :
    draw(arr);

    for ( int i = 0; i < 7 * 7 ; ++i ) {

        cout << "Player " << ( player ? 1 : 2 ) << " Enter the Column for your next move \n";
        int col ; cin >> col;
        if_not_int();

        while( col < 1 || col > 7 ){
            cout << "Sorry, it's out of bounds! enter another one : \n";
            cin >> col;
            if_not_int();
        }

        while( arr[0][col-1] != '.' ){
            cout << "Sorry, The column is full, enter another one : \n";
            cin >> col;
            if_not_int();
        }

        col--;

        // check the position & set the pos
        int row = pos(arr, col, ch);

        system("cls");
        draw(arr);

        char c = (ch ? 'X' : 'O');

        bool a = 0, b = 0;
        a = ch_row(arr, row, c);
        b = ch_col(arr, col, c);

        if (a || b) {
            player ? (cout << "Player 1 Wins\n") : (cout << "Player 2 Wins\n") ;
            win = 1;
            break;
        }
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

        // check the principal diagonal
        for (int j = row, k = col; (j >= 0), (k < 7); j--, k++) {
            if (arr[j][k] == c) cnt1++;
            else break;
        }
        for (int j = row, k = col; (j < 7), (k >= 0); j++, k--) {
            if (arr[j][k] == c) cnt2++;
            else break;
        }

        // check the second daigonal
        for ( int j = row, k = col; (j >= 0), (k >= 0); j--, k-- ) {
            if (arr[j][k] == c) cnt3++;
            else break;
        }

        for ( int j = row, k = col; (j < 7), (k < 7); j++, k++ ) {
            if (arr[j][k] == c) cnt4++;
            else break;
        }

        if (cnt1 + cnt2 - 1 >= 4 || cnt3 + cnt4 - 1 >= 4) {
            player ? (cout << "Player 1 Wins\n") : (cout << "Player 2 Wins ")  ;
            win = 1;
            break;
        }

        ch = !ch;
        player = !player;
    }

        if (!win){ cout << "Draw!\n"; }

        cout << "Wanna Play again ?\n";
        cout << "Enter 'Y' or 'N'\n";
        cin >> k ;
        while( k.size() > 1 || k != "Y" && k != "y" && k != "N" && k != "n" ){
            cout << "Invalid input , pls try again: \n";
            cin >> k;
        }

    }while( k == "Y" || k == "y" );
    cout << "\nGame Over!\n";

    system("pause");

    return 0;

}