class Ball : public sf::Drawable
{
    public:
        float x,y,vx,vy,mass;

        sf::CircleShape marker;

        Ball( float x0, float y0, float vx0, float vy0, float mass_arg)
        {
            x=x0; y=y0;
            vy=vy0; vx=vx0;
            marker=sf::CircleShape(mass_arg);
        }

        void move(void)
        {
            vy+=-g*dt;
            vy*=alpha;
            y+=vy*dt;
            vx*=alpha;
            x+=vx*dt;
        }
        void bounce(void)
        {
            if(y<=yspace_i)
            {
                y=yspace_i;
                vy*=-beta;
                vx*=beta;
            }
            if(y>=yspace_f)
            {
                y=yspace_f;
                vy*=-beta;
            }
            if(x<=xspace_i)
            {
                x=xspace_i;
                vx*=-beta;
            }
            if(x>=xspace_f)
            {
                x=xspace_f;
                vx*=-beta;
            }
        }
        void update(void)
        {
            move();
            bounce();
            marker.setPosition( x , transform_y(y) );
        }
    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates state) const
        {
            target.draw(marker);
        }
};
