/* 
 *                  ****  The MyPoint class  ****
 *
 * # The data fields x and y that represent the coordinates with getter
 *   methods.
 * # A no-arg constructor that creates a point (0, 0).
 * # A constructor that constructs a point with specified coordinates.
 * # A method named distance that returns the distance from this point to a
     specified point of the MyPoint type.
 * # A method named distance that returns the distance from this point to
     another point with specified x- and y-coordinates.
*/
package sidpro;
class MyPoint{

	private double x;
	private double y;
	

	MyPoint(){
		x = 0;
		y = 0;
	}
	MyPoint(double x,double y){
		this.x = x;
		this.y = y;
	}
	
	double distance(MyPoint mypoint){
		return Math.sqrt( (x - mypoint.x)*(x - mypoint.x) + (y - mypoint.y)*(y - mypoint.y) );
	}
	double distance(double x,double y){
		return Math.sqrt( (this.x - x)*(this.x - x) + (this.y - y)*(this.y - y) );
	}
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
	
}