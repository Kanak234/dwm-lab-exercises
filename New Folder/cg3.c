/*   

                                                        Bresenham's Line Drawing Algorithm
1)Faster execution 
2)No floating  point b/w required 
3) ideal for  real time  applications

step 1 scope (m)
 m = (/_| y) / ( /_| x) (y2 - y1) / (x2 - x1)
2Decision parameter (p) =2dy - dx
                             m<1
                       p<o                 p>=0      
                 xi+1 = xi +1            xi+1 = xi +1
                 yi+1 = yi              yi+1 = yi + 1
                 (no change in y)       p1 = p0 * 2dy -2dx
                 p1= p0 + 2dy

                               m>=1
                       p<o                 p>=0
                 xi+1 = xi              xi+1 = xi + 1
                 yi+1 = yi + 1          yi+1 = yi + 1
                 (no change in x)       p1 = p0 * 2dy -2dx
                 p1= p0 + 2dy - 2dx     

2 deision parameter (p) = 2dx - dy
   p1(8,5),p2(12,8 )
   m= (y2-y1)/(x2-x1) = (8-5)/(12-8) = 3/4 = 0.75 < 1
   p= 3*2-4
   = 6-4
   = 2
                p     x1    y1  xi+1 yi+1
                2     8     5    9    6
                0     9     6   10    7
                -2    10    7   11    7
                4     11    7   12    8

                2+2*3-2*4
                2+6-8
                8-8 =2
                ==> 0+2*3-2*4
                0+6-8
                =2


*/