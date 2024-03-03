#include<iostream>
#include"yourgraphics.h"
#include<fstream>

using namespace std;

int main() {
    PlaySound(TEXT("bgm1"), NULL, SND_ASYNC);
    delay(100);
    fstream sg_file, score_file;
    int score = 0, hits = 0, k, lives = 3, highscore, finalscore = 0;
    int check[5][10];
    int score_array[6];
    int brick_x[10];
    int brick_y[5];
    int c1, c2, c3;
    showConsoleCursor(false);
    for (int i = 0; i < 1500; i += 120)
    {
        for (int j = 0; j < 800; j += 40)
        {
            showConsoleCursor(false);
            if (i == 0)
            {
                c1 = 204, c2 = 0, c3 = 204;
            }
            else if (i == 120)
            {
                c1 = 204, c2 = 0, c3 = 0;
            }
            else if (i == 240)
            {
                c1 = 255, c2 = 255, c3 = 0;
            }
            else if (i == 360)
            {
                c1 = 51, c2 = 51, c3 = 255;
            }
            else if (i == 480)
            {
                c1 = 204, c2 = 0, c3 = 102;
            }
            else if (i == 600)
            {
                c1 = 0, c2 = 255, c3 = 255;
            }
            else if (i == 720)
            {
                c1 = 128, c2 = 255, c3 = 0;
            }
            else if (i == 840)
            {
                c1 = 255, c2 = 0, c3 = 0;
            }
            else if (i == 960)
            {
                c1 = 96, c2 = 96, c3 = 96;
            }
            else if (i == 1080)
            {
                c1 = 0, c2 = 153, c3 = 0;
            }
            else if (i == 1200)
            {
                c1 = 255, c2 = 0, c3 = 127;
            }
            drawRectangle(i, j, i + 120, j + 40, 0, 0, 0, c1, c2, c3);
            delay(5);
        }
    }
    delay(50);
    for (int i = 0; i < 1500; i += 120)
    {
        for (int j = 0; j < 800; j += 40)
        {
            showConsoleCursor(false);
            drawRectangle(i, j, i + 120, j + 40, 0, 0, 0, 0, 0, 0);
            delay(5);
        }
    }
    cls();
    gotoxy(27, 4);
    cout << "*************************************************************\n";
    for (int g = 5; g < 24; g++)
    {
        gotoxy(87, g);
        cout << "*\n";
    }
    gotoxy(48, 14);
    cout << "THE BRICK BREAKER GAME!\n";
    for (int g = 5; g < 24; g++)
    {
        gotoxy(27, g);
        cout << "*\n";
    }
    gotoxy(27, 24);
    cout << "*************************************************************\n";
    delay(6000);
    for (int i = 0; i < 3; i++)
    {

        cls();
        gotoxy(40, 4);
        cout << "******************************************\n";
        for (int g = 5; g < 24; g++)
        {
            gotoxy(40, g);
            cout << "*\n";
        }
        for (int g = 5; g < 24; g++)
        {
            gotoxy(81, g);
            cout << "*\n";
        }
        gotoxy(40, 24);
        cout << "******************************************\n";
        if (i == 1)
        {
            showConsoleCursor(false);
            gotoxy(53, 6);
            cout << "-:INSTRUCTIONS:-\n";
            gotoxy(52, 11);
            cout << "-:READ CAREFULLY:-\n";
            gotoxy(40, 8);
            cout << "*****************************************\n";
            gotoxy(51, 13);
            cout << "1. A\\a to move Left.\n";
            gotoxy(51, 15);
            cout << "2. D\\d to move Right.\n";
            gotoxy(51, 17);
            cout << "3. P\\p to move Pause.\n";
            gotoxy(51, 19);
            cout << "4. Q\\q to quit Game.\n";
            gotoxy(51, 21);
            cout << "5. S\\s to save Game.\n";
            delay(6000);
            continue;
        }
        if (i == 2)
        {
            gotoxy(55, 6);
            cout << "-:MENU:-\n";
            gotoxy(40, 8);
            cout << "*****************************************\n";
            gotoxy(55, 10);
            cout << "1.New Game\n";
            gotoxy(55, 12);
            cout << "2.Load Game\n";
            gotoxy(55, 14);
            cout << "3.King's Scores\n";
            gotoxy(55, 16);
            cout << "4.Exit Game\n";
            gotoxy(55, 18);
            cout << "Enter: ";
            cin >> k;
            while (k < 1 || k>4)
            {
                cin >> k;
            }
            i++;
        }
    }
    score_file.open("highscore.txt", ios::in);
    int memory;
    score_file >> memory;
    score_array[0] = memory;
    highscore = memory;
    for (int i = 1; i < 5; i++)
    {
        score_file >> score_array[i];
    }
    score_file.close();
    showConsoleCursor(false);
    if (k == 1)
    {
        for (int i = 0; i < 3; i++)   //Check if brick is broken or not single hit
        {
            for (int j = 0; j < 10; j++)
            {
                check[i][j] = 1;
            }
        }
        for (int i = 3; i < 5; i++)  //Check if brick is broken or not double hit
        {
            for (int j = 0; j < 10; j++)
            {
                check[i][j] = 2;
            }
        }
    }
    if (k == 2)
    {
        sg_file.open("savedgame.txt", ios::in);
        sg_file >> lives;
        sg_file >> score;
        for (int i = 0; i < 5; i++)   //Check if brick is broken or not single hit
        {
            for (int j = 0; j < 10; j++)
            {
                sg_file >> check[i][j];
            }
        }
        sg_file.close();
    }
    gotoxy(0, 0);
    cls();
    int l;
    if (k == 3)
    {
        cls();
        for (int i = 0, j = 10; i < 5; i++, j += 2)
        {
            gotoxy(50, j);
            cout << i + 1 << "th high score: " << score_array[i] << endl;
        }
        while (69)
        {
            gotoxy(48, 20);
            cout << "Press 8 to end the game: ";
            cin >> l;

            if (l == 8)
            {
                k = 4;
                while (k != 4)
                {
                    cin >> k;
                }
                cls();
                break;
            }

        }
    }
    if (k == 4)
    {
        while (true)
        {
            gotoxy(53, 14);
            cout << "The Game has ended!";
            gotoxy(50, 16);
            cout << "To play again start again.";
        }
    }
    drawRectangle(0, 0, 880, 480, 0, 0, 0, 0, 0, 0);
    showConsoleCursor(false);
    //Printing main outer rectangle and 3 lives
    drawRectangle(185, 75, 1117, 705, 255, 255, 255, 0, 0, 0);
    if (lives == 3)
    {
        drawEllipse(1050, 30, 1080, 60, 255, 0, 0, 255, 0, 0);
        drawEllipse(1000, 30, 1030, 60, 255, 0, 0, 255, 0, 0);
        drawEllipse(950, 30, 980, 60, 255, 0, 0, 255, 0, 0);
    }
    if (lives == 2)
    {
        drawEllipse(1050, 30, 1080, 60, 255, 0, 0, 255, 0, 0);
        drawEllipse(1000, 30, 1030, 60, 255, 0, 0, 255, 0, 0);
    }
    if (lives == 1)
    {
        drawEllipse(1050, 30, 1080, 60, 255, 0, 0, 255, 0, 0);
    }
    gotoxy(20, 1);
    cout << "High Score: " << highscore;
    gotoxy(50, 1);
    cout << "Current Score: " << score;
    //Bricks Making Loop
    for (int i = 200, y = 0; i < 1100; i += 100, y++) {
        for (int j = 80, x = 0; j < 220; j += 30, x++) {
            if (check[x][y] == 2)
            {
                drawRectangle(i, j, i + 100, j + 30, 0, 0, 0, 255, 0, 0);
            }
            else if (check[x][y] == 1)
            {
                drawRectangle(i, j, i + 100, j + 30, 0, 0, 0, 255, 255, 255);
            }
            delay(30);
        }
    }
    for (int i = 0, j = 200; j < 1100; j += 100, i++) {  //Array to store x-coordinates
        brick_x[i] = j;
    }
    for (int i = 0, j = 80; j < 220; j += 30, i++) {    //Array to store y-coordinates
        brick_y[i] = j;
    }
    int i = 0, j = 0, i_e = 45, j_e = 25;
    int bat_x2, bat_x1, bat_y1, bat_y2;
    int ball_x1 = 727, ball_x2 = 750, ball_y1 = 227, ball_y2 = 250;
    PlaySound(TEXT("bgm"), NULL, SND_ASYNC);
    bool final = true;
    int b_x1 = 545, b_x2 = 760;
    int cr1 = 123;
    while (final == true && lives > 0) {
        bat_x1 = b_x1 + i;
        bat_x2 = b_x2 + i;
        bat_y1 = 635;
        bat_y2 = 650;
        ball_x1 += i_e;
        ball_x2 += i_e;
        ball_y1 += j_e;
        ball_y2 += j_e;
        drawRectangle(bat_x1, bat_y1, bat_x2, bat_y2, cr1, cr1, cr1, cr1, cr1, cr1);
        drawEllipse(ball_x1, ball_y1, ball_x2, ball_y2, 255, 0, 0, 255, 0, 0);
        delay(70);
        drawEllipse(ball_x1, ball_y1, ball_x2, ball_y2, 0, 0, 0, 0, 0, 0);
        drawRectangle(bat_x1, bat_y1, bat_x2, bat_y2, 0, 0, 0, 0, 0, 0);
        char x = getKey();
        if (x == 'p' || x == 'P') //Pause
        {
            while (1)
            {
                char x = getKey();
                if (x == 'r' || x == 'R')
                {
                    break;
                }
            }
        }
        if (x == 's' || x == 'S')
        {
            sg_file.open("savedgame.txt", ios::out);
            sg_file << lives << " ";
            sg_file << score << " ";
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    sg_file << check[i][j] << " ";
                }
            }
            sg_file.close();
        }
        if (x == 'a' || x == 'A') {     //Movement to the left
            i -= 30;
        }
        if (x == 'd' || x == 'D') {     //Movement to the right
            i += 30;
        }
        if (x == 'q' || x == 'Q') {     //Game End
            lives = 0;
        }
        if (bat_x2 >= 1060)            //Not letting escape (right side)
        {
            i -= 30;
        }
        if (bat_x1 <= 215)             // Not letting escape (left side)
        {
            i += 30;
        }
        if (ball_x1 <= 230)            //Deflection from left side
        {
            i_e *= -1;
        }
        //BrickBreakingLoop
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {

                if (ball_x2 + 30 + i_e > brick_x[j] && ball_x2 + i_e < brick_x[j] + 120 && ball_y2 + 30 > brick_y[i] && ball_y2 < brick_y[i] + 30 && check[i][j]>0)
                {
                    if (check[i][j] == 2)
                    {
                        drawRectangle(brick_x[j], brick_y[i], brick_x[j] + 100, brick_y[i] + 30, 0, 0, 0, 255, 255, 255);
                        check[i][j] = 1;
                        i_e *= -1;
                        hits += 1;
                        score += 10;
                        gotoxy(50, 1);
                        cout << "Current Score: " << score;
                    }
                    else if (check[i][j] == 1)
                    {
                        score += 10;
                        drawRectangle(brick_x[j], brick_y[i], brick_x[j] + 100, brick_y[i] + 30, 0, 0, 0, 0, 0, 0);
                        check[i][j] = 0;
                        i_e *= -1;
                        score += 10;
                        gotoxy(50, 1);
                        cout << "Current Score: " << score;
                    }
                }
                if (ball_x2 + 30 > brick_x[j] && ball_x2 < brick_x[j] + 120 && ball_y2 + 30 + j_e > brick_y[i] && ball_y2 + j_e < brick_y[i] + 30 && check[i][j]>0)
                {
                    if (check[i][j] == 2)
                    {
                        score += 10;
                        hits += 1;
                        drawRectangle(brick_x[j], brick_y[i], brick_x[j] + 100, brick_y[i] + 30, 0, 0, 0, 255, 255, 255);
                        check[i][j] = 1;
                        j_e *= -1;
                        score += 10;
                        gotoxy(50, 1);
                        cout << "Current Score: " << score;
                    }
                    else if (check[i][j] == 1)
                    {
                        score += 10;
                        drawRectangle(brick_x[j], brick_y[i], brick_x[j] + 100, brick_y[i] + 30, 0, 0, 0, 0, 0, 0);
                        check[i][j] = 0;
                        j_e *= -1;
                        score += 10;
                        gotoxy(50, 1);
                        cout << "Current Score: " << score;
                    }
                }
                if (ball_y1 <= 80) //Top
                {
                    j_e *= -1;
                }
            }
        }
        if (ball_y1 <= 83) //Top
        {
            j_e *= -1;
        }
        if (ball_x2 > 1070) //right
        {
            i_e *= -1;
        }
        if (ball_x1 > bat_x1 - 100 && ball_x2 < bat_x1 + 250 && ball_y2 + j_e > bat_y1 + 6) //Bat Hit
        {
            int ball_middle = (ball_x2 + ball_x1) / 2;
            int bat_middle = (bat_x2 + bat_x1) / 2;
            if (ball_middle > bat_middle + 20 && ball_middle <= bat_x2)         //Right side
            {
                if (ball_middle >= bat_middle && ball_middle < bat_middle + 60) // Between bat middle and bat left side
                {
                    i_e = 15;
                    j_e *= -1;
                }
                else                                                            //Most right side of bat
                {
                    i_e = 45;
                    j_e *= -1;
                }
            }
            else if (ball_middle >= bat_middle - 20 && ball_middle <= bat_middle + 20) //MIDDLE STRAIGHT ONLY
            {

                i_e *= 0;
                j_e *= -1;

            }
            else if ((ball_middle >= bat_middle - 107 && ball_middle < bat_middle - 20)) // left side
            {
                if (ball_middle >= bat_x1 && ball_middle <= bat_middle - 53) // most left side
                {
                    i_e = 45;
                    i_e *= -1;
                    j_e *= -1;
                }
                else
                {
                    i_e = 15;
                    j_e = 25;
                    i_e *= -1;
                    j_e *= -1;
                }
            }
        }
        if (ball_y2 > 670) //bottom+score calculator for loser
        {
            ball_x1 = 597, ball_x2 = 620, ball_y1 = 497, ball_y2 = 520;
            j_e *= -1;
            lives--;
            if (lives == 2) {
                drawEllipse(950, 30, 980, 60, 0, 0, 0, 0, 0, 0);
            }
            if (lives == 1) {
                drawEllipse(1000, 30, 1030, 60, 0, 0, 0, 0, 0, 0);
            }
        }
        //CHECKING GAME ENDED OR NOT + SCORE CALCULATOR IF WON
        bool flag = false;
        for (int x = 0; x < 5 && flag == false; x++) {
            for (int y = 0; y < 9 && flag == false; y++) {
                if (check[x][y] == 0) {
                    flag = false;
                }
                else {
                    flag = true;
                }
            }
        }
        if (flag == false) {
            final = false;
        }
    }
    finalscore = ((score + (lives * 4)) - (hits * 2));
    score_array[5] = finalscore;
    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 6; j++)
        {
            if (score_array[i] < score_array[j])
            {
                int memory = score_array[j];
                score_array[j] = score_array[i];
                score_array[i] = memory;
            }
        }
    }
    score_file.open("highscore.txt", ios::out);
    for (i = 0; i < 5; i++)
    {
        score_file << score_array[i] << " ";
    }
    score_file.close();
    if (final == false || lives == 0) {
        cls();
        gotoxy(62, 10);
        if (lives == 0) {
            cout << "NOOB!";
        }
        else {
            cout << "KING!";
        }
        gotoxy(60, 12);
        if (lives == 0) {
            cout << "GAME OVER!";
        }
        else {
            cout << "YOU WON!";
        }
        gotoxy(61, 14);
        cout << "Hits: " << hits;
        gotoxy(57, 18);
        cout << "Lives Remaining: " << lives;
        gotoxy(51, 16);
        cout << "Bonus based on lives remaining: " << lives * 4;
        gotoxy(58, 20);
        if (score > 0)
            cout << "Final Score: " << score << endl;
        else
            cout << "Final Score: " << 0 << endl;
    }
    system("pause");
    return 0;
}