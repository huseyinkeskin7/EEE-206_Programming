#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int board [3][3];
void createSquare();
void playerMoves();
void aiMoves();
int results();


int main(void)
{
    int i,j;
    int gameState=0; // Game situation Variable
    


    for (i=0; i<3; i++) {   // Make the board array 0 in the beginning.
        for (j=0; j<3; j++)
        {
            board [i][j]=0;
        }
    }


    printf("WELCOME TO THE TIC-TAC-TOE GAME! \n");
    printf("YOU ARE 'X' \n");
    printf("COMPUTER IS 'O' \n");
    
    createSquare(); 

    while (gameState==0) {

        playerMoves(); // Player starts the game.
        gameState= results();

        if(gameState==0){ // Checking whether the game is over or not
            aiMoves(); 
            gameState= results();
            
        }

        createSquare();

        if(gameState != 0){ // Checks if  the game is over
            if(gameState==1) { // User won
                printf("\n !!! YOU WIN !!!");
            }

            else if(gameState==-1){ // Computer won
                printf("\n !!! YOU LOSE!!!");

            }
            else if(gameState==2) { // DRAW
                printf("\n DRAW ");

            }


            //Asking the player if he/she wants to play again

            printf("\n Do you want to play another game: ? ");
            printf("\n Press 9 to play again or if you want to exit, press another number: ");
            scanf("%d", &gameState);

            if (gameState ==9) { //  The player wants to play again
                printf("\n New Game: \n");
                gameState=0; //To keep working in while loop
                for(i=0; i<3;i++) {  // It clears the game board
                    for(j=0;j<3;j++) {
                        board[i][j]=0;
                    }
                }
                createSquare(); // It starts the game again  


            }

            else { // If the player wants to exit
                printf("\n ... Exiting the game ... \n");
                gameState=3; // Exiting from the while loop
            }

        }
        
    }
    
    return 0;
}

// Creating the TIC-TAC-TOE board
// Placement of X and O on the board

void createSquare(){ // It draws the 3x3 surface on which the TIC-TAC-TOE game will be played.
    int i,j;

    for(i=0; i<3 ; i++) {
        printf("       |       |       \n");

        for (j=0; j<3; j++) {
            if (board[i][j] == 1) { // if the square is X its value will be 1
            printf("   X   ");
            }

            if (board[i][j] == 0) { // if the square is empty its value will be 0
            printf("       ");
            }

            if (board[i][j] == -1) { // if the square is O its value will be -1
            printf("   O   ");
            }
            if( j !=2) { // for the line formed between the columns
            printf("|");
            
            }
        }
        
        if (i!=2) { // To add a line between lines
        
            printf("\n_______|_______|_______\n");

            }
             else {

            printf("\n       |       |       \n");
            
            }
    
    }

}


// PLAYER'S MOVEMENT. 

void playerMoves() {
    int row;
    int column;

    while(1) {
        
        // Location to place an 'X' will be determied by a row & column.
        while(1){

            printf("\n Enter the row: ");
            scanf("%d", &row);

            if(row <=3 && row >=1)
            {
                break;
            }
            else 
            {
                printf("\n Invalid Value, try again. ");   
            } 
        }

        while(1){

            printf(" Enter the column: ");
            scanf("%d", &column);

            if(column <=3 && column >=1)
            {
                break;
            }

            else 
            {
                printf("\n Invalid Value, try again. ");
                
            } 
        }

        // If location is not available, try again.
        if (board[row-1][column-1] !=0){
            printf("\n This square is unavailable. Please enter a valid location. ");
        }
        else{
            board[row - 1][column - 1]=1;
            break;
        }
    }

}


