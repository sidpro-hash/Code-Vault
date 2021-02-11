/*
 *        ****  Geometry: the Rectangle2D class  ****
 *
 * # Two double data fields named x and y that specify the center of the rectangle
 *   with getter and setter methods. (Assume that the rectangle sides are
 *   parallel to x- or y- axes.)
 * # The data fields width and height with getter and setter methods.
 * # A no-arg constructor that creates a default rectangle with (0, 0) for (x, y)
 *   and 1 for both width and height.
 * # A constructor that creates a rectangle with the specified x, y, width, and
     height.
 * # A method getArea() that returns the area of the rectangle.
 * # A method getPerimeter() that returns the perimeter of the rectangle.
 * # A method contains(double x, double y) that returns true if the
 *   specified point (x, y) is inside this rectangle.
 * # A method contains(Rectangle2D r) that returns true if the specified
 *   rectangle is inside this rectangle.
 * # A method overlaps(Rectangle2D r) that returns true if the specified
 *   rectangle overlaps with this rectangle.
*/


class Rectangle2D{
	

	public static void main(String []args){
		Rectangle2D r1 = new Rectangle2D(2,2, 5.5, 4.9);
		System.out.println("Area of Rectangle is:"+r1.getArea()+" Whose Width:"+r1.getWidth()+" and Height:"+r1.getHeight());
		System.out.println("Perimeter of Rectangle is:"+r1.getPerimeter()+" Whose Width:"+r1.getWidth()+" and Height:"+r1.getHeight());
		System.out.println("Point (3,3) is inside of rectangle? "+r1.contains(3,3));
		System.out.println("Point (4,-4) is inside of rectangle? "+r1.contains(4,-4));
		System.out.println("Rectangle (1.75,1.75,2,2) is inside of rectangle? "+r1.contains(new Rectangle2D(1.75,1.75,2,2)));
		System.out.println("Rectangle (3,3,4,4) is inside of rectangle? "+r1.contains(new Rectangle2D(3,3,4,4)));
		System.out.println("Rectangle (5,5,2,2) is overlaps to Main rectangle? "+r1.overlaps(new Rectangle2D(5,5,2,2)));
		System.out.println("Rectangle (3,3,4,4) is overlaps to Main rectangle? "+r1.overlaps(new Rectangle2D(3,3,4,4)));
		System.out.println("Rectangle (7,7,2,2) is overlaps to Main rectangle? "+r1.overlaps(new Rectangle2D(7,7,2,2)));
	}

	private double x;
	private double y;
	private double width,height;

	Rectangle2D(){
		x = 0;
		y = 0;
		width = 1;
		height = 1;
	}
	Rectangle2D(double x,double y,double width,double height){
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}

	boolean contains(double x, double y){
		double H = height/2.0;
		double W = width/2.0;
		
		//get coordinates of rectangle
		double x1 = this.x - W;
		double x2 = this.x + W;
		double y1 = this.y + H;
		double y2 = this.y - H;
	
		// point must be inside of Rectangle 
		if( (x > x1 && x < x2) && (y > y2 && y < y1) ) return true;
		return false;
	}
	boolean contains(Rectangle2D r){
		double H = this.height/2.0;
		double W = this.width/2.0;
		//get coordinates of main rectangle
		double x1 = this.x - W;
		double x2 = this.x + W;
		double y1 = this.y + H;
		double y2 = this.y - H;

		H = r.getHeight()/2.0;
		W = r.getWidth()/2.0;
		//get coordinates of given rectangle
		double xx1 = r.getX() - W;
		double xx2 = r.getX() + W;
		double yy1 = r.getY() + H;
		double yy2 = r.getY() - H;
	
		if( (xx1>=x1 && xx2<=x2) && (yy2>=y2 && yy1<=y1))return true;
		
		return false;	
	}
	boolean overlaps(Rectangle2D r){
		double H = this.height/2.0;
		double W = this.width/2.0;
		
		double x1 = this.x - W;
		double x2 = this.x + W;
		double y1 = this.y + H;
		double y2 = this.y - H;

		H = r.getHeight()/2.0;
		W = r.getWidth()/2.0;
		
		double xx1 = r.getX() - W;
		double xx2 = r.getX() + W;
		double yy1 = r.getY() + H;
		double yy2 = r.getY() - H;

		// if one rectangle is on left side of other
		if( x2<xx1 || xx2<x1)return false;
		// if one rectangle is above other
		if( y2>yy1 || yy2>y1)return false;

		return true;
	}

	double getArea(){
		return (width * height);
	}
	double getPerimeter(){
		return 2*(width + height);
	}

	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
	void setX(double x){
		this.x = x;
	}
	void setY(double y){
		this.y = y;
	}

	double getWidth(){
		return width;
	}
	double getHeight(){
		return height;
	}
	void setWidth(double width){
		this.width = width;
	}
	void setHeight(double height){
		this.height = height;
	}

}