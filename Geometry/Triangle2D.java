/*
 *               ****  Geometry: the Triangle2D class   ****
 *
 * # Three points named p1, p2, and p3 of the type MyPoint with getter and
 *   setter methods. 
 * # A no-arg constructor that creates a default triangle with the points
 *   (0, 0), (1,1), and (2, 5).
 * # A constructor that creates a triangle with the specified points.
 * # A method getArea() that returns the area of the triangle.
 * # A method getPerimeter() that returns the perimeter of the triangle.
 * # A method contains(MyPoint p) that returns true if the specified point
 *   p is inside this triangle.
 * # A method contains(Triangle2D t) that returns true if the specified
 *   triangle is inside this triangle.
 * # A method overlaps(Triangle2D t) that returns true if the specified
 *   triangle overlaps with this triangle
*/

import java.sidpro.*;

class Triangle2D{
	

	public static void main(String []args){
		Triangle2D t1= new Triangle2D(new MyPoint(2, 1), new MyPoint(5, 2),new MyPoint(3, 4));
		boolean take= t1.contains(new Triangle2D(new MyPoint(3, 2), new MyPoint(4, 2), new MyPoint(3.5, 2.5)));
		System.out.println("Triangle is inside? "+take);
		System.out.println("Area of triangle: "+t1.getArea());
		System.out.println("Perimeter of Triangle: "+t1.getPerimeter());
		System.out.println("triangle contains 3,2 ?:"+t1.contains(new MyPoint(3,2)));
		take = t1.overlaps(new Triangle2D(new MyPoint(6, 6), new MyPoint(14, 12), new MyPoint(8, 8)));
		System.out.println("triangle overlaps? :"+take);
	}
	
	private MyPoint p1;
	private MyPoint p2;
	private MyPoint p3;

	Triangle2D(){
		p1 = new MyPoint(0,0);
		p2 = new MyPoint(1,1);
		p3 = new MyPoint(2,5);
	}
	Triangle2D(MyPoint p1,MyPoint p2,MyPoint p3){
		this.p1 = p1;
		this.p2 = p2;
		this.p3 = p3;
	}
	
	double getPerimeter(){
		double s1,s2,s3;
		s1 = p1.distance(p2);
		s2 = p2.distance(p3);
		s3 = p3.distance(p1);

		return (s1+s2+s3);
	}
	double getArea(){
		//here we can use Heron's formula too.
		// but we are useing coordinates, 
		double x1=p1.getX(),x2=p2.getX(),x3=p3.getX(),y1=p1.getY(),y2=p2.getY(),y3=p3.getY();
		double area = Math.abs( (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2 );
		
		return area;
	}
	double getArea(MyPoint p1,MyPoint p2,MyPoint p3){
		double x1=p1.getX(),x2=p2.getX(),x3=p3.getX(),y1=p1.getY(),y2=p2.getY(),y3=p3.getY();
		double area = Math.abs( (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2 );
		return area;
	}
	boolean ccw(MyPoint A,MyPoint B,MyPoint C){
		return ((C.getY() - A.getY())*(B.getX() - A.getX()) > (B.getY() - A.getY())*(C.getX() - A.getX()));
	}
	boolean interSect(MyPoint A,MyPoint B,MyPoint C,MyPoint D){
		//we can find interSecting point by Cramer's rule
		return (ccw(A,C,D) != ccw(B,C,D) && ccw(A,B,C) != ccw(A,B,D));
	}
	boolean contains(MyPoint p){
		double a1 = this.getArea(p,this.p1,this.p2);
		double a2 = this.getArea(p,this.p2,this.p3);
		double a3 = this.getArea(p,this.p3,this.p1);
		double A = this.getArea();
		if( (a1+a2+a3)==A )return true;
		return false;
	}
	boolean contains(Triangle2D t){
		if(!this.contains(t.p1))return false;
		if(!this.contains(t.p2))return false;
		if(!this.contains(t.p3))return false;
		return true;
	}	
	
	boolean overlaps(Triangle2D t){
			if(interSect(p1,p2,t.p1,t.p2))return true;
			if(interSect(p1,p2,t.p2,t.p3))return true;
			if(interSect(p1,p2,t.p3,t.p1))return true;
			if(interSect(p2,p3,t.p1,t.p2))return true;
			if(interSect(p2,p3,t.p2,t.p3))return true;
			if(interSect(p2,p3,t.p3,t.p1))return true;
			if(interSect(p3,p1,t.p1,t.p2))return true;
			if(interSect(p3,p1,t.p2,t.p3))return true;
			if(interSect(p3,p1,t.p3,t.p1))return true;
			return false;
	}
}