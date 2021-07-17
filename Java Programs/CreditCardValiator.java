/*
 *
 * @author SidPro
 * @version 1.0
 *
 *        **** Financial: credit card number validation class ****
 *
 * # A method isValid(int[] number) that returns true if the specified
 *   CreditCard is valid.
 * # A method sumOfOddPlace(int[] number) that returns the sum of odd 
 *   place digits.
 * # A method sumOfEvenDoublePlace(int[] number) that returns the sum 
 *     of Even place digits.
 * # A method getDigit(int digit) that reduce digits to < 10.
 * type of cards:
 * https://en.wikipedia.org/wiki/Payment_card_number#Issuer_identification_number_(IIN) 
 * https://www.freeformatter.com/credit-card-number-generator-validator.html
 * Input : 379354508162306
 * Output : 379354508162306 is Valid
 * Input : 4388576018402626
 * Output : 4388576018402626 is invalid
 */




import java.util.Scanner;

class CreditCardValiator{
	public static void main(String []args){
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter your Credit Card number: ");
		String num = scan.nextLine();
		String Name;
		boolean size = false;
		switch(num.charAt(0)){
			case '3':if(num.charAt(1)=='7' || num.charAt(1)=='4')Name="American Express card";
				 else Name="Diners Club card";
				 if(getSize(num)==15)size=true;
				break;
			case '4':Name="Visa card";if(getSize(num)==16)size=true;break;
			case '5':Name="Master card";if(getSize(num)==16)size=true;break;
			case '6':Name="Discover card";if(getSize(num)==16)size=true;break;
			default:Name="";
		}
		if(size){
			int[] number = new int[num.length()];
			for(int i=0;i<num.length();++i)number[i] = num.charAt(num.length()-i-1) - '0';
			System.out.print(Name+" "+num+(isValid(number)?" is Valid":" is Invalid"));
		}else System.out.print(Name+" "+num+" is Invalid");
	}

	static boolean isValid(int[] number){
		return ( (sumOfEvenDoublePlace(number) + sumOfOddPlace(number)) % 10 == 0)?true:false;
	}
	static int sumOfOddPlace(int[] number){
		int sum=0;
		for(int i=0;i<number.length;i+=2)sum+=number[i];
		return sum;
	}
	static int sumOfEvenDoublePlace(int[] number){
		int sum=0,temp=0;
		for(int i=1;i<number.length;i+=2){
			temp = number[i]*2;
			if(temp>9)temp=getDigit(temp);
			sum+=temp;
		}
		return sum;
	}
	static int getDigit(int digit){
		return ( (digit/10) + (digit%10) );
	}
	static int getSize(String num){
		return num.length();
	}
}