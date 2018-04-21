#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define box_x 500.
#define label_space 150.
#define box_y 300.
#define g 9.8
static float dt=0.0008;

//sf::RenderWindow window;

double xspace_i;
double xspace_f;
double yspace_i;
double yspace_f;


// Initial states, R is the radius.
// beta: the fraction of energy loss on every bounce.
// alpha: fraction of energy loss per unit time
double yi,xi,vxi,vyi,beta,alpha,R;

double transform_y(double var)
{
    return -var+box_y-2*R;
}


#include "Ball.h"


int main(int argc, char *argv[])
{
    cout << "\nInelastic Single-Ball-Box Simulation" << endl;

/*
    // Read parameters
    if(argv[1]=="-i")
    {
        cout << "Input radius (in pixels)\t";
        cin >> R;

        xspace_i=0;
        xspace_f=box_x-2*R;
        yspace_i=0;
        yspace_f=box_y-2*R;

        cout << "Input x0: (" << xspace_i << " to " << xspace_f << ")\t" ;
        cin >> xi;
        if( (xi<xspace_i) || (xi>xspace_f) ){cout << "Invalid input." << endl; return 1;}

        cout << "Input y0: (" << yspace_i << " to " << yspace_f << ")\t" ;
        cin >> yi;
        if( (yi<yspace_i) || (yi>yspace_f) ){cout << "Invalid input." << endl; return 1;}

        cout << "Input vx0:\t";
        cin >> vxi;

        cout << "Input vy0:\t";
        cin >> vyi;

        cout << "Input bounce coefficient:\t";
        cin >> beta;

        cout << "Input viscocity coefficient:\t";
        cin >> alpha;
    }
    else
    {*/
        R=20.;xi=10.;yi=50.;vxi=50.;vyi=40.;beta=0.8;alpha=1;
        xspace_i=0;
        xspace_f=box_x-2*R-label_space;
        yspace_i=0;
        yspace_f=box_y-2*R;
    //}

    Ball ball(xi,yi,vxi,vyi,R);

    //Display


    sf::RenderWindow window(sf::VideoMode(box_x, box_y), "Holololo");


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }



        //window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);

        window.clear();

        for(int i=0;i<250;i++)
        {
            ball.update(); // 200 steps every time
        }
        //cout << ball.vy << endl;
        window.draw(ball);

        window.display();
    }

    return 0;
}
