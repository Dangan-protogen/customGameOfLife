#include <SFML/Graphics.hpp>



//taille de la fenetre



#define TAILLE_X 800

#define TAILLE_Y 800



#define RESOLUTION 32



//resolution de la grille

//Nombre de case pour l'ensemble de la fenetre

// donc si la resolution fait 8 la fenetre fait 8*8 donc 64







void nouvelleGeneration(bool cellule[RESOLUTION][RESOLUTION])

{

    int nbCelluleVivantes = 0;



    bool ancienneGen[RESOLUTION][RESOLUTION];

    for(int x = 0; x < RESOLUTION;x++)

    {

        for(int y = 0; y < RESOLUTION;y++)

        {

            ancienneGen[x][y] = cellule[x][y];

        }

    }



    //si en dehors du tableau alors 



    for(int x = 0; x < RESOLUTION;x++)

    {

        for(int y = 0; y < RESOLUTION;y++)

        {   

            

            /*if(x == 1 && y == 1){

                if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y+1]) nbCelluleVivantes++;

            }else{

            if(x == 1 && y != RESOLUTION){

                if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y-1]) nbCelluleVivantes++;

                

            }else{

            if(x == 1 && y == RESOLUTION){

                //if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y]) nbCelluleVivantes++;

                //if(ancienneGen[x-1][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y-1]) nbCelluleVivantes++;

            }else{

            if(x != RESOLUTION && y == 1){

                if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x+1][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y]) nbCelluleVivantes++;

            }else{

            if(x == RESOLUTION && y == 1){

                //if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x+1][y+1]) nbCelluleVivantes++;

                //if(ancienneGen[x-1][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x+1][y]) nbCelluleVivantes++;

            }else{

            if(x == RESOLUTION && y == RESOLUTION){

                //if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x+1][y-1]) nbCelluleVivantes++;

                //if(ancienneGen[x-1][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x+1][y]) nbCelluleVivantes++;

            }else{

                if(ancienneGen[x+1][y]) nbCelluleVivantes++;

                if(ancienneGen[x+1][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x+1][y-1]) nbCelluleVivantes++;

                if(ancienneGen[x][y]) nbCelluleVivantes++;

                if(ancienneGen[x][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x][y-1]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y+1]) nbCelluleVivantes++;

                if(ancienneGen[x-1][y-1]) nbCelluleVivantes++;

            }}}}}}*/

            if(ancienneGen[x+1][y] == true) nbCelluleVivantes++;

            if(ancienneGen[x+1][y+1]== true) nbCelluleVivantes++;

            if(ancienneGen[x+1][y-1]== true) nbCelluleVivantes++;

            //if(ancienneGen[x][y]) nbCelluleVivantes++;

            if(ancienneGen[x][y+1]== true) nbCelluleVivantes++;

            if(ancienneGen[x][y-1]== true) nbCelluleVivantes++;

            if(ancienneGen[x-1][y]== true) nbCelluleVivantes++;

            if(ancienneGen[x-1][y+1]== true) nbCelluleVivantes++;

            if(ancienneGen[x-1][y-1]== true) nbCelluleVivantes++;

            



            if(nbCelluleVivantes == 3) cellule[x][y] = true;

            //if(nbCelluleVivantes == 2) //--//;

            if(nbCelluleVivantes < 2 ) cellule[x][y] = false;

            if(nbCelluleVivantes > 3 ) cellule[x][y] = false;



            nbCelluleVivantes = 0;

        }

    }



    

}



int main()

{

    

    float n = TAILLE_X / RESOLUTION;    

    int nombreGen = 0;

    //tableau qui contient les cellules

    //faux = mort

    //vrai = vivant



    bool tabCellule[RESOLUTION][RESOLUTION];



    //tout le monde est dead :c



    for(int x = 0; x < RESOLUTION;x++)

    {

        for(int y = 0; y < RESOLUTION;y++)

        {

            tabCellule[x][y] = 0;

        }

    }



    tabCellule[20][10] = true;

    tabCellule[20][11] = true;

    tabCellule[20][12] = true;

    /*tabCellule[21][10] = true;

    tabCellule[23][11] = true;

    tabCellule[26][12] = true;*/



    tabCellule[10][10] = true;

    tabCellule[10][11] = true;

    tabCellule[10][12] = true;



    // create the window

    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    

    //différente forme utilisé

    //sf::CircleShape shape(50.f);

    sf::RectangleShape rectangle(sf::Vector2f(2.f, 800.f));

    sf::RectangleShape rectangle2(sf::Vector2f(2.f, 800.f));



    sf::RectangleShape cellule(sf::Vector2f(n,n));    

        

    rectangle2.setRotation(-90.f);



    



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



        // clear the window with black color

        window.clear(sf::Color::Black);



        // draw everything here...

        // window.draw(...);



        for(int i = 0; i<RESOLUTION;i++)

        {

            //(TAILLE_X/RESOLUTION) = n

            //O -> RESOLUTION*n de n en n

            //a chaque fois on trace un trait qui part de 0,i*n a 800,i*n

            //et un trait de i*n,0 a i*n 800

            

            rectangle.setPosition(i*n,0 );

            window.draw(rectangle);

            rectangle2.setPosition(0,i*n);

            window.draw(rectangle2);

            

        

        }

        

        if(nombreGen != 0)nouvelleGeneration(tabCellule);

        nombreGen++;





        for(int x = 0; x < RESOLUTION;x++)

        {

            for(int y = 0; y < RESOLUTION;y++)

            {

                if(tabCellule[x][y] == true){

                    //positionner rectangle a x*n et y*n

                    //puis dessiner rectangle



                    cellule.setPosition(x*n,y*n);

                    window.draw(cellule);                                

                }

            }

        }



        //rectangle2.setPosition(100,100);

        //window.draw(rectangle2);

        //shape.setPosition(100.f, 50.f);

        //shape.move(1.f, 1.f);



        // set the shape color to green

        //shape.setFillColor(sf::Color(100, 250, 50));

        //window.draw(shape);

        //shape.move(100.f, 100.f);

        //shape.setPosition(300.f, 50.f);

        //window.draw(shape);

        //dessine_grille(window,rectangle);

        // end the current frame

        

        window.display();

        sf::sleep(sf::seconds(1));

    }

    return 0;

}