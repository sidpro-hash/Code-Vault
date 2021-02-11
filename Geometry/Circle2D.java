/*
 *        **** Geometry: the Circle2D class ****
 *
 * # Two double data fields named x and y that specify the center of
 *   the circle with getter methods.
 * # A data field radius with a getter method.
 * # A no-arg constructor that creates a default circle with (0, 0) for
 *   (x, y) and 1 for radius.
 * # A constructor that creates a circle with the specified x, y, and radius.
 * # A method getArea() that returns the area of the circle.
 * # A method getPerimeter() that returns the perimeter of the circle.
 * # A method contains(double x, double y) that returns true if the
 *   specified point (x, y) is inside this circle.
 * # A method contains(Circle2D circle) that returns true if the specified
 *   circle is inside this circle.
 * # A method overlaps(Circle2D circle) that returns true if the specified
 *   circle overlaps with this circle.
 */
class Circle2D{

	public static void main(String args[]){
		Circle2D c1 = new Circle2D(2,2,5.5);
		System.out.println("Area of circle with radius "+c1.r+" : "+c1.getArea());
		System.out.println("Perimeter of circle with radius "+c1.r+" : "+c1.getPerimeter());
		System.out.println("circle contains this point: "+c1.contains(3,3)); 
		System.out.println("circle contains this circle: "+c1.contains(new Circle2D(3, 3, 1))); 
		System.out.println("circle overlaps this circle: "+c1.overlaps(new Circle2D(3, 5, 2.3)));
	}
		
	private double x;
	private double y;
	private double r;
	
	Circle2D(){
		x=0;
		y=0;
		r=1;
	}
	Circle2D(double x,double y,double r){
		this.x = x;
		this.y = y;
		this.r = r;
	}

	boolean contains(double x, double y){
		double d = Math.sqrt( (this.x - x)*(this.x - x) + (this.y - y)*(this.y - y) );
		System.out.println("         point inside condition       ");
		System.out.println("distance between Maincircle's center & point: "+d);
		if(r>d) return true;
		return false;
	}
	boolean contains(Circle2D circle){
		System.out.println("         circle inside condition       ");
		double d = Math.sqrt( (this.x - circle.x)*(this.x - circle.x) + (this.y - circle.y)*(this.y - circle.y) );
		System.out.println("distance between Maincircle's center & new circle's center: "+d);
		d += circle.r;
		System.out.println("distance + new cricle's raius :"+d);
		System.out.println("Above distance is must be less than Maincircle's radius than it is inside");
		if(this.r > d)return true;
		return false; 
	}
	boolean overlaps(Circle2D circle){
		double d = Math.sqrt( (this.x - circle.x)*(this.x - circle.x) + (this.y - circle.y)*(this.y - circle.y) );
		System.out.println("         circle overlap condition       ");
		System.out.println("distance between circles must be greater than: "+(this.r - circle.r));
		System.out.println("distance between circles:"+d);
		System.out.println("distance between circles must be less than: "+(this.r + circle.r));
		if( (this.r - circle.r)<d && d<(this.r + circle.r)  ) return true;
		return false;
	}

	double getArea(){
		return (Math.PI * r * r);
	}
	double getPerimeter(){
		return (2 * Math.PI * r);
	}
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
}
