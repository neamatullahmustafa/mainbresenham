#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
int xs = 0 , ys = 0 , xe = 0 , ye = 0 ;
void bresenham(void)
{
    int dx = xe - xs , dy = ye - ys , x  , y , p = 2*abs(dy) - abs(dx) ;
    float m = dy / dx ;
    glClear ( GL_COLOR_BUFFER_BIT ) ;
    glBegin ( GL_POINTS ) ;
    glVertex2d ( x , y ) ;
    if ( abs ( m ) <= 1 )
   { x = xs ;
    y = ys ;
    if (dx>0)
        while ( x <= xe )
    {
       if ( p <= 0 )
       {
           x++;
           glVertex2i( x , y );
           p += 2*abs(dy) ;
       }
       else
       {
            x++;
        if (dy>0)
            y++;
        else
            y--;
           glVertex2i( x , y );
           p += (2*abs(dy) - 2*abs(dx));
       }
   }
   else
        while ( xe <= x )
    {
       if ( p <= 0 )
       {
           x--;
           glVertex2i( x , y );
           p += 2*abs(dy) ;
       }
       else
       {
            x--;
        if (dy>0)
            y++;
        else
            y--;
           glVertex2i( x , y );
           p += (2*abs(dy) - 2*abs(dx));
       }
   }
   }
   else
    { int s = xs;
    xs = ys;
    ys = s;
    s =xe;
    xe = ye;
    ye = s;
    dx = xe - xs ;
    dy = ye - ys;
    x = xs ;
    y = ys ;
   if (dx>0)
        while ( x <= xe )
    {
       if ( p <= 0 )
       {
           x++;
           glVertex2i( y , x  );
           p += 2*abs(dy) ;
       }
       else
       {
            x++;
        if (dy>0)
            y++;
        else
            y--;
           glVertex2i( y , x  );
           p += (2*abs(dy) - 2*abs(dx));
       }
   }
   else
        while ( xe <= x )
    {
       if ( p <= 0 )
       {
           x--;
           glVertex2i( y , x );
           p += 2*abs(dy) ;
       }
       else
       {
            x--;
        if (dy>0)
            y++;
        else
            y--;
           glVertex2i( y , x );
           p += (2*abs(dy) - 2*abs(dx));
       }
   }
   }
    glEnd ( ) ;
    glFlush ( ) ;
}
    void Init ( )
    {
    glClearColor ( 0.0 , 0.0 , 0.0 , 0 ) ;
    glColor3f ( 1.0 , 0.0 , 0.0 ) ;
    gluOrtho2D ( 0 , 500 , 0 , 500);
    }
int main ( int argc , char **argv )
{
    printf ( "draw line bresenham \n" ) ;
    printf ( "please enter start point \n" ) ;
    scanf ( "%f%f" , &xs , &ys ) ;
    printf ( "please enter end point \n" ) ;
    scanf ( "%f%f" , &xe , &ye ) ;
    glutInit (&argc , argv) ;
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB ) ;
    glutInitWindowPosition ( 0 , 0 ) ;
    glutInitWindowSize ( 500 , 500) ;
    glutCreateWindow ( " bresenham " ) ;
    Init ( ) ;
    glutDisplayFunc( bresenham ) ;
    glutMainLoop ( );
    return 0 ;
}
