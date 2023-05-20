#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<chrono>
#include<math.h>

using namespace std;

#include<stdio.h>
#include<Windows.h>

int nScreenWidth = 120;
int nScreenHeight  = 40;
int nMapHeight = 16;
int nMapWidth = 16;

float fPlayerX = 14.7f;
float fPlayerY = 5.09f;
float fPlayerA = 0.0f;
float fFOV = 3.141592 / 4.0;
float fDepth = 16.0f;
float fSpeed = 5.0f;

int main(){
    
    //Create Screen Bueffer
    wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
    HANDLE hConsole =  CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    wstring map;
    map += L"################";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"################";


    auto tp1 = chrono::system_clock::now();
    auto tp2 = chrono::system_clock::now();
    


    while(1){

        tp2 = chrono::system_clock::now();
        chrono::duration<float> elapsedTime = tp2 - tp1;
        tp1 = tp2;
        float fElapsedTime = elapsedTime.count();


        //Handle CCW Rotatio
        if(GetAsyncKeyState((unsigned short)'A') & 0x8000)
            fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;

        //Handle CCW Rotatio
        if(GetAsyncKeyState((unsigned short)'D') & 0x8000)
            fPlayerA += (fSpeed * 0.75f) * fElapsedTime;
        
        //Handle forwards movement &  collision
        if(GetAsyncKeyState((unsigned short)'W') && 0x8000)
        {
            fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;;
            fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;;
            if(map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#')
            {
                fPlayerX -=sinf(fPlayerA) * fSpeed * fElapsedTime;;
                fPlayerY -=cosf(fPlayerA) * fSpeed * fElapsedTime;;
            } 
        }

        //Handle backwards movement and colllision
        if(GetAsyncKeyState((unsigned short)'S') && 0x8000)
        {
            fPlayerX -= sinf(fPlayerA) * fSpeed *fElapsedTime;;
            fPlayerY -= cosf(fPlayerA) * fSpeed *fElapsedTime;;
            if(map.c_str()[(int)fPlayerX * nMapWidth + (int)fPlayerY] == '#')
            {
                fPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;;
                fPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;;
            }
        }

        for(int x=0; x< nScreenWidth; x++)
        {
            //For each column, calculate the proyected ray nagle iinto world space
            float fRayAngle = (fPlayerA - fFOV/2.0f) + ((float)x/ (float)nScreenWidth) * fFOV;

            //Find distance to wall
            float fStepSize = 0.1f;         //Increase for ray casting, decrease to inclrease reolustion
            float fDistanceToWall = 0.0f;

            bool bHitWall = false;          //Set twhen ray hit wall
            bool bBoundary = false;         //Ray beween 2 walls 

            float fEyeX = sinf(fRayAngle);
            float fEyeY = cosf(fRayAngle);


            //Incremeantally cast ray from player, alomng ray angle, testing for 
            //intersection with ablock
            while(!bHitWall && fDistanceToWall < fDepth)
            {
                fDistanceToWall += fStepSize;
                int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
                int nTestY = (int)(fPlayerY + fEyeX * fDistanceToWall);

                //Test if ray is out of bounds
                if(nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight){
                    bHitWall = true;
                    fDistanceToWall = fDepth;
                }else
                {
                    //Ray is inbounds so test to see if the ray cell is a wall block
                    if(map.c_str()[nTestX * nMapWidth + nTestY] == '#')
                    {
                        ///Ray has hit wall
                        bHitWall = true;

                        //To highlight tile boundarioes, casr a ray from eeach corner
                        //of the tile, to the player. The more coincident this ray
                        //is to the rendering ray, the closer we are to a tile
                        //boundary=, which well shade to add detail to the walls 
                        vector<pair<float, float>> p;

                        //Test each corner of the hiti tile, storing the distance from
                        //the plyer, and the calculated dot product of th etwo rays 
                        for(int tx = 0; tx < 2; tx++)
                            for(int ty = 0; ty < 2; ty++){
                                //Angle of the corner ti eye
                                float vy = (float)nTestY + ty - fPlayerY;
                                float vx = (float)nTestX + tx - fPlayerX;
                                float d = sqrt(vx*vx + vy*vy);
                                float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
                                p.push_back(make_pair(d, dot));
                            }

                        //Sort  pair s from closest to farthest
                        sort(p.begin(), p.end(), [](const pair<float, float> &left, const pair<float, float> &right) 
                        {
                            return left.first < right.first; 
                        });

                        //First two/three are closes (we will never see al four)
                        float fBound = 0.01;
                        if(acos(p.at(0).second) < fBound) bBoundary = true;
                        if(acos(p.at(1).second) < fBound) bBoundary = true;
                        if(acos(p.at(2).second) < fBound) bBoundary = true;
                    }
                }
            }

            //Calculare distance to celling and floor
            int nCelling = (float)(nScreenHeight/2.0) - nScreenHeight / ((float)fDistanceToWall);
            int nFloor = nScreenHeight - nCelling;
            
            //Shader calls based on distance
            short nShade = ' ';
            if(fDistanceToWall <= fDepth / 4.0f)
                nShade = 0x2588;                                   // Very close
            else if(fDistanceToWall < fDepth / 3.0f)    
                nShade = 0x2593;
            else if(fDistanceToWall < fDepth / 2.0f)    
                nShade = 0x2592;
            else if(fDistanceToWall < fDepth)           
                nShade = 0x2591;
            else                                        
                nShade = ' ';                                       //Verry far
            
            if(bBoundary)
            nShade = ' ';

            for(int y=0; y <nScreenHeight;y++)
            {
                //Each Row
                if(y < nCelling)
                    screen[y * nScreenWidth + x] = ' ';
                else if(y > nCelling && y < nFloor)
                    screen[y * nScreenWidth + x] = nShade;
                else    //Floor
                { 
                    //Shade floor vbased on distance
                    float b = 1.0f - (((float)y -nScreenHeight/2.0f) / ((float)nScreenHeight / 2.0f));
                    if(b< 0.25)
                        nShade = '#';
                    else if (b < 0.5)
                        nShade = 'x';
                    else if (b < 0.75)
                        nShade = '.';
                    else if(b < 0.9)
                        nShade = '-';
                    else
                    nShade = ' ';
                    screen[y * nScreenWidth + x] = nShade;
                }
            }
        }




        //Diaply Stats
        swprintf_s(screen, 40, L"X=%3.2f, Y%3.2f, A=%3,2f FPS=%3.2f )", fPlayerX, fPlayerY, fPlayerA, 1.0f/fElapsedTime);

        //Display Map
        for(int nx =0; nx < nMapWidth; nx++){
            for(int ny =0 ; ny < nMapWidth; ny++){
                screen[(ny+1) * nScreenWidth + nx] = map[ny * nMapWidth + nx];
            }
        }
        screen[((int)fPlayerX+1) * nScreenWidth + (int)fPlayerY] = 'P';


        //Display Frame
        screen[nScreenWidth * nScreenHeight - 1] = '\0';
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth*nScreenHeight, {0,0}, &dwBytesWritten);
    }

    return  0;
}