// AI MOVES + WIN CONDITIONS
// THE TOTAL POINT OF THE ROW-COLUMN-DIAGONAL SHOULD BE -3 FOR COMPUTER TO WIN
void aiMoves() {
    int i;
    int j;
    int point=0;
    // THE POITNS MUST BE -2 FOR COMPUTER TO WIN WITH A MOVE
    // TO CHECK IF COMPUTER CAN WIN IN A ROW
    for(i = 0; i < 3; i++){
        point = 0;
        for(j=0; j<3; j++){
            point = point + board[i][j];
        }
        if(point == -2){
            for(j=0;j<3;j++){
                if(board[i][j]==0){
                    board[i][j]=-1;
                    return;
                }
            }
        }
    }

    // TO CHECK IF COMPUTER CAN WIN IN A COLUMN
    for(i = 0; i < 3; i++){
        point = 0;
        for(j=0; j<3; j++){
            point = point + board[j][i];
        }
        if(point == -2){
            for(j=0;j<3;j++){
                if(board[j][i]==0){
                    board[j][i]=-1;
                    return;
                }
            }
        }
    }

    // TO CHECK IF COMPUTER CAN WIN IN LEFT DIAGONAL
    point =0;
    for(i=0;i<3;i++){
        point = point + board[i][i];
    }
    if(point == -2){
        for(i=0;i<3;i++){
            if(board[i][i]==0){
                board[i][i]=-1;
                return;
            }
        }
    }

    // TO CHECK IF COMPUTER CAN WIN IN RIGHT DIAGONAL
    point = 0;
    j = 2;
    for(i=0;i<3;i++){
        point = point + board[i][i];
        j--;
    }
    if(point == -2){
        j=2;
        for(i=0;i<3;i++){
            if(board[i][i]==0){
                board[i][i]=-1;
                return;
            }
            j--;
        }
    }
    //---------------------------------------------------------------------------------//
    // +3 POINTS ARE NEEDED IN ROW-COLUMN-DIAGONAL FOR PLAYER TO WIN 
    // COMPUTER WILL BLOCK THAT +2 SITUATION SO THAT PLAYER CANT ENTER 'X' THERE

    // TO CHECK IF PLAYER CAN WIN IN A ROW
    for(i = 0; i < 3; i++){
        point = 0;
        for(j=0; j<3; j++){
            point = point + board[i][j];
        }
        if(point == 2){
            for(j=0;j<3;j++){
                if(board[i][j]==0){
                    board[i][j]=-1;
                    return;
                }
            }
        }
    }

    // TO CHECK IF PLAYER CAN WIN IN A COLUMN
    for(i = 0; i < 3; i++){
        point = 0;
        for(j=0; j<3; j++){
            point = point + board[j][i];
        }
        if(point == 2){
            for(j=0;j<3;j++){
                if(board[j][i]==0){
                    board[j][i]=-1;
                    return;
                }
            }
        }
    }

    // TO CHECK IF PLAYER CAN WIN IN LEFT DIAGONAL
    point =0;
    for(i=0;i<3;i++){
        point = point + board[i][i];
    }
    if(point == 2){
        for(i=0;i<3;i++){
            if(board[i][i]==0){
                board[i][i]=-1;
                return;
            }
        }
    }

    // TO CHECK IF PLAYER CAN WIN IN RIGHT DIAGONAL
    point =0;
    j=2;
    for(i=0;i<3;i++){
        point = point + board[i][i];
        j--;
    }
    if(point == 2){
        j=2;
        for(i=0;i<3;i++){
            if(board[i][i]==0){
                board[i][i]=-1;
                return;
            }
            j--;
        }
    }
    //----------------------------------------------------------------------//
    // IF COMPUTER HAS ONLY ONE 'O' WHICH REPRESENTED AS POINT = -1
    
    //-1 IN ROW
    for(i = 0; i < 3; i++){
        point = 0;
        for(j=0; j<3; j++){
            point = point + board[i][j];
        }
        if(point == -1){
            for(j=0;j<3;j++){
                if(board[i][j]==0){
                    board[i][j]=-1;
                    return;
                }
            }
        }
    }
    //-1 IN COLUMN
    for(i = 0; i < 3; i++){
        point = 0;
        for(j=0; j<3; j++){
            point = point + board[j][i];
        }
        if(point == -1){
            for(j=0;j<3;j++){
                if(board[j][i]==0){
                    board[j][i]=-1;
                    return;
                }
            }
        }
    }
    //-1 IN LEFT DIAGONAL
    point =0;
    for(i=0;i<3;i++){
        point = point + board[i][i];
    }
    if(point == -1){
        for(i=0;i<3;i++){
            if(board[i][i]==0){
                board[i][i]=-1;
                return;
            }
        }
    }
    
    //-1 IN RIGHT DIAGONAL
    point =0;
    j=2;
    for(i=0;i<3;i++){
        point = point + board[i][i];
        j--;
    }
    if(point == -1){
        j=2;
        for(i=0;i<3;i++){
            if(board[i][i]==0){
                board[i][i]=-1;
                return;
            }
            j--;
        }
    }
//------------------------------------------------------------------------------------//
// SAFE CHOICE FOR COMPUTER WHEN THERE'S NO OTHER OPTION 

    for(i=0;j<3;j++){
        for(j=0;j<3;j++){
            if(board[i][j]==0){
                board[i][j]=-1;
                return;
            }
        }

    }
    
}

// The player will win if it hits 3.
// The computer will win if it hits 3.
// When the return is 1, the player wins.
// When the return is -1, the computer wins.

int results(){
    int i,j, point;

    // In this section, we look at whether the player has won in the row 
    for(i = 0; i < 3; i++){
        point = 0;
        for(j =0; j < 3; j++) {
            point = point + board[i][j]; // Point the row
            
        }
        if (point == 3) { // The player will win if it hits 3
            return 1; //When the return is 1, the player wins.
        }
        if (point == -3) { //The computer will win if it hits 3
             return -1; //When the return is -1, the computer wins.
        }
    }
    
    
    // In this section, we look at whether the player has won in the column
    for(i = 0; i < 3; i++){
        point = 0;
        for(j =0; j < 3; j++) {
            point = point + board[j][i]; // Point the column
            
        }
        if (point == 3) { // The player will win if it hits 3
            return 1; //When the return is 1, the player wins.
        }
        if (point == -3) { // The computer will win if it hits 3
             return -1; //When the return is -1, the computer wins.
        }
    }

    // In this section, we look at whether the player has won in the slant
    point =0;
    for(i = 0; i < 3; i++) {
        point = point + board[i][i];
    }
    if (point == 3) { // The player will win if it hits 3
        return 1; //When the return is 1, the player wins.
    }
    if (point == -3) { // The computer will win if it hits 3
        return -1; //When the return is -1, the computer wins.
    }
    
    // In this section, we look at whether the player has won in the second slant
    point =0;
    j = 2; // For the second slant
    for(i = 0; i < 3; i++) {
        point = point + board[i][j];
        j--;
    }
    if (point == 3) { // The player will win if it hits 3
        return 1; //When the return is 1, the player wins.
    }
    if (point == -3) { // The computer will win if it hits 3
        return -1; //When the return is -1, the computer wins.
    }  
    
    // In this section, we look at the equality of the player and the computer.
    point =0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++){
            if(board[i][j] == 0){ // If there is a gap, it means the game is not over yet.
                return 0;
            }
        }
    }
    return 2; // If no one has won and there are no more empty squares, then it's a draw.
    
}







