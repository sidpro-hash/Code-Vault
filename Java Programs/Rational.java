/*
 *
 * @author SidPro
 * @version 1.0
 *
 *        **** Number: the Rational class ****
 *
 * # Two long data fields named numerator and denominator for rational number. 
 * # A no-arg constructor that creates a rational number with numerator 0 and
 *   denominator 1 for rational number.
 * # A constructor that creates a Creates a rational number with a specified 
 *   numerator and denominator.
 * # A method getNumerator() that returns the numerator of this rational number.
 * # A method getDenominator() that returns the denominator of this rational number.
 * # A method add(Rational add_number) that Returns the addition of this rational 
 *   number with another.
 * # A method subtract(Rational subtract_number) that Returns the subtraction of this 
 *   rational number with another.
 * # A method multiply(Rational multiply_number) that Returns the multiplication of 
 *   this rational number with another.
 * # A method divide(Rational divide_number) that Returns the division of this 
 *   rational number with another.
 * # A method toString() that Returns a string in the form "numerator/denominator".
 *   Returns the numerator if denominator is 1.
 * # A method gcd(long n,long d) that Returns the greatest common divisor of n and d.
 *
 */
import java.math.BigInteger;
class Rational extends Number implements Comparable<Rational>{

	public static void main(String []args){
		Rational r1 = new Rational(4,2);
		Rational r2 = new Rational(2,3);
		Rational r3 = new Rational(1,123456789);
		System.out.println(r1 + " + " + r2 + " = " + r1.add(r2));
		System.out.println(r1 + " - " + r2 + " = " + r1.subtract(r2));
		System.out.println(r1 + " * " + r2 + " = " + r1.multiply(r2));
		System.out.println(r1 + " / " + r2 + " = " + r1.divide(r2));
		System.out.println(r2 + " is " + r2.doubleValue());
		System.out.println("r1 * r2 * r3 is " +r1.multiply(r2.multiply(r3)));
	}



	// Data fields for numerator and denominator
	private BigInteger numerator = BigInteger.ZERO;
	private BigInteger denominator = BigInteger.ONE;

	// Construct a rational with default properties
	Rational(){
		numerator = BigInteger.ZERO;
		denominator = BigInteger.ONE;
	}
	// Construct a rational with specified numerator and denominator
	Rational(long numerator,long denominator){
		this.numerator = BigInteger.valueOf(numerator);
		this.denominator= BigInteger.valueOf(denominator);
		BigInteger gcde = this.numerator.gcd(this.denominator);
		BigInteger temp = BigInteger.valueOf( (long)((denominator > 0)?1:-1) );
		this.numerator =  temp.multiply(this.numerator.divide(gcde));
		this.denominator = (this.denominator.abs()).divide(gcde);
	}
	Rational(BigInteger numerator,BigInteger denominator){
		BigInteger gcde = numerator.gcd(denominator);
		BigInteger temp = BigInteger.valueOf( (long)(denominator.compareTo(BigInteger.ZERO)) );
		this.numerator =  temp.multiply(numerator.divide(gcde));
		this.denominator = (denominator.abs()).divide(gcde);
	}
	
	// Return numerator
	public BigInteger getNumerator(){
		return numerator;
	}
	// Return denominator
	public BigInteger getDenominator(){
		return denominator;
	}

	// add a rational number to this rational a/b+r.a/r.b = a*r.b + r.a*b/r.b*b
	public Rational add(Rational r){
		BigInteger n = (numerator.multiply(r.getDenominator())).add(denominator.multiply(r.getNumerator())); 
		BigInteger d = denominator.multiply(r.getDenominator());
		return new Rational(n,d);
	}
	// subtract a rational number to this rational a/b - r.a/r.b = a*r.b - r.a*b/r.b*b
	public Rational subtract(Rational r){
		BigInteger n = (numerator.multiply(r.getDenominator())).subtract(denominator.multiply(r.getNumerator())); 
		BigInteger d = denominator.multiply(r.getDenominator());
		return new Rational(n,d);
	}
	// multiply a rational number to this rational a/b * r.a/r.b = a*r.a / b*r.b
	public Rational multiply(Rational r){
		BigInteger n = numerator.multiply(r.getNumerator()); 
		BigInteger d = denominator.multiply(r.getDenominator());
		return new Rational(n,d);
	}
	// divide a rational number to this rational a/b * r.a/r.b = a*r.b / b*r.a
	public Rational divide(Rational r){
		BigInteger n = numerator.multiply(r.getDenominator()); 
		BigInteger d = denominator.multiply(r.getNumerator());
		return new Rational(n,d);
	}
	
	@Override // Override the toString method in the Object class
	public String toString(){
		if(denominator==BigInteger.ONE)return (numerator+"");
		return (numerator+"/"+denominator);
	}
	@Override // Override the equals method in the Object class
	public boolean equals(Object o){
		if( (this.subtract((Rational)(o))).getNumerator() == BigInteger.ZERO )return true;
		return false;
	}
	
	@Override // Implement the abstract intValue method in Number
	public int intValue(){
		return (int)doubleValue();
	}
	@Override // Implement the abstract floatValue method in Number
	public float floatValue(){
		return (float)doubleValue();
	}
	@Override // Implement the abstract doubleValue method in Number
	public double doubleValue(){
		return numerator.doubleValue()/denominator.doubleValue();
	}
	@Override // Implement the abstract longValue method in Number
	public long longValue(){
		return (long)doubleValue();
	}
	public int compareTo(Rational r){
		return (this.subtract(r).getNumerator()).compareTo(BigInteger.ZERO);
	}

	// Find GCD of two numbers
	private static long gcd(long n,long d){
		long n1 = Math.abs(n);
		long n2 = Math.abs(d);
		long temp;
		int gcd = 1;
		
		while(n2>0){
			n1 = n1 % n2;
			temp = n1;
			n1 = n2;
			n2 = temp;	
		}
		return n1;
	}
}