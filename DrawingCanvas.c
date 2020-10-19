#include<stdio.h>
#include<math.h>
typedef struct Point{
	double xc;
	double yc;
}Point;
typedef struct Line{
	Point point1;
	Point point2;
}Line;
typedef struct Triangle{
	Point point1;
	Point point2;
	Point point3;
}Triangle;
typedef struct Circle{
	Point center;
	double radius;
}Circle;
double dist(Point p1,Point p2)
{
	double d;
	d=sqrt(pow((p1.xc-p2.xc),2)+pow((p1.yc-p2.yc),2));
	return d;
}
double smaller(double x,double y)
{
	if(x<y)
		return x;
	return y;
}
double larger(double x,double y)
{
	if(x>y)
		return x;
	return y;
}
int pointcircle(Point p,Circle c)
{
	if(dist(p,c.center)==c.radius)
                return 1;
        return 0;
}
int pointpoint(Point p1,Point p2)
{
	if(p1.xc==p2.xc && p1.yc==p2.yc)
		return 1;
	return 0;
}
int pointline(Point p,Line l)
{
	if(l.point1.xc==l.point2.xc && l.point1.yc==l.point2.yc)
	{
		Point p1;
		return pointpoint(p,p1);
	}
	if(p.xc<smaller(l.point1.xc,l.point2.xc)||p.xc>larger(l.point1.xc,l.point2.xc)||p.yc<smaller(l.point1.yc,l.point2.yc)||p.yc>larger(l.point1.yc,l.point2.yc))
			{
			return 0;
			}
			if((p.xc==l.point1.xc && p.yc==l.point1.yc)||(p.xc==l.point2.xc && p.yc==l.point2.yc))
			{
				return 1;
			}
			if(l.point1.xc==l.point2.xc)
			{
				return 1;
			}
			if((l.point2.yc-l.point1.yc)/(l.point2.xc-l.point1.xc)==(l.point2.yc-p.yc)/(l.point2.xc-p.xc))
			{
				return 1;
			}
			return 0;		
}
int pointtriangle(Point p,Triangle t)
{
	Line l1,l2,l3;
	l1.point1.xc=t.point1.xc;
	l1.point1.yc=t.point1.yc;
	
	l1.point2.xc=t.point2.xc;
        l1.point2.yc=t.point2.yc;
	
	l2.point1.xc=t.point2.xc;
        l2.point1.yc=t.point2.yc;
	
	l2.point2.xc=t.point3.xc;
        l2.point2.yc=t.point3.yc;
	
	l3.point1.xc=t.point3.xc;
        l3.point1.yc=t.point3.yc;
	
	l3.point2.xc=t.point1.xc;
        l3.point2.yc=t.point1.yc;

	if(pointline(p,l1)||pointline(p,l2)||pointline(p,l3))
		return 1;
	return 0;	
}
int lineline(Line l1,Line l2)
{
	if(l1.point1.xc==l1.point2.xc && l1.point1.yc==l1.point2.yc && l2.point1.xc==l2.point2.xc && l2.point1.yc==l2.point2.yc)
	{
		Point p1,p2;
		p1.xc=l1.point1.xc;
		p1.yc=l1.point1.yc;
		p2.xc=l2.point2.xc;
		p2.yc=l2.point2.yc;
		return pointpoint(p1,p2);
	}
	if(l1.point1.xc==l1.point2.xc && l1.point1.yc==l1.point2.yc)
	{
		Point p;
		p.xc=l1.point1.xc;
                p.yc=l1.point1.yc;
		return pointline(p,l2);
	}
	if(l2.point1.xc==l2.point2.xc && l2.point1.yc==l2.point2.yc)
        {
                Point p;
                p.xc=l2.point1.xc;
                p.yc=l2.point1.yc;
                return pointline(p,l1);
        }
	if(l1.point1.xc==l1.point2.xc && l2.point1.xc==l2.point2.xc)
	{
		if(l1.point1.xc!=l2.point1.xc)
		{
			return 0;
		}
		if(l1.point1.xc==l2.point1.xc)
		{
			if(smaller(l1.point1.yc,l1.point2.yc)>larger(l2.point1.yc,l2.point2.yc) || smaller(l2.point1.yc,l2.point2.yc)>larger(l1.point1.yc,l1.point2.yc))
			{
				return 0;
			}
			return 1;
		}
	}
	double x,y,m,c;
	if(l1.point1.xc==l1.point2.xc)
	{
		m=(l2.point2.yc-l2.point1.yc)/(l2.point2.xc-l2.point1.xc);
		c=l2.point2.yc-(m*l2.point2.xc);
		x=l1.point1.xc;
		y=(m*x)+c;
		if(x<=larger(l2.point2.xc,l2.point1.xc) && x>=smaller(l2.point2.xc,l2.point1.xc) && y<=larger(l2.point2.yc,l2.point1.yc) && y>=smaller(l2.point2.yc,l2.point1.yc) && y<=larger(l1.point2.yc,l1.point1.yc) && y>=smaller(l1.point2.yc,l1.point1.yc))
		{
			return 1;
		}
	}	
 	if(l2.point1.xc==l2.point2.xc)
        {
                m=(l1.point2.yc-l1.point1.yc)/(l1.point2.xc-l1.point1.xc);
                c=l1.point2.yc-(m*l1.point2.xc);
                x=l2.point1.xc;
                y=(m*x)+c;
                if(x<=larger(l1.point2.xc,l1.point1.xc) && x>=smaller(l1.point2.xc,l1.point1.xc) && y<=larger(l1.point2.yc,l1.point1.yc) && y>=smaller(l1.point2.yc,l1.point1.yc) && y<=larger(l2.point2.yc,l2.point1.yc) && y>=smaller(l2.point2.yc,l2.point1.yc))  
                {
                        return 1;
                }
        }
	else
	{
		double m1,m2,c1,c2;
		m1=(l1.point2.yc-l1.point1.yc)/(l1.point2.xc-l1.point1.xc);
		m2=(l2.point2.yc-l2.point1.yc)/(l2.point2.xc-l2.point1.xc);
		if(m1!=m2)
		{
			 c1=l1.point2.yc-(m1*l1.point2.xc);
			 c2=l2.point2.yc-(m2*l2.point2.xc);
			 x=(c2-c1)/(m1-m2);
			 y=(m1*x)+c1;
			 if(x<=larger(l1.point2.xc,l1.point1.xc) && x>=smaller(l1.point2.xc,l1.point1.xc) && y<=larger(l1.point2.yc,l1.point1.yc) && y>=smaller(l1.point2.yc,l1.point1.yc) && x<=larger(l2.point2.xc,l2.point1.xc) && x>=smaller(l2.point2.xc,l2.point1.xc) && y<=larger(l2.point2.yc,l2.point1.yc) && y>=smaller(l2.point2.yc,l2.point1.yc))
			 {
				 return 1;
			 }
			 return 0;
		}
		if(m1==m2)
		{
			if(m1==0)
			{
				if(l1.point1.yc!=l2.point1.yc)
                		{
                        		return 0;
                		}
                		if(l1.point1.yc==l2.point1.yc)
                		{
                        		if(smaller(l1.point1.xc,l1.point2.xc)>larger(l2.point1.xc,l2.point2.xc) || smaller(l2.point1.xc,l2.point2.xc)>larger(l1.point1.xc,l1.point2.xc))
                        		{
                                		return 0;
                        		}
                			return 1;
                		}

			}
			else
			{
				if(pointline(l1.point1,l2) || pointline(l1.point2,l2) || pointline(l2.point1,l1) || pointline(l2.point2,l1))
					return 1;
				return 0;
			}	
		}
	}
}
int linetriangle(Line l,Triangle t)
{
        Line l1,l2,l3;
        l1.point1.xc=t.point1.xc;
        l1.point1.yc=t.point1.yc;

        l1.point2.xc=t.point2.xc;
        l1.point2.yc=t.point2.yc;

        l2.point1.xc=t.point2.xc;
        l2.point1.yc=t.point2.yc;

        l2.point2.xc=t.point3.xc;
        l2.point2.yc=t.point3.yc;

        l3.point1.xc=t.point3.xc;
        l3.point1.yc=t.point3.yc;

        l3.point2.xc=t.point1.xc;
        l3.point2.yc=t.point1.yc;

        if(lineline(l,l1)||lineline(l,l2)||lineline(l,l3))
                return 1;
        return 0;

}
int linecircle(Line l,Circle c)
{
	if(l.point1.xc==l.point2.xc && l.point1.yc==l.point2.yc && c.radius==0)
	{
		return pointpoint(l.point1,c.center);
	}
	if(l.point1.xc==l.point2.xc && l.point1.yc==l.point2.yc)
	{
		return pointcircle(l.point1,c); 
	}
	if(c.radius==0)
	{
		return pointline(c.center,l);
	}
	if(dist(l.point1,c.center)<=c.radius || dist(l.point2,c.center)<=c.radius)
	{
		return 1;
	}
	else
	{
	double x,y;
	if(l.point1.xc==l.point2.xc)
	{
		x=l.point1.xc;
		y=c.center.yc;
		if(y>=smaller(l.point1.yc,l.point2.yc) && y<=larger(l.point1.yc,l.point2.yc))
		{
			if(c.center.xc>=l.point1.xc)
			{
				if(c.center.xc-l.point1.xc<=c.radius)
				{
					return 1;
				}
				return 0;
			}
			else
			{
				if(l.point1.xc-c.center.xc<=c.radius)
				{
					return 1;
				}
				return 0;
			}
		}
		return 0;
	}
	if(l.point1.yc==l.point2.yc)
        {
                x=c.center.xc;
                y=l.point1.yc;
                if(x>=smaller(l.point1.xc,l.point2.xc) && x<=larger(l.point1.xc,l.point2.xc))
                {
                        if(c.center.yc>=l.point1.yc)
                        {
                                if(c.center.yc-l.point1.yc<=c.radius)
                                {
                                        return 1;
                                }
                                return 0;
                        }
                        else
                        {
                                if(l.point1.yc-c.center.yc<=c.radius)
                                {
                                        return 1;
                                }
                                return 0;
                        }
                }
                return 0;
        }
	double m=(l.point2.yc-l.point1.yc)/(l.point2.xc-l.point1.xc);
	double c2=l.point1.yc-(m*l.point1.xc);
	x=c.center.xc-((m*(m*c.center.xc-c.center.yc+c2))/(m*m+1));
	y=c.center.yc+((m*c.center.xc-c.center.yc+c2)/(m*m+1));
	Point foot;
	foot.xc=x;
	foot.yc=y;
	if(x>=smaller(l.point1.xc,l.point2.xc) && x<=larger(l.point1.xc,l.point2.xc) && y>=smaller(l.point1.yc,l.point2.yc) && y<=larger(l.point1.yc,l.point2.yc))
	{
		if(dist(c.center,foot)<=c.radius)
		{
			return 1;
		}
		return 0;
	}	
	return 0;
	}
}
int triangletriangle(Triangle t1,Triangle t2)
{
	Line l1,l2,l3;
        l1.point1.xc=t1.point1.xc;
        l1.point1.yc=t1.point1.yc;

        l1.point2.xc=t1.point2.xc;
        l1.point2.yc=t1.point2.yc;

        l2.point1.xc=t1.point2.xc;
        l2.point1.yc=t1.point2.yc;

        l2.point2.xc=t1.point3.xc;
        l2.point2.yc=t1.point3.yc;

        l3.point1.xc=t1.point3.xc;
        l3.point1.yc=t1.point3.yc;

        l3.point2.xc=t1.point1.xc;
        l3.point2.yc=t1.point1.yc;

        if(linetriangle(l1,t2)||linetriangle(l2,t2)||linetriangle(l3,t2))
                return 1;
        return 0;

}
int circletriangle(Circle c,Triangle t)
{
	Line l1,l2,l3;
        l1.point1.xc=t.point1.xc;
        l1.point1.yc=t.point1.yc;

        l1.point2.xc=t.point2.xc;
        l1.point2.yc=t.point2.yc;

        l2.point1.xc=t.point2.xc;
        l2.point1.yc=t.point2.yc;

        l2.point2.xc=t.point3.xc;
        l2.point2.yc=t.point3.yc;

        l3.point1.xc=t.point3.xc;
        l3.point1.yc=t.point3.yc;

        l3.point2.xc=t.point1.xc;
        l3.point2.yc=t.point1.yc;

        if(linecircle(l1,c)||linecircle(l2,c)||linecircle(l3,c))
                return 1;
        return 0;

}
int circlecircle(Circle c1,Circle c2)
{
	if(c1.radius>c2.radius)
	{
		if(dist(c1.center,c2.center)>(c1.radius+c2.radius) || dist(c1.center,c2.center)<(c1.radius-c2.radius))
			return 0;
		return 1;
	}
	else
	{
		if(dist(c1.center,c2.center)>(c1.radius+c2.radius) || dist(c1.center,c2.center)<(c2.radius-c1.radius))
			return 0;
		return 1;
	}

}
int main()
{
	int r;
	Point p1,p2;
	Line l1,l2;
	Triangle t1,t2;
	Circle c1,c2;
	char figure1;
	scanf("%c",&figure1);
	if(figure1=='C')
	{
		scanf("%lf%lf%lf",&c1.center.xc,&c1.center.yc,&c1.radius);
	}
	if(figure1=='T')
	{
		scanf("%lf%lf%lf%lf%lf%lf",&t1.point1.xc,&t1.point1.yc,&t1.point2.xc,&t1.point2.yc,&t1.point3.xc,&t1.point3.yc);
	}
	if(figure1=='L')
	{
		scanf("%lf%lf%lf%lf",&l1.point1.xc,&l1.point1.yc,&l1.point2.xc,&l1.point2.yc);
	}
	if(figure1=='P')
	{
		scanf("%lf%lf",&p1.xc,&p1.yc);
	}
	char figure2;
        scanf(" %c",&figure2);
        if(figure2=='C')
        {
                scanf("%lf%lf%lf",&c2.center.xc,&c2.center.yc,&c2.radius);
        }
        if(figure2=='T')
        {
                scanf("%lf%lf%lf%lf%lf%lf",&t2.point1.xc,&t2.point1.yc,&t2.point2.xc,&t2.point2.yc,&t2.point3.xc,&t2.point3.yc);
        }
        if(figure2=='L')
        {
                scanf("%lf%lf%lf%lf",&l2.point1.xc,&l2.point1.yc,&l2.point2.xc,&l2.point2.yc);
        }
        if(figure2=='P')
        {
                scanf("%lf%lf",&p2.xc,&p2.yc);
        }
	if(figure1=='P' && figure2=='P')
	{
		r=pointpoint(p1,p2);
	}
	if(figure1=='L' && figure2=='L')
        {
                r=lineline(l1,l2);
        }
	if(figure1=='T' && figure2=='T')
        {
                r=triangletriangle(t1,t2);
        }
        if(figure1=='C' && figure2=='C')
        {
                r=circlecircle(c1,c2);
        }
	if((figure1=='P' && figure2=='L'))
        {
                r=pointline(p1,l2);
        }
	if((figure1=='L' && figure2=='P'))
        {
                r=pointline(p2,l1);
        }
	if((figure1=='C' && figure2=='P'))
        {
                r=pointcircle(p2,c1);
        }
	if((figure1=='P' && figure2=='C'))
        {
                r=pointcircle(p1,c2);
        }
	if((figure1=='T' && figure2=='P'))
        {
                r=pointtriangle(p2,t1);
        }
        if((figure1=='P' && figure2=='T'))
        {
                r=pointtriangle(p1,t2);
        }
	if((figure1=='T' && figure2=='L'))
        {
                r=linetriangle(l2,t1);
        }
        if((figure1=='L' && figure2=='T'))
        {
                r=linetriangle(l1,t2);
        }
	if((figure1=='C' && figure2=='L'))
        {
                r=linecircle(l2,c1);
        }
        if((figure1=='L' && figure2=='C'))
        {
                r=linecircle(l1,c2);
        }
	if((figure1=='C' && figure2=='T'))
        {
                r=circletriangle(c1,t2);
        }
        if((figure1=='T' && figure2=='C'))
        {
                r=circletriangle(c2,t1);
        }
	if(r==1)
	{
		printf("The primitives intersect.\n");
	}
	if(r==0)
	{
		printf("The primitives do not intersect.\n");
	}
	return 0;
}